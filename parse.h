#include <stdio.h>
#include <string.h>
#include "directives.h"
#include "utils.h"

#define LINE_LENGTH 80
#define INITIAL_ADDRESS 100
#define DIRECTIVES '.'
#define LABLE ':'
#define DATA "data"
#define ENTRY "entry"
#define EXTERN "extern"
#define STING "string"

void parse(FILE *source_file, char *filename, LIST *mapping);
void parseline(char *line, int linenum, char *filename, LIST *mapping);