#include "assembler.h"

int main(int argc, char *argv[])
{
    char path[FILE_PATH];
    FILE *source_file;
    if(argc == SYSTEM_PARAMETERS)
        fprintf(stderr, "No files provided to compile.\n");
    else
    {
        while(argc > SYSTEM_PARAMETERS)
        {
            strcpy(path, argv[argc - 1]);
            strcat(path, FILE_POSTFIX);
            if((source_file = fopen(path, FILE_READ)) == NULL)
            {
                fprintf(stderr, "Cannot open %s file.\n", path);
            }
            else
            {
                printf("Compile file %s.\n", path);
            }
            --argc;
        }
    }
    return(EXIT_SUCCESS);
}