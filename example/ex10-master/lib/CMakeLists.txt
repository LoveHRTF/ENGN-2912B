cmake_minimum_required (VERSION 3.2)

# create the project
project (integrate)
add_library(integrate STATIC integrate.hpp integrate.cpp)
