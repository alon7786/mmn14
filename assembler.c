/*
    
*/
#include "assembler.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    if(argc == SYSTEM_PARAMETERS)
        fprintf(stderr, "No files provided to compile.\n");
    else
    {
        while(argc > SYSTEM_PARAMETERS)
        {
            printf("%s\n", argv[argc - 1]);
            --argc;
        }
    }
    return(EXIT_SUCCESS);
}