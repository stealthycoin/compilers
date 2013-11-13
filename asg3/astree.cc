//This assignment completed with pair programming
// Name: John Carlyle Username: jcarlyle@ucsc.edu
// Name: Morgan McDermott Username: moamcderxf@ucsc.edu

#include <assert.h>
#include <inttypes.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "astree.h"
#include "astree.rep.h"
#include "lyutils.h"
#include "stringset.h"

static char *astree_tag = "struct astree_rep";

bool is_astree (void *object) {
   astree tree = (astree) object;
   return tree != NULL && tree->tag == astree_tag;
}
astree func_astree(int symbol, astree obj){
   size_t size = sizeof (struct astree_rep);
   astree tree = (astree)malloc (size);
   tree->tag = astree_tag;
   tree->symbol = symbol;
   tree->filenr = obj->filenr;
   tree->linenr = obj->linenr;
   tree->offset = obj->offset;
   tree->lexinfo = intern_stringset(""); 
   tree->first = NULL;
   tree->last = NULL;
   tree->next = NULL;
   return tree;
}

astree new_astree (int symbol, int filenr, int linenr, int offset,
                   const char* lexinfo) {
   size_t size = sizeof (struct astree_rep);
   astree tree = (astree)malloc (size);
   assert (tree != NULL);
   tree->tag = astree_tag;
   tree->symbol = symbol;
   tree->filenr = filenr;
   tree->linenr = linenr;
   tree->offset = offset;
   tree->lexinfo = intern_stringset(lexinfo);
   //initially its going to be null
   //for now, no reason to check
   assert (tree->lexinfo != NULL);
   tree->first = NULL;
   tree->last = NULL;
   tree->next = NULL;
   DEBUGF ('f', "malloc (%d) = %p-> %d:%d.%d: %s: %p->\"%s\"\n",
           size, tree, tree->filenr, tree->linenr, tree->offset,
           get_yytname (tree->symbol), tree->lexinfo, tree->lexinfo);
   return tree;
}


astree adopt (astree root, ...) {
   va_list children;
   assert (is_astree (root));
   va_start (children, root);
   for(;;) {
      astree child = va_arg (children, astree);
      if (child == NULL) break;
      assert (is_astree (child));
      if (root->last == NULL) root->first = child;
                         else root->last->next = child;
      root->last = child;
      DEBUGF ('a', "%p (%s) adopting %p (%s)\n",
              root, root->lexinfo,
              child, child->lexinfo);
   }
   va_end (children);
   return root;
}

astree adopt3(astree root, astree child1, astree child2, astree child3){
   return adopt(root, child1, child2, child3, NULL);
}

astree adopt2 (astree root, astree left, astree right) {
   return adopt (root, left, right, NULL);
}

astree adopt1 (astree root, astree child) {
   return adopt (root, child, NULL);
}

astree adopt1sym (astree root, astree child, int symbol) {
   root = adopt1 (root, child);
   root->symbol = symbol;
   return root;
}

astree adopt2sym (astree root, astree child1,
                  astree child2, int symbol){
   root = adopt2(root, child1, child2);
   root->symbol = symbol;
   return root;
}

astree adopt3sym (astree root, astree child1,
                  astree child2,  astree child3, int symbol){
   root = adopt3(root, child1, child2, child3);
   root->symbol = symbol;
   return root;
}

void changeSYM (astree ast, int symbol){
   ast->symbol = symbol;
}

void changeIFproto(astree root, astree block)
{
   if(block->symbol==';') root->symbol=TOK_PROTOTYPE;
}


static void dump_node (FILE *outfile, astree node, int depth) {
   assert (is_astree (node));
   for(int i =0 ;i<depth;i++)
       fprintf(outfile,"  ");
   /*fprintf (outfile, "%s \"%s\" %d.%d.%d",get_yytname (node->symbol),
	                               node->lexinfo->c_str(),
                                       node->filenr, node->linenr, 
                                       node->offset);
   */
   /*fprintf (outfile, "%s \"%s\" ",get_yytname (node->symbol),
     node->lexinfo->c_str());*/

     string out = "";
       switch(node->symbol){
       case TOK_ROOT: out = "program"; break;
       case TOK_VOID: out = "void"; break;
       case TOK_PROTOTYPE: out = "prototype"; break;
       case TOK_ARRAY: out = "array"; break;
       case TOK_WHILE: out = "while"; break;
       case TOK_VARIABLE: out = "variable"; break;
       case TOK_BLOCK: out = "block"; break;
       case TOK_BINOP: out = "binop"; break;
       case TOK_UNOP: out = "unop"; break;
       case TOK_CALL: out = "call"; break;
       case TOK_CONSTANT: out = "constant"; break;
       case TOK_VARDECL: out = "vardecl"; break;
       case TOK_BASETYPE: out = "basetype"; break;
       case TOK_TYPE: out = "type"; break;
       default: out = string(get_yytname(node->symbol)) + " (" + *(node->lexinfo)+")"; break;
       }
     fprintf (outfile, "%s", out.c_str());
}

static void dump_astree_rec (FILE *outfile, astree root, int depth) {
   astree child = NULL;
   if (root == NULL) return;
   assert (is_astree (root));
   dump_node (outfile, root, depth);
   fprintf (outfile, "\n");
   for (child = root->first; child != NULL; child = child->next) {
      dump_astree_rec (outfile, child, depth + 1);
   }
}

void dump_astree (FILE *outfile, astree root) {
   dump_astree_rec (outfile, root, 0);
   fflush (NULL);
}

void yyprint (FILE *outfile, unsigned short toknum, astree yyvaluep) {
   fprintf (outfile, "%d=%s)\n%*s(",
             toknum, get_yytname (toknum), 9, "");
   if (is_astree (yyvaluep)) {
      dump_node (outfile, yyvaluep, 3);
   }else{
      fprintf (outfile, "yyvaluep = %p", (void*) yyvaluep);
   }
   fflush (NULL);
}

void freeast (astree root) {
  return;
   astree child = NULL;
   if (root == NULL) return;
   assert (is_astree (root));
   for (child = root->first; child != NULL;) {
      astree asttofree = child;
      assert (is_astree (asttofree));
      child = child->next;
      freeast (asttofree);
   }
   DEBUGF ('f', "free [%X]-> %d:%d.%d: %s: %p->\"%s\")\n",
           (uintptr_t) root, root->filenr, root->linenr, root->offset,
            get_yytname (root->symbol), root->lexinfo, root->lexinfo);
   //free (root->lexinfo);
   memset (root, 0, sizeof (struct astree_rep));
   free (root);
}


