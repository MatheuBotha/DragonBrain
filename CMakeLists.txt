cmake_minimum_required(VERSION 3.5)
project(simpleOPT)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set (HEADERS HillClimber.h ObjectiveFunction.h OPT_Process.h Particle.h PSO.h RandomSearch.h SinObjective.h RandObjective.h SaddleObjective.h SnapshotManager.h snapshot.h)
set(SOURCE_FILES HillClimber.cpp ObjectiveFunction.cpp OPT_Process.cpp Particle.cpp PSO.cpp RandomSearch.cpp SinObjective.cpp RandObjective.cpp SaddleObjective.cpp SnapshotManager.cpp snapshot.cpp)
add_library(simpleOPT ${SOURCE_FILES})

add_executable(simpleOPTex main.cpp ${SOURCE_FILES})
add_subdirectory(gtest)
add_subdirectory(test)