cmake_minimum_required(VERSION 3.6)
project(simpleOPT)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

set (HEADERS HillClimber.h ObjectiveFunction.h OPT_Process.h Particle.h PSO.h RandomSearch.h SinObjective.h RandObjective.h SaddleObjective.h SnapshotManager.h snapshot.h FIPS.h GCPSO.h CPSO.h AckleyObjective.h)
set(SOURCE_FILES HillClimber.cpp ObjectiveFunction.cpp OPT_Process.cpp Particle.cpp PSO.cpp RandomSearch.cpp SinObjective.cpp RandObjective.cpp SaddleObjective.cpp SnapshotManager.cpp snapshot.cpp FIPS.cpp GCPSO.cpp CPSO.cpp AckleyObjective.cpp)
add_library(simpleOPT ${SOURCE_FILES})

add_executable(simpleOPTex main.cpp ${SOURCE_FILES})
add_subdirectory(gtest)
add_subdirectory(test)