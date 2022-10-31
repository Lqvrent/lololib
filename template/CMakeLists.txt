cmake_minimum_required(VERSION 3.20)
# Define project properties
set(PROJECT_VERSION "1.0.0")
set(PROJECT_NAME "myenv")
project(${PROJECT_NAME}
    VERSION ${PROJECT_VERSION}
    LANGUAGES C
    DESCRIPTION "Pretty print environment variables"
)
set(CMAKE_C_STANDARD 11)

# Define source files
set(SOURCES
    "sources/main.c"
)

# Define includes directory
include_directories("includes")

# Add an executable to build
add_executable(${PROJECT_NAME} ${SOURCES})

# Fetch, install and link lololib to the project
include(FetchContent)
FetchContent_Declare(
    lololib
    GIT_REPOSITORY "https://github.com/Lqvrent/lololib.git"
    GIT_TAG "1.0.0" # can be a branch, a tag or a commit
)
FetchContent_MakeAvailable(lololib)
target_link_libraries(${PROJECT_NAME} lolo)
target_include_directories(${PROJECT_NAME} PRIVATE ${lololib_SOURCE_DIR}/includes) # lololib headers are not installed locally, so we need to add the includes directory to the project

# Make the executable installable
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
