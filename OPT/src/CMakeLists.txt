cmake_minimum_required(VERSION 3.5)
project(OPT_SRC)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11 -pthread")

set (HEADERS HillClimber.h  OPT_Process.h Particle.h PSO.h RandomSearch.h
       CPSO.h     ../../SnapshotManager/SnapshotManager.h ../../SnapshotManager/snapshot.h FIPS.h GCPSO.h
        )

set(SOURCE_FILES HillClimber.cpp OPT_Process.cpp Particle.cpp PSO.cpp RandomSearch.cpp
        CPSO.cpp ../../SnapshotManager/SnapshotManager.cpp ../../SnapshotManager/snapshot.cpp FIPS.cpp GCPSO.cpp
        ../../Objectives/AlpineObjective.cpp ../../Objectives/AlpineObjective.h ../../Objectives/BealeObjective.cpp ../../Objectives/BealeObjective.h ../../Objectives/BohachevskyObjective.cpp
BohachevskyObjective.h ../../Objectives/EggHolderObjective.cpp ../../Objectives/EggHolderObjective.h ../../Objectives/GoldSteinPriceObjective.cpp
GoldSteinPriceObjective.h ../../Objectives/GriewankObjective.cpp ../../Objectives/GriewankObjective.h ../../Objectives/Levy13Objective.cpp ../../Objectives/Levy13Objective.h
Michalewicz.cpp ../../Objectives/Michalewicz.h ../../Objectives/PathologicalObjective.cpp ../../Objectives/PathologicalObjective.h ../../Objectives/QuadricObjective.cpp
QuadricObjective.h ../../Objectives/QuarticObjective.cpp ../../Objectives/QuarticObjective.h ../../Objectives/RanaObjective.cpp ../../Objectives/RanaObjective.h
RastriginObjective.cpp ../../Objectives/RastriginObjective.h ../../Objectives/RosenbrockObjective.cpp ../../Objectives/RosenbrockObjective.h ../../Objectives/SalomonObjective.cpp
SalomonObjective.h ../../Objectives/Schwefel22Objective.cpp ../../Objectives/Schwefel22Objective.h ../../Objectives/Schwefel26Objective.cpp ../../Objectives/Schwefel26Objective.h
SixHumpCamelBackObjective.cpp ../../Objectives/SixHumpCamelBackObjective.h ../../Objectives/SkewRastriginObjective.cpp ../../Objectives/SkewRastriginObjective.h
SphericalObjective.cpp ../../Objectives/SphericalObjective.h ../../Objectives/StepObjective.cpp ../../Objectives/StepObjective.h ../../Objectives/WeierstrassObjective.cpp
WeierstrassObjective.h ../../Objectives/ZakharovObjective.cpp ../../Objectives/ZakharovObjective.h ../../Objectives/AckleyObjective.cpp ../../Objectives/AckleyObjective.h
        )

add_library(OPT_SRC ${SOURCE_FILES} ${HEADERS})
target_link_libraries(OPT_SRC SnapshotManagerSRC OBJECTIVES_SRC)
#add_executable(OPT_exec main.cpp ${SOURCE_FILES} ${OBJECTIVES_H} ${OBJECTIVES_SRC})
#target_link_libraries(OPT_exec SnapshotManagerSRC)