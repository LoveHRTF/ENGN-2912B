include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(05_runHW3StringTests testStrings.cpp)

target_link_libraries(05_runHW3StringTests hw3Q5Library gtest gtest_main)
