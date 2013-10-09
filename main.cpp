#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <libgen.h>

#include <vector>
#include <string>
#include <iostream>


#define BUF_SIZE 128


//my_popen taken from http://stackoverflow.com/questions/7807755/reading-popen-results-in-c
// and modified slightly. 
std::vector<std::string> my_popen (const std::string& cmd) {
    std::vector<std::string> out;
    bool            ret_boolValue = true;
    FILE*           fp;
    const int       SIZEBUF = 1234;
    char            buf [SIZEBUF];
    out = std::vector<std::string> ();
    if ((fp = popen(cmd.c_str (), "r")) == NULL) {
      //return false;
    }
    std::string  cur_string = "";
    while (fgets(buf, sizeof (buf), fp)) {
        cur_string += buf;
    }
    out.push_back (cur_string.substr (0, cur_string.size () - 1));
    pclose(fp);
    return out;
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

  strcpy(filename, argv[optind]);
  program = basename(filename);

  printf("%s, %s", filename, program);//program is off by one or something lame.

  std::vector<std::string> output = my_popen("/usr/bin/cpp " + std::string(filename));
        for ( std::vector<std::string>::iterator itr = output.begin();
                                                 itr != output.end();
                                                 ++itr) {
                std::cout << *itr << std::endl;
        }
  
  return 0;
}
