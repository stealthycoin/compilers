#include "codegen.h"

void switchOnToken(astree token) {
  
  switch (token->symbol) {
    
  }

}


void codegen(string filename, astree t){  
  FILE *oilFile = fopen(filename.c_str(), "w");

  switchOnToken(t);
  
  fclose(oilFile);

}
