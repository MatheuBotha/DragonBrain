cmake_minimum_required(VERSION 3.3)

project(SwarmViz)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")


add_subdirectory(SettingsPackage)
add_subdirectory(gtest)