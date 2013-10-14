//Name: John Carlyle Username: jcarlyle@ucsc.edu
//Name: Morgan McDermott Username: moamcdermo@ucsc.edu

#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <libgen.h>
#include <errno.h>
#include "auxlib.h"
#include "stringset.h"
#include <string>
#include <stdio.h>

#define BUF_SIZE 128
#define LINESIZE 1024

using namespace std;
char  *program;
void syswarn (char *problem) {
   fflush (NULL);
   fprintf (stderr, "%s: %s: %s\n",
            program, problem, strerror (errno));
   fflush (NULL);
   set_exitstatus(EXIT_FAILURE);
}

void chomp (char *string, char delim) {
   size_t len = strlen (string);
   if (len == 0) return;
   char *nlpos = string + len - 1;
   if (*nlpos == delim) *nlpos = '\0';
}

int main(int argc, char** argv) {
  //cout << "Test case" <<endl;
  intern_stringset("Meow meow");
  FILE *myfi = fopen("./myfi.file", "rw");
  dump_stringset(myfi);
  //cout << "Exiting test case" <<endl;
  exit(1);



  //set flags for boolean arguments
  int i;
  
  char* buf_d = NULL; 
  char* buf_at = NULL;
  char* program = NULL;
  char filename[BUF_SIZE];
  
  int yy_flex_debug = 0;
  int yydebug = 0;
    
  //process arguments
  int c, index;
  while ((c = getopt(argc, argv, "lyD:@:")) != -1) {
    switch (c) 
      {
      case 'l':
	yy_flex_debug = 1;
	break;
      case 'y':
	 yydebug = 1;
	 break;
      case 'D':
	buf_d = strdup(optarg);
	break;
      case '@':
	buf_at = strdup(optarg);
	break;
      case '?':
	 if (optopt == 'D' || optopt == '@') {
	   fprintf(stderr, "Option -%c requires an argument.\n", optopt);
	 }
	 else if (isprint(optopt)) {
	   fprintf(stderr, "Unknown option `-%c'.\n", optopt);
	 }
	 else {
	   fprintf(stderr, "Unknown option character `\\x%x'.\n", optopt);
	 }
	 return 1;
      default:
	abort();
	break;
      }
  }
  

  if (argc - optind > 1) {
    fprintf(stderr, "Only one program to compile at a time.\n");
  }

  strcpy(filename, argv[optind]);
  program = strdup(basename(filename));

  printf("%s, %s", filename, program);//program is off by one or something lame.
  
  string command = "/usr/bin/cpp";
  if (buf_d != NULL) {
    command += " -D" + string(buf_d);
  }
  command += " " + string(filename);
  FILE *pipe = popen(command.c_str(), "r");
  //cout << "Command: " + command << endl;
  if (pipe == NULL) {
    syswarn((char*)command.c_str());
  } 

  else {
    int line = 1;
    char buffer[LINESIZE];

    for (;;) {

      char *fgets_rc = fgets(buffer, LINESIZE, pipe);
      if (fgets_rc == NULL) break;
      chomp(buffer, '\n');
      int sscanf_rc = sscanf(buffer, "# %d \%[^\"]\"",
			     &line, filename);
      if (sscanf_rc==2) continue;
      char *savepos = NULL;
      char *bufptr = buffer;
      
      for (int tokenct = 1 ;; ++tokenct) {
	char *token = strtok_r(bufptr, " \t\n", &savepos);
	bufptr = NULL;
	if (token == NULL) break;
	intern_stringset(token);
      }
      ++line;
    }
    
    int pclose_i = pclose(pipe);
    eprint_status(command.c_str(), pclose_i);
    if(pclose_i != 0) set_exitstatus( EXIT_FAILURE );
    
    string programstr = string(program) + ".str";
    FILE *strfi = fopen(programstr.c_str(), "rw");
    //cout << "Opening " +programstr <<endl;
    dump_stringset(strfi);
    fclose(strfi);
    
    
  }
  
  return 0;
}
