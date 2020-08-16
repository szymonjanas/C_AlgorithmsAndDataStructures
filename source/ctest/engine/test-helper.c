#include "test-helper.h"

char *arr_to_string(int *arr, size_t size)
{
    if (size == 0 || arr == NULL)
        return NULL;
    char *str = (char *)malloc(sizeof(char) * size * 2 + 2);
    strcpy(str, "[");
    char num[16];
    for (int i = 0; i < size; ++i)
    {
        sprintf(num, "%i", arr[i]);
        strcat(str, num);
        if (i < size - 1)
            strcat(str, ",");
    }
    strcat(str, "]");
    return str;
}
