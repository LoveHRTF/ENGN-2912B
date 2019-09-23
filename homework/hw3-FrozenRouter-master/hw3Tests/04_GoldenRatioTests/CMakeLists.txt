include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(04_runHW3GoldenRatioTests testGoldenRatio.cpp)

target_link_libraries(04_runHW3GoldenRatioTests hw3Q4Library gtest gtest_main)
