CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

project(SwarmVis)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")


add_subdirectory(Snapshots)
add_subdirectory(gtest)
