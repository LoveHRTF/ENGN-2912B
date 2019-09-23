# Gnuplot graphics plotting utility

Gnuplot is a powerful plotting utility for 2D and 3D graphics.  Many typical plot types available in MATLAB or Python can be replicated using Gnuplot.  By itself, however, Gnuplot is a standalone program and cannot interface directly with a C++ program.

## Gnuplot-iostream interface library

Several 3rd party projects have been created as solutions to use gnuplot as a simple, easy-to-use plotting tool that accepts C++ vectors and multi-dimensional data types.  This is where the gnuplot-iostream library comes into play.

The iostream interface uses the `<<` operator to pass data and commands directly to an instance of a Gnuplot object.  Two working examples are found in the `src` directory that were adopted from the author's web page.

## Compiling programs with the Gnuplot-iostream interface

To build a program that includes this support, simply copy the "gnuplot-iostream.h" file from the project's GitHub repository.  Place this file in your directory and make sure that it can be found by the compiler.  If you place the file in a separate folder, you will need to include this directory.

Gnuplot-iostream uses Boost and therefore requires including Boost's iostreams, filesystem, and system libraries.  Using the instructions from the examples in [ex14-boost](https://github.com/ENGN2912B-2018/ex14-boost), you should be able to compile the program.
