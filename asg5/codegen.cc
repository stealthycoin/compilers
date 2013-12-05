#include "codegen.h"
#include "typechecker.h"
#include "symtable.h"
#include "yyparse.h"
#include <cstdlib>
#include <unordered_set>
#include <vector>

FILE *output;
int varCounter;
int controlCounter;

string codegenExpr(astree expr);
void switchOnTokenInstructions(astree token, bool root = false);
void printStmt(string s, bool label = false);
void printBlock(astree token);

unordered_set<string> globals;
vector<astree> initializers;

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
  else if(op == ">=" || op == ">" || op == "<=" || op == "<" || "!="){
    string newTempName = "b"+itoa(varCounter++);
    printStmt("ubyte " + newTempName + " = " + left + " " + op + " " + right);
    return newTempName; 
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
  else if (t == "char"){ newType = "ubyte"; }
  else if (t == "int"){ newType = "int"; }

  else if (t == "string"){ newType = "ubyte *"; }
  else if (t == "bool[]"){ newType = "ubyte *"; }
  else if (t == "char[]"){ newType = "ubyte *"; }
  else if (t == "int[]"){ newType = "int *"; }
  else if (t == "string[]"){ newType = "ubyte **"; }
  else { newType = "struct "+t+" **"; }
  return newType;

}

string rename(string varname, astree node){
  string newName = "_" + itoa(node->scope->findOrigin(varname)->getNum()) + "_" + varname;
  if(globals.find(newName) != globals.end()) return "_" + newName; 
  return newName;
}

string codegen_vardecl(astree node, bool global = false, bool globalInit = false){
  string leftType = "";
  string varname = "";
  
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
  string newName = rename(varname, node);

  if(globalInit){
    return newName + "=" + codegenExpr(node->last);
  }
  else{
    if(globals.find(newName) != globals.end()){
      return "_" + newName + "=" + codegenExpr(node->last);
    }
    else if(global) {
      globals.insert(newName);
      initializers.push_back(node); 
      newName = "_" + newName;
      return newType + " " + newName;
    }
    else return newType + " " + newName + "=" + codegenExpr(node->last);
  }
}




string codegen_variable(astree expr){
  string varname = *(expr->first->lexinfo);
  return rename(varname, expr);
}

string codegen_constant(astree expression){
  if(expression->first->symbol == TOK_NULL){ return "null"; }
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

string codegen_newarray(astree expr){
  string type = *(expr->first->first->lexinfo);
  string newType = typeMap(type);
  return "("+newType+"*)xcalloc("+(*(expr->last->first->lexinfo))+", sizeof("+newType+"))";
}

string codegen_new(astree expr){
  string type = *(expr->first->first->lexinfo);
  string newType = typeMap(type);
  return "("+newType+"*)xcalloc("+(*(expr->last->first->lexinfo))+", sizeof("+newType+"))";
}

string codegen_index(astree expr){
  string newType = typeMap(expr->scope->lookup(*(expr->first->first->lexinfo)));
  string newName = rename(*(expr->first->first->lexinfo), expr);
  return newName + "[" + codegenExpr(expr->last) + "]";
}

string codegen_ord(astree expr){
  string v = codegen_variable(expr->first);
  string newTempName = "i"+itoa(varCounter++);
  printStmt("int "+newTempName+" = "+v+" - 48;");
  return newTempName;
}

string codegen_chr(astree expr){
  string v = codegen_variable(expr->first);
  string newTempName = "b"+itoa(varCounter++);
  printStmt("ubyte "+newTempName+" = "+v+" + 48;");
  return newTempName;
}

//Returns an oil expression containing or referencing the desired value.
// Will return a constant in the case of a constant.
string codegenExpr(astree expr){
  switch(expr->symbol){
  case TOK_ORD: return codegen_ord(expr);
  case TOK_CHR: return codegen_chr(expr);
  case TOK_INDEX: return codegen_index(expr); 
  case TOK_NEWARRAY: return codegen_newarray(expr);
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
      fprintf(output, "        ");
  }
  fprintf(output, "%s;\n", s.c_str()); 

}

void codegen_while(astree token){
  string counter = itoa(controlCounter++);
  printStmt("while_"+counter+":", true);
  string condition = codegenExpr(token->first);
  printStmt("if(!" + condition + ") goto break_" + counter);
  switchOnTokenInstructions(token->last);
  printStmt("goto while_"+counter);
  printStmt("break_"+counter+":", true);
}

void printBlock(astree token){
  switchOnTokenInstructions(token);
}

void codegen_function(astree token){
  fprintf(output, "%s\n", token->first->first->first->lexinfo->c_str());
  fprintf(output, "__%s(", token->first->first->next->lexinfo->c_str());
  
  astree arg = token->first->next->first;
  bool first = true;
  while(arg != NULL){
    if(first != true){ fprintf(output, ", "); }
    first = false; 
    string varname = *(arg->last->lexinfo);
    string type = *(arg->first->first->lexinfo);
    if(arg->first->next->symbol == TOK_ARRAY) type += "[]";
    string newType = typeMap(type);

    fprintf(output, "%s ", newType.c_str());
    fprintf(output, "%s",  rename(varname, token->last->first).c_str());
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

void switchOnTokenDefinitions(astree token){
  switch (token->symbol) {
  case TOK_FUNCTION: codegen_function(token); break; 
  case TOK_ROOT: {
    astree child = token->first;
    while(child != NULL){ switchOnTokenDefinitions(child); child = child->next; }
    break;
  }
  case TOK_VARDECL: printStmt(codegen_vardecl(token, true), true); break;
  case TOK_STRUCT: break; //covered in struct pass
  }
}


void codegen_if(astree node, string successJump = "-1"){
  switchOnTokenInstructions(node->last);
  //  if(node->last->symbol == 291)
  string counter = itoa(controlCounter++);
  string condition = codegenExpr(node->first);
  printStmt("if_"+counter+":;", true);
  printStmt("if(!"+condition+") goto fi_" + counter, true);
  switchOnTokenInstructions(node->last);
  if(successJump != "-1")
    printStmt("goto fi_ifelse_"+successJump);
  printStmt("fi_"+counter+":", true);
}

/*
              TOK_IFELSE (if)
                binop
                block
                TOK_IFELSE (if)
                  binop
                  block
                  block
 */

void codegen_ifelse(astree node, string successJump = "-1"){


  string chainCounter = itoa(controlCounter++);

  string thisCounter = itoa(controlCounter++);

  string condition = codegenExpr(node->first);

  printStmt("if(!"+condition+") goto fi_" + thisCounter);
  switchOnTokenInstructions(node->first->next);
  if(successJump == "-1")
    printStmt("goto fi_ifelse_"+chainCounter);
  else
    printStmt("goto fi_ifelse_"+successJump);
  printStmt("fi_"+thisCounter+":", true);

  astree temp = node->first->next->next;
  while(temp != NULL){
    if(temp->symbol == TOK_IF){
      codegen_if(temp, chainCounter);
      printStmt("goto fi_ifelse_"+chainCounter);
    }
    else if(temp->symbol == TOK_IFELSE) codegen_ifelse(temp, chainCounter);
    else { switchOnTokenInstructions(temp); }
    temp = temp->next;
  }
  printStmt("fi_ifelse_"+chainCounter+":", true);
}	
void switchOnTokenInstructions(astree token, bool rootLevel) {
  switch (token->symbol) {
  case TOK_WHILE: codegen_while(token); break;
  case TOK_IF: codegen_if(token); break;
  case TOK_IFELSE: codegen_ifelse(token); break;
  case TOK_CALL: printStmt(codegenExpr(token)); break;
  case TOK_FUNCTION: break;
  case TOK_RETURN: codegen_return(token); break;
  case TOK_RETURNVOID: printStmt("return"); break; 
  case TOK_ROOT: {
    astree child = token->first;
    while(child != NULL){ switchOnTokenInstructions(child, true); child = child->next; }
    break;
  }
  case TOK_BLOCK: {
    astree child = token->first;
    while(child != NULL){ switchOnTokenInstructions(child); child = child->next; }
    break;
  }
  case TOK_VARDECL: if(!rootLevel) printStmt(codegen_vardecl(token)); break;
  case TOK_BINOP: printStmt(codegenExpr(token)); break;
    break;
  case TOK_STRUCT: break; //covered in struct pass
  }
}

void initializeGlobals(){
  for(uint i = 0; i < initializers.size(); i++){
    printStmt(codegen_vardecl(initializers[i], true, true));
  }

}
void codegen(string filename, astree t){  
  output = fopen(filename.c_str(), "w");
  varCounter = 0;
  controlCounter = 0;
  
  fprintf(output, "#define __OCLIB_C__\n");
  fprintf(output, "#include \"oclib.oh\"\n");

  fprintf(output, "ubyte ** __argv;\n");
  fprintf(output, "int __argi;\n\n");

  structPass(t);
  switchOnTokenDefinitions(t);
  
  fprintf(output, "\n__ocmain ()\n{\n");
  initializeGlobals();
  switchOnTokenInstructions(t, true);
  fprintf(output, "}\n");
  
  fclose(output);
}
