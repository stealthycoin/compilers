//This assignment completed with pair programming
// Name: John Carlyle Username: jcarlyle@ucsc.edu
// Name: Morgan McDermott Username: moamcder@ucsc.edu

%{

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "lyutils.h"
#include "astree.h"

#define YYMALLOC yycalloc
static void *yycalloc (size_t size);
%}

%debug
%defines
%error-verbose
%token-table
%verbose
%start start

%token TOK_VOID TOK_BOOL TOK_CHAR TOK_INT TOK_STRING TOK_ROOT
%token TOK_IF TOK_ELSE TOK_WHILE TOK_RETURN TOK_STRUCT
%token TOK_FALSE TOK_TRUE TOK_NULL TOK_NEW TOK_ARRAY 
%token TOK_EQ TOK_NE TOK_LT TOK_LE TOK_GT TOK_GE
%token TOK_IDENT TOK_INTCON TOK_CHARCON TOK_STRINGCON TOK_VARIABLE
%token TOK_ORD TOK_CHR TOK_DECLID TOK_PROTOTYPE TOK_TYPE TOK_BASETYPE

%token TOK_BLOCK TOK_BINOP TOK_UNOP TOK_CALL TOK_IFELSE TOK_INITDECL TOK_VARDECL
%token TOK_CONSTANT TOK_POS TOK_NEG TOK_TYPEID TOK_FIELD  TOK_RETURNVOID TOK_NEWARRAY 
%token TOK_NEWSTRING TOK_INDEX TOK_FUNCTION TOK_PARAMLIST 

%right TOK_ELSE
%right TOK_IF 
%right '='
%left TOK_EQ TOK_NE TOK_LT TOK_LE TOK_GT TOK_GE
%left '+' '-'
%left '*' '/' '%'
%right TOK_POS TOK_NEG '!' TOK_ORD TOK_CHR
%left TOK_CALL '[' '.' 

%nonassoc TOK_NEW
%nonassoc TOK_PAREN



%%
start       : program               { yyparse_astree = $1; }
            ;
program     : program structdef     { $$ = adopt1 ($1, $2); }
            | program function      { $$ = adopt1 ($1, $2); }
            | program statement     { $$ = adopt1 ($1, $2); }
            | program error '}'     { $$ = $1; }
            | program error ';'     { $$ = $1; }
            |                       { $$ = new_parseroot(); }
            ;

structdef   : TOK_STRUCT  fieldecls '}'    {$$ = adopt1 ($1, $2);
                                            freeast($3);}
            | TOK_STRUCT TOK_IDENT '{' '}' {changeSYM($2,TOK_TYPEID);
                                             $$=adopt1($1,$2);
                                             freeast($3);
                                             freeast($4); } 
fieldecls   : fieldecls fieldecl';'        {$$ = adopt1 ($1,$2); 
                                            freeast($3);}
            | TOK_IDENT '{' fieldecl';'    {changeSYM ($1, TOK_TYPEID);
                                            $$=adopt1($1,$3);
                                            freeast($2); 
                                            freeast($4); } 
            ;

fieldecl    : basetype TOK_IDENT           { $$=$2;
                                             changeSYM ($2,TOK_FIELD);
                                             $$ = adopt1 ($1, $2);}
            | basetype TOK_ARRAY TOK_IDENT { $$=$3;
                                             changeSYM ($3,TOK_FIELD);
                                             $$ = adopt2 ($2, $1, $3);}
            ;


basetype    : TOK_VOID                     {$$=adopt1(func_astree(TOK_BASETYPE, $1), $1);}
            | TOK_BOOL                     {$$=adopt1(func_astree(TOK_BASETYPE, $1), $1);}
            | TOK_CHAR                     {$$=adopt1(func_astree(TOK_BASETYPE, $1), $1);}
            | TOK_INT                      {$$=adopt1(func_astree(TOK_BASETYPE, $1), $1);}
            | TOK_STRING                   {$$=adopt1(func_astree(TOK_BASETYPE, $1), $1);}
            | TOK_IDENT                    {$$=$1;
                                            changeSYM ($1,TOK_TYPEID);}
            ;

function    : identdecl paramlist ')' block
                                      { $$ =  func_astree
                                        (TOK_FUNCTION, $1);
                                        $$ = adopt3 ($$, $1, $2, $4);
                                        changeIFproto($$,$4);
                                        freeast($3);}
            | identdecl '(' ')' block
                                      { $$ = func_astree
                                        (TOK_FUNCTION, $1);
                                        $$ = adopt2 ($$, $1, $4); 
                                        changeIFproto($$,$4);
                                        freeast($2);
                                        freeast($3);}
            ;
paramlist   : paramlist ',' identdecl { $$ = adopt1($1,$3); 
                                        freeast($2);}
            | '(' identdecl           { changeSYM($1,TOK_PARAMLIST);
                                        $$ = adopt1($1,$2);}
            ;



decl        : basetype TOK_IDENT ';'           { $$ = adopt2 (func_astree(TOK_INITDECL, $1), $1, $2);}
            | basetype TOK_ARRAY TOK_IDENT ';' { $$ = adopt3 (func_astree(TOK_INITDECL, $1), $1, $2, $3);}
            ;


identdecl   : basetype TOK_IDENT            { $$ = adopt2 (func_astree(TOK_DECLID, $1), $1, $2);}
            | basetype TOK_ARRAY TOK_IDENT  { $$ = adopt3 (func_astree(TOK_DECLID, $1), $1, $2, $3);}
            ;

block       : blockhead '}'          { freeast($2); $$=$1;}
            | '{' '}'                { changeSYM($1,TOK_BLOCK);
                                       $$=$1; }
            | ';'                    { $$=$1; }
blockhead   : blockhead statement    { $$=adopt1($1,$2);}
            | '{' statement          { $$ = adopt1sym
                                       ($1, $2, TOK_BLOCK);}
            ;

statement   : block                  { $$=$1;}
            | vardecl                { $$=$1;}
            | identdecl              { $$=$1; }
            | while                  { $$=$1;}
            | ifelse                 { $$=$1;}
            | return                 { $$=$1;}
            | expr ';'               { $$=$1; freeast($2);}
            ;

vardecl     : basetype TOK_IDENT '=' expr ';' { 
              $$ = adopt3(func_astree(TOK_VARDECL, $1), $1,$2,$4);
	      freeast($3);
                                       freeast($4);}
            | basetype TOK_ARRAY TOK_IDENT '=' expr ';' { 
	      $$ = adopt3(adopt1(func_astree(TOK_VARDECL, $1), $2), $1,$3,$5);
	      freeast($4);}
            ;

while       : TOK_WHILE '(' expr ')' statement
                                     {$$=adopt2($1,$3,$5);
                                      freeast($2);
                                      freeast($4);}
            ;

ifelse      : TOK_IF '(' expr ')' statement TOK_ELSE statement 
                                          { freeast($6);
                                            freeast($2);
                                            freeast($4);
                                            $$ = adopt2sym
                                              ($1, $3, $5, TOK_IFELSE); 
                                            $$ = adopt1 ($1, $7); }
            | TOK_IF '(' expr ')' statement %prec TOK_ELSE
                                          { $$ = adopt2 ($1, $3, $5);
                                            freeast($2);
                                            freeast($4); }
            ;

return      : TOK_RETURN ';'         { $$ = $1;
                                       changeSYM ($1,TOK_RETURNVOID);
                                       freeast($2);}
            | TOK_RETURN expr ';'    { $$=adopt1($1,$2);
                                       freeast($3);}
            ;

expr        : binop
            | unop


            | '(' expr ')'           { freeast($1);
                                       freeast($3);
                                       $$ = $2;}
            | allocator              { $$ = $1; }
            | call                   { $$ = $1; }
            | variable               { $$ = $1; }
            | constant               { $$ = $1; }
            ;

binop       : expr '=' expr          { $$ = adopt3 (func_astree(TOK_BINOP, $1), $1, $2, $3); }
            | expr '+' expr          { $$ = adopt3 (func_astree(TOK_BINOP, $1), $1, $2, $3); }
            | expr '-' expr          {  $$ = adopt3 (func_astree(TOK_BINOP, $1), $1, $2, $3); }
            | expr '*' expr          {  $$ = adopt3 (func_astree(TOK_BINOP, $1), $1, $2, $3); }
            | expr '/' expr          {  $$ = adopt3 (func_astree(TOK_BINOP, $1), $1, $2, $3); }
            | expr '%' expr          {  $$ = adopt3 (func_astree(TOK_BINOP, $1), $1, $2, $3); }
            | expr TOK_GE expr       {  $$ = adopt3 (func_astree(TOK_BINOP, $1), $1, $2, $3); }
            | expr TOK_GT expr       {  $$ = adopt3 (func_astree(TOK_BINOP, $1), $1, $2, $3); }
            | expr TOK_LE expr       { $$ = adopt3 (func_astree(TOK_BINOP, $1), $1, $2, $3);  }
            | expr TOK_LT expr       {  $$ = adopt3 (func_astree(TOK_BINOP, $1), $1, $2, $3); }
            | expr TOK_NE expr       {  $$ = adopt3 (func_astree(TOK_BINOP, $1), $1, $2, $3); }
            | expr TOK_EQ expr       {  $$ = adopt3 (func_astree(TOK_BINOP, $1), $1, $2, $3); }

unop        : '+' expr %prec TOK_POS { $$ = adopt1sym ($1, $2,
                                       TOK_POS); }
            | '-' expr %prec TOK_NEG { $$ = adopt1sym ($1,$2,TOK_NEG);}
            | TOK_ORD expr           { $$ = adopt1($1,$2);}
            | TOK_CHR expr           { $$ = adopt1($1,$2);}
            | '!' expr               { $$ = adopt1 ($1, $2); } 

allocator   : TOK_NEW TOK_IDENT '(' ')'       {changeSYM($2,
                                                         TOK_TYPEID);
                                               $$=adopt1($1,$2);
                                               freeast($3);
                                               freeast($4);}
            | TOK_NEW TOK_STRING '(' expr ')' {$$ = adopt1sym($1,$4,
                                                        TOK_NEWSTRING);
                                               freeast($1);
                                               freeast($3);
                                               freeast($4);}
            | TOK_NEW basetype '[' expr ']'   { $$ = adopt2sym($1, $2, 
                                                     $4, TOK_NEWARRAY); 
                                                freeast($3);
                                                freeast($5);}
            ;

call        : callhead ')'           { freeast ($2);}
            | TOK_IDENT '(' ')'      { $$=adopt1sym($2, $1, TOK_CALL);}
callhead    : callhead ',' expr      { $$=adopt1($1,$3);
                                       freeast($2); }
            | TOK_IDENT '(' expr     {$$=adopt2sym($2,$1,$3,TOK_CALL);}
            ;

variable    : expr '[' expr ']'      { freeast($4);

                                       $$ = adopt2sym
                                        ($2, $1, $3, TOK_INDEX);  }
            | expr '.' TOK_IDENT     { $$ = adopt2 ($2, $1, $3);
                                       changeSYM ($3, TOK_FIELD); }
            | TOK_IDENT              { $$ = adopt1(func_astree(TOK_VARIABLE, $1), $1); }
            ;

constant    : TOK_CHARCON            { $$ = adopt1(func_astree(TOK_CONSTANT, $1), $1); }
            | TOK_INTCON             { $$ =  adopt1(func_astree(TOK_CONSTANT, $1), $1);; }
            | TOK_STRINGCON          { $$ =  adopt1(func_astree(TOK_CONSTANT, $1), $1);; }
            | TOK_FALSE              { $$ =  adopt1(func_astree(TOK_CONSTANT, $1), $1);; }
            | TOK_TRUE               { $$ =  adopt1(func_astree(TOK_CONSTANT, $1), $1);; }
            | TOK_NULL               { $$ =  adopt1(func_astree(TOK_CONSTANT, $1), $1);; }
            ;
%%

const char *get_yytname (int symbol) {
   return yytname [YYTRANSLATE (symbol)];
}

static void *yycalloc (size_t size) {
   void *result = calloc (1, size);
   assert (result != NULL);
   return result;
}
