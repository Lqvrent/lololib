# Specify the minimum version.
cmake_minimum_required(VERSION 3.20)

# Specify the project info.
project(lolo VERSION 1.0.0 DESCRIPTION "Simple utilities library for C in UNIX systems")

# Declare the library target.
add_library(${PROJECT_NAME} SHARED
    "source/internal.h"
    "source/internal.c"
    "source/error.h"
    "source/error.c"
    "source/string.h"
    "source/string.c"
)

# Set the version property.
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})

# Set the shared object version property to the project's major version.
set_target_properties(${PROJECT_NAME} PROPERTIES SOVERSION ${PROJECT_VERSION_MAJOR})

# Configure the directories to search for header files.
target_include_directories(${PROJECT_NAME} PRIVATE source)

# Set the public header property to the one with the actual API.
set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER
    "source/error.h;source/string.h"
)

# For access to standard installation directory variables (CMAKE_INSTALL_xDIR).
include(GNUInstallDirs)

# Set library shared object and API header file to install.
install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/lolo
)

find_package(Doxygen OPTIONAL_COMPONENTS dot)
if (DOXYGEN_FOUND)
    set(DOXYGEN_PROJECT_NAME "${PROJECT_NAME}lib")
    set(DOXYGEN_PROJECT_DESCRIPTION "${PROJECT_DESCRIPTION}")
    set(DOXYGEN_FULL_PATH_NAMES YES)
    set(DOXYGEN_FILE_PATTERNS *.h)
    set(DOXYGEN_RECURSIVE YES)
    set(DOXYGEN_GENERATE_TREEVIEW YES)
    set(DOXYGEN_UML_LOOK YES)
    doxygen_add_docs(doc
        "${CMAKE_CURRENT_LIST_DIR}/source"
    )
endif(DOXYGEN_FOUND)
