#include "catalog.h"

dict_n* getNew(char * name) 
{
    dict_n* node = (dict_n*) malloc (sizeof(dict_n));
    node->name = name;
    // node->up = NULL;
    return node;  
}


