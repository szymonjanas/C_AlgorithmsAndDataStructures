#include "test.h"
// #include "tests/test-array.h"
// #include "tests/test-list.h"
#include "tests/test-catalog.h"
int main(){

    test_testing_begin();
    // test_array();
    // test_IntList();
    test_catalog();
    return test_testing_end();
}
