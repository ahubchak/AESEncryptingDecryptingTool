#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <errno.h>

int main(int argc, char ** argv) {
    printf("Here everything begins\n");

    bool helpFlag = false;
    int index;
    int c;

    opterr = 0;

    while ((c = getopt (argc, argv, "ah")) != -1)
        switch (c)
          {
          case 'a':
              printf("Helaaaap output\n");
              break;
          case 'h':
            helpFlag = true;
            printf("It accepts a path to a binary image (*.bin), output directory and an encryption key from a command line\n");
            break;
          case '?':
            if (optopt == 'c')
            {
                fprintf(stderr, "Option -%c requires an argument.\n", optopt);
            }
            else if (isprint (optopt))
            {
                fprintf(stderr, "Unknown option `-%c'.\n", optopt);
            }
            else
            {
                fprintf(stderr, "Unknown option character `\\x%x'.\n", optopt);
            }
            return 1;
          default:
            printf("somethings went wrong\n");
            abort ();
      }

    for (index = optind; index < argc; index++)
    {
        printf("Non-option argument %s\n", argv[index]);
    }

    FILE *filePointer;
    filePointer = fopen("./bin.bin", "rwb");
    int32_t fileError = errno;
    if(fileError > 0)
    {
       switch(fileError)
       {
           case 2:
               printf("No such file or directory\n");
               abort();
               break;
           case 13:
               printf("Permission denied\n");
               abort();
               break;
       }
    }
    return 0;
}