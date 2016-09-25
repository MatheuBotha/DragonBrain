cmake_minimum_required(VERSION 3.5)
project(OPT_SRC)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11 -pthread")

set (OBJECTIVES_H ObjectiveFunction.h SinObjective.h SaddleObjective.h)
set (OBJECTIVES_SRC ObjectiveFunction.cpp SinObjective.cpp SaddleObjective.cpp)
set (HEADERS HillClimber.h  OPT_Process.h Particle.h PSO.h RandomSearch.h
       CPSO.h     ../../../SnapshotManager/SnapshotManager.h ../../../SnapshotManager/snapshot.h FIPS.h)

set(SOURCE_FILES HillClimber.cpp OPT_Process.cpp Particle.cpp PSO.cpp RandomSearch.cpp
        CPSO.cpp ../../../SnapshotManager/SnapshotManager.cpp ../../../SnapshotManager/snapshot.cpp FIPS.cpp)

add_library(OPT_SRC ${SOURCE_FILES} ${HEADERS} ${OBJECTIVES_H} ${OBJECTIVES_SRC})
target_link_libraries(OPT_SRC SnapshotManagerSRC)
#add_executable(OPT_exec main.cpp ${SOURCE_FILES} ${OBJECTIVES_H} ${OBJECTIVES_SRC})
#target_link_libraries(OPT_exec SnapshotManagerSRC)