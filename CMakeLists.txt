cmake_minimum_required (VERSION 3.7)

project (caads) 

include_directories(source)
include_directories(source/color/)
include_directories(source/test-engine/)

set(TEST_SRC
    source/main.c
    source/test-engine/test.c
    source/color/color.c
    source/test-engine/engine/test-helper.c
    source/test-engine/engine/test-print.c
    source/algorithms/Array/find.c
    source/structures/List/IntList.c
    source/structures/Catalog/catalog.c
)

add_executable(${PROJECT_NAME} ${TEST_SRC})
