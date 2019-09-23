include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(01_runHW5TemplatedMatrixTests TemplatedMatrixTests.cpp)

target_link_libraries(01_runHW5TemplatedMatrixTests hw5Q1Library gtest gtest_main)
