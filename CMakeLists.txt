cmake_minimum_required(VERSION 3.20)
# Define project properties
set(PROJECT_VERSION "1.0.0")
set(PROJECT_NAME "lolo")
project(${PROJECT_NAME}
    VERSION ${PROJECT_VERSION}
    LANGUAGES C
    DESCRIPTION "Cross-platform utilities library for C"
)

# To build shared libraries in Windows, we set CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS to TRUE.
# See https://cmake.org/cmake/help/v3.4/variable/CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS.html
# See https://blog.kitware.com/create-dlls-on-windows-without-declspec-using-new-cmake-export-all-feature/
if(WIN32)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
endif()

# Declare the library target.
add_library(${PROJECT_NAME} SHARED)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<INSTALL_INTERFACE:includes>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/includes>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/sources
)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION}
)

target_sources(${PROJECT_NAME}
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/sources/error.c"
        "${CMAKE_CURRENT_SOURCE_DIR}/sources/internal.c"
        "${CMAKE_CURRENT_SOURCE_DIR}/sources/linkedlist.c"
        "${CMAKE_CURRENT_SOURCE_DIR}/sources/string.c"
)

# Compiler options OS specific
if (${CMAKE_C_COMPILER_ID} STREQUAL "GNU")
    message(STATUS "Setting gcc flags")
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra)
elseif (${CMAKE_C_COMPILER_ID} STREQUAL "Clang")
    message(STATUS "Setting clang flags")
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra)
elseif (${CMAKE_C_COMPILER_ID} STREQUAL "MSVC")
    message(STATUS "Setting MSVC flags")
    target_compile_options(${PROJECT_NAME} PRIVATE /EHsc /W2 /c)
    # Set the DLLEXPORT variable to export symbols
    target_compile_definitions(${PROJECT_NAME} PRIVATE WIN_EXPORT)
endif()

# Install the library
install(TARGETS ${PROJECT_NAME}
    EXPORT ${PROJECT_NAME}-config
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)

# Doxygen documentation.
OPTION(BUILD_WITH_DOCS "Generate Documentation" ON)
IF(BUILD_WITH_DOCS)
    ADD_SUBDIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/docs)
ENDIF()
