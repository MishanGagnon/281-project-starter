// Project Identifier: "ADD"
#include <iostream>
#include <getopt.h>
#include "project.h"

//add class here

int main(int argc, char *argv[]) {
  std::ios::sync_with_stdio(false);
  // These are used with getopt_long()
  opterr = false; // Let us handle all error output for command line options
  int choice;
  int index = 0;
  option long_options[] = {
    // the "help" ('h') options.
    { "help", no_argument,       nullptr, 'h'},
    { "TEST REPLACE", no_argument, nullptr, 'q'},
    { nullptr, 0, nullptr, '\0' },
  };  // long_options[]

  while ((choice = getopt_long(argc, argv, "hqsb:e:o:clp", long_options, &index)) != -1) {
    switch (choice) {
      case 'h':
        // TODO: Implement printHelp() function
        std::cout << "Help option selected\n";
        break;
      default:
        std::cerr << "Unknown command line option\n";
        exit(1);
    }  // switch ..choice
  } 

  return 0;
}  // main()
