//This assignment completed with pair programming
// Name: John Carlyle Username: jcarlyle@ucsc.edu
// Name: Morgan McDermott Username: moamcder@ucsc.edu

#ifndef __ASTREE_H__
#define __ASTREE_H__

#include <string>
#include <vector>
using namespace std;

#include "auxlib.h"

typedef struct astree_rep* astree;

bool is_astree (void *object);
astree new_astree (int symbol, int filenr, int linenr, int offset, const char* lexinfo);
astree adopt (astree root, /*Astree*/ ... /*, NULL */);
astree adopt1 (astree root, astree child);
astree adopt2 (astree root, astree left, astree right);
astree adopt3(astree root, astree child1, astree child2,astree child3);
astree adopt1sym (astree root, astree child, int symbol);
astree adopt2sym (astree root, astree child1,astree child2,int symbol);

int filenr (astree obj);
int linenr(astree obj);
int offset(astree obj);
void changeIFproto(astree root, astree block);
astree func_astree(int symbol, astree obj);

void changeSYM (astree ast, int symbol);

void dump_astree(FILE* outfile, astree root);
void yyprint (FILE* outfile, unsigned short toknum,
              astree yyvaluep);
void free_ast (astree tree);
void free_ast2 (astree tree1, astree tree2);


struct astree_rep {
  string tag;
  int symbol;               // token code
  int filenr;            // index into filename stack
  int linenr;            // line number from source code
  int offset;            // offset of token with current line
  const string* lexinfo;    // pointer to lexical information
  vector<astree> children; // children of this n-way node

  astree first, last, next;
};

#endif
