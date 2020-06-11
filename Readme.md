# Companion source code for "Effizienterer Code mit Fold Expressions"


[![Build Status](https://github.com/andreasfertig/heise-2020-04-cpp-tricks-fold-expressions/workflows/ci/badge.svg)](https://github.com/andreasfertig/heise-2020-04-cpp-tricks-fold-expressions/actions/) [![License](https://img.shields.io/badge/license-MIT-blue.svg)](/LICENSE.txt) 


## Code examples

This repository contains runnable source code examples from the article [Effizienterer Code mit Fold Expressions](https://www.heise.de/select/ix/2020/4), by [Andreas Fertig](https://andreasfertig.info).

### The layout of the examples

Each example is located in a dedicated directory based on how it appears in the article. Sometimes an example appears more than once. This is usually when it is shown in pieces in the article. In this case, only the first occurrence of an example is kept. Later occurrences are represented by a text-file naming the initial occurrence.

### Running the examples

The examples are each contained in a single `.cpp` file that can be easily compiled and executed. There is also an `CMakeLists.txt` which can generate IDE projects or used to compile the examples in a terminal. 
This repo contains a top-level `CMakeLists.txt` which builds all the examples. 

### Building the examples

You can select the compiler by setting the `CXX` environment variable.

```
mkdir heise-2020-04-cpp-tricks-fold-expressions
cd heise-2020-04-cpp-tricks-fold-expressions
git clone https://github.com/andreasfertig/heise-2020-04-cpp-tricks-fold-expressions
mkdir build
cd build
cmake ../
cmake --build . -j
```

After that you find all the executables in `heise-2020-04-cpp-tricks-fold-expressions/build/bin`.

Some of these examples use the latest C++ standard, so you will need a modern compiler to compile them. The latest stable versions of [GCC](https://gcc.gnu.org/releases.html) or [Clang](https://releases.llvm.org) are recommended.

## Submitting Issues / PRs

I appreciate pull requests which fix errors, or issues which point them out as long as it is about the code. For feedback on the article itself, please write me an email. This repository is about the code only.


## License

The source code is released under the [MIT License](/LICENSE.txt).

