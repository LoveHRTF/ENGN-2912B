include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(02_runHW2FactorialTests factorialTests.cpp)

target_link_libraries(02_runHW2FactorialTests hw2Q2Library gtest gtest_main )
