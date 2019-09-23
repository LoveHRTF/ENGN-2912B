include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(02_runHW6ANCTests ANCTests.cpp)

if(DEFINED ENV{TRAVIS})

  target_link_libraries(02_runHW6ANCTests hw6Q2Library gtest gtest_main openblas lapack)

else ()

target_link_libraries(02_runHW6ANCTests hw6Q2Library gtest gtest_main openblas lapack)

endif()
