#include "IntList.h"

node_int* getNewHead(int value) 
{
    node_int* node = (node_int*) malloc (sizeof(node_int));
    node->value = value;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

size_t getSize(node_int* head) 
{
    if (!head) return 0;
    if (!head->next) return 1;
    size_t size = 1;
    node_int* temp = head;
    while (temp->next){
        ++size;
        temp = temp->next;
    }
    return size;
}

int* getArray(node_int* head) 
{
    if (!head) return NULL;
    int size = getSize(head);
    int* arr = (int*) malloc (sizeof(int)*size);
    int iter = 0;
    node_int* node = head;
    arr[iter++] = node->value;
    while(node->next){
        node = node->next;
        arr[iter++] = node->value;
    }
    return arr;
}

node_int* append(node_int* head, int value) 
{
    node_int* node = (node_int*) malloc (sizeof(node_int));
    node->value = value;
    node->next = NULL;
    node->prev = NULL;

    if (!head) return node;
    node_int* temp = head, tnode;
    while (temp->next) temp = temp->next;
    temp->next = node;
    node->prev = temp;
    return head;
}
