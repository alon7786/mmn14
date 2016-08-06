#include "clist.h"

LIST *insert_item(LIST *l, ...)
{
    LIST *nl;
    va_list ap;

    va_start(ap, l);
    nl = (LIST*)malloc(sizeof(elements));
    switch(va_arg(ap, int))
    {
        case LINETYPE:
            nl->data.line.address = va_arg(ap, int);
            nl->data.line.info = va_arg(ap, int);
            va_end(ap);
            break;
        case MAPTYPE:
            nl->data.map.address = va_arg(ap, int);
            nl->data.map.type = va_arg(ap, int);
            strcpy(nl->data.map.label, va_arg(ap, char*));
            va_end(ap);
            break;
    }

    if(l == NULL)
        nl->next = nl;
    else
    {
        nl->next = l->next;
        l->next = nl;
    }

    return nl;
}