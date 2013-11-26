#include "typechecker.h"
#include "yyparse.h"
#include "auxlib.h"
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

bool isPrimative(astree t){
  bool z = (PRIMATIVE_MAP.find(extractPrimSymbol(t)) != PRIMATIVE_MAP.end());
  return z;
}

bool isPrimativeRep(astree t){
  if(t->symbol == TOK_VARIABLE){
    string varname = *(t->first->lexinfo);
    string ty = t->scope->lookup(varname);
    return (ty == "char" || ty == "bool" || ty == "int");
  }
  else return isPrimative(t);
}
void assert_expr_type(string type, astree expression);
string expr_type(astree expression){
  if (expression->scope == NULL)
    show_error("Does not have scope.", expression);
  if(isPrimative(expression))
    return PRIMATIVE_MAP[extractPrimSymbol(expression)];
  else {
    switch (expression->symbol) {
    case TOK_POS:
      assert_expr_type("int", expression->first);
      return "int";
      break;
    case TOK_NEG:
      assert_expr_type("int", expression->first);
      return "int";
      break;
    case '!': 
      assert_expr_type("bool", expression->first);
      return "bool"; break;
    case TOK_ORD: 
      assert_expr_type("char", expression->first);
      return "int"; break;
    case TOK_CHR: 
      assert_expr_type("int", expression->first);
      return "char"; break;
	break;
    case TOK_NEW:
      return *(expression->first->lexinfo);
      break;
    case TOK_NEWARRAY:
      return *(expression->first->first->lexinfo)+"[]";
      break;
    case TOK_CALL:
      return expression->scope->lookup(*(expression->first->lexinfo));

    case TOK_BINOP:
      {
	string leftType = expr_type(expression->first);
	string rightType = expr_type(expression->last);
	if(leftType != rightType)
	  show_error("Expression of type "+rightType+" found, expected "+leftType, expression->last);
	string op = *(expression->first->next->lexinfo);
	if(op == "==" || op == "!=" || op == "<=" || op == ">=" || op == "<" || op == ">")
	  return "bool";
	return leftType;
	break;
      }
    case TOK_CONSTANT:
      {
	string s = PRIMATIVE_MAP[extractPrimSymbol(expression)];
	if(s == ""){
	  if(expression->first->symbol == TOK_NULL) return "null";
	  else {
	    show_error("Unknown constant", expression);
	  }
	}
	return s;
	break;
      }
    case TOK_VARIABLE:
      {
	string t = expression->scope->lookup(*(expression->first->lexinfo));
	return t;
	break;
      }
    default:
      printf("\t No case in expr_type for node type: %d\n", expression->symbol);
      return "";
    }
  }
}

void assert_expr_type(string type, astree expression) {
  if (expression->scope == NULL) {
    show_error("Does not have scope.", expression);
  }
  
  if(isPrimative(expression)){
    string t = PRIMATIVE_MAP[extractPrimSymbol(expression)];
    if (type != t)
      show_error("Primative is of type: " + t + ", expected "+type, expression);
  } 
  else {
    switch (expression->symbol) {
    case TOK_POS:
      if(type != "int") show_error("Can only ?posify? integers", expression);
      assert_expr_type("int", expression->first);
      break;
    case TOK_NEG:
      if(type != "int") show_error("Can only negate integers", expression);
      assert_expr_type("int", expression->first);
      break;
    case '!': 
      if(type != "bool"){ show_error("! operator always yields a bool", expression); }
      assert_expr_type("bool", expression->first);
      break;
    case TOK_ORD: 
      if(type != "int"){ show_error("Ord converts a char to an int.", expression); }
      assert_expr_type("char", expression->first);
      break;
    case TOK_CHR: 
      if(type != "char"){ show_error("Ord converts an int to a char.", expression); }
      assert_expr_type("int", expression->first);
    case TOK_NEW:
      
      if(type != *(expression->first->lexinfo))
	show_error("Expected type "+type+", got a new "
		   + *(expression->first->lexinfo), expression);
      break;
    case TOK_CALL:
      {
	
	string fn = *(expression->first->lexinfo);
	string t = expression->scope->lookup(*(expression->first->lexinfo));

	if (type != t.substr(0, type.length()))
	  show_error("Function returns type "+t.substr(0, t.find("("))
		     +", expected "+type, expression);

	string argType = "";
	bool first = true;
	astree plist = expression->first->next;
	while(plist != NULL){
	  if(first != true){ argType += ", "; }
	  first = false; 
	  argType += expr_type(plist);
	  plist = plist->next; 
	}
	
	string foundType = t.substr(0, t.find("(")) + "(" + argType + ")";
	if(t != foundType)
	  show_error("Wrong argument types given to function "+fn
		     +"."+"\n\tGiven "+foundType.substr(foundType.find("("))
		     +"\n\tExpected "+t.substr(t.find("(")), expression);
	break;
      }
    case TOK_BINOP:
      {
	string op = *(expression->first->next->lexinfo);

	if(op == "+" || op == "-" || op == "/" || op == "*" || op =="%") {
	  printf("Arithmetical operator\n");
	  if(expr_type(expression->first) != "int" 
	     || expr_type(expression->last) != "int")
	    show_error("Arithmetical operators can only accept int arguments", expression);
	}
	if(op == "==" || op == "!=" || op == "<=" || op == ">=" || op == "<" || op == ">"){
	  if(type != "bool"){ show_error("Operator "+op+" returns a bool, expected "+type, expression); }
	  else {
	    if((op == "<=" || op == ">=" || op == "<" || op == ">") && \
	       (!isPrimativeRep(expression->first) || !isPrimativeRep(expression->last))){
	      show_error("Operator "+op+" only compares primitive values", expression);
	      string leftType = expr_type(expression->first);
	      string rightType = expr_type(expression->last);
	      if(leftType != rightType)
		show_error("Operator "+op+" RHS "+rightType+" found, expected "+leftType, expression->last);
	    }

	    if(op == "==" || op == "!="){
	      string leftType = expr_type(expression->first);
	      string rightType = expr_type(expression->last);
	      if((isPrimativeRep(expression->first) || isPrimativeRep(expression->last))
		 && leftType != rightType && leftType != "null" && rightType !="null"){
		  show_error("Operator "+op+" RHS "+rightType
			     +" found, expected "+leftType, expression->last);
	      }
	      else if(leftType != rightType 
		      && leftType != "null" && rightType != "null"){
		show_error("Operator "+op+" RHS "+rightType
			   +" found, expected "+leftType, expression->last);		
	      }
	      
	    }
	  }
	}
	break;
      }
    case TOK_CONSTANT:
      {
	string t = PRIMATIVE_MAP[expression->first->symbol];
	if (type != t) show_error("Constant is of type: " + t + ", expected "+type, expression);
	break;
      }
    case TOK_VARIABLE:
      {      
	string varname = *(expression->first->lexinfo);
	string t = expression->scope->lookup(varname);
	if(t != type)
	  show_error("Variable "+varname+" is of type "+t+", expected "+type, expression);
	break;
      }
    }
  }
}



void typecheck(astree tree) {  
  astree node = tree->first;
  while (node != NULL) {
    switch (node->symbol) {
    case TOK_STRUCT: break;
    case TOK_DECLID: break;
    case ';': break; 
    case TOK_CALL:
      {
	//We just need to type check the arguments for a 
	// statement-level function call. 
	string ret = node->scope->lookup(*(node->first->lexinfo));
	assert_expr_type(ret, node);
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
	
	assert_expr_type(leftType, node->last);
      }
      break;
    case TOK_WHILE:
      assert_expr_type("bool", node->first);
      typecheck(node->last);
      break;
    case TOK_IF:
      assert_expr_type("bool", node->first);
      typecheck(node->last);
      break;
    case TOK_IFELSE:
      {
	assert_expr_type("bool", node->first);
	astree temp = node->first->next;
	while(temp != NULL){
	  if(temp->symbol == TOK_IF){
	    assert_expr_type("bool", temp->first);
	    typecheck(temp->last);
	  }
	  else typecheck(temp);
	  temp = temp->next;
	}
	break;
      }
    case TOK_BINOP:
      {
	string op = *(node->first->next->lexinfo);
	if(op != "=") show_error("Assignment (=) is the only binary operator that forms a statement, you gave me a silly ("+op+") :S", node);
	else {
	  if(node->first->symbol != TOK_VARIABLE
	     && node->first->symbol != TOK_INDEX
	     && node->first->symbol != '.')
	    show_error("You can only assign values to variables", node->first);
	  else {
	    
	    string varname = *(node->first->first->lexinfo);
	    string leftType = "";
	    if(node->first->symbol == '.'){
	      varname = node->scope->lookup(*(node->first->first->first->lexinfo))
		+ "." + *(node->first->last->lexinfo);
	      leftType = node->scope->lookup(varname);	    
	    }
	    else if(node->first->symbol == TOK_INDEX){
	      varname = *(node->first->first->first->lexinfo);
	      string t = node->scope->lookup(varname);
	      leftType = t.substr(0, t.find("["));
	      
	      if(leftType == "string"){ leftType = "char"; }
	      
	      if(expr_type(node->first->last->first) != "int"){
		show_error("You can only index into arrays and strings with integers", node->first->last->first);
	      }
	    }
	    else {
	      leftType = node->scope->lookup(varname); 
	    }

	    assert_expr_type(leftType, node->last);
	    /*string rightType = expr_type(node->last);
	    if(leftType != rightType)
	    show_error("Attempted to assign "+rightType+" to "+varname+", expected "+leftType, node->first);*/
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
	string realRetType = expr_type(node->first);
	if(retType != realRetType)
	  show_error("Attempted to return type "+realRetType
		     +", expected "+retType
		     , node);
	break;
      }
    case TOK_FUNCTION: 
      {
	typecheck(node->last);
	break;
      }
    case TOK_PROTOTYPE:
      {
	break;
      }
    default:
      printf("\t No case in typecheck for node type: %d\n", node->symbol);
      break;
    }

  node = node->next;
  }
}

