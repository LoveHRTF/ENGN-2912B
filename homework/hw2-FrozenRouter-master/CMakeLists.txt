cmake_minimum_required(VERSION 2.8)
project(hw2)

## Check for Windows ##
if (WIN32) # true if windows (32 and 64 bit)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x")
else ()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif ()

include_directories(src)
add_subdirectory(src)
add_subdirectory(hw2Tests)

add_executable(hw2Q1Executable mainQ1.cpp)
target_link_libraries(hw2Q1Executable hw2Q1Library)

add_executable(hw2Q2Executable mainQ2.cpp)
target_link_libraries(hw2Q2Executable hw2Q2Library)





