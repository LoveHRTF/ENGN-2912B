cmake_minimum_required(VERSION 2.8)

project(hw5Library)

## Check for Windows ##
if (WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x")
else ()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif ()

add_library(hw5Q1Library Matrix.h Matrix.cpp)
add_library(hw5Q2Library RNG.h RNG.cpp)
add_library(hw5Q3Library firFilter.h firFilter.cpp)

set_target_properties(hw5Q1Library PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(hw5Q2Library PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(hw5Q3Library PROPERTIES LINKER_LANGUAGE CXX)
