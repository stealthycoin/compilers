#ifndef __TC_H__
#define __TC_H__

#include <map>
#include "astree.h"
#include "symtable.h"
#include "yyparse.h"

using namespace std;

static map<int, string> PRIMATIVE_MAP = {
{TOK_INTCON, "int"}, 
{TOK_CHARCON, "char"}, 
{TOK_INT, "int"},
{TOK_CHAR, "char"}, 
{TOK_BOOL, "bool"},
{TOK_FALSE, "bool"},
{TOK_TRUE, "bool"}};

void typecheck(astree tree);

void typecheck_expr(astree tree);

string expr_type(astree expression);

#endif
