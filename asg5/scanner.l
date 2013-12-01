%{
//This assignment completed with pair programming
// Name: John Carlyle Username: jcarlyle@ucsc.edu
// Name: Morgan McDermott Username: moamcder@ucsc.edu
#include <stdlib.h>
#include <stdbool.h>
#include "auxlib.h"
#include "lyutils.h"

#define YY_USER_ACTION  { scanner_useraction (); }
#define IGNORE(THING)   { }

%}

%option 8bit
%option backup
%option debug
%option ecs
%option nodefault
%option nounput
%option perf-report
%option verbose


LETTER            [A-Za-z_]
DIGIT             [0-9]
MANTISSA          ({DIGIT}+\.?{DIGIT}*|\.{DIGIT}+)
EXPONENT          ([Ee][+-]?{DIGIT}+)
NUMBER            ({MANTISSA}{EXPONENT}?)
NOTNUMBER         ({MANTISSA}[Ee][+-]?)
IDENT             ({LETTER}({LETTER}|{DIGIT})*)
TOK_STRINGCON     (\"([^\\"\n]|\\[\\'"0nt])*\")
TOK_CHARCON       (\'([^\\'\n]|\\[\\'"0nt])\')

INVLIDENT      ({DIGIT}({LETTER}|{DIGIT})+)
STR_NOT_CLOSE  (\"([^\\"\n]|\\[\\'"0nt])*)
STR_NOT_CLOSE2 (\"([^\\"\n]|\\[\\'"0nt])*\\)
CHR_NOT_CLOSE  (\'([^\\'\n]|\\[\\'"0nt]))
CHR_NOT_CLOSE2 (\'([\\'\n]|\\[\\'"0nt]))

%%

"#".*           { scanner_include(); }
[ \t]+          { IGNORE (white space) }
\n              { scanner_newline(); }

"void"            { return yylval_token(TOK_VOID);  }
"bool"            { return yylval_token(TOK_BOOL);  }
"char"            { return yylval_token(TOK_CHAR);  }
"int"             { return yylval_token(TOK_INT);   }
"string"          { return yylval_token(TOK_STRING);}
"if"              { return yylval_token(TOK_IF);    }
"else"            { return yylval_token(TOK_ELSE);  }
"while"           { return yylval_token(TOK_WHILE); }
"return"          { return yylval_token(TOK_RETURN);}
"struct"          { return yylval_token(TOK_STRUCT);}
"false"           { return yylval_token(TOK_FALSE); }
"true"            { return yylval_token(TOK_TRUE);  }
"null"            { return yylval_token(TOK_NULL);  }
"new"             { return yylval_token(TOK_NEW);   }
"chr"             { return yylval_token(TOK_CHR);   }
"ord"             { return yylval_token(TOK_ORD);   }

{IDENT}         { return yylval_token(TOK_IDENT);   }
{NUMBER}        { return yylval_token(TOK_INTCON);   }
{TOK_STRINGCON} { return yylval_token(TOK_STRINGCON);}
{TOK_CHARCON}   { return yylval_token(TOK_CHARCON);  }

"="             { return yylval_token('='); }
"+"             { return yylval_token('+'); }
"-"             { return yylval_token('-'); }
"*"             { return yylval_token('*'); }
"/"             { return yylval_token('/'); }
"^"             { return yylval_token('^'); }
"("             { return yylval_token('('); }
")"             { return yylval_token(')'); }
"["             { return yylval_token('['); }
"]"             { return yylval_token(']'); }
"{"             { return yylval_token('{'); }
"}"             { return yylval_token('}'); }
";"             { return yylval_token(';'); }
","             { return yylval_token(','); }
"!"             { return yylval_token('!'); }
"."             { return yylval_token('.'); }
"%"             { return yylval_token('%'); }
"<"             { return yylval_token(TOK_LT);    }
">"             { return yylval_token(TOK_GT);    }
"[]"            { return yylval_token(TOK_ARRAY); }
"=="            { return yylval_token(TOK_EQ);    }
"<="            { return yylval_token(TOK_LE);    }
">="            { return yylval_token(TOK_GE);    }
"!="            { return yylval_token(TOK_NE);    }

  

{INVLIDENT}             { scanner_badtoken(yytext);}    
{STR_NOT_CLOSE}         { scanner_badtoken (yytext);}
{STR_NOT_CLOSE2}        { scanner_badtoken (yytext);}
{CHR_NOT_CLOSE}         { scanner_badtoken (yytext);}
{CHR_NOT_CLOSE2}        { scanner_badtoken (yytext);}
{NOTNUMBER}             { scanner_badtoken (yytext);
                          return yylval_token (TOK_INTCON); }

.                       { scanner_badchar (*yytext); }


%%

// unset: %option noyywrap
int yywrap (void){
   yy_delete_buffer (YY_CURRENT_BUFFER);
   if (yy_flex_debug) eprintf ("yywrap() return %d\n", true);
   return true;
}


