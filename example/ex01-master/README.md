# Classroom examples from Lecture 01

The following are the build commands used to demonstrate compiling C++ code examples.  These lines should be executed on the Linux shell with the GNU Compiler Collection (GCC) installed.

## simple g++ usage, creates a.out
`g++ main.cpp`

## specify output name
`g++ main.cpp -o main`

## iostream - cout
`g++ main2.cpp -o main`

## iostream - namespace
`g++ main3.cpp -o main`

## iostream - cin
`g++ main4.cpp -o main`

## g++, not gcc!
`gcc main4.cpp -o main`

## specify optimization parameters
`g++ -O3 main4.cpp -o main`

## specify debugging parameters
`g++ -g main4.cpp -o main`

## show syntax and library errors (omit ';' and '#include <iostream>'
`g++ main4.cpp -o main`
