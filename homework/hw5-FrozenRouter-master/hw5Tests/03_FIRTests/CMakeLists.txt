include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(03_runHW5FIRTests FIRTests.cpp)

target_link_libraries(03_runHW5FIRTests hw5Q3Library gtest gtest_main)
