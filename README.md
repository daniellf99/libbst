# Libbst

Libbst is a C library for creating and manipulating binary search trees.

## Building

The library is built using [CMake](https://cmake.org/).

To install `cmake` on Ubuntu:
* `sudo apt install cmake`

To build it, simply run `cmake CMakeLists.txt`.

## Documentation

The documentation needs to be generated with [Doxygen](https://www.doxygen.nl/index.html). To do so, first install `doxygen` in your machine.
In order to create graphs you will also need `graphviz`.

On Ubuntu:
* `sudo apt install doxygen graphviz`

On Windows:
see [this link](https://www.doxygen.nl/manual/install.html#install_bin_windows).

When installation is finished, run `doxygen docs/Doxyfile` in the repo's root directory.
After that, you should be able to find the index page (`index.html`) inside `docs/html/`.
