//Name: John Carlyle Username: jcarlyle@ucsc.edu
//Name: Morgan McDermott Username: moamcdermo@ucsc.edu

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <libgen.h>
#include <errno.h>
#include "auxlib.h"

#define BUF_SIZE 128

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
      }
  }
  
  if (argc - optind > 1) {
    fprintf(stderr, "Only one program to compile at a time.\n");
  }

  strcpy(filename, argv[optind]);
  program = strdup(basename(filename));

  printf("%s, %s", filename, program);//program is off by one or something lame.


  
  return 0;
}
