include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(03_runHW3TranslationTests testTranslation.cpp)

target_link_libraries(03_runHW3TranslationTests hw3Q3Library gtest gtest_main)
