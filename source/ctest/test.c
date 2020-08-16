#include "test.h"

static bool enable = false;

/*
    Testing management
*/

void test_testing_begin() 
{
    enable = true;
    if (enable)
        p_testing_begin();
}

int test_testing_end()
{
    if (enable){
        enable = false;
        return p_testing_end();
    }
}

void test_scenario_begin(const char * name)
{
    if (enable)
        p_scenario_begin(name);
}

void test_scenarios_end()
{
    if (enable)
        p_scenario_end();
}

void test_category_begin(const char * name) 
{
    if (enable)
        p_category_begin(name);
}

void test_category_end() 
{
    if (enable)
        p_category_end();
}

/*
    Testing cases
*/

void test_assert(bool condition) 
{
    if (!enable) return;
    p_case_add();
    if (condition)
        p_case_pass();
    else 
        p_case_failed();
}

void test_assert_comp_int(int a, int b)
{
    if (!enable) return;
    p_case_add();
    if (a == b)
        p_case_pass();
    else 
        p_case_failed_val_int(a, b);    
}

void test_assert_strs(char * a, char * b) 
{
    if (!enable) return;
    p_case_add();
    if (!a || !b){
        p_case_failed_msg("Given str is NULL!");
        return;
    } 
    int size_a = strlen(a);
    int size_b = strlen(b);
    if (size_a != size_b) {
        p_case_failed_msg("size_a is not equal size_b");
        return;
    } 
    if (size_a == 0 || size_b == 0){
        p_case_pass();
        return;
    } 
    for (int i = 0; i < size_a; ++i){
        if (*(a+i) != *(b+i)){
            p_case_failed_strs(a, b);
            return;
        } 
    }
    p_case_pass();
}

void test_assert_array_int(int *a, size_t size_a, int *b, size_t size_b)
{
    if (!enable) return;
    p_case_add();
    if (!a || !b){
        p_case_failed_msg("Given str is NULL!");
        return;
    }
    if (size_a != size_b){
        p_case_failed_msg("size_a is not equal size_b");
        return;
    } 
    if (size_a == 0 || size_b == 0){
        p_case_pass();
        return;
    } 
    for (int i = 0; i < size_a; ++i){
        if (*(a+i) != *(b+i)){
            p_case_failed_strs(   arr_to_string(a, size_a),
                                arr_to_string(b, size_b));
            return;
        } 
    }
    p_case_pass();
}
