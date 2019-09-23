include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(01_runHW4TextFileAnalysisTests textFileAnalysisTests.cpp)

target_link_libraries(01_runHW4TextFileAnalysisTests hw4Q1Library gtest gtest_main )
