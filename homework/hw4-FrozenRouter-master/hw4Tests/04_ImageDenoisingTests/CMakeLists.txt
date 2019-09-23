include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(04_runHW4ImageDenoisingTests imageDenoisingTests.cpp)

target_link_libraries(04_runHW4ImageDenoisingTests hw4Q4Library gtest gtest_main )
