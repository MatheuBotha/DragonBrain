cmake_minimum_required(VERSION 3.5)
project(SnapshotManagerSRC)


set (HEADERS SnapshotManager.h snapshot.h ../OPT/src/Particle.h)
set(SOURCE_FILES SnapshotManager.cpp snapshot.cpp ../OPT/src/Particle.cpp)
add_library(SnapshotManagerSRC ${SOURCE_FILES})
