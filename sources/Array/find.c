#include "find.h"

int find_missing(int arr[], int size) 
{
    /*
        return (find) missing number in range 1 - 100
    */

    if (size == 0 || size == 1) return -1;
    for (int i = 1; i <= size; ++i)
        if (arr[i-1] != i) return i;
    return -1;
}

int find_duplicate(int arr[], int size)
{
    /*
        return (find) duplicate number in range 
    */
   if (size == 0 || size == 1) return -1;
   for (int i = 0; i < size-1; ++i)
    for (int j = i+1; j < size; ++j)
        if (arr[i] == arr[j]) return arr[i];
    return -1;
}

int find_unique(int arr[], int size)
{
    /*
        return (find) unique number in range 
    */

}
