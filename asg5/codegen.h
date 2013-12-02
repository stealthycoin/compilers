#ifndef _CODEGEN_H_
#define _CODEGEN_H_

#include "astree.h"
#include "symtable.h"
#include "typechecker.h"

typedef struct codegenParams {
  FILE *output;
  SymbolTable symTable;
} codegenParams; 

void codegen(string filename, astree t);

#endif
