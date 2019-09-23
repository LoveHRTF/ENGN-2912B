cmake_minimum_required(VERSION 2.8)

project(hw2Library)

## Check for Windows ##
if (WIN32) # true if windows (32 and 64 bit)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x")
else ()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif ()


add_library(hw2Q1Library newtonRaphson.cpp newtonRaphson.h)
add_library(hw2Q2Library factorial.cpp factorial.h)


set_target_properties(hw2Q1Library PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(hw2Q2Library PROPERTIES LINKER_LANGUAGE CXX)
