include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(02_runHW5RNGTests RNGTests.cpp)

target_link_libraries(02_runHW5RNGTests hw5Q2Library gtest gtest_main)
