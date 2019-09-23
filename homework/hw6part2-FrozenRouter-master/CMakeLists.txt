cmake_minimum_required(VERSION 2.8)
project(hw6)

# add compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -p -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")

if(DEFINED ENV{TRAVIS})

  message(STATUS "Running on Travis CI")

  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D ARMA_DONT_USE_WRAPPER")
  execute_process(COMMAND bash "-c" "wget http://sourceforge.net/projects/arma/files/armadillo-9.200.4.tar.xz")
  execute_process(COMMAND bash "-c" "tar xvf armadillo-9.200.4.tar.xz")
  execute_process(COMMAND bash "-c" "rm -rf armadillo-9.200.4.tar.xz")
  include_directories(build/armadillo-9.200.4/include)

  # invoke library CMakeLists.txt
  include_directories(src)
  add_subdirectory(src)
  add_subdirectory(hw6Tests)

  # create the executable
  add_executable(hw6Q2Executable mainQ2.cpp)
  target_link_libraries(hw6Q2Executable hw6Q2Library openblas lapack)

else ()

  message(STATUS "Running on CCV")

  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D ARMA_DONT_USE_WRAPPER")
  execute_process(COMMAND bash "-c" "wget http://sourceforge.net/projects/arma/files/armadillo-9.200.4.tar.xz")
  execute_process(COMMAND bash "-c" "tar xvf armadillo-9.200.4.tar.xz")
  execute_process(COMMAND bash "-c" "rm -rf armadillo-9.200.4.tar.xz")
  include_directories(build/armadillo-9.200.4/include)

  # invoke library CMakeLists.txt
  include_directories(src)
  add_subdirectory(src)
  add_subdirectory(hw6Tests)

  # create the executable
  add_executable(hw6Q2Executable mainQ2.cpp)
  target_link_libraries(hw6Q2Executable hw6Q2Library openblas lapack)

endif()
