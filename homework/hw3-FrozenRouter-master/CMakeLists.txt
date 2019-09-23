cmake_minimum_required(VERSION 2.8)
project(hw3)
##set(CMAKE_CXX_COMPILER "/usr/bin/g++")

## Check for Windows ##
if (WIN32)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x")
else ()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif ()

set(SOURCE_FILES main.cpp)

include_directories(src)
add_subdirectory(src)
add_subdirectory(hw3Tests)

add_executable(hw3Q1Executable mainQ1.cpp)
target_link_libraries(hw3Q1Executable hw3Q1Library)

add_executable(hw3Q2Executable mainQ2.cpp)
target_link_libraries(hw3Q2Executable hw3Q2Library)

add_executable(hw3Q3Executable mainQ3.cpp)
target_link_libraries(hw3Q3Executable hw3Q3Library)

add_executable(hw3Q4Executable mainQ4.cpp)
target_link_libraries(hw3Q4Executable hw3Q4Library)

add_executable(hw3Q5Executable mainQ5.cpp)
target_link_libraries(hw3Q5Executable hw3Q5Library)
