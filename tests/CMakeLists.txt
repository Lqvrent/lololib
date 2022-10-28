cmake_minimum_required(VERSION 3.20)
# Define project properties
set(PROJECT_NAME "unit_tests")
project(${PROJECT_NAME} LANGUAGES C)
FIND_PROGRAM(GCOV gcov)

add_executable(${PROJECT_NAME})

# add include directories
target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../includes
)

target_sources(${PROJECT_NAME}
    PRIVATE
        "../sources/error.c"
        "../tests/error.c"
        "../sources/internal.c"
        "../tests/internal.c"
        "../sources/linkedlist.c"
        "../tests/linkedlist.c"
        "../sources/string.c"
        "../tests/string.c"
)

if(CMAKE_COMPILER_IS_GNUCC)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fprofile-arcs -ftest-coverage --coverage")
endif() # CMAKE_COMPILER_IS_GNUCC

target_link_libraries(${PROJECT_NAME}
    criterion
)
