add_executable(demoTester test.cpp test.cpp)

target_link_libraries(demoTester gtest gtest_main)
target_link_libraries(demoTester simpleOPT)