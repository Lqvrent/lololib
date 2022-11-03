cmake_minimum_required(VERSION 3.20)
# Define project properties
set(PROJECT_VERSION "1.0.0")
set(PROJECT_NAME "lolo")
project(${PROJECT_NAME}
    VERSION ${PROJECT_VERSION}
    LANGUAGES C
    DESCRIPTION "Cross-platform utilities library for C"
)
set(CMAKE_C_STANDARD 11)

# To build shared libraries in Windows, we set CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS to TRUE.
# See https://cmake.org/cmake/help/v3.4/variable/CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS.html
# See https://blog.kitware.com/create-dlls-on-windows-without-declspec-using-new-cmake-export-all-feature/
if(WIN32)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
endif()

set(INCLUDES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/includes)
set(SOURCES_FILES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/sources)

# Define headers & sources, both to compile and install
set(PUBLIC_HEADERS
    "${INCLUDES_DIR}/lolo/error.h"
    "${INCLUDES_DIR}/lolo/internal.h"
    "${INCLUDES_DIR}/lolo/linkedlist.h"
    "${INCLUDES_DIR}/lolo/queue.h"
    "${INCLUDES_DIR}/lolo/stack.h"
    "${INCLUDES_DIR}/lolo/string.h"
)

set(SOURCES
    "${SOURCES_FILES_DIR}/error.c"
    "${SOURCES_FILES_DIR}/internal.c"
    "${SOURCES_FILES_DIR}/linkedlist.c"
    "${SOURCES_FILES_DIR}/queue.c"
    "${SOURCES_FILES_DIR}/stack.c"
    "${SOURCES_FILES_DIR}/string.c"
)

add_library(${PROJECT_NAME} SHARED ${SOURCES})

target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${INCLUDES_DIR}>
        $<INSTALL_INTERFACE:include>
    PRIVATE
        ${INCLUDES_PRIVATE}
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
    PUBLIC_HEADER "${PUBLIC_HEADERS}"
)

# Compiler options OS specific
if(${CMAKE_C_COMPILER_ID} STREQUAL "GNU")
    message(STATUS "Setting gcc flags")
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra)
elseif (${CMAKE_C_COMPILER_ID} STREQUAL "Clang" OR CMAKE_C_COMPILER_ID STREQUAL "AppleClang")
    message(STATUS "Setting clang flags")
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra)
elseif (${CMAKE_C_COMPILER_ID} STREQUAL "MSVC")
    message(STATUS "Setting MSVC flags")
    target_compile_options(${PROJECT_NAME} PRIVATE /EHsc /W2 /c)
    # Set the DLLEXPORT variable to export symbols
    target_compile_definitions(${PROJECT_NAME} PRIVATE WIN_EXPORT)
endif()

install(TARGETS ${PROJECT_NAME}
    EXPORT ${PROJECT_NAME}-target
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include/lolo
    PUBLIC_HEADER DESTINATION include/lolo
)

# Doxygen documentation.
OPTION(BUILD_WITH_DOCS "Generate Documentation" OFF)
IF(BUILD_WITH_DOCS)
    ADD_SUBDIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/docs)
ENDIF()
