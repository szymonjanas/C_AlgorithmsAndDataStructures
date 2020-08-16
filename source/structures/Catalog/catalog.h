#ifndef STRUCTURE_CATALOG
#define STRUCTURE_CATALOG

#include <stdlib.h>

typedef struct dict {
    char * name;
    // struct dict* up;
    // struct dict* down[];
} dict_n;

dict_n* getNew(char * name);


#endif