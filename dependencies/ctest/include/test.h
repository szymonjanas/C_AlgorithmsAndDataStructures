#ifndef TEST_ENGINE
#define TEST_ENGINE

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "engine/test-print.h"
#include "engine/test-helper.h"

void test_testing_begin();
int test_testing_end();

void test_scenario_begin(const char * name);
void test_scenarios_end();

void test_category_begin(const char * name);
void test_category_end();

void test_assert(bool condition);
void test_assert_comp_int(int a, int b);
void test_assert_array_int(int *a, size_t size_a, int *b, size_t size_b);
void test_assert_strs(char * a, char * b);


#endif
