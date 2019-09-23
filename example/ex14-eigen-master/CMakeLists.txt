cmake_minimum_required (VERSION 3.2)

# compiler settings
set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_FLAGS "--std=c++11")

# add compiler flags
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -p -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")

project (ex14-eigen)

# point to Eigen include directories
include_directories($EIGEN3_INCLUDE_DIR)

# create the executable
add_executable(ex14 src/main.cpp)
