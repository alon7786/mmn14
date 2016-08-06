#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>
#include <string.h>

#define LABEL_LENGTH 10
#define elements union datastructure

enum {LINETYPE, MAPTYPE};

typedef struct list LIST;
typedef union datastructure DATASTRACTURE;
typedef struct map MAP;
typedef struct line LINE;

struct line
{
    unsigned short int address;
    unsigned char info;
};

struct map
{
    char label[LABEL_LENGTH];
    unsigned short int address;
    unsigned char type;
};

union datastructure
{
    LINE line;
    MAP map;
};

struct list
{
    elements data;
    LIST *next;
};

LIST *insert_item(LIST *l, ...);