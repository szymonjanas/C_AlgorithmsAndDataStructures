#include "find.h"
#include <stdio.h>
int find_missing(int arr[], int size) 
{
    /*
        return (find) missing number in range 1 - 100
    */

    if (size == 0) return 0;
    for (int i = 1; i <= size; ++i)
        if (arr[i-1] != i) return i;
    return 0;
}
