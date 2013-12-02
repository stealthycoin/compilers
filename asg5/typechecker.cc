#include "typechecker.h"
#include "yyparse.h"
#include "auxlib.h"
#include <cmath>
#include <cstdlib>

void show_error(string message, astree bad_token) {
  errprintf("Line %d: %s\n", bad_token->linenr, message.c_str());
  set_exitstatus(EXIT_FAILURE);
}

//If the passed tree is a constant, its first child is returned
// otherwise, the symbol of the original tree is returned.
int extractPrimSymbol(astree t){
  astree prim = t;
  if(t->symbol == TOK_CONSTANT) prim = t->first;
  return prim->symbol;
}


bool isTypePrimative(string t){
  return (t == "char" || t == "bool" || t == "int");
}

bool isPrimative(astree t){
  if(extractPrimSymbol(t) == TOK_NULL) return false;
  if(extractPrimSymbol(t) == TOK_STRINGCON) return false; 
  return (PRIMATIVE_MAP.find(extractPrimSymbol(t)) != PRIMATIVE_MAP.end());
}

bool isPrimativeRep(astree t){
  if(t->symbol == TOK_VARIABLE){
    string varname = *(t->first->lexinfo);
    string ty = t->scope->lookup(varname);
    return isTypePrimative(ty); 
  }
  else return isPrimative(t);
}
void assert_expr_type(string context, string type, astree expression);


// string expr_type(astree expression){
//   if (expression->scope == NULL)
//     show_error("Does not have scope.", expression);
//   if(isPrimative(expression))
//     return PRIMATIVE_MAP[extractPrimSymbol(expression)];
//   else {
//     switch (expression->symbol) {
//     case TOK_POS:
//       assert_expr_type("int", expression->first);
//       return "int";
//       break;
//     case TOK_NEG:
//       assert_expr_type("int", expression->first);
//       return "int";
//       break;
//     case '!': 
//       assert_expr_type("bool", expression->first);
//       return "bool"; break;
//     case TOK_ORD: 
//       assert_expr_type("char", expression->first);
//       return "int"; break;
//     case TOK_CHR: 
//       assert_expr_type("int", expression->first);
//       return "char"; break;
// 	break;
//     case TOK_NEW:
//       return *(expression->first->lexinfo);
//       break;
//     case TOK_NEWARRAY:
//       return *(expression->first->first->lexinfo)+"[]";
//       break;
//     case TOK_CALL:
//       {
// 	string type = expression->scope->lookup(*(expression->first->lexinfo));
// 	return type.substr(0, type.find("("));
//       }
//       break;
//     case TOK_BINOP:
//       {
// 	string leftType = expr_type(expression->first);
// 	string rightType = expr_type(expression->last);
// 	if(leftType != rightType)
// 	  show_error("Expression of type "+rightType+" found, expected "+leftType, expression->last);
// 	string op = *(expression->first->next->lexinfo);
// 	if(op == "==" || op == "!=" || op == "<=" || op == ">=" || op == "<" || op == ">")
// 	  return "bool";
// 	return leftType;
// 	break;
//       }
//     case TOK_CONSTANT:
//       {
// 	string s = PRIMATIVE_MAP[extractPrimSymbol(expression)];
// 	if(s == ""){
// 	  if(expression->first->symbol == TOK_NULL) return "null";
// 	  else {
// 	    show_error("Unknown constant", expression);
// 	  }
// 	}
// 	return s;
// 	break;
//       }
//     case TOK_VARIABLE:
//       {
// 	string t = expression->scope->lookup(*(expression->first->lexinfo));
// 	return t;
// 	break;
//       }
//     case '.':
//       {
// 	string name = expression->scope->lookup(*(expression->first->first->lexinfo)) + "." + *(expression->last->lexinfo);
// 	string t = expression->scope->lookup(name);
// 	return t;
// 	break;
//       }
//     default:
//       printf("\t No case in expr_type for node type: %c\n", (char)expression->symbol);
//       return "";
//     }
//   }
// }

void breakpoint() {}

string typecheck_expr(astree expression);

void assert_expr_type(string context, string type, astree expression){
  string t = typecheck_expr(expression);
  if(t != type) show_error("In "+context+", found type "+t+", expected "+type, expression);
}

string typecheck_expr(astree expression) {
  if (expression->scope == NULL) {
    show_error("Does not have scope.", expression);
  }
  
  if(isPrimative(expression)){
    return PRIMATIVE_MAP[extractPrimSymbol(expression)];
  }
  else {
    switch (expression->symbol) {
    case TOK_POS:
      assert_expr_type("+", "int", expression->first);
      return "int"; break;
    case TOK_NEG:
      assert_expr_type("-", "int", expression->first);
      return "int"; break;
    case '!': 
      assert_expr_type("!", "bool", expression->first);
      return "bool"; break;
    case TOK_ORD: 
      assert_expr_type("ord", "char", expression->first);
      return "int"; break;
    case TOK_CHR: 
      assert_expr_type("chr", "int", expression->first);
      return "char"; break;
    case TOK_NEW:
      return *(expression->first->lexinfo); break;
    case TOK_NEWARRAY:
      return *(expression->first->first->lexinfo)+"[]"; break;
    case TOK_NULL: return "null"; break;
    case TOK_INDEX:
      {
	string varname = *(expression->first->first->lexinfo);
	string type = expression->scope->lookup(varname);
	if(type == "string"){  return "char"; }
	else return type.substr(0, type.find("["));
	break;
      }
    case TOK_CALL:
      {
	string fn = *(expression->first->lexinfo);
	string t = expression->scope->lookup(*(expression->first->lexinfo));

	if (t == "") {  show_error("Function "+fn+" has empty type.", expression); break; 	}

	string argType = "";
	bool first = true;
	astree plist = expression->first->next;
	while(plist != NULL){
	  if(first != true){ argType += ", "; }
	  first = false; 
	  argType += typecheck_expr(plist);
	  plist = plist->next; 
	}
	
	string foundType = t.substr(0, t.find("(")) + "(" + argType + ")";
	if(t != foundType)
	  show_error("Wrong argument types given to function "+fn
		     +"."+"\n\tGiven "+foundType
		     +"\n\tExpected "+t, expression);

	return t.substr(0, t.find("("));
	break;
      }
    case TOK_BINOP:
      {
	string op = *(expression->first->next->lexinfo);
	if(op == "+" || op == "-" || op == "/" || op == "*" || op =="%") {
	  if(typecheck_expr(expression->first) != "int" 
	     || typecheck_expr(expression->last) != "int")
	    show_error("Arithmetical operators can only accept int arguments", expression);
	  return "int";
	}
	if(op == "==" || op == "!=" || op == "<=" || op == ">=" || op == "<" || op == ">"){
	  string leftType = typecheck_expr(expression->first);
	  string rightType = typecheck_expr(expression->last);
	  if((op == "<=" || op == ">=" || op == "<" || op == ">") && \
	     (!isTypePrimative(typecheck_expr(expression->first)) || !isTypePrimative(typecheck_expr(expression->last)))){
	    show_error("Operator "+op+" only compares primitive values", expression);
	    if(leftType != rightType)
	      show_error("2Operator "+op+" RHS "+rightType+" found, expected "+leftType, expression->last);
	  }
	  if(op == "==" || op == "!="){
	    if((isPrimativeRep(expression->first) || isPrimativeRep(expression->last))
	       && leftType != rightType && leftType != "null" && rightType !="null"){
	      show_error("3Operator "+op+" RHS "+rightType
			 +" found, expected "+leftType, expression->last);
	    }
	    else if(leftType != rightType 
		    && leftType != "null" && rightType != "null"){
	      show_error("4Operator "+op+" RHS "+rightType
			 +" found, expected "+leftType, expression->last);		
	    }
	  }
	  return "bool"; //comparison operators
	}
	show_error("Unknown binary operator "+op, expression);
	return "UnknownBinopType";
	break;
      }
    case TOK_CONSTANT:
      {
	string t = PRIMATIVE_MAP[expression->first->symbol];
	if(expression->first->symbol == TOK_NULL){ return "null"; }
	if(t == ""){
	  if(expression->first->symbol == TOK_STRINGCON) return "string";
	  show_error("Unknown constant", expression->first);
	}
	return t; 
	break;
      }
    case TOK_VARIABLE:
      {      
	string varname = *(expression->first->lexinfo);
	string t = expression->scope->lookup(varname);
	if(t == ""){
	  if(expression->first->symbol == TOK_NULL) return "null";
	  else  show_error("Unknown variable "+varname, expression);
	}
	return t;
	break;
      }
    case TOK_IDENT:
      {
      	string varname = *(expression->lexinfo);
	string t = expression->scope->lookup(varname);
	if(t == ""){
	  show_error("Unknown tok_ident", expression);
	}
	return t;
	break;
      }
    case '.':
      {
	string name = expression->scope->lookup(*(expression->first->first->lexinfo)) + "." + *(expression->last->lexinfo);
	string t = expression->scope->lookup(name);
	return t;
	break;
      }
    default:
      breakpoint();
      printf("\t No case in typecheck_expr for node type: %c\n", (char)expression->symbol);
      return "";
    }
    show_error("Error: Reached end of switch in typechecker", expression);
  }
  show_error("Error: Reached end of control in typechecker", expression);
  return "";
}


void typecheck_if(astree node){
  assert_expr_type("if statement", "bool", node->first);
  if(node->last->symbol == 291)
    typecheck_block(node->last);
  else 
    typecheck_stmt(node->last);
}

void typecheck_ifelse(astree node){
  assert_expr_type("if-else statement", "bool", node->first);
  astree temp = node->first->next;
  while(temp != NULL){
    if(temp->symbol == TOK_IF) typecheck_if(temp);
    else if(temp->symbol == TOK_IFELSE) typecheck_ifelse(temp);
    else { typecheck_stmt(temp); }
    temp = temp->next;
  }
}	




void typecheck_stmt(astree node){
  if(node->symbol == TOK_BLOCK){ typecheck_block(node); return; }
  switch (node->symbol) {
  case TOK_STRUCT: break;
  case TOK_DECLID: break;
  case ';': break; 
  case TOK_CALL:
    {
      //We don't care about the return type for a statement-level function call
      typecheck_expr(node);
      break;
    }
  case TOK_VARDECL:
    {
      string leftType = "";
      string varname = "";
      if(node->first->symbol == TOK_ARRAY){
	leftType = *(node->first->next->first->lexinfo)+"[]";
	varname = *(node->first->next->next->lexinfo);	  
      }
      else if(node->first->symbol == TOK_BASETYPE){
	leftType = *(node->first->first->lexinfo);
	varname = *(node->first->next->lexinfo);	  
      }
      else { //is a TOK_TYPEID
	leftType = *(node->first->lexinfo);
	varname = *(node->first->next->lexinfo);
      }
      assert_expr_type("variable declaration", leftType, node->last);
    }
    break;
  case TOK_WHILE:
    assert_expr_type("while statement", "bool", node->first);
    typecheck_stmt(node->last);
    break;
  case TOK_IF: typecheck_if(node); break;
  case TOK_IFELSE: typecheck_ifelse(node); break;
  case TOK_BINOP:
    {
      string op = *(node->first->next->lexinfo);
      string leftType = typecheck_expr(node->first);
      string rightType = typecheck_expr(node->last);
      
      if(op != "=")  {
	show_error("Assignment (=) is the only binary operator that forms a statement", node);
      }
      if (op == "==") {
	printf("== found\n");
      }
      else {
	if(node->first->symbol != TOK_VARIABLE
	   && node->first->symbol != TOK_INDEX
	   && node->first->symbol != '.')
	  show_error("You can only assign values to variables", node->first);
	else {
	  string varname = *(node->first->first->lexinfo);
	  string leftType = "";
	  if(node->first->symbol == '.'){
	    varname = node->scope->lookup(*(node->first->first->first->lexinfo));
	    varname +=
	      "." + *(node->first->last->lexinfo);
	    leftType = node->scope->lookup(varname);	    
	  }
	  else if(node->first->symbol == TOK_INDEX){
	    varname = *(node->first->first->first->lexinfo);
	    string t = node->scope->lookup(varname);

	    if(leftType == "string"){ leftType = "char"; }
	    else leftType = t.substr(0, t.find("["));
	      
	    if(typecheck_expr(node->first->last->first) != "int"){
	      show_error("You can only index into arrays and strings with integers", node->first->last->first);
	    }
	  }
	  else {
	    leftType = node->scope->lookup(varname); 
	  }
	  assert_expr_type("binop "+op, leftType, node->last);
	}
      }
      break;
    }
  case TOK_RETURNVOID:
    {
      string funType = node->scope->parentFunction(NULL);
      string retType = funType.substr(0, funType.find("("));
      if(retType != "void"){
	show_error("Got a return type void, expected "
		   +funType.substr(0, funType.find("(")), node);
      }
      break;
    }
  case TOK_RETURN:
    {
      string funType = node->scope->parentFunction(NULL);
      string retType = funType.substr(0, funType.find("("));
      string realRetType = typecheck_expr(node->first);
      if(retType != realRetType)
	show_error("Attempted to return type "+realRetType
		   +", expected "+retType
		   , node);
      break;
    }
  case TOK_FUNCTION: 
    {
      typecheck_block(node->last);
      break;
    }
  case TOK_PROTOTYPE:
    {
      break;
    }
  default:
    breakpoint();
    printf("MEow");
    show_error("No case in typecheck_stmt for node type:", node);
    printf("\tNode Symbol: %d\n", node->symbol);
    break;
  }

}

void typecheck_block(astree tree) {  
  astree node = tree->first;
  while (node != NULL) {
    typecheck_stmt(node);
    node = node->next;
  }
}
