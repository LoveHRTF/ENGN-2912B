cmake_minimum_required (VERSION 3.2)

# create the project (must have a name)
project (ex22_threads)

# add compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -pg -Wall -std=c++11")
set(CMAKE_BUILD_TYPE "Debug")

# look for pthreads library
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

# create the executable
add_executable(main1 src/main1.cpp)
add_executable(main2 src/main2.cpp)
add_executable(main3 src/main3.cpp)
add_executable(main4 src/main4.cpp)

# link pthreads
target_link_libraries(main1 Threads::Threads)
target_link_libraries(main2 Threads::Threads)
target_link_libraries(main3 Threads::Threads)
target_link_libraries(main4 Threads::Threads)
