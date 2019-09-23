cmake_minimum_required(VERSION 2.8)

project(hw3Library)

## Check for Windows ##
if (WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x")
else ()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif ()

add_library(hw3Q1Library Matrix2x2.h Matrix2x2.cpp)
add_library(hw3Q2Library AbstractOdeSolver.h AbstractOdeSolver.cpp ForwardEulerSolver.h ForwardEulerSolver.cpp RungeKuttaSolver.h RungeKuttaSolver.cpp)
add_library(hw3Q3Library translation.h translation.cpp)
add_library(hw3Q4Library fibonacci.h fibonacci.cpp estimategoldenratio.h estimategoldenratio.cpp)
add_library(hw3Q5Library concat.h concat.cpp substr.h substr.cpp erase.h erase.cpp)

set_target_properties(hw3Q1Library PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(hw3Q2Library PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(hw3Q3Library PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(hw3Q4Library PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(hw3Q5Library PROPERTIES LINKER_LANGUAGE CXX)