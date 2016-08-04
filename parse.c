#include "parse.h"

void parse(FILE *source_file, char *filename, LIST *mapping)
{
    int linenum = 0;
    char line[LINE_LENGTH + 1];
    while(fgets(line, LINE_LENGTH, source_file) != NULL)
    {
        parseline(line, ++linenum, filename, mapping);
    }
}

void parseline(char *line, int linenum, char *filename, LIST *mapping)
{
    int whitespaces = 0, wordlength = 0;
    char *word, *p, *label;
    word = strtok(line, DELIMITER);
    if(word != NULL)
    {
        if(word[0] == DIRECTIVES)
        {
            printf("%3d.\tDirectives %s\n", linenum, &word[1]);
            wordlength = strlen(word);
            p = line;
            while(*p++ == ' ' || *p++ == '\t')
            {
                whitespaces++;
            }
            parsedirective(&word[1], &line[whitespaces + wordlength + 1], linenum, filename, mapping);
        }
        else if(word[strlen(word) - 1] == LABLE)
        {
            wordlength = strlen(word);
            word[wordlength - 1] = '\0';
            label = word;
            printf("%3d.\tLabel %s\n", linenum, word);
            word = strtok(NULL, DELIMITER);
            if(word != NULL)
            {
                if(strcmp(&word[1], ENTRY) == 0 || strcmp(&word[1], EXTERN) == 0)
                {
                    fprintf(stderr, "%s:%d: warning: unnecessary label (%s) for %s directive.\n", filename, linenum, label, &word[1]);
                }
                p = line;
                while(*p++ == ' ' || *p++ == '\t')
                {
                    whitespaces++;
                }
                parseline(&line[whitespaces + wordlength + 1], linenum, filename, mapping);
            }
        }
        else
        {
            printf("%3d.\tCommand %s\n", linenum, word);
        }
    }
}