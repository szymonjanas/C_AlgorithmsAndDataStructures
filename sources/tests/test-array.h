#ifndef HEADER_FILE
#define HEADER_FILE

#include "Array/find.h"
#include "test-engine/test.h"
#include <stdio.h>
void test_array(){
    test_start_scenario("find missing");
    int arr10[1] = {1};
    int arr11[5] = {1,2,4,5,6};
    int arr12[9] = {1,2,3,4,5,6,7,8,9};
    int arr13[8] = {1,2,3,4,5,6,7};
    testc(find_missing(arr10, 1), -1);
    testc(find_missing(arr11, 5), 3);
    testc(find_missing(arr12, 9), -1);
    testc(find_missing(arr13, 8), 8);

    test_start_scenario("find duplicate");
    int arr20[1] = {1};
    int arr21[5] = {1,2,4,6,6};
    int arr22[9] = {1,2,3,4,5,6,7,8,1};
    int arr23[8] = {1,2,3,4,5,6,7};
    testc(find_duplicate(arr20, 1), -1);
    testc(find_duplicate(arr21, 5), 6);
    testc(find_duplicate(arr22, 9), 1);
    testc(find_duplicate(arr23, 8), -1);

    

    test_end_scenarios();
}

#endif
