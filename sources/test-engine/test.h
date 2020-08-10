#ifndef HEADER_FILE
#define HEADER_FILE

#include<stdio.h>
#include <stdbool.h>

void enable_testing();
bool test(bool condition);
bool testc(void *a, void *b);
void signal(const char * message);

#endif
