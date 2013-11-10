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

%token TOK_VOID TOK_BOOL TOK_CHAR TOK_INT TOK_STRING
%token TOK_IF TOK_ELSE TOK_WHILE TOK_RETURN TOK_STRUCT
%token TOK_FALSE TOK_TRUE TOK_NULL TOK_NEW TOK_ARRAY
%token TOK_EQ TOK_NE TOK_LT TOK_LE TOK_GT TOK_GE
%token TOK_IDENT TOK_INTCON TOK_CHARCON TOK_STRINGCON
%token TOK_ORD TOK_CHR TOK_ROOT TOK_DECLID TOK_PROTOTYPE

%token TOK_BLOCK TOK_CALL TOK_IFELSE TOK_INITDECL TOK_VARDECL
%token TOK_POS TOK_NEG TOK_TYPEID TOK_FIELD TOK_RETUNVOID TOK_NEWARRAY
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
                                            free_ast($3);}
            | TOK_STRUCT TOK_IDENT '{' '}' {changeSYM($2,TOK_TYPEID);
                                             $$=adopt1($1,$2);
                                             free_ast($3);
                                             free_ast($4); } 
fieldecls   : fieldecls fieldecl';'        {$$ = adopt1 ($1,$2); 
                                            free_ast($3);}
            | TOK_IDENT '{' fieldecl';'    {changeSYM ($1, TOK_TYPEID);
                                            $$=adopt1($1,$3);
                                            free_ast($2); 
                                            free_ast($4); } 
            ;

fieldecl    : basetype TOK_IDENT           { $$=$2;
                                             changeSYM ($2,TOK_FIELD);
                                             $$ = adopt1 ($1, $2);}
            | basetype TOK_ARRAY TOK_IDENT { $$=$3;
                                             changeSYM ($3,TOK_FIELD);
                                             $$ = adopt2 ($2, $1, $3);}
            ;

basetype    : TOK_VOID                     {$$=$1;}
            | TOK_BOOL                     {$$=$1;}
            | TOK_CHAR                     {$$=$1;}
            | TOK_INT                      {$$=$1;}
            | TOK_STRING                   {$$=$1;}
            | TOK_IDENT                    {$$=$1;
                                            changeSYM ($1,TOK_TYPEID);}
            ;

function    : identdecl paramlist ')' block
                                      { $$ =  func_astree
                                        (TOK_FUNCTION, $1);
                                        $$ = adopt3 ($$, $1, $2, $4);
                                        changeIFproto($$,$4);
                                        free_ast($3);}
            | identdecl '(' ')' block
                                      { $$ = func_astree
                                        (TOK_FUNCTION, $1);
                                        $$ = adopt2 ($$, $1, $4); 
                                        changeIFproto($$,$4);
                                        free_ast($2);
                                        free_ast($3);}
            ;
paramlist   : paramlist ',' identdecl { $$ = adopt1($1,$3); 
                                        free_ast($2);}
            | '(' identdecl           { changeSYM($1,TOK_PARAMLIST);
                                        $$ = adopt1($1,$2);}
            ;

identdecl   : basetype TOK_ARRAY TOK_IDENT {changeSYM ($3,TOK_DECLID);
                                            $$ = adopt2 ($2, $1, $3);}
            | basetype TOK_IDENT           {changeSYM ($2,TOK_DECLID);
                                            $$ = adopt1 ($1, $2);}
            ;

block       : blockhead '}'          { free_ast($2); $$=$1;}
            | '{' '}'                { changeSYM($1,TOK_BLOCK);
                                       $$=$1; }
            | ';'                    { $$=$1; }
blockhead   : blockhead statement    { $$=adopt1($1,$2);}
            | '{' statement          { $$ = adopt1sym
                                       ($1, $2, TOK_BLOCK);}
            ;

statement   : block                  { $$=$1;}
            | vardecl                { $$=$1;}
            | while                  { $$=$1;}
            | ifelse                 { $$=$1;}
            | return                 { $$=$1;}
            | expr ';'               { $$=$1; free_ast($2);}
            ;

vardecl     : identdecl '=' expr ';' { $$=adopt2sym
                                         ($2,$1,$3, TOK_VARDECL);
                                       free_ast($4);}
            ;

while       : TOK_WHILE '(' expr ')' statement
                                     {$$=adopt2($1,$3,$5);
                                      free_ast($2);
                                      free_ast($4);}
            ;

ifelse      : TOK_IF '(' expr ')' statement TOK_ELSE statement 
                                          { free_ast($6);
                                            free_ast($2);
                                            free_ast($4);
                                            $$ = adopt2sym
                                              ($1, $3, $5, TOK_IFELSE); 
                                            $$ = adopt1 ($1, $7); }
            | TOK_IF '(' expr ')' statement %prec TOK_ELSE
                                          { $$ = adopt2 ($1, $3, $5);
                                            free_ast($2);
                                            free_ast($4); }
            ;

return      : TOK_RETURN ';'         { $$ = $1;
                                       changeSYM ($1,TOK_RETUNVOID);
                                       free_ast($2);}
            | TOK_RETURN expr ';'    { $$=adopt1($1,$2);
                                       free_ast($3);}
            ;

expr        : expr '=' expr          { $$ = adopt2 ($2, $1, $3); }
            | expr '+' expr          { $$ = adopt2 ($2, $1, $3); }
            | expr '-' expr          { $$ = adopt2 ($2, $1, $3); }
            | expr '*' expr          { $$ = adopt2 ($2, $1, $3); }
            | expr '/' expr          { $$ = adopt2 ($2, $1, $3); }
            | expr '%' expr          { $$ = adopt2 ($2, $1, $3); }
            | expr TOK_GE expr       { $$ = adopt2 ($2, $1, $3); }
            | expr TOK_GT expr       { $$ = adopt2 ($2, $1, $3); }
            | expr TOK_LE expr       { $$ = adopt2 ($2, $1, $3); }
            | expr TOK_LT expr       { $$ = adopt2 ($2, $1, $3); }
            | expr TOK_NE expr       { $$ = adopt2 ($2, $1, $3); }
            | expr TOK_EQ expr       { $$ = adopt2 ($2, $1, $3); }
            | '+' expr %prec TOK_POS { $$ = adopt1sym ($1, $2,
                                       TOK_POS); }
            | '-' expr %prec TOK_NEG { $$ = adopt1sym ($1,$2,TOK_NEG);}
            | TOK_ORD expr           { $$ = adopt1($1,$2);}
            | TOK_CHR expr           { $$ = adopt1($1,$2);}
            | '!' expr               { $$ = adopt1 ($1, $2); } 
            | '(' expr ')'           { free_ast($1);
                                       free_ast($3);
                                       $$ = $2;}
            | allocator              { $$ = $1; }
            | call                   { $$ = $1; }
            | variable               { $$ = $1; }
            | constant               { $$ = $1; }
            ;

allocator   : TOK_NEW TOK_IDENT '(' ')'       {changeSYM($2,
                                                         TOK_TYPEID);
                                               $$=adopt1($1,$2);
                                               free_ast($3);
                                               free_ast($4);}
            | TOK_NEW TOK_STRING '(' expr ')' {$$ = adopt1sym($1,$4,
                                                        TOK_NEWSTRING);
                                               free_ast($1);
                                               free_ast($3);
                                               free_ast($4);}
            | TOK_NEW basetype '[' expr ']'   { $$ = adopt2sym($1, $2, 
                                                     $4, TOK_NEWARRAY); 
                                                free_ast($3);
                                                free_ast($5);}
            ;

call        : callhead ')'           { free_ast ($2);}
            | TOK_IDENT '(' ')'      { $$=adopt1sym($2, $1, TOK_CALL);}
callhead    : callhead ',' expr      { $$=adopt1($1,$3);
                                       free_ast($2); }
            | TOK_IDENT '(' expr     {$$=adopt2sym($2,$1,$3,TOK_CALL);}
            ;

variable    : expr '[' expr ']'      { free_ast($4);
                                       $$ = adopt2sym
                                        ($2, $1, $3, TOK_INDEX);  }
            | expr '.' TOK_IDENT     { $$ = adopt2 ($2, $1, $3);
                                       changeSYM ($3, TOK_FIELD); }
            | TOK_IDENT              { $$=$1;}
            ;

constant    : TOK_CHARCON            { $$ = $1; }
            | TOK_INTCON             { $$ = $1; }
            | TOK_STRINGCON          { $$ = $1; }
            | TOK_FALSE              { $$ = $1; }
            | TOK_TRUE               { $$ = $1; }
            | TOK_NULL               { $$ = $1; }
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
