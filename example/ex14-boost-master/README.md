# Boost portable C++ libraries

[Boost](https://www.boost.org/) is a collection of approximately 80 different libraries that have been extensively peer reviewed by the C++ community.  The goal of the Boost project is to provide a useful set of portable external libraries that are fully compatible with and extensions of the C++ Standard Library.  About 10 of the Boost libraries have actually been included into the C++ standard and implemented in recent compilers.  For example, in the C++11 standard, many libraries from Boost were included in the language standard (e.g., thread, random, regex, array, bind).

The following example demonstrates how to compile a program that uses Boost.Filesystem.  Note that this library was added to the C++17 standard, but the source code demonstrates how to build projects with Boost.

## Installation on CCV

Boost is available as a pyModules package on the CCV.  To load the library, add the following to a `.modules` file or run it directly from the command line.

```
load boost
```

The boost library contains all of the necessary include and source files to build your project at compile time.

## Compiling programs using g++ with the Boost library

Compiling your program with the Boost library is straightforward if you know the location of the files to be included and linked.  Using the `g++` command you would tell the compiler to include and link the boost libraries as follows:

```
g++ -I ${BOOST_INCLUDEDIR} -lboost_filesystem -lboost_system  main.cpp -o main
```

Note that Boost.Filesystem also requires the Boost.System library to work properly.

## Compiling programs using CMake with the Boost library
In order to use Boost with CMake, CMake must be able to locate library files.  To do so automatically, use the `find_package` command in your `CMakeLists.txt` file with the specific library components you want to include.  Then you can include the directories using the environment variable, as usual.

```
find_package(Boost 1.63.0 COMPONENTS filesystem iostreams system)
if(Boost_FOUND)
	include_directories(${Boost_INCLUDE_DIRS})
endif()
```

Next, after you create the executable, you must link your code to the libraries in your `CMakeLists.txt` file.

```
target_link_libraries(ex14 ${Boost_LIBRARIES})
```

CMake can also set various environmental variables so you can control the Boost library build process.  The following commands can be added to your `CMakeLists.txt` file and adapted to suit your needs.

```
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
```

