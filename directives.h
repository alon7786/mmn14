#include <stdio.h>
#include <string.h>
#include "clist.h"
#include "utils.h"

void parsedirective(char *directive, char *line, int linenum, char *filename, LIST *mapping);

void data(char *line, char *filename, LIST *mapping);
void entry(char *line, char *filename, LIST *mapping);
void exter(char *line, char *filename, LIST *mapping);
void string(char *line, char *filename, LIST *mapping);