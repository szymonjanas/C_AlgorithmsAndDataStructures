#include "find.h"

int* find_missing(int *arr, size_t size) 
{
    /*
        return (find) ptr to missing number in range 1 - 100
        if not found, return NULL
    */

    if (size == 0 || size == 1 || arr == NULL) return NULL;
    int* missing = (int*) malloc (sizeof(int));
    for (int i = 1; i <= size; ++i)
        if (arr[i-1] != i){
            *missing = i;
            return missing;
        }
    return NULL;
}

int* find_duplicate(int *arr, size_t size)
{
    /*
        return (find) ptr to duplicate number in range 
        if not found, return NULL
    */
    if (size == 0 || size == 1 || arr == NULL) return NULL;
    int *duplicate = (int*) malloc (sizeof(int));
    for (int i = 0; i < size-1; ++i)
        for (int j = i+1; j < size; ++j)
            if (arr[i] == arr[j]){
                *duplicate = arr[i];
                return duplicate;
            }
    return NULL;
}

int* find_unique(int *arr, size_t size)
{
    /*
        return (find) ptr to unique number in range 
        if not found, return NULL
    */   
    if (size == 0 || arr == NULL) return NULL;
    int* unique = (int*) malloc (sizeof(int));
    if (size == 1){
        *unique = arr[0];
        return unique;
    } 
    for (int i = 0, tsize = 1; i < size; ++i){
        for (int j = 0; j < size; ++j)
            if (i != j && arr[i] != arr[j]) ++tsize;
        if (tsize == size){
            *unique = arr[i];
            return unique;
        } 
        else tsize = 1;
    }
    return NULL;
}

int* find_duplicates(int *arr, size_t size)
{
    /*
        return (find) ptr to arr with duplicates number in range 
        if not found, return NULL
    */
    if (size == 0 || size == 1 || arr == NULL) return NULL;
    int *duplicates = (int*) malloc (sizeof(int)*size);
    for (int i = 0, d = 0; i < size-1; ++i)
        for (int j = i+1; j < size; ++j)
            if (arr[i] == arr[j]){
                duplicates[d++] = arr[i];
            }
    return duplicates;
}

int* find_uniques(int *arr, size_t size)
{

}

int* find_max(int *arr, size_t size)
{
    /*
        return (find) ptr to maximum value in array
        if not found, return NULL
    */
    if (!size || !arr) return NULL;
    int *max = (int*) malloc (sizeof(int));
    *max = arr[0];
    if (size == 1) return max;
    for (int i = 0; i < size; ++i)
        if (arr[i] > *max) *max = arr[i];
    return max;
}

int* find_min(int *arr, size_t size)
{
    /*
        return (find) ptr to minimum value in array
        if not found, return NULL
    */
    if (!size || !arr) return NULL;
    int *min = (int*) malloc (sizeof(int));
    *min = arr[0];
    if (size == 1) return min;  
    for (int i = 0; i < size; ++i)
        if (arr[i] < *min) *min = arr[i];
    return min;
}
