cmake_minimum_required (VERSION 3.7)

project (caads) 

include_directories(sources)

set(TEST_SRC
    sources/main.c
    sources/test-engine/test.c
    sources/Array/find.c
)

add_executable(${PROJECT_NAME} ${TEST_SRC})
