[![Build](https://github.com/Lqvrent/lololib/actions/workflows/build.yml/badge.svg)](https://github.com/Lqvrent/lololib/actions/workflows/build.yml) [![Unit tests](https://github.com/Lqvrent/lololib/actions/workflows/unit_tests.yml/badge.svg)](https://github.com/Lqvrent/lololib/actions/workflows/unit_tests.yml) [![Unit tests](https://img.shields.io/badge/Code%20Coverage-100%25-success?style=flat)](https://github.com/Lqvrent/lololib/actions/workflows/unit_tests.yml)
# lololib - Simple utilities library for C in UNIX systems
## Download
You can download the latest version in the releases section of the [Github repository](https://github.com/Lqvrent/lololib/releases).<br />
If you're mad enough to use the source code, you can do so by cloning the repository.

## Building and installing
The library needs to be compile with CMake.<br />
If you're new to CMake, heres the commands to get you started:
```bash
mkdir build
cd build
cmake ..
make
```
You can also install the library with the following command :
```bash
make install
```
Here you go !

## Documentation
You can find the documentation [here](https://lqvrent.github.io/lololib/). <br />
If you need informations about something really new (which is not online), you can build the documentation with the following command (once you have runned cmake) in your build folder :
```bash
make doc
```
The documentation is generated with Doxygen (You need to have it installed).<br />

## Todo list
- [ ] Add the documentation on Github pages programmatically.
- [x] Internal
- [x] Errors
- [ ] Strings (working on it)
- [ ] Linked lists
- [ ] Stack
- [ ] Queue
