#include "typechecker.h"
#include "yyparse.h"
#include "auxlib.h"


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
    return (ty == "char" || ty == "string" || ty == "bool" || ty == "int");
  }
  else return isPrimative(t);
}

string expr_type(astree expression){
  if (expression->scope == NULL)
    show_error("Does not have scope.", expression);
  if(isPrimative(expression))
    return PRIMATIVE_MAP[extractPrimSymbol(expression)];
  else {
    switch (expression->symbol) {
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
      return PRIMATIVE_MAP[expression->first->symbol];
      break;
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
	if(op == "==" || op == "!=" || op == "<=" || op == ">=" || op == "<" || op == ">"){
	  if(type != "bool"){ show_error("Operator "+op+" returns a bool, expected "+type, expression); }
	  else {
	    if((op == "<=" || op == ">=" || op == "<" || op == ">") && \
	       (!isPrimativeRep(expression->first) || !isPrimativeRep(expression->last))){
	      show_error("Operator "+op+" only compares primitive values", expression);
	    }
	    string leftType = expr_type(expression->first);
	    string rightType = expr_type(expression->last);
	    if(leftType != rightType)
	      show_error("Operator "+op+" RHS "+rightType+" found, expected "+leftType, expression->last);
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
	string leftType = *(node->first->first->lexinfo); 
	string varname = *(node->first->next->lexinfo); 
	string rightType = expr_type(node->last);
	if(leftType != rightType)
	  show_error("Variable "+varname+" initialized with type "+rightType+", expected "+leftType, node->first);
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
	  if(node->first->symbol != TOK_VARIABLE)
	    show_error("You can only assign values to variables", node->first);
	  else {
 	    string varname = *(node->first->first->lexinfo);
	    string leftType = node->scope->lookup(varname);
	    string rightType = expr_type(node->last);
	    if(leftType != rightType)
	      show_error("Attempted to assign "+rightType+" to "+varname+", expected "+leftType, node->first);
	  }
	}
      break;
      }
    case TOK_RETURN:
      {
	string funType = node->scope->parentFunction(NULL);
	string retType = funType.substr(0, funType.find("("));
	string realRetType = expr_type(node->first);
	if(retType != realRetType)
	  show_error("Attempted to return type "+realRetType+", expected "+retType
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

