#include "test.h"

static bool enable = false;
static int allTests = 0;
static int passed = 0;
static int scenarioCurrentTests = 0;
static int scenarioPassTests = 0;
static int allScenario = 0;
static int passedScenario = 0;

const char * const red = "[0;31m";
const char * const boldRed = "[1;31m";
const char * const green = "[0;32m";
const char * const boldGreen = "[1;32m";
const char * const yellow = "[0;33m";
const char * const boldYellow = "[01;33m";
const char * const blue = "[0;34m";
const char * const boldBlue = "[1;34m";
const char * const magenta = "[0;35m";
const char * const boldMagenta = "[1;35m";
const char * const cyan = "[0;36m";
const char * const boldCyan = "[1;36m";
const char * const reset = "[0m";	
const char * const esc = "\033";

char * color(const char * const colorName, const char * message)
{
    char * out = (char *) malloc (3 + strlen(colorName) + strlen(message) + strlen(reset));
    strcpy(out, esc);
    strcat(out, colorName);
    strcat(out, message);
    strcat(out, esc);
    strcat(out, reset);
    return out;
}

void enable_testing() 
{
    printf(color(blue,"TESTING ENABLED!\n"));
    enable = true;
}

void end_testing()
{
    if (allTests - passed == 0) printf(color(boldGreen, "All tests passed! [%i/%i]\nAll scenario passed! [%i/%i]\n"), passed, allTests, passedScenario, allScenario);
    else printf(color(boldRed, "Tests failed! [%i/%i]\nScenario failed! [%i/%i]\n"), allTests-passed, allTests, allScenario-passedScenario, allScenario);
    printf(color(blue, "END TESTING!\n    all tests: %i\n    passed: %i\n    all scenario: %i\n    passed scenario: %i\n"), allTests, passed, allScenario, passedScenario);
}

static clock_t t;
static double cpu_time_used;
static char * time_id;
void test_time_start(char * identifier)
{    
    time_id = identifier;
    t = clock();
}

void test_time_end()
{
     t = clock() - t;
     cpu_time_used = ((double)t) / CLOCKS_PER_SEC;
     printf(color(magenta, "[%s] execution time: %f\n"), time_id, cpu_time_used);
}

void test_end_scenario()
{
    if (allScenario != 0){
        if (scenarioCurrentTests - scenarioPassTests == 0){
            printf(color(green, "   Scenario all test passed! [%i/%i]\n"), scenarioPassTests, scenarioCurrentTests);
            ++passedScenario;
        } else {
            printf(color(red, "   Scenario tests failed! [%i/%i]\n"), scenarioPassTests, scenarioCurrentTests);
        }
    } 
    scenarioCurrentTests = 0;
    scenarioPassTests = 0;
}

void test_start_scenario(const char * name)
{
    test_end_scenario();
    ++allScenario;
    printf(color(yellow, " [%i] Scenario: %s \n"), allScenario, name);
}


void test_end_scenarios()
{
    test_end_scenario();
}

void test_add()
{
    ++allTests;
    ++scenarioCurrentTests;
}

void test_passed()
{
    ++passed;
    ++scenarioPassTests;
    printf(color(green, "      [%i|%i] TEST PASSED!\n"), scenarioCurrentTests, allTests);
}

void test_failed()
{
    printf(color(red, "      [%i|%i] TEST FAILED! \n"), scenarioCurrentTests, allTests);
}

void test_failed_values(void * a, void * b)
{
    printf(color(red, "    [%i|%i] TEST FAILED! got: %i, expected: %i \n"), scenarioCurrentTests, allTests, a, b);
}

void test_failed_strs(void * a, void * b)
{
    printf(color(red, "    [%i|%i] TEST FAILED!\n             got: %s\n"), scenarioCurrentTests, allTests, a);
    printf(color(red, "        expected: %s\n"), b);
}

bool test(bool condition) 
{
    if (!enable) return false;
    test_add();
    if (condition)
        test_passed();
    else 
    
    return condition;
}

void test_signal(const char * message) 
{
    if (!enable) return;
    printf(color(magenta,"     TEST SIGNAL: %s \n"), message);
}

bool testc(void *a, void *b)
{
    if (!enable) return false;
    test_add();
    if (a == b)
        test_passed();
    else 
        test_failed_values(a, b);    
    return a == b;
}

char* arr_to_string(int *arr, size_t size)
{
    if (size == 0 || arr == NULL) return NULL;
    char * str = (char*) malloc (sizeof(char)*size*2+2);
    strcpy(str, "[");
    char num[16];
    for (int i = 0; i < size; ++i){
        sprintf(num, "%i", *(arr+i));
        strcat(str, num);
        if (i < size-1) strcat(str, ",");
    }
    strcat(str, "]");
    return str;
}

bool testIntArr(int *a, size_t size_a, int *b, size_t size_b)
{
    if (!enable) return false;
    test_add();
    if (size_a != size_b) return false;
    if (size_a == 0 || size_b == 0) return true;
    for (int i = 0; i < size_a; ++i){
        if (*(a+i) != *(b+i)){
            test_failed_strs(   arr_to_string(a, size_a),
                                arr_to_string(b, size_b));
            return false;
        } 
    }
    test_passed();
    return true;
}
