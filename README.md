[![Build](https://github.com/Lqvrent/lololib/actions/workflows/build.yml/badge.svg?branch=main)](https://github.com/Lqvrent/lololib/actions/workflows/build.yml) [![Unit tests](https://github.com/Lqvrent/lololib/actions/workflows/unit_tests.yml/badge.svg?branch=main)](https://github.com/Lqvrent/lololib/actions/workflows/unit_tests.yml) [![Unit tests](https://img.shields.io/badge/Code%20Coverage-100%25-success?style=flat)](https://github.com/Lqvrent/lololib/actions/workflows/unit_tests.yml)
# lololib - Simple utilities library for C in UNIX systems
## Using the library
In the `template/` folder, you can see how to use the library to build a binary.<br />
You can also use the library in your project by adding the following lines to your CMakeLists.txt:
```cmake
include(FetchContent)
FetchContent_Declare(
    lololib
    GIT_REPOSITORY "https://github.com/Lqvrent/lololib.git"
    GIT_TAG "main" # can be a branch, a tag (like "1.0.0") or a commit
)
FetchContent_MakeAvailable(lololib)
target_link_libraries(${PROJECT_NAME} lolo)
target_include_directories(${PROJECT_NAME} PRIVATE ${lololib_SOURCE_DIR}/includes)
```
## Documentation
You can find the documentation [here](https://lqvrent.github.io/lololib/). <br />
You can also build it locally (with Doxygen) by running the following commands :
```bash
mkdir build && cd build
cmake -DBUILD_WITH_DOCS=ON ..
make docs # or mingw32-make docs, depending on your OS
```
## Todo list
- [x] Add the documentation on Github pages programmatically.
- [x] Make the library fetchable with CMake.
- [x] Internal
- [x] Errors
- [x] Strings
- [x] Linked lists
- [ ] Queues
- [ ] Stacks
- [ ] Trees
- [ ] Hash tables
- [ ] Graphs
