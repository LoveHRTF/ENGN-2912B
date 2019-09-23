cmake_minimum_required (VERSION 3.2)

# compiler settings
set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_FLAGS "--std=c++11")

# add compiler flags
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -p -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")

project (ex14-boost)

#set(Boost_USE_STATIC_LIBS OFF)
#set(Boost_USE_MULTITHREADED ON)
#set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.63.0 COMPONENTS filesystem iostreams system)

if(Boost_FOUND)
	include_directories(${Boost_INCLUDE_DIRS})
endif()

# create the executable
add_executable(ex14 src/main.cpp)
target_link_libraries(ex14 ${Boost_LIBRARIES})

