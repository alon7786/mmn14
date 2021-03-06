#include "directives.h"

struct {
    char *name;
    void (*func)(char *, char *, LIST *);
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
        (*(directives[i].func))(line, filename, mapping);
    }
}

void data(char *line, char *filename, LIST *mapping)
{
    printf("data\n");
}
void entry(char *line, char *filename, LIST *mapping)
{
    char *word;
    LIST *cursor, *head;

    word = strtok(line, DELIMITER);
    if(mapping != NULL)
    {
        head = mapping;
        for(cursor = head->next; cursor != head; cursor = cursor->next)
        {
            continue;
        }
    }
    else
    {
        mapping = insert_item(mapping, MAPTYPE, 0, 0, word);
        printf("\n\n\n\n\n\t%s\n", (mapping->data).map.label);
    }
    printf("entry\n");
}
void exter(char *line, char *filename, LIST *mapping)
{
    printf("extern\n");
}
void string(char *line, char *filename, LIST *mapping)
{
    printf("string\n");
}