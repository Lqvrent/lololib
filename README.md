[![Build](https://github.com/Lqvrent/lololib/actions/workflows/build.yml/badge.svg?branch=main)](https://github.com/Lqvrent/lololib/actions/workflows/build.yml) [![Unit tests](https://github.com/Lqvrent/lololib/actions/workflows/unit_tests.yml/badge.svg?branch=main)](https://github.com/Lqvrent/lololib/actions/workflows/unit_tests.yml) [![Unit tests](https://img.shields.io/badge/Code%20Coverage-100%25-success?style=flat)](https://github.com/Lqvrent/lololib/actions/workflows/unit_tests.yml)
# lololib - Simple utilities library for C in UNIX systems
## Download
You can download the latest version in the releases section of the [Github repository](https://github.com/Lqvrent/lololib/releases).<br />
If you're mad enough to use the source code, you can do so by cloning the repository.

## UNIX Systems : Compile and install
We assume that you got dome devs dependencies installed (like CMake, make, gcc..)<br />
You can compile the library and installing it by running the following commands in the root directory of the project:
```bash
mkdir build && cd build
cmake ..
make
make install # You may need to run this command as root
```
## Windows : Compile and install
We assume that you got dome devs dependencies installed (like CMake, mingw32-make, mingw..)<br />
You can compile the library and installing it by running the following commands in the root directory of the project:
```bash
mkdir build && cd build
cmake -G "MinGW Makefiles" ..
mingw32-make
mingw32-make install
```
## Documentation
You can find the documentation [here](https://lqvrent.github.io/lololib/). <br /><br />
You can also build it locally (with Doxygen) by running the following commands :
```bash
mkdir build && cd build
cmake -DBUILD_WITH_DOCS=ON ..
make docs # or mingw32-make docs, depending on your OS
```
## Todo list
- [x] Add the documentation on Github pages programmatically.
- [x] Internal
- [x] Errors
- [x] Strings
- [ ] Regular linked lists (working on it !)
- [ ] Doubly linked lists
- [ ] Circular linked lists
