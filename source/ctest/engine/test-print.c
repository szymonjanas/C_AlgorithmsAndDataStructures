#include "test-print.h"

const char * const padding_end          = " ";
const char * const padding_category     = "  ";
const char * const padding_scenario     = "      ";
const char * const padding_case         = "          ";
const char * const padding_case_details = "                ";

static int case_all = 0;
static int case_pass = 0;

static int scenario_all = 0;
static int scenario_pass = 0;
static int scenario_case_all = 0;
static int scenario_case_pass = 0;

static int category_all = 0;
static int category_pass = 0;
static int category_scenario_all = 0;
static int category_scenario_pass = 0;

/*
    ENABLE TESTING,
    SUMMARY OF TESTING ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
*/

void p_testing_begin()
{
    printf("%s", c_color(c_blue, "TESTING BEGIN!\n"));
}

void testing_end_summary()
{
    printf("%s", c_color(c_blue, "END TESTING!\n"));
    printf(c_color(c_blue, "case ------> [%i/%i]\n"), case_pass, case_all);
    printf(c_color(c_blue, "scenario --> [%i/%i]\n"), scenario_pass, scenario_all);
    printf(c_color(c_blue, "category --> [%i/%i]\n"), category_pass, category_all);

}

int p_testing_end()
{
    p_scenario_end();
    p_category_end();
    if (case_all - case_pass == 0)
    {
        printf(c_color(c_green_light, "%sAll tests passed! [%i/%i]\n"), padding_end, case_pass, case_all);
        printf(c_color(c_green_light, "%sAll scenario passed! [%i/%i]\n"), padding_end, scenario_pass, scenario_all);
        printf(c_color(c_green_light, "%sAll category passed! [%i/%i]\n"), padding_end, category_pass, category_all);
        testing_end_summary();
        return 0;
    }
    else
    {
        printf(c_color(c_red, "%sTests failed! [%i/%i]\n"), padding_end, case_all - case_pass, case_all);
        printf(c_color(c_red, "%sScenario failed! [%i/%i]\n"), padding_end, scenario_all - scenario_pass, scenario_all);
        printf(c_color(c_red, "%sCategory failed! [%i/%i]\n"), padding_end, category_all - category_pass, category_all);
        testing_end_summary();
        return 1;
    }
}

/*
    CASES MANAGEMENT ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
*/

void p_case_add()
{
    ++case_all;
    ++scenario_case_all;
    printf(c_color(c_cyan_light, "%s[%i|%i] CASE: "), padding_case, scenario_case_all, case_all);
}

void add_case_m(char *message)
{
    ++case_all;
    ++scenario_case_all;
    printf(c_color(c_cyan_light, "%s[%i|%i] %s CASE: "), padding_case, scenario_case_all, case_all, message);
}

void p_case_pass()
{
    ++case_pass;
    ++scenario_case_pass;
    printf("%s", c_color(c_green, "PASSED!\n"));
}

void p_case_failed()
{
    printf("%s", c_color(c_red, "FAILED!\n"));
}

void p_case_failed_msg(char *message)
{
    printf(c_color(c_red, "FAILED: %s\n"), message);
}

void p_case_failed_val_int(int a, int b)
{
    printf("%s", c_color(c_red, "FAILED!\n"));
    printf(c_color(c_red,"%sa: %i\n"), padding_case_details, a);
    printf(c_color(c_red, "%sb: %i\n"), padding_case_details, b);
}

void p_case_failed_strs(char *a, char *b)
{
    printf("%s", c_color(c_red, "FAILED!\n"));
    printf(c_color(c_red, "%sA: %s\n"), padding_case_details, a);
    printf(c_color(c_red, "%sB: %s\n"), padding_case_details, b);
}

/*
    SCENARIO MANAGEMENT ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
*/
static bool scenario = true;
void p_scenario_begin(const char *name)
{
    p_scenario_end();
    ++scenario_all;
    ++category_scenario_all;
    scenario = true;
    printf(c_color(c_cyan, "%s[%i] Scenario: "), padding_scenario, scenario_all);
    printf(c_color(c_cyan_light, "%s \n"), name);

}

void p_scenario_end()
{
    if (scenario_all != 0 && scenario)
    {
        if (scenario_case_all - scenario_case_pass == 0)
        {
            printf(c_color(c_green_light, "%sScenario passed! [%i/%i]\n"), padding_case, scenario_case_pass, scenario_case_all);
            ++scenario_pass;
            ++category_scenario_pass;
        }
        else
        {
            printf(c_color(c_red_light, "%sScenario [%i/%i] tests failed!\n"), padding_case, scenario_case_all - scenario_case_pass, scenario_case_all);
        }
    }
    scenario = false;
    scenario_case_all = 0;
    scenario_case_pass = 0;
}

/*
    CATEGORY MANAGEMENT ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
*/
static bool category = false;
void p_category_begin(const char *name)
{
    p_scenario_end();
    p_category_end();
    category = true;
    ++category_all;
    printf(c_color(c_magenta_light, "%s[%i] Category: %s\n"), padding_category, category_all, name);
}

void p_category_end()
{
    if (category_all != 0 && category)
    {
        if (category_scenario_all - category_scenario_pass == 0)
        {
            printf(c_color(c_green, "%sCategory passed! [%i/%i]\n"), padding_scenario, category_scenario_pass, category_scenario_all);
            ++category_pass;
        }
        else 
        {
            printf(c_color(c_red, "%sCategory [%i/%i] scenario failed!\n"), padding_scenario, category_scenario_all - category_scenario_pass, category_scenario_all);
        }
    }
    category = false;
    category_scenario_all = 0;
    category_scenario_pass = 0;
}
