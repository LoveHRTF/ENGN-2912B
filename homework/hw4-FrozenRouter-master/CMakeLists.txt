cmake_minimum_required(VERSION 2.8)
project(hw4)

## Check for Windows ##
if (WIN32) # true if windows (32 and 64 bit)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x")
else ()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif ()

include_directories(src)
add_subdirectory(src)
add_subdirectory(hw4Tests)

add_executable(hw4Q1Executable mainQ1.cpp)
target_link_libraries(hw4Q1Executable hw4Q1Library)

add_executable(hw4Q2Executable mainQ2.cpp)
target_link_libraries(hw4Q2Executable hw4Q2Library)

add_executable(hw4Q3Executable mainQ3.cpp)
target_link_libraries(hw4Q3Executable hw4Q3Library)

add_executable(hw4Q4Executable mainQ4.cpp)
target_link_libraries(hw4Q4Executable hw4Q4Library)
