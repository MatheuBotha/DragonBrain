
add_executable(tester test.cpp test.cpp)

target_link_libraries(tester gtest gtest_main)
target_link_libraries(tester OPTSrc)