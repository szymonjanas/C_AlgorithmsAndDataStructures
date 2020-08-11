#ifndef HEADER_FILE
#define HEADER_FILE

#include<stdio.h>
#include <stdbool.h>
#include <time.h>

void test_enable_testing();
void test_start_scenario(const char * name);
void test_end_scenarios();
bool test(bool condition);
bool testc(void *a, void *b);
void test_signal(const char * message);
void test_time_start(char * identifier);
void test_time_end();

#endif
