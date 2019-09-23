include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(01_runHW3ClassesTests testMatrix2x2.cpp)

target_link_libraries(01_runHW3ClassesTests hw3Q1Library gtest gtest_main)
