#include "assembler.h"

int main(int argc, char *argv[])
{
    char filename[FILE_NAME];
    LIST *lines = NULL, *mapping = NULL;
    FILE *source_file;
    if(argc == SYSTEM_PARAMETERS)
        fprintf(stderr, "No files provided to compile.\n");
    else
    {
        while(argc > SYSTEM_PARAMETERS)
        {
            strcpy(filename, argv[argc - 1]);
            strcat(filename, FILE_INPUT_POSTFIX);
            if((source_file = fopen(filename, FILE_READ)) == NULL)
            {
                fprintf(stderr, "Cannot open %s file.\n", filename);
            }
            else
            {
                printf("Compiling file %s.\n", filename);
                parse(source_file, filename, mapping);
                /* assembly(source_file) */
                fclose(source_file);
            }
            --argc;
        }
    }
    return(EXIT_SUCCESS);
}