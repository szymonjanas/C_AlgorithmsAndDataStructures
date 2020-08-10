#ifndef HEADER_FILE
#define HEADER_FILE

#include "find.h"
#include "test-engine/test.h"

void test_array(){
    
    int arr1[5] = {1,2,4,5,6};
    int arr2[9] = {1,2,3,4,5,6,7,8,9};
    int arr3[8] = {1,2,3,4,5,6,7};
    testc(find_missing(arr1, 5), 3);
    testc(find_missing(arr2, 9), 0);
    testc(find_missing(arr3, 8), 8);

}

#endif
