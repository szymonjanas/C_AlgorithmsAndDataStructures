cmake_minimum_required (VERSION 3.7)

project (caads) 

include_directories(source)
include_directories(source/color/)
include_directories(dependencies/ctest/include)
link_directories(dependencies/ctest/source)

set(TEST_SRC
    source/main.c
    source/algorithms/Array/find.c
    source/algorithms/Array/modify.c
    source/structures/List/IntList.c
    source/structures/Catalog/catalog.c
)

add_executable(${PROJECT_NAME} ${TEST_SRC})
target_link_libraries(${PROJECT_NAME} ctest)
