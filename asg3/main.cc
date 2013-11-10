//This assignment completed with pair programming
// Name: John Carlyle Username: jcarlyle@ucsc.edu
// Name: Morgan McDermott Username: moamcderxf@ucsc.edu

#include <string>
#include <vector>
using namespace std;

#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>


#include <libgen.h>
#include <getopt.h>
#include <assert.h>


#include "astree.h"
#include "auxlib.h"
//#include "emit.h"
#include "lyutils.h"
#include "stringset.h"

extern FILE *ly_tokFile;
extern FILE *yyin;

const string cpp_name = "/usr/bin/cpp";
string yyin_cpp_command;

// Open a pipe from the C preprocessor.
// Exit failure if can't.
// Assignes opened pipe to FILE* yyin.
void yyin_cpp_popen (const char* filename) {
   yyin_cpp_command = cpp_name;
   yyin_cpp_command += " ";
   yyin_cpp_command += filename;
   yyin = popen (yyin_cpp_command.c_str(), "r");
   if (yyin == NULL) {
      syserrprintf (yyin_cpp_command.c_str());
      exit (get_exitstatus());
   }
}

void yyin_cpp_pclose (void) {
   int pclose_rc = pclose (yyin);
   eprint_status (yyin_cpp_command.c_str(), pclose_rc);
   if (pclose_rc != 0) set_exitstatus (EXIT_FAILURE);
}

bool want_echo () {
   return not (isatty (fileno (stdin)) and isatty (fileno (stdout)));
}


void scan_opts (int argc, char** argv) {
   int option;
   opterr = 0;
   yy_flex_debug = 0;
   yydebug = 0;
   for(;;) {
      option = getopt (argc, argv, "@:ely");
      if (option == EOF) break;
      switch (option) {
         case '@': set_debugflags (optarg);   break;
         case 'l': yy_flex_debug = 1;         break;
         case 'y': yydebug = 1;               break;
         default:  errprintf ("%:bad option (%c)\n", optopt); break;
      }
   }
   if (optind > argc) {
      errprintf ("Usage: %s [-ly] [filename]\n", get_execname());
      exit (get_exitstatus());
   }
   const char* filename = optind == argc ? "-" : argv[optind];
   yyin_cpp_popen (filename);
   DEBUGF ('m', "filename = %s, yyin = %p, fileno (yyin) = %d\n",
           filename, yyin, fileno (yyin));
   scanner_newfilename (filename);
}

int main (int argc, char** argv) {
   int parsecode = 0;
   new_parseroot();
   set_execname (argv[0]);
   DEBUGSTMT ('m',
      for (int argi = 0; argi < argc; ++argi) {
         eprintf ("%s%c", argv[argi], argi < argc - 1 ? ' ' : '\n');
      }
   );
   scan_opts (argc, argv);
   scanner_setecho (want_echo());
   
   char *filename = strdup(argv[optind]);
   char *program = strdup(basename(filename));
   ly_tokFile=fopen((string(program)+".tok").c_str(),"w");
   assert(ly_tokFile!=NULL);
   for(;;)
     {
       if(yylex()==YYEOF)
         break;
       //Temporarily we shall adopt each astree
       // so that they get appropriately freed
       adopt1(yyparse_astree, yylval);
     }
   fclose(ly_tokFile);
   
   free_ast (yyparse_astree); 
   yyin_cpp_pclose();

   string programstr = string(program) + ".str";
   FILE *strfi = fopen(programstr.c_str(), "w");
   dump_stringset(strfi);
   fclose(strfi);
   
   DEBUGSTMT ('s', dump_stringset (stderr); );
   yylex_destroy();
   free(filename);
   free(program);
   return get_exitstatus();
}
