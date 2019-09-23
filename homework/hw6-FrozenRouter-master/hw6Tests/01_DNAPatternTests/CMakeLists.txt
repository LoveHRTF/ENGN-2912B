include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(01_runHW6DNAPatternTests DNAPatternTests.cpp)

if(DEFINED ENV{TRAVIS})

  target_link_libraries(01_runHW6DNAPatternTests hw6Q1Library gtest gtest_main boost_filesystem boost_system boost_regex boost_iostreams)

else ()

target_link_libraries(01_runHW6DNAPatternTests hw6Q1Library gtest gtest_main ${Boost_LIBRARIES})

endif()
