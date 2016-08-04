#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>
#include <string.h>

#define LABEL_LENGTH 10
#define elements union datastructure

typedef struct list LIST;
typedef union datastructure DATASTRACTURE;
typedef struct map MAP;
typedef struct line LINE;

LIST *insert_item(LIST *l, ...);