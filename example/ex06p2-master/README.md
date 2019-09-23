# Classroom examples from Lectures 06 - Part 2

This example shows how to separate multiple functions into a separate library.  Libraries can be statically or dynamically linked.

## Generate a statically linked library

Functions referenced by a program to a statically linked library are resolved at compile time.  In Linux, static libraries contain the name `lib<name>.a`.  In Windows, static libraries are named `<name>.lib`.

To build both the main executable and static library, run the following commands:

```
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make
```

The files will be build in `build` and `build/lib`.  The `ex06p2` program can then be installed on the system path by running `make install`.  At compile time, the machine code from the static library is essentially copied into the binary executable `ex06p2`.

Note that per our instructions in `lib/CMakeLists.txt` this will also copy the header file `fibonacci.hpp` to `~/inc` and the shared library `libfibonacci.a` to `~/lib`.

We can also build the library as a standalone unit, without creating any executable program (generally, you would want to build a comprehensive suite of unit and functional tests for your library).  To build this static library, run the following commands from the main directory:

```
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ../lib
make
```

If we wish to deploy our library to other programmers, we can provide these two library files (`libfibonacci.a` and `fibonacci.hpp`) and perhaps the source code example `main.cpp` showing how to use it.

## Generate a dynamically linked library

Another option for building an application that uses a library is to use a dynamically linked library.  In Linux, dynamic libraries are named `lib<name>.so` where the `.so` extention stands for Shared Object.  In Windows, dynamic libraries are named `<name>.dll` for Dynamically Linked Library.

Dynamic libraries are required to deploy along with the binary executable that references functions within that library.  This is because a dynamically linked function is not copied inside the executable, like in the statically linked case.  Instead, the executable is referenced to a specific location within that .so or .dll file where the function's machine code resides.  In this manner, many different executables can be built upon a common dynamic library file without replicating the source code for each executable being built.

To create a dynamically linked library with CMake, simply change `STATIC` to `SHARED` in the function `add_library()`.  You may then build the project as before in the static library case.  In order to "see" the functions and objects provided within a shared object library, you can use the `nm` command as follows from the `build` directory.

```
nm -D --demangle lib/libfibonacci.so
```

If an executable is built with a dynamic library, the dependencies (i.e., required libraries) can be viewed by using the `ldd` command.  This command will show that libfibonacci.so is required by the executable in order to run.

```
ldd ex06p2
```

For a more complete description of shared libraries in Linux, refer to [tldp.org](http://tldp.org/HOWTO/Program-Library-HOWTO/shared-libraries.html, "The Linux Documentation Project").

You can also look at any Linux machine and browse the folders `/usr/lib` to see a listing of numerous shared object (i.e., dynamically linked) libraries and `/usr/include` to see various header files and associated static libraries.
