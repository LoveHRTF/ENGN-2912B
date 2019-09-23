cmake_minimum_required (VERSION 3.2)

# compiler settings
set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CONFIGURATION_TYPES "Debug;Release")

# create the project (must have a name)
project (ex06p2)

# create the library (using the CMakeLists.txt file found there)
add_subdirectory(lib)

# create the executable
add_executable(ex06p2
	src/main.cpp
	lib/fibonacci.hpp
)
target_include_directories(ex06p2 PUBLIC lib)
target_link_libraries(ex06p2 fibonacci)

install(TARGETS ex06p2 DESTINATION ~/bin)

