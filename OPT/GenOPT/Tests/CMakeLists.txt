
add_executable(tester test.cpp test.cpp testParticle.cpp testParticle.h)

target_link_libraries(tester gtest gtest_main)
target_link_libraries(tester OPTSrc)