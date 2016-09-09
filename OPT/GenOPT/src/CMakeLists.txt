cmake_minimum_required(VERSION 3.5)
project(OPT_SRC)


set (HEADERS HillClimber.h ObjectiveFunction.h OPT_Process.h Particle.h PSO.h RandomSearch.h
        SinObjective.h RandObjective.h SaddleObjective.h ../../../SnapshotManager/SnapshotManager.h ../../../SnapshotManager/snapshot.h)
set(SOURCE_FILES HillClimber.cpp ObjectiveFunction.cpp OPT_Process.cpp Particle.cpp PSO.cpp RandomSearch.cpp
        SinObjective.cpp RandObjective.cpp SaddleObjective.cpp ../../../SnapshotManager/SnapshotManager.cpp ../../../SnapshotManager/snapshot.cpp)

add_library(OPT_SRC ${SOURCE_FILES})
target_link_libraries(OPT_SRC SnapshotManagerSRC)
#add_executable(OPT_exec main.cpp ${SOURCE_FILES})
#target_link_libraries(OPT_exec SnapshotManagerSRC)