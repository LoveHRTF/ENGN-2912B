cmake_minimum_required(VERSION 2.8)
project(hw5)
##set(CMAKE_CXX_COMPILER "/usr/bin/g++")

## Check for Windows ##
if (WIN32)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x")
else ()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif ()

include_directories(src)
add_subdirectory(src)
add_subdirectory(hw5Tests)

add_executable(hw5Q1Executable mainQ1.cpp)
target_link_libraries(hw5Q1Executable hw5Q1Library)

add_executable(hw5Q2Executable mainQ2.cpp)
target_link_libraries(hw5Q2Executable hw5Q2Library)

add_executable(hw5Q3Executable mainQ3.cpp)
target_link_libraries(hw5Q3Executable hw5Q3Library)
