# Eigen linear algebra template library

Eigen is an external (3rd party) linear algebra library that includes matrices, vectors, solvers, and algorithms.

## Installation on CCV
The `Eigen` package is available through the pyModules package manager on the CCV.  To load the library, you simply need to add the following line to your `.modules` file, or run it directly from the command line.

```
load eigen
```

To see the directory where Eigen include source files are located, you can run

```
show eigen
```

You will notice that the include directories are mapped to an environment variable `EIGEN3_INCLUDE_DIR`.  This variable can be used directly on the command line when building programs that include `Eigen` in the source file.

## Compiling programs with the Eigen library

The library may be invoked using the `-I` option directly from `g++`.

```
g++ -I ${EIGEN3_INCLUDE_DIR} main.cpp -o main
```

If you want to use the CMake build environment, you can add this include directory to your `CMakeLists.txt` file.

```
include_directories($EIGEN3_INCLUDE_DIR)
```

There is no need to link any libraries, as the Eigen library is built directly from the headers and source files.
