cmake_minimum_required(VERSION 2.8)

project(hw6Library)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_library(hw6Q2Library anc.h anc.cpp)

set_target_properties(hw6Q2Library PROPERTIES LINKER_LANGUAGE CXX)
