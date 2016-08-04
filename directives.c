#include "directives.h"

struct {
    char *name;
    void (*func)(LIST*);
} directives[] = {
        {"data", data},
        {"entry", entry},
        {"extern", exter},
        {"string", string},
        {"not_valid", NULL}
    };

void parsedirective(char *directive, char *line, int linenum, char *filename, LIST *mapping)
{
    int i;
    for(i = 0; directives[i].func != NULL; i++)
    {
        if(strcmp(directive, directives[i].name) == 0)
        {
            break;
        }
    }
    if(directives[i].func == NULL)
    {
        fprintf(stderr, "%s:%d: warning: unknown directive %s.\n", filename, linenum, directive);
        
    }
    else
    {
        (*(directives[i].func))(mapping);
    }
}

void data(LIST *mapping)
{
    printf("data\n");
}
void entry(LIST *mapping)
{
    printf("entry\n");
}
void exter(LIST *mapping)
{
    printf("extern\n");
}
void string(LIST *mapping)
{
    printf("string\n");
}