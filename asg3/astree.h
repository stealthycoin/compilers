//This assignment completed with pair programming
// Name: John Carlyle Username: jcarlyle@ucsc.edu
// Name: Morgan McDermott Username: moamcder@ucsc.edu

#ifndef __ASTREE_H__
#define __ASTREE_H__

#include <stdbool.h>

#include "auxlib.h"
#include "stringset.h"

struct astree_rep; 

typedef struct astree_rep *astree;

struct astree_rep {
   char *tag;               // tag field to verify class membership
   int symbol;              // token code
   int filenr;              // index into filename stack
   int linenr;              // line number from source code
   int offset;              // offset of token with current line
  const string *lexinfo;  // pointer to lexical information
   astree first;            // first child node of this node
   astree last;             // last child node of this node
   astree next;             // next younger sibling of this node
};





bool is_astree (void *object);
astree new_astree (int symbol, int filenr, int linenr, int offset,
                   const char *lexinfo);
astree adopt (astree root, /*ASTree*/ ... /*, NULL */);
astree adopt1 (astree root, astree child);
astree adopt2 (astree root, astree left, astree right);
astree adopt3(astree root, astree child1, astree child2,astree child3);
astree adopt1sym (astree root, astree child, int symbol);
astree adopt2sym (astree root, astree child1,astree child2,int symbol);
int filenr (astree obj);
int linenr(astree obj);
int offset(astree obj);
astree func_astree(int symbol, astree obj);
astree new_parseroot (void);
void changeSYM (astree ast, int symbol);
void changeIFproto(astree root, astree block);
void dump_astree (FILE *outfile, astree root);
void yyprint (FILE *outfile, unsigned short toknum, astree yyvaluep);
void freeast (astree tree);




#define freeast2(T1,T2) { freeast (T1); freeast (T2); }
#endif
