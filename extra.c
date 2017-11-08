/*
 * Utility functions
 * for bash interpreter
*/

#include "bash.h"

int show_version(void)
{
    printf("version 1.0\n");
    printf("Runs single commands\n");
    return 0;
}

int show_help(void)
{
    printf("\nBash version 1.0\n\n");
    printf("-v, --version           show version and exit\n");
    printf("    --help              show help and exit\n");
    printf("Interpret single commands like uname, ls, wc, cat.\n");
    printf("No pipe support available as of now.\n\n");
    printf("To exit press ctrl+c.\n\n");
}

int command_line_parser(int argc, char *argv[])
{
      // handle version -v right now
      if(argc == 2 && (strcmp(argv[1],"-v") == 0 || strcmp(argv[1],"--version") == 0) )
      {
          show_version();
          exit(0);
      }
      else if(argc == 2 && strcmp(argv[1],"--help") == 0)
      {
          show_help();
          exit(0);
      }
      else if(argc == 2)
      {
          printf("Invalid arguments....\n");
          exit(0);
      }

      return 0;
}
