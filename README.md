[![Build](https://github.com/Lqvrent/lololib/actions/workflows/build.yml/badge.svg)](https://github.com/Lqvrent/lololib/actions/workflows/build.yml) [![Unit tests](https://github.com/Lqvrent/lololib/actions/workflows/unit_tests.yml/badge.svg)](https://github.com/Lqvrent/lololib/actions/workflows/unit_tests.yml) [![Unit tests](https://img.shields.io/badge/Code%20Coverage-45%25-yellow?style=flat)](https://github.com/Lqvrent/lololib/actions/workflows/unit_tests.yml)
# lololib - Simple utilities library for C in UNIX systems
### Download
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
The documentation is generated with Doxygen (You need to have it installed).<br />
After running cmake (like in the build part), run this command in your build directory :
```bash
make doc
```
In your build directory, you'll find a `html` folder, open the index.html file and you'll see the documentation.