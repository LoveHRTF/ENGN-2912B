cmake_minimum_required(VERSION 2.8)

project(hw4Library)

## Check for Windows ##
if (WIN32) # true if windows (32 and 64 bit)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x")
else ()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif ()

add_library(hw4Q1Library analyzeTextFile.h analyzeTextFile.cpp)
add_library(hw4Q2Library pairs.h pairs.cpp)
add_library(hw4Q3Library estimatePiSeries.h estimatePiSeries.cpp estimatePiRecurrence.h estimatePiRecurrence.cpp)
add_library(hw4Q4Library Image.h Image.cpp ImageDenoiser.h ImageDenoiser.cpp)

set_target_properties(hw4Q1Library PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(hw4Q2Library PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(hw4Q3Library PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(hw4Q4Library PROPERTIES LINKER_LANGUAGE CXX)
