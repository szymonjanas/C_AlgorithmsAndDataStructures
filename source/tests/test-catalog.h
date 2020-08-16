#ifndef TEST_CATALOG
#define TEST_CATALOG

#include "test.h"
// #include "structures/Catalog/catalog.h"

void test_catalog() {

    test_scenario_begin("init catalog");

    // dict_n* head = getNew("Head directory");
    test_assert_strs("some sdsd!", "Some name!");

    test_scenarios_end();

}

#endif