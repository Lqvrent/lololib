# Specify the minimum version.
cmake_minimum_required(VERSION 3.20)
project(unit_tests)

FIND_PROGRAM(GCOV gcov)

set(PROJECT_ROOT "..")
set(SOURCE_ROOT "${PROJECT_ROOT}/source")

include_directories(
    "${PROJECT_ROOT}/source"
)

add_executable(unit_tests
    "${SOURCE_ROOT}/error.c"
    "error.c"
    "${SOURCE_ROOT}/internal.c"
    "internal.c"
    "${SOURCE_ROOT}/linkedlist.c"
    "linkedlist.c"
    "${SOURCE_ROOT}/string.c"
    "string.c"
)

if(CMAKE_COMPILER_IS_GNUCC)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fprofile-arcs -ftest-coverage --coverage")
endif() # CMAKE_COMPILER_IS_GNUCC

target_link_libraries(unit_tests
    criterion
)
