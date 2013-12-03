//This assignment completed with pair programming
// Name: John Carlyle Username: jcarlyle@ucsc.edu
// Name: Morgan McDermott Username: moamcder@ucsc.edu

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>
#include <getopt.h>
#include <assert.h>
#include <errno.h>

#include "auxlib.h"
#include "stringset.h"
#include "astree.h"
#include "lyutils.h"
#include "symtable.h"
#include "typechecker.h"
#include "codegen.h"

string dOption= "";
string yyin_cpp_command = "";

void yyin_cpp_popen (char* filename) {
  yyin_cpp_command = "/usr/bin/cpp ";
   if(dOption!="")
     yyin_cpp_command += "-D" + dOption + " ";
   
   yyin_cpp_command += string(filename);
   yyin = popen (yyin_cpp_command.c_str(), "r");
   if (yyin == NULL) {
     syserrprintf (yyin_cpp_command.c_str());
      exit (get_exitstatus());
   }

   FILE *checkFile=fopen(filename,"r");
   if(checkFile==NULL)
   {
      set_exitstatus (EXIT_FAILURE);
      return;
   }
   fclose(checkFile);
}

void yyin_cpp_pclose (void) {
   int pclose_rc = pclose (yyin);
   eprint_status (yyin_cpp_command.c_str(), pclose_rc);
   if (pclose_rc != 0) set_exitstatus (EXIT_FAILURE);
}

void write_files(char *filename) {
    string tokFilename = string(filename)+".tok";
    ly_tokFile=fopen(tokFilename.c_str(),"w");
    assert(ly_tokFile!=NULL);
    yyparse();
    fclose(ly_tokFile);

    string strName = string(filename)  + ".str";
    FILE *cor = fopen(strName.c_str(),"w");
    dump_stringset(cor);
    fclose(cor);

    string astFilename = string(filename)+".ast";
    FILE *astFile=fopen(astFilename.c_str(), "w");
    dump_astree(astFile, yyparse_astree);
    fclose(astFile);

    //global symbol table
    SymbolTable* globalTable = new SymbolTable(NULL);
    globalTable->populateTable(yyparse_astree);
    string symFilename = string(filename) + ".sym";
    FILE *symFile = fopen(symFilename.c_str(), "w");
    globalTable->dump(symFile, 0);
    fclose(symFile);


}

void scan_opts (int argc, char **argv) {
   int option;
   opterr = 0;
   yy_flex_debug = 0;
   yydebug = 0;
   for(;;) {
      option = getopt(argc,argv,"@:D:ly");
      if (option == EOF) break;
      switch (option) {
         case '@': set_debugflags (optarg);   break;
         case 'D': dOption=string(optarg);    break;
         case 'l': yy_flex_debug = 1;         break;
         case 'y': yydebug = 1;               break;
         default:  errprintf ("%:bad option (%c)\n", optopt); break;
      }
   }
   if (optind > argc) {
      errprintf ("Usage: %s [-@debugflag][-D][-ly] [filename]\n",
                                                      get_execname());
      exit (get_exitstatus());
   }
   const char *filename = optind == argc ? "-" : argv[optind];
   char *m = strdup(filename);
   yyin_cpp_popen (m);
   free(m);
}

int main(int argc, char **argv) {
   set_execname(argv[0]);
   scan_opts (argc, argv);
   write_files( argv[1] );
   yyin_cpp_pclose();

   typecheck_block(yyparse_astree);

   if(get_exitstatus() != EXIT_FAILURE){
     codegen(string(argv[1])+".oil", yyparse_astree);
   }

   return get_exitstatus();
}
