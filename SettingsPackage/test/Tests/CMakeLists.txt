add_executable(setTester test.cpp test.cpp)

target_link_libraries(setTester gtest gtest_main)
target_link_libraries(setTester SettingsPackageSRC)