include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(03_runHW4PiTests piTests.cpp)

target_link_libraries(03_runHW4PiTests hw4Q3Library gtest gtest_main)
