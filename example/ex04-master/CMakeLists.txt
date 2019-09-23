cmake_minimum_required (VERSION 3.2)

# compiler settings
set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_BUILD_TYPE Debug)

# create the project (must have a name)
project (Example04)


# add compiler flags
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -p -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")

add_executable(main main.cpp)
add_executable(main2 main2.cpp)
add_executable(main3 main3.cpp)
add_executable(main4 main4.cpp)
