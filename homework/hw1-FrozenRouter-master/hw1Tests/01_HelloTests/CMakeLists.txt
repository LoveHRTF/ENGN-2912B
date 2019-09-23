include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(01_runHW1HelloTests helloTests.cpp)

target_link_libraries(01_runHW1HelloTests hw1Q1Library gtest gtest_main )
