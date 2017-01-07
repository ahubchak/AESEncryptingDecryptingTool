#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <errno.h>
#include <stdint.h>
#include <tomcrypt.h>

#define DebugInfo true

int main(int argc, char ** argv)
{
#if DebugInfo
    printf("Here everything begins\n");
#endif

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
    filePointer = fopen("../bin.bin", "rwb");
    int32_t fileError;
    fileError = errno;
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

    /* Get file size */
    uint16_t fileSize;
    fseek(filePointer, 0L, SEEK_END);
    fileSize = ftell(filePointer);
    rewind(filePointer);

#if DebugInfo
    printf("File size is equal to %u\n", fileSize);
#endif

    uint8_t * data;
    data = malloc(fileSize);
    fread(data, sizeof(uint8_t), fileSize, filePointer);

#if DebugInfo
    printf("Data is equal to \"%s\" \n", data);
#endif

    /*here encryption should be provided */
    register_cipher(&aes_desc);

    free(data);
    fclose(filePointer);
    return 0;
}