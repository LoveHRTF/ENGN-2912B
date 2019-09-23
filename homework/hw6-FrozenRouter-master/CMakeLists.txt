cmake_minimum_required(VERSION 2.8)
project(hw6)

# add compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -p -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")

if(DEFINED ENV{TRAVIS})

  message(STATUS "Running on Travis CI")

  include_directories($ENV{PWD}/boost_1_63_0/include/)
  link_directories($ENV{PWD}/boost_1_63_0/lib/)

  # invoke library CMakeLists.txt
  include_directories(src)
  add_subdirectory(src)
  add_subdirectory(hw6Tests)

  # create the executable
  add_executable(hw6Q1Executable mainQ1.cpp)
  target_link_libraries(hw6Q1Executable hw6Q1Library boost_filesystem boost_system boost_regex boost_iostreams)

else ()

  message(STATUS "Running on CCV")
  find_package(Boost 1.63.0 COMPONENTS filesystem iostreams system)

  if(Boost_FOUND)
  	include_directories(${Boost_INCLUDE_DIRS})
  endif()

  # invoke library CMakeLists.txt
  include_directories(src)
  add_subdirectory(src)
  add_subdirectory(hw6Tests)

  # create the executable
  add_executable(hw6Q1Executable mainQ1.cpp)
  target_link_libraries(hw6Q1Executable hw6Q1Library ${Boost_LIBRARIES})

endif()
