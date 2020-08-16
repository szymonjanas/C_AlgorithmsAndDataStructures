#ifndef INT_LIST_STRUCTURE
#define INT_LIST_STRUCTURE

#include <stdlib.h>

typedef struct IntList
{
    int value;
    struct IntList* next;
    struct IntList* prev;
} node_int;

node_int* getNewHead(int value);
node_int* append(node_int* head, int value);
size_t getSize(node_int* head);
int* getArray(node_int* head);

#endif