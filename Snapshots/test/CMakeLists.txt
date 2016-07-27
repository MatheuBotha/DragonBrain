add_executable(snapTester test.cpp test.cpp)


target_link_libraries(snapTester gtest gtest_main)
target_link_libraries(snapTester SnapshotSRC)