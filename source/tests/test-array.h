#ifndef HEADER_FILE
#define HEADER_FILE

#include "algorithms/Array/find.h"
#include "algorithms/Array/modify.h"
#include "test.h"
#include <stdlib.h>

void test_array_find(){
    test_category_begin("TEST ARRAY FIND");
        test_scenario_begin("find missing");
        int arr10[1] = {1};
        int arr11[5] = {1,2,4,5,6};
        int arr12[9] = {1,2,3,4,5,6,7,8,9};
        int arr13[8] = {1,2,3,4,5,6,7};
        test_assert_comp_int(find_missing(arr10, 1), NULL);
        test_assert_comp_int(*find_missing(arr11, 5), 3);
        test_assert_comp_int(find_missing(arr12, 9), NULL);
        test_assert_comp_int(*find_missing(arr13, 8), 8);

        test_scenario_begin("find duplicate");
        int arr20[1] = {1};
        int arr21[5] = {1,2,4,6,6};
        int arr22[9] = {1,2,3,4,5,6,7,8,1};
        int arr23[8] = {1,2,3,4,5,6,7};
        test_assert_comp_int(find_duplicate(arr20, 1), NULL);
        test_assert_comp_int(*find_duplicate(arr21, 5), 6);
        test_assert_comp_int(*find_duplicate(arr22, 9), 1);
        test_assert_comp_int(find_duplicate(arr23, 8), NULL);

        test_scenario_begin("find unique");
        int arr30[10] = {1,2,2,1,4,3,6,3,4,1};
        int arr31[10] = {1,1,3,3,5,5,7,7,9,9};
        test_assert_comp_int(find_unique(NULL, 0), NULL);
        test_assert_comp_int(*find_unique(arr30, 10), 6);
        test_assert_comp_int(find_unique(arr31, 10), NULL);

        test_scenario_begin("find max");
        int arr40[10] = {0,1,2,3,4,5,6,7,8,9};
        int arr41[10] = {1,1,2,2,2,3,1,1,3,3};
        int arr42[1] = {1};
        test_assert_comp_int(find_max(NULL, 0), NULL);
        test_assert_comp_int(*find_max(arr40, 10), 9);
        test_assert_comp_int(*find_max(arr41, 10), 3);
        test_assert_comp_int(*find_max(arr42, 1), 1);

        test_scenario_begin("find min");
        test_assert_comp_int(find_min(NULL, 0), NULL);
        test_assert_comp_int(*find_min(arr40, 10), 0);
        test_assert_comp_int(*find_min(arr41, 10), 1);
        test_assert_comp_int(*find_max(arr42, 1), 1);

        test_scenarios_end();
    test_category_end();
}

void test_array_modify(){
    test_category_begin("TEST ARRAY MODIFY");
        test_scenario_begin("modify get reversed and reverse");
            int arr1000[10] = {1,2,3,4,5,6,7,8,9,0};
            int arr1001[10] = {0,9,8,7,6,5,4,3,2,1};
            int arr1002[10] = {1,2,3,4,5,6,7,8,9,0};
            test_assert_array_int(get_reversed(arr1000, 10), 10, arr1001, 10);
            reverse(arr1002, 10);
            test_assert_array_int(arr1002, 10, arr1001, 10);

        test_scenarios_end();
    test_category_end();
}

#endif
