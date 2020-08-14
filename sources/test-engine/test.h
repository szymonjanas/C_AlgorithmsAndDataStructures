#ifndef TEST_ENGINE
#define TEST_ENGINE

#include<stdio.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

void test_enable_testing();
void test_start_scenario(const char * name);
void test_end_scenarios();
bool test(bool condition);
bool testc(void *a, void *b);
bool testIntArr(int *a, size_t size_a, int *b, size_t size_b);
void test_signal(const char * message);
void test_time_start(char * identifier);
void test_time_end();

#endif
