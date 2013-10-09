#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUF_SIZE 128

int main(int argc, char** argv) {
  //set flags for boolean arguments
  int i;
  
  char* buf_d = NULL; 
  char* buf_at = NULL;
  char program[BUF_SIZE];
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
	buf_d = optarg;
	break;
      case '@':
	buf_at = optarg;
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



  
  return 0;
}
