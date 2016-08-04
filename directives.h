#include <stdio.h>
#include <string.h>
#include "clist.h"

void parsedirective(char *directive, char *line, int linenum, char *filename, LIST *mapping);

void data(LIST *mapping);
void entry(LIST *mapping);
void exter(LIST *mapping);
void string(LIST *mapping);