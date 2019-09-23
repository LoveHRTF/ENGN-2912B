cmake_minimum_required(VERSION 2.8)

project(hw1Library)

## Check for Windows ##
if (WIN32) # true if windows (32 and 64 bit)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x")
else ()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif ()


add_library(hw1Q1Library hello.h hello.cpp)
add_library(hw1Q2Library sumIntegers.h sumIntegers.cpp)


set_target_properties(hw1Q1Library PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(hw1Q2Library PROPERTIES LINKER_LANGUAGE CXX)
