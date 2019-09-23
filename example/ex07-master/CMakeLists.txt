cmake_minimum_required (VERSION 3.2.2)

project (PointClass)

set(CMAKE_BUILD_TYPE Debug)

# define library location
add_library(Points
	inc/libPoints/points.hpp
	inc/libPoints/points.cpp
)
target_include_directories(Points PUBLIC inc/libPoints)

# create the executable file
add_executable (main src/main.cpp)
target_link_libraries (main Points)

# create install rules
#install (TARGETS main DESTINATION bin)
#install (FILES "${PROJECT_BINARY_DIR)/

