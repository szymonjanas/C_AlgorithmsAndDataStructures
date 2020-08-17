#include "modify.h"

int* get_reversed(int *arr, size_t size) 
{
    int* rarr = (int*) malloc (sizeof(int)*size);

    for (int i = 0; i < size; ++i){
        rarr[size-i-1] = arr[i];
    }
    return rarr;
}

int* reverse(int *arr, size_t size) 
{
    for (int iter = 0; iter < size/2; ++iter){
        int temp = arr[iter];
        arr[iter] = arr[size-iter-1];
        arr[size-iter-1] = temp;
    }
    return arr;
}
