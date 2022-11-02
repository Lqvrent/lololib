[![Build](https://github.com/Lqvrent/lololib/actions/workflows/build.yml/badge.svg?branch=main)](https://github.com/Lqvrent/lololib/actions/workflows/build.yml) [![Unit tests](https://github.com/Lqvrent/lololib/actions/workflows/unit_tests.yml/badge.svg?branch=main)](https://github.com/Lqvrent/lololib/actions/workflows/unit_tests.yml) [![Unit tests](https://img.shields.io/badge/Code%20Coverage-100%25-success?style=flat)](https://github.com/Lqvrent/lololib/actions/workflows/unit_tests.yml)
# lololib - Cross-platform multi-purposes library for C
## ⚙️ Usage
In the `template/` folder, you can see how to use the library to build a binary.<br />
You can also use the library in your project by adding the following lines to your `CMakeLists.txt`:
```cmake
include(FetchContent)
FetchContent_Declare(
    lololib
    GIT_REPOSITORY "https://github.com/Lqvrent/lololib.git"
    GIT_TAG "1.0.0" # can be a branch, a tag or a commit
)
FetchContent_MakeAvailable(lololib)
target_link_libraries(${PROJECT_NAME} lolo)
target_include_directories(${PROJECT_NAME} PRIVATE ${lololib_SOURCE_DIR}/includes)
```
## 📚 Documentation
You can find the documentation [here](https://lqvrent.github.io/lololib/). <br />
You can also build it locally (with Doxygen) by running the following commands :
```bash
mkdir build && cd build
cmake -DBUILD_WITH_DOCS=ON ..
make docs # or mingw32-make docs, depending if you're on Windows
```
## 🎯 Roadmap
- [x] Add unit tests
- [x] Add the documentation on Github pages programmatically.
- [x] Make the library cross-platform.
- [x] Make the library fetchable with CMake.
- [x] Internal
- [x] Errors
- [x] Strings
- [x] Linked lists
- [x] `v1.0.0` Release 🚀
- [x] Now that a release is out, features MUST be written in issues and PRs.
- [x] Queues
- [ ] Stacks
- [ ] Graphs
- [ ] Maps
- [ ] Path
- [ ] Filesystem
- [ ] `v1.1.0` Release 🚀
- [ ] Threads (cross-platform !)
- [ ] Networking - Client (cross-platform !)
- [ ] Networking - Server (cross-platform !)
- [ ] `v2.0.0` Release 🚀
- [ ] And more ! (If you have any ideas, feel free to open an issue, I don't bite and more importantly, I don't know what to do next !)
## 🤝 Contributing
If you want to modify the library, you can do so by following these steps:<br />
**1.** Fork the repository.<br />
**2.** Create a new branch.<br />
**3.** Make your changes.<br />
**4.** Create a pull request.<br /><br />
If you want to add a new feature, please open an issue first to discuss it.

## 📜 License
This project is licensed under the `MIT` License. See the [LICENSE](/LICENSE) file for details.
