cmake_minimum_required(VERSION 3.5)

project(SwarmViz)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")
add_subdirectory(SettingsPackage)
add_subdirectory(gtest)
add_subdirectory(GUI)