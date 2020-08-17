#ifndef TEST_ENGINE_PRINT
#define TEST_ENGINE_PRINT

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "color/color.h"

void p_testing_begin();
int  p_testing_end();

void p_scenario_begin(const char *name);
void p_scenario_end();

void p_category_begin(const char *name);
void p_category_end();

void p_case_add();

void p_case_pass();

void p_case_failed();
void p_case_failed_val_int(int a, int b);
void p_case_failed_msg(char *message);
void p_case_failed_arr(char *a, char *b);
void p_case_failed_strs(char *a, char *b);

#endif
