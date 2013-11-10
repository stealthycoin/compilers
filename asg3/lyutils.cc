
#include <vector>
#include <string>
using namespace std;

#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stringset.h"
#include "lyutils.h"
#include "auxlib.h"

FILE *ly_tokFile;
astree yyparse_astree = NULL;
int scan_linenr = 1;
int scan_offset = 0;
bool scan_echo = false;
vector<string> included_filenames;

const string* scanner_filename (int filenr) {
   return &included_filenames.at(filenr);
}

void scanner_newfilename (const char* filename) {
   included_filenames.push_back (filename);
}

void scanner_newline (void) {
   ++scan_linenr;
   scan_offset = 0;
}

void scanner_setecho (bool echoflag) {
   scan_echo = echoflag;
}


void scanner_useraction (void) {
   if (scan_echo) {
      if (scan_offset == 0) printf (";%5d: ", scan_linenr);
      printf ("%s", yytext);
   }
   scan_offset += yyleng;
}

void yyerror (const char* message) {
   assert (not included_filenames.empty());
   errprintf ("%:%s: %d: %s\n",
              included_filenames.back().c_str(),
              scan_linenr, message);
}

void scanner_badchar (unsigned char bad) {
   char char_rep[16];
   sprintf (char_rep, isgraph (bad) ? "%c" : "\\%03o", bad);
   errprintf ("%:%s: %d: invalid source character (%s)\n",
              included_filenames.back().c_str(),
              scan_linenr, char_rep);
}

void scanner_badtoken (char* lexeme) {
   errprintf ("%:%s: %d: invalid token (%s)\n",
              included_filenames.back().c_str(),
              scan_linenr, lexeme);
}

int yylval_token (int symbol) {
   int offset = scan_offset - yyleng;

   //insert to the hashtable
   const std::string *tmp =intern_stringset(yytext);
   yylval = new_astree (symbol, included_filenames.size() - 1,
                        //filename_stack.last_filenr,
                        scan_linenr, offset, tmp->c_str());
   std::string formattedYytext;
   formattedYytext = "(" + std::string(yytext) + ")";
   fprintf(ly_tokFile,"%3d%4d.%03d   %-5d%-15s%s\n",yylval->filenr, 
           yylval->linenr,yylval->offset,yylval->symbol,
           get_yytname(yylval->symbol),formattedYytext.c_str());
   return symbol;
}

astree new_parseroot (void) {
   yyparse_astree = new_astree (TOK_ROOT, 0, 0, 0, "<<ROOT>>");
   return yyparse_astree;
}


void scanner_include (void) {
   scanner_newline();
   char filename[strlen (yytext) + 1];
   int linenr;
   int scan_rc = sscanf (yytext, "# %d \"%[^\"]\"",
                         &linenr, filename);
   if (scan_rc != 2) {
      errprintf ("%: %d: [%s]: invalid directive, ignored\n",
                 scan_rc, yytext);
   }else {
      fprintf (ly_tokFile, ";# %d \"%s\"\n", linenr, filename);
      scanner_newfilename (filename);
      scan_linenr = linenr - 1;
      DEBUGF ('m', "filename=%s, scan_linenr=%d\n",
              included_filenames.back().c_str(), scan_linenr);
   }
}

