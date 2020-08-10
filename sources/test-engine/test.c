#include "test.h"

static bool enable = false;
static int allTests = 0;
static int passed = 0;

void enable_testing() 
{
    printf("\033[38;5;8mTESTING ENABLED!\033[0m \n");
    enable = true;
}

void end_testing()
{
    printf("\033[38;5;8mEND TESTING!\n    all tests: %i\n    passed: %i\033[0m \n", allTests, passed);
    if (allTests - passed == 0) printf("\033[38;5;2mAll tests passed! [%i/%i]\033[0m \n", passed, allTests);
    else printf("\033[38;5;9mTests failed! [%i/%i]\033[0m \n", allTests-passed, allTests);
}

bool test(bool condition) 
{
    if (!enable) return false;
    ++allTests;
    if (condition){
        ++passed;
        printf("\033[38;5;2m    [%i] TEST PASSED! \033[0m \n", allTests);
    }
    else 
        printf("\033[38;5;9m    [%i] TEST FAILED! \033[0m \n", allTests);
    
    return condition;
}

void signal(const char * message) 
{
    if (!enable) return;
    printf("\033[38;5;99m      MESSAGE: %s \033[0m \n", message);
}

bool testc(void *a, void *b)
{
    if (!enable) return false;
    ++allTests;
    if (a == b){
        ++passed;
        printf("\033[38;5;2m    [%i] TEST PASSED! \033[0m \n", allTests);
    }
    else 
        printf("\033[38;5;9m    [%i] TEST FAILED! expected: %i, got: %i \033[0m \n", allTests, a, b);
    
    return a == b;
}

