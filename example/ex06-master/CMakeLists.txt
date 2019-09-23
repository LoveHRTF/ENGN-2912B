cmake_minimum_required (VERSION 3.2)

# compiler settings
set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CONFIGURATION_TYPES "Debug;Release")


# create the project (must have a name)
project (ex06_exceptions)

message("\nAvailable build configuration types:  ${CMAKE_CONFIGURATION_TYPES}")
message("Set the config type by using CMake flag \"CMAKE_BUILD_TYPE\":")
message("  cmake -DCMAKE_BUILD_TYPE=Debug\n")

# add compiler flags
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -p -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")

include_directories(src)
add_executable(ex06 src/main.cpp)
install(TARGETS ex06 DESTINATION ~/bin)

