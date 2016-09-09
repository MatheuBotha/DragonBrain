cmake_minimum_required(VERSION 3.5)
project(SnapshotManagerSRC)


set (HEADERS SnapshotManager.h snapshot.h ../OPT/GenOPT/src/Particle.h)
set(SOURCE_FILES SnapshotManager.cpp snapshot.cpp ../OPT/GenOPT/src/Particle.cpp)
add_library(SnapshotManagerSRC ${SOURCE_FILES})
