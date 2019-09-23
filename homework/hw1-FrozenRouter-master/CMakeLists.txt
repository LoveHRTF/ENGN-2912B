cmake_minimum_required(VERSION 2.8)
project(hw1)

## Check for Windows ##
if (WIN32) # true if windows (32 and 64 bit)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x")
else ()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif ()

include_directories(src)
add_subdirectory(src)
add_subdirectory(hw1Tests)

add_executable(hw1Q1Executable mainQ1.cpp)
target_link_libraries(hw1Q1Executable hw1Q1Library)

add_executable(hw1Q2Executable mainQ2.cpp)
target_link_libraries(hw1Q2Executable hw1Q2Library)











