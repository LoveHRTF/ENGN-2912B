include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(02_runHW4PairsTests pairsTests.cpp)

target_link_libraries(02_runHW4PairsTests hw4Q2Library gtest gtest_main )
