#include "codegen.h"
#include "typechecker.h"
#include "yyparse.h"
#include <cstdlib>

FILE *output;
int varCounter;
int controlCounter;
int tabCounter; 

string codegenExpr(astree expr);
void switchOnToken(astree token);
void printStmt(string s, bool label = false);
void printBlock(astree token);

string itoa(int i){
  char v[50] = {0};
  sprintf(v, "%d", i);
  return string(v);
}

void structPass(astree token){
  token = token;
}

string codegen_binop(astree token){
  string left = codegenExpr(token->first);
  string op = *(token->first->next->lexinfo);
  string right = codegenExpr(token->last);
  
  if(op == "="){
    return(left + " = " + right);
  }
  else {
    string t = typecheck_expr(token->first);
    string newTempType = ""; 
    string newTempName = ""; 

    if(t == "int"){ newTempType = "int"; newTempName = "i"+itoa(varCounter++); }
    else if(t == "bool" || t == "char"){ newTempType = "ubyte"; newTempName = "b"+itoa(varCounter++); }
    else if(t == "string"){ newTempType = "ubyte *"; newTempName = "p"+itoa(varCounter++); }
    else {
      newTempType = "struct " + t + " *"; newTempName = "p"+itoa(varCounter++);
    }
    
    if(t.find("[") != string::npos){
      newTempName = "p"+itoa(varCounter++);

      string basetype = t.substr(0, t.find("["));
      if(basetype == "bool" || basetype == "char") newTempType = "ubyte *";
      else if(basetype == "int") newTempType = "int *";
      else if(basetype == "string") newTempType = "ubyte **";
      else newTempType = "struct " + basetype + " **;";
	     }

    printStmt(newTempType + " " + newTempName + " = " + left + " " + op + " " + right);
    return newTempName;
  }
}
/*
bool     ubyte
char     ubyte
int      int
string   ubyte *
typeid   struct typeid *
bool[]   ubyte *
char[]   ubyte *
int[]    int *
string[] ubyte **
typeid[] struct typeid **
*/
string typeMap(string t){
  string newType = "";
  if(t == "bool"){ newType = "ubyte"; }
  else if (t == "int"){ newType = "int"; }
  else if (t == "bool"){ newType = "ubyte"; }
  else if (t == "int"){ newType = "int"; }
  else if (t == "string"){ newType = "ubyte *"; }
  else if (t == "bool[]"){ newType = "ubyte *"; }
  else if (t == "char[]"){ newType = "ubyte *"; }
  else if (t == "int[]"){ newType = "int *"; }
  else if (t == "string[]"){ newType = "ubyte **"; }
  else { newType = "struct "+t+" **"; }
  return newType;

}

string rename(string varname, string newType, astree node){
  string newName = "";
  if(false){ /* Global Name Logic */ }
  else {
    newName = "_" + itoa(node->scope->getNum()) + "_" + varname;
  }
  return newName;
}

string codegen_vardecl(astree node){
  string leftType = "";
  string varname = "";
  astree rvalue;
  
  if(node->first->symbol == TOK_ARRAY){ //something magical
    leftType = *(node->first->next->first->lexinfo)+"[]";
    varname = *(node->first->next->next->lexinfo);	  
  }
  else if(node->first->symbol == TOK_BASETYPE){ //something not magical
    leftType = *(node->first->first->lexinfo);
    varname = *(node->first->next->lexinfo);	  
  }
  else { //is a TOK_TYPEID
    leftType = *(node->first->lexinfo);
    varname = *(node->first->next->lexinfo);
  } 

  string newType = typeMap(leftType);;
  string newName = rename(varname, newType, node);
  
  return newType + " " + newName + " = " + codegenExpr(node->last);
}




string codegen_variable(astree expr){
  string varname = *(expr->first->lexinfo);
  if(false){ /* global name logic */ }
  else {
    return "_" + itoa(expr->scope->findOrigin(varname)->getNum()) + "_" + varname; 
  }
  return "UNKNOWN VAR";
}

string codegen_constant(astree expression){
  if(expression->first->symbol == TOK_NULL){ return "NULL"; }
  return *(expression->first->lexinfo);
}

string codegen_call(astree expression){
  string fn = *(expression->first->lexinfo);

  string argList = "";
  astree plist = expression->first->next;
  bool first = true; 
  while(plist != NULL){
    if(first != true){ argList += ", "; }
    first = false; 
    argList += codegenExpr(plist);
    plist = plist->next; 
  }

  return + "__" + fn + "(" + argList + ")";
}

//Returns an oil expression containing or referencing the desired value.
// Will return a constant in the case of a constant.
string codegenExpr(astree expr){
  switch(expr->symbol){
  case TOK_CALL: return codegen_call(expr);
  case TOK_CONSTANT: return codegen_constant(expr);
  case TOK_VARIABLE: return codegen_variable(expr); 
    break;
  case TOK_BINOP: return codegen_binop(expr); 
    break;
  default: return "UnknownTokenExpr"; break;
  }
}

void printStmt(string s, bool label){
  if(!label){
    for(int i = 0; i < tabCounter; i ++){
      fprintf(output, "\t");
    }
  }
  fprintf(output, "%s;\n", s.c_str()); 

}

void codegen_while(astree token){
  string counter = itoa(controlCounter++);
  printStmt("while_"+counter+":", true);
  string condition = codegenExpr(token->first);
  printStmt("if(!" + condition + ") goto break_" + counter);
  switchOnToken(token->last);
  printStmt("goto while_"+counter);
  printStmt("break_"+counter+":", true);
}

void printBlock(astree token){
  tabCounter++;
  switchOnToken(token);
  tabCounter--;
}

void codegen_function(astree token){
  fprintf(output, "%s\n", token->first->first->first->lexinfo->c_str());
  fprintf(output, "__%s(", token->first->first->next->lexinfo->c_str());
  
  astree arg = token->first->next->first;
  bool first = true;
  while(arg != NULL){
    if(first != true){ fprintf(output, ", "); }
    first = false; 
    string varname = *(arg->first->next->lexinfo);
    string newType = typeMap(*(arg->first->first->lexinfo));
    fprintf(output, "%s ", newType.c_str());
    fprintf(output, "%s",  rename(varname, newType, token->last->first).c_str());
    arg = arg->next;
  }

  fprintf(output, ")\n{\n");

  printBlock(token->last);
  
  fprintf(output, "%s", "}\n");
}

void codegen_return(astree token){
  string val = codegenExpr(token->first);
  printStmt("return "+val);
}

void switchOnToken(astree token) {
  switch (token->symbol) {
  case TOK_WHILE: codegen_while(token); break;
  case TOK_CALL: printStmt(codegenExpr(token)); break;
  case TOK_FUNCTION: codegen_function(token); break; 
  case TOK_RETURN: codegen_return(token); break;
  case TOK_RETURNVOID: printStmt("return"); break; 
  case TOK_ROOT: {
    astree child = token->first;
    while(child != NULL){ switchOnToken(child); child = child->next; }
    break;
  }
  case TOK_BLOCK: {
    astree child = token->first;
    while(child != NULL){ switchOnToken(child); child = child->next; }
    break;
  }
  case TOK_VARDECL: printStmt(codegen_vardecl(token)); break;
  case TOK_BINOP: printStmt(codegenExpr(token)); break;
    break;
  case TOK_STRUCT: break; //covered in struct pass
  }
}

void codegen(string filename, astree t){  
  output = fopen(filename.c_str(), "w");
  varCounter = 0;
  controlCounter = 0;
  tabCounter = 0;
  
  fprintf(output, "#define __OCLIB_C__\n");
  fprintf(output, "#include \"oclib.oh\"\n");

  structPass(t);
  switchOnToken(t);
  
  fclose(output);
}
