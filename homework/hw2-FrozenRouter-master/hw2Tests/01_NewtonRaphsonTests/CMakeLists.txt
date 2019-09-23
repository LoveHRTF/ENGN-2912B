include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(01_runHW2NewtonRaphsonTests newtonRaphsonTests.cpp)

target_link_libraries(01_runHW2NewtonRaphsonTests hw2Q1Library gtest gtest_main )
