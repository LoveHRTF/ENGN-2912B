# Classroom examples from Lecture 10 - Preprocessor Directives and Templates

## Numerical integration using the Trapezoidal Rule
Integration can be numerically approximated by using a variety of methods.  One such method, used here, is the Trapezoidal Rule:

<img src="https://latex.codecogs.com/gif.latex?\int_{a}^{b}&space;f(x)&space;dx&space;\approx&space;\sum_{k=1}^{N}&space;\frac{f(x_{k-1})&plus;f(x_k)}{2}&space;\Delta&space;x_k" title="\int_{a}^{b} f(x) dx \approx \sum_{k=1}^{N} \frac{f(x_{k-1})+f(x_k)}{2} \Delta x_k" />

The Trapezoidal Rule is implemented in a function within [`main1.cpp`](./src/main1.cpp).  Generate the executable by following the standard CMake out-of-source build process.

### Generate executables using CMake
```
mkdir build
cd build
cmake ..
make
```

The `make` command will automatically build all target executables and libraries specified by the CMakeLists.txt file.  To build only the target executable you want, you can alternatively clean the build environment of all previously built executables and specify only the build target you want.

```
make clean
make ex10p1
```

`make help` lists all of the available targets that were written into the `Makefile` by CMake.

```
gaudetteje@macbookpro:~/Documents/src/cpp/ENGN2912B/examples/ex10/build$ make help
The following are some of the valid targets for this Makefile:
... all (the default if no target is provided)
... clean
... depend
... rebuild_cache
... edit_cache
... ex10p2
... ex10p1
... integrate
... lib/integrate.o
... lib/integrate.i
... lib/integrate.s
... src/main1.o
... src/main1.i
... src/main1.s
... src/main2.o
... src/main2.i
... src/main2.s
```

### Preprocessor Directives

You have already seen and used the most common preprocessor directive, `#include` in almost every C++ program you've written!  The `#include` directive tells the preprocessor to look for the specified source header file to include in the program.  Using angle brackets `<filename>` tells the preprocessor that this library can be found in the built-in C++ libraries, such as `<iostream>` or the legacy C-library functions `<cmath>` and `<cstdlib>`.  The `c` prepended to the library name clearly identifies this as a C-standard library.

It is worth noting that we could also specify the header file by it's name directly as `#include <math.h>` and yield similar results.  `<cmath>` is a C++ wrapper to the C library `math.h`.  `<cmath>` defines the math functions in the `std` namespace, whereas `<math.h>` has no such guarantees.

Alternatively, double quotations can be used to specify the header file (e.g., `#include "myLib.hxx"`).  This tells the compiler to search the current directory first, followed by any directories specified with `-I` during the compilation process.  If GCC cannot locate these files locally, it will search the standard `/usr/include` and `/usr/local/include` directories.

Another preprocessor directive, `#define`, is used in `main1.cpp` to define a preprocessor variable named `DEBUG`.  By commenting this line out, the programmer can explicitly suppress the debugging output because the compiler ignores any text between `#ifdef DEBUG` and `#endif`.  Excessive use of these directives can clutter the source code, so usage should be minimized for readability.  Nevertheless, these directives can be useful for quickly validating the program behavior when a debugger is overkill.

In `main1.cpp`, we are using function pointers to pass the test function (i.e., y1, y2) as the first parameter to `trapz()`.  Try swapping the function used in `main()` and validate the resulting output.  You can also use the optional command line parameters to validate the implementation with different integration step sizes.

```
./ex10p1
./ex10p1 -10 10 1000
```

### Using Function Templates

The `src/main1.cpp` function is strictly implemented using floats.  Suppose we wanted to use double data types instead.  How would we implement this?

Although we can replicate the same function for each and every combination of data types (using function overloading), it is a much better solution to use C++ Templates.  By using Function Templates, we only need to maintain one function implementation and check that the input data types and values are valid.

`src/main2.cpp` and `lib/integrate.hpp` moves the `trapz()` function to a static library and converts the signature with floats to a function template. To verify that a floating point type is used, we run an assertion check using the `<type_traits>` library for types T1 and T2.
