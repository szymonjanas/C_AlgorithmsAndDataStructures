#include "find.h"

int find_missing(int *arr, int size) 
{
    /*
        return (find) missing number in range 1 - 100
        if not found, return -1
    */

    if (size == 0 || size == 1) return -1;
    for (int i = 1; i <= size; ++i)
        if (arr[i-1] != i) return i;
    return -1;
}

int find_duplicate(int *arr, int size)
{
    /*
        return (find) duplicate number in range 
        if not found, return -1
    */
    if (size == 0 || size == 1) return -1;
    for (int i = 0; i < size-1; ++i)
        for (int j = i+1; j < size; ++j)
            if (arr[i] == arr[j]) return arr[i];
    return -1;
}

int find_unique(int *arr, int size)
{
    /*
        return (find) unique number in range 
        if not found, return -1
    */   
    if (size == 0) return -1;
    if (size == 1) return arr[0];
    for (int i = 0, tsize = 1; i < size; ++i){
        for (int j = 0; j < size; ++j)
            if (i != j && arr[i] != arr[j]) ++tsize;
        if (tsize == size) return arr[i];
        else tsize = 1;
    }
    return -1;
}

int* find_duplicates(int *arr, int size)
{

}

int* find_uniques(int *arr, int size)
{

}

int find_max(int *arr, int size)
{

}

int find_min(int *arr, int size)
{

}
