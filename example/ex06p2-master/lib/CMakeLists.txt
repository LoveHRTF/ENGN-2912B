cmake_minimum_required (VERSION 3.2)

# create the project (must have a name)
project (libfibonacci)

add_library(fibonacci STATIC fibonacci.hpp fibonacci.cpp)
#add_library(fibonacci SHARED fibonacci.hpp fibonacci.cpp)

install(TARGETS fibonacci DESTINATION ~/lib)
install(FILES fibonacci.hpp DESTINATION ~/inc)

