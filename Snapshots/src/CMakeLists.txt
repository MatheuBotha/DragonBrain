cmake_minimum_required(VERSION 3.5)
project(SnapshotSRC)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        ../../OPT/src/Particle.h
        snapshot.cpp
        snapshot.h
        SnapshotManager.cpp
        SnapshotManager.h)

add_library(SnapshotSRC ${SOURCE_FILES})