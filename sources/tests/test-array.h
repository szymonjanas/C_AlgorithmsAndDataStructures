#ifndef HEADER_FILE
#define HEADER_FILE

#include "Array/find.h"
#include "test-engine/test.h"
#include <stdio.h>
#include <stdlib.h>

void test_array(){
    test_start_scenario("find missing");
    int arr10[1] = {1};
    int arr11[5] = {1,2,4,5,6};
    int arr12[9] = {1,2,3,4,5,6,7,8,9};
    int arr13[8] = {1,2,3,4,5,6,7};
    testc(find_missing(arr10, 1), NULL);
    testc(*find_missing(arr11, 5), 3);
    testc(find_missing(arr12, 9), NULL);
    testc(*find_missing(arr13, 8), 8);

    test_start_scenario("find duplicate");
    int arr20[1] = {1};
    int arr21[5] = {1,2,4,6,6};
    int arr22[9] = {1,2,3,4,5,6,7,8,1};
    int arr23[8] = {1,2,3,4,5,6,7};
    testc(find_duplicate(arr20, 1), NULL);
    testc(*find_duplicate(arr21, 5), 6);
    testc(*find_duplicate(arr22, 9), 1);
    testc(find_duplicate(arr23, 8), NULL);

    test_start_scenario("find unique");
    int arr30[10] = {1,2,2,1,4,3,6,3,4,1};
    int arr31[10] = {1,1,3,3,5,5,7,7,9,9};
    testc(find_unique(NULL, 0), NULL);
    testc(*find_unique(arr30, 10), 6);
    testc(find_unique(arr31, 10), NULL);

    test_start_scenario("find max");
    int arr40[10] = {0,1,2,3,4,5,6,7,8,9};
    int arr41[10] = {1,1,2,2,2,3,1,1,3,3};
    int arr42[1] = {1};
    testc(find_max(NULL, 0), NULL);
    testc(*find_max(arr40, 10), 9);
    testc(*find_max(arr41, 10), 3);
    testc(*find_max(arr42, 1), 1);

    test_start_scenario("find min");
    testc(find_min(NULL, 0), NULL);
    testc(*find_min(arr40, 10), 0);
    testc(*find_min(arr41, 10), 1);
    testc(*find_max(arr42, 1), 1);

    test_start_scenario("find duplicates");
    int arr50[10] = {0,1,2,3,4,5,6,7,8,9};
    int arr51[10] = {1,1,2,2,2,3,1,1,3,3};
    testIntArr(arr50, 10, arr51, 10);

    test_end_scenarios();
}

#endif
