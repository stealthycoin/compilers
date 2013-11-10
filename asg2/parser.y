%{
  // Dummy parser for scanner project.

#include "lyutils.h"
#include "astree.h"

  %}

%debug
%defines
%error-verbose
%token-table
%verbose

 /*Define token values for non-terms*/
%token NTERM_CONSTANT NTERM_VAR NTERM_E NTERM_CALL NTERM_ALLOCATOR 
%token NTERM_UNOP NTERM_BINOP NTERM_EXPR NTERM_RET
%token NTERM_IFELSE NTERM_WHILE NTERM_VARDECL 
%token NTERM_STATEMENT NTERM_D NTERM_BLOCK
%token NTERM_C NTERM_FUNCTION NTERM_BASETYPE NTERM_TYPE NTERM_DECL
%token NTERM_B NTERM_STRUCTDEF NTERM_A NTERM_PROGRAM 


%token TOK_VOID TOK_BOOL TOK_CHAR TOK_INT TOK_STRING
%token TOK_WHILE TOK_RETURN TOK_STRUCT
%token TOK_FALSE TOK_TRUE TOK_NULL
%token TOK_IDENT TOK_INTCON TOK_CHARCON TOK_STRINGCON

%token TOK_BLOCK TOK_IFELSE TOK_INITDECL
%token TOK_NEWARRAY TOK_TYPEID 
%token TOK_ROOT TOK_DIR
    
    
%right TOK_IF TOK_ELSE
%right '='    
%left  TOK_EQ TOK_NE '<' TOK_LE '>' TOK_GE
%left  '+' '-'
%left  '*' '/' '%'
%right TOK_POS TOK_NEG '!' TOK_ORD TOK_CHR
%left  TOK_CALL
%left  TOK_ARRAY TOK_FIELD
%nonassoc TOK_NEW
%nonassoc TOK_PAREN
    
%start program

%%

program     : A             {$$ = new_parseroot(); adopt1($$, $1); adopt_grandchildren($$,$1);}
|               {$$ = new_parseroot();}
;

A           : structdef A  

{$$ = new_astree(NTERM_A, $1->filenr,
		 $1->linenr, $1->offset, "NTERM_A");
  adopt2($$, $1, $2);
  adopt_grandchildren($$, $2);}
 
            | function A  

	    {$$ = new_astree(NTERM_A, $1->filenr,
                             $1->linenr, $1->offset, "NTERM_A");
	      adopt2($$, $1, $2);
	      adopt_grandchildren($$, $2);}
 
            | statement A  

	    {$$ = new_astree(NTERM_A, $1->filenr,
                             $1->linenr, $1->offset, "NTERM_A");
	      adopt2($$, $1, $2);
	      adopt_grandchildren($$, $1);
	      adopt_grandchildren($$, $2);}

            | structdef  

	    {$$ = new_astree(NTERM_A, $1->filenr,
                             $1->linenr, $1->offset, "NTERM_A");
	      adopt1($$, $1);}
 
            | function  

	    {$$ = new_astree(NTERM_A, $1->filenr,
                             $1->linenr, $1->offset, "NTERM_A");
	      adopt1($$, $1);}
 
            | statement   

	    {$$ = new_astree(NTERM_A, $1->filenr,
                             $1->linenr, $1->offset, "NTERM_A");
	      adopt1($$, $1);
	      adopt_grandchildren($$, $1);}
 
;
            
structdef   : TOK_STRUCT TOK_IDENT '{' B '}'  

{$$ = new_astree(NTERM_STRUCTDEF, $1->filenr,
		 $1->linenr, $1->offset, "structdef");
  adopt1($$, $2);
  adopt1($$, $4);
  adopt_grandchildren($$, $4);}
 
            | TOK_STRUCT TOK_IDENT '{' '}'  

	    {$$ = new_astree(NTERM_STRUCTDEF, $1->filenr,
                             $1->linenr, $1->offset, "structdef");
	      adopt2($$, $1, $2);}
 
;
            
B           : decl ';' B  

{$$ = new_astree(NTERM_B, $1->filenr,
		 $1->linenr, $1->offset, "B_NTERM");
  adopt2($$, $1, $3);
  adopt_grandchildren($$, $3);}
 
            | decl ';'  

	    {$$ = new_astree(NTERM_B, $1->filenr,
                             $1->linenr, $1->offset, "B_NTERM");
	      adopt1($$, $1);}

;
            
decl        : type TOK_IDENT  

{$$ = new_astree(NTERM_DECL, $1->filenr,
		 $1->linenr, $1->offset, "decl");
  adopt2($$, $1, $2);}
  
;
            
type        : basetype  

{$$ = new_astree(NTERM_TYPE, $1->filenr,
		 $1->linenr, $1->offset, "type");
  adopt1($$, $1);}
 
            | basetype TOK_NEWARRAY  

	    {$$ = new_astree(NTERM_TYPE, $1->filenr,
                             $1->linenr, $1->offset, "type");
	      adopt2($$, $1, $2);}
  
; 
            
basetype    : TOK_VOID  

{$$ = new_astree(NTERM_BASETYPE, $1->filenr,
		 $1->linenr, $1->offset, "basetype");
  adopt1($$, $1);}
   
            | TOK_BOOL  

	    {$$ = new_astree(NTERM_BASETYPE, $1->filenr,
                             $1->linenr, $1->offset, "basetype");
	      adopt1($$, $1);}
 
            | TOK_CHAR   

	    {$$ = new_astree(NTERM_BASETYPE, $1->filenr,
                             $1->linenr, $1->offset, "basetype");
	      adopt1($$, $1);}

            | TOK_INT   

	    {$$ = new_astree(NTERM_BASETYPE, $1->filenr,
                             $1->linenr, $1->offset, "basetype");
	      adopt1($$, $1);}

            | TOK_STRING   

	    {$$ = new_astree(NTERM_BASETYPE, $1->filenr,
                             $1->linenr, $1->offset, "basetype");
	      adopt1($$, $1);}

            | TOK_IDENT   

	    {$$ = new_astree(NTERM_BASETYPE, $1->filenr,
                             $1->linenr, $1->offset, "basetype");
	      adopt1($$, $1);}

;
            
function    : type TOK_IDENT '(' C ')' block  

{$$ = new_astree(NTERM_FUNCTION, $1->filenr,
		 $1->linenr, $1->offset, "function");
  adopt2($$, $1, $2);
  adopt1($$, $4);
  adopt_grandchildren($$, $4);
  adopt1($$,$6);}
  
            | type TOK_IDENT '(' ')' block  

	    {$$ = new_astree(NTERM_FUNCTION, $1->filenr,
                             $1->linenr, $1->offset, "function");
	      adopt2($$, $1, $2);
	      adopt1($$, $5);}
 
;
            
C           : decl  

{$$ = new_astree(NTERM_C, $1->filenr,
		 $1->linenr, $1->offset, "C_NTERM");
  adopt1($$, $1);}
 
            | C ',' decl  

	    {$$ = new_astree(NTERM_C, $1->filenr,
                             $1->linenr, $1->offset, "C_NTERM");
	      adopt2($$, $1, $3);
	      adopt_grandchildren($$, $1);}
  
;
            
block       : '{' D '}'  

{$$ = new_astree(NTERM_BLOCK, $1->filenr,
		 $1->linenr, $1->offset, "block");
  adopt1($$, $2);
  adopt_grandchildren($$, $2);}
 
            | '{' '}'  

	    {$$ = new_astree(NTERM_BLOCK, $1->filenr,
                             $1->linenr, $1->offset, "block");
	      adopt2($$,$1,$2);}
  
            | ';'  

	    {$$ = new_astree(NTERM_BLOCK, $1->filenr,
                             $1->linenr, $1->offset, "block");
	      adopt1($$, $1);}
  
;
            
D           : D statement  

{$$ = new_astree(NTERM_D, $1->filenr,
		 $1->linenr, $1->offset, "D_NONTERM");
  adopt2($$, $1, $2);
  adopt_grandchildren($$, $1);
  adopt_grandchildren($$, $2);}
  
            | statement  

	    {$$ = new_astree(NTERM_D, $1->filenr,
                             $1->linenr, $1->offset, "D_NONTERM");
	      adopt1($$, $1);
	      adopt_grandchildren($$, $1);}
   
;
            
statement   : block  

{$$ = new_astree(NTERM_STATEMENT, $1->filenr,
		 $1->linenr, $1->offset, "statment");
  adopt1($$, $1);}
  
            | vardecl  

	    {$$ = new_astree(NTERM_STATEMENT, $1->filenr,
                             $1->linenr, $1->offset, "statment");
	      adopt1($$, $1);}
 
            | while  

	    {$$ = new_astree(NTERM_STATEMENT, $1->filenr,
                             $1->linenr, $1->offset, "statment");
	      adopt1($$, $1);}
 
            | ifelse  

	    {$$ = new_astree(NTERM_STATEMENT, $1->filenr,
                             $1->linenr, $1->offset, "statment");
	      adopt1($$, $1);}
 
            | return  

	    {$$ = new_astree(NTERM_STATEMENT, $1->filenr,
                             $1->linenr, $1->offset, "statment");
	      adopt1($$, $1);}
 
            | expr ';'  

	    {$$ = new_astree(NTERM_STATEMENT, $1->filenr,
                             $1->linenr, $1->offset, "statment");
	      adopt1($$, $1);
	      adopt_grandchildren($$, $1);}

;
            
vardecl     : type TOK_IDENT '=' expr ';'  

{$$ = new_astree(NTERM_VARDECL, $1->filenr,
		 $1->linenr, $1->offset, "vardecl");
  adopt2($$, $1, $2);
  adopt1($$, $4);
  adopt_grandchildren($$,$4);}
  
;
            
while       : TOK_WHILE '(' expr ')' statement  

{$$ = new_astree(NTERM_WHILE, $1->filenr,
		 $1->linenr, $1->offset, "while");
  adopt1($$, $3);
  adopt1($$, $5);
  adopt_grandchildren($$, $3);
  adopt_grandchildren($$, $5);}
                                 
;
            
ifelse      : TOK_IF '(' expr ')' statement TOK_ELSE statement 

{$$ = new_astree(NTERM_IFELSE, $1->filenr,
		 $1->linenr, $1->offset, "ifelse");
  adopt1($$, $3);
  adopt_grandchildren($$, $3);
  adopt_grandchildren($$, $5);
  adopt_grandchildren($$, $7);}
 
            | TOK_IF '(' expr ')' statement  

	    {$$ = new_astree(NTERM_IFELSE, $1->filenr,
                             $1->linenr, $1->offset, "ifelse");
	      adopt1($$, $3);
	      adopt_grandchildren($$, $3);
	      adopt_grandchildren($$, $5);}
 
;
            
return      : TOK_RETURN expr ';' 

{$$ = new_astree(NTERM_RET, $1->filenr,
		 $1->linenr, $1->offset, "return");
  adopt1($$, $2);
  adopt_grandchildren($$, $2);}

            | TOK_RETURN ';' 

	    {$$ = new_astree(NTERM_RET, $1->filenr,
                             $1->linenr, $1->offset, "return");
	      adopt1($$,$2);}

;

expr        : binop 

{$$ = new_astree(NTERM_EXPR, $1->filenr,
		 $1->linenr, $1->offset, "expr");
  adopt1($$, $1);}
                        
            | unop %prec TOK_POS 
            
	    {$$ = new_astree(NTERM_EXPR, $1->filenr,
                             $1->linenr, $1->offset, "expr");
	      adopt1($$, $1);}
   
            | allocator %prec TOK_NEW 
            
	    {$$ = new_astree(NTERM_EXPR, $1->filenr,
                             $1->linenr, $1->offset, "expr");
	      adopt1($$, $1);}
   
            | call %prec TOK_CALL 
            
	    {$$ = new_astree(NTERM_EXPR, $1->filenr,
                             $1->linenr, $1->offset, "expr");
	      adopt1($$, $1);}
   
            | '(' expr ')' %prec TOK_PAREN 
            
	    {$$ = new_astree(NTERM_EXPR, $1->filenr,
                             $1->linenr, $1->offset, "expr");
	      adopt1($$, $2);
	      adopt_grandchildren($$, $2);}
   
            | variable %prec TOK_ARRAY 
            
	    {$$ = new_astree(NTERM_EXPR, $1->filenr,
                             $1->linenr, $1->offset, "expr");
	      adopt1($$, $1);}
   
            | constant  
            
	    {$$ = new_astree(NTERM_EXPR, $1->filenr,
                             $1->linenr, $1->offset, "expr");
	      adopt1($$, $1);}
   
;

binop       : expr '=' expr

{$$ = new_astree(NTERM_BINOP, $1->filenr,
		 $1->linenr, $1->offset, "binop");
  adopt1($$, $1);
  adopt_grandchildren($$, $1);
  adopt1($$, $2);
  adopt1($$, $3);
  adopt_grandchildren($$, $3);}
                        
            | expr TOK_EQ expr

	    {$$ = new_astree(NTERM_BINOP, $1->filenr,
                             $1->linenr, $1->offset, "binop");
	      adopt1($$, $1);
	      adopt_grandchildren($$, $1);
	      adopt1($$, $2);
	      adopt1($$, $3);
	      adopt_grandchildren($$, $3);}

            | expr TOK_NE expr

	    {$$ = new_astree(NTERM_BINOP, $1->filenr,
                             $1->linenr, $1->offset, "binop");
	      adopt1($$, $1);
	      adopt_grandchildren($$, $1);
	      adopt1($$, $2);
	      adopt1($$, $3);
	      adopt_grandchildren($$, $3);}

            | expr '<' expr

	    {$$ = new_astree(NTERM_BINOP, $1->filenr,
                             $1->linenr, $1->offset, "binop");
	      adopt1($$, $1);
	      adopt_grandchildren($$, $1);
	      adopt1($$, $2);
	      adopt1($$, $3);
	      adopt_grandchildren($$, $3);}

            | expr TOK_LE expr

	    {$$ = new_astree(NTERM_BINOP, $1->filenr,
                             $1->linenr, $1->offset, "binop");
	      adopt1($$, $1);
	      adopt_grandchildren($$, $1);
	      adopt1($$, $2);
	      adopt1($$, $3);
	      adopt_grandchildren($$, $3);}

            | expr '>' expr

	    {$$ = new_astree(NTERM_BINOP, $1->filenr,
                             $1->linenr, $1->offset, "binop");
	      adopt1($$, $1);
	      adopt_grandchildren($$, $1);
	      adopt1($$, $2);
	      adopt1($$, $3);
	      adopt_grandchildren($$, $3);}

            | expr TOK_GE expr

	    {$$ = new_astree(NTERM_BINOP, $1->filenr,
                             $1->linenr, $1->offset, "binop");
	      adopt1($$, $1);
	      adopt_grandchildren($$, $1);
	      adopt1($$, $2);
	      adopt1($$, $3);
	      adopt_grandchildren($$, $3);}

            | expr '+' expr

	    {$$ = new_astree(NTERM_BINOP, $1->filenr,
                             $1->linenr, $1->offset, "binop");
	      adopt1($$, $1);
	      adopt_grandchildren($$, $1);
	      adopt1($$, $2);
	      adopt1($$, $3);
	      adopt_grandchildren($$, $3);}

            | expr '-' expr

	    {$$ = new_astree(NTERM_BINOP, $1->filenr,
                             $1->linenr, $1->offset, "binop");
	      adopt1($$, $1);
	      adopt_grandchildren($$, $1);
	      adopt1($$, $2);
	      adopt1($$, $3);
	      adopt_grandchildren($$, $3);}

            | expr '*' expr

	    {$$ = new_astree(NTERM_BINOP, $1->filenr,
                             $1->linenr, $1->offset, "binop");
	      adopt1($$, $1);
	      adopt_grandchildren($$, $1);
	      adopt1($$, $2);
	      adopt1($$, $3);
	      adopt_grandchildren($$, $3);}

            | expr '/' expr

	    {$$ = new_astree(NTERM_BINOP, $1->filenr,
                             $1->linenr, $1->offset, "binop");
	      adopt1($$, $1);
	      adopt_grandchildren($$, $1);
	      adopt1($$, $2);
	      adopt1($$, $3);
	      adopt_grandchildren($$, $3);}

            | expr '%' expr

	    {$$ = new_astree(NTERM_BINOP, $1->filenr,
                             $1->linenr, $1->offset, "binop");
	      adopt1($$, $1);
	      adopt_grandchildren($$, $1);
	      adopt1($$, $2);
	      adopt1($$, $3);
	      adopt_grandchildren($$, $3);}

; 

unop        : '+' expr %prec TOK_POS

{$$ = new_astree(NTERM_UNOP, $1->filenr,
		 $1->linenr, $1->offset, "unop");
  adopt1($$, $1);
  adopt1($$, $2);
  adopt_grandchildren($$, $2);}

            | '-' expr %prec TOK_NEG

	    {$$ = new_astree(NTERM_UNOP, $1->filenr,
                             $1->linenr, $1->offset, "unop");
	      adopt1($$, $1);
	      adopt1($$, $2);
	      adopt_grandchildren($$, $2);}

            | '!' expr

	    {$$ = new_astree(NTERM_UNOP, $1->filenr,
                             $1->linenr, $1->offset, "unop");
	      adopt1($$, $1);
	      adopt1($$, $2);
	      adopt_grandchildren($$, $2);}

            | TOK_ORD expr

	    {$$ = new_astree(NTERM_UNOP, $1->filenr,
                             $1->linenr, $1->offset, "unop");
	      adopt1($$, $1);
	      adopt1($$, $2);
	      adopt_grandchildren($$, $2);}

            | TOK_CHR expr

	    {$$ = new_astree(NTERM_UNOP, $1->filenr,
                             $1->linenr, $1->offset, "unop");
	      adopt1($$, $1);
	      adopt1($$, $2);
	      adopt_grandchildren($$, $2);}
;
            

allocator   : TOK_NEW basetype '(' expr ')' 

{$$ = new_astree(NTERM_ALLOCATOR, $1->filenr,
		 $1->linenr, $1->offset, "allocator" );
  adopt2($$, $2, $4);
  adopt_grandchildren($$, $4);}
                    
            | TOK_NEW basetype '(' ')' 

	    {$$ = new_astree(NTERM_ALLOCATOR, $1->filenr,
                             $1->linenr, $1->offset, "allocator" );
	      adopt1($$, $2);}
                              
            | TOK_NEW basetype '[' expr ']'  

	    {$$ = new_astree(NTERM_ALLOCATOR, $1->filenr,
                             $1->linenr, $1->offset, "allocator" );
	      adopt2($$, $2, $4);
	      adopt_grandchildren($$, $4);}
;
            
call        : TOK_IDENT '(' E ')' 

{$$ = new_astree(NTERM_CALL, $1->filenr,
		 $1->linenr, $1->offset, "call" );
  adopt1($$,$1);
  /*for(unsigned int i=0; i < $3->children.size(); i++)
                                 {
                                     adopt1($$, $3->children.at(i));
                                     }*/
  adopt_grandchildren($$, $3);}
                        
            | TOK_IDENT '(' ')' 
            
	    {$$ = new_astree(NTERM_CALL, $1->filenr,
                             $1->linenr, $1->offset, "call" );
	      adopt1($$, $1);}
;
            
E           : expr
    
{$$ = new_astree(NTERM_E, $1->filenr,
		 $1->linenr, $1->offset, "E_NONTERM");
  adopt1($$,$1);
  adopt_grandchildren($$, $1);}
                            
            | expr ',' E 
            
	    {$$ = new_astree(NTERM_E, $1->filenr,
                             $1->linenr, $1->offset, "E_NONTERM");
	      adopt2($$,$1,$3);
	      adopt_grandchildren($$, $3);
	      adopt_grandchildren($$, $1);}
;

variable    : TOK_IDENT 
                        
{$$ = new_astree(NTERM_VAR, $1->filenr,
		 $1->linenr, $1->offset, "variable" );
  adopt1($$, $1);}
                                
            | expr '[' expr ']' %prec TOK_ARRAY
             
	    {$$ = new_astree(TOK_ARRAY, $1->filenr,
			     $1->linenr, $1->offset, "variable" );
	      adopt2($$, $1, $3);
	      adopt_grandchildren($$, $1);
	      adopt_grandchildren($$, $3);}
                                 
            | expr '.' TOK_IDENT %prec TOK_FIELD
            
	    {$$ = new_astree(TOK_FIELD, $1->filenr,
			     $1->linenr, $1->offset, "variable");
	      adopt2($$,$1,$3);
	      adopt_grandchildren($$, $1);}
;

constant    : TOK_INTCON 
                        
{$$ = new_astree(NTERM_CONSTANT, $1->filenr,
		 $1->linenr, $1->offset, "constant" ); adopt1($$, $1);}
                             
            | TOK_CHARCON 
            
	    {$$ = new_astree(NTERM_CONSTANT, $1->filenr,
                             $1->linenr, $1->offset, "constant" ); adopt1($$, $1);}
                             
            | TOK_STRINGCON 
                        
	    {$$ = new_astree(NTERM_CONSTANT, $1->filenr,
                             $1->linenr, $1->offset, "constant" ); adopt1($$, $1);}
                             
            | TOK_FALSE 
                        
	    {$$ = new_astree(NTERM_CONSTANT, $1->filenr,
                             $1->linenr, $1->offset, "constant" ); adopt1($$, $1);}
                             
            | TOK_TRUE 
                    
	    {$$ = new_astree(NTERM_CONSTANT, $1->filenr,
                             $1->linenr, $1->offset, "constant" ); adopt1($$, $1);}
                             
            | TOK_NULL 
	    {$$ = new_astree(NTERM_CONSTANT, $1->filenr,
                             $1->linenr, $1->offset, "constant" ); adopt1($$, $1);}
;


%%

const char *get_yytname (int symbol) {
  return yytname [YYTRANSLATE (symbol)];
}


bool is_defined_token (int symbol) {
  return YYTRANSLATE (symbol) > YYUNDEFTOK;
}

