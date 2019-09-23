include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runBasicHW1Tests ../basicTests/basicCheck.cpp)

##linking
target_link_libraries(runBasicHW1Tests gtest gtest_main)

