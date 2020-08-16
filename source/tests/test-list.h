#ifndef TEST_INT_LIST
#define TEST_INT_LIST

#include "structures/List/IntList.h"
#include "test-engine/test.h"
#include <stdlib.h>

void test_IntList(){
    test_scenario_begin("init");
    node_int* head = getNewHead(5);
    testc(head->value, 5);

    test_scenario_begin("get size");
    testc(getSize(head), 1);
    append(head, 9);
    testc(getSize(head), 2);
    append(head, 3);
    append(head, 4);
    append(head, 2);
    testc(getSize(head), 5);
    int arr[5] = {5,9,3,4,2};
    testIntArr(getArray(head), getSize(head), arr, 5);
}

#endif
