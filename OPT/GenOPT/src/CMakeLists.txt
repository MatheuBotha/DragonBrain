cmake_minimum_required(VERSION 3.5)
project(OPT_SRC)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11 -pthread")

set (OBJECTIVES_H ObjectiveFunction.h SinObjective.h SaddleObjective.h)
set (OBJECTIVES_SRC ObjectiveFunction.cpp SinObjective.cpp SaddleObjective.cpp)
set (HEADERS HillClimber.h  OPT_Process.h Particle.h PSO.h RandomSearch.h
       CPSO.h     ../../../SnapshotManager/SnapshotManager.h ../../../SnapshotManager/snapshot.h FIPS.h GCPSO.h
        )

set(SOURCE_FILES HillClimber.cpp OPT_Process.cpp Particle.cpp PSO.cpp RandomSearch.cpp
        CPSO.cpp ../../../SnapshotManager/SnapshotManager.cpp ../../../SnapshotManager/snapshot.cpp FIPS.cpp GCPSO.cpp
        AlpineObjective.cpp AlpineObjective.h BealeObjective.cpp BealeObjective.h BohachevskyObjective.cpp
        BohachevskyObjective.h EggHolderObjective.cpp EggHolderObjective.h GoldSteinPriceObjective.cpp
        GoldSteinPriceObjective.h GriewankObjective.cpp GriewankObjective.h Levy13Objective.cpp Levy13Objective.h
        Michalewicz.cpp Michalewicz.h PathologicalObjective.cpp PathologicalObjective.h QuadricObjective.cpp
        QuadricObjective.h QuarticObjective.cpp QuarticObjective.h RanaObjective.cpp RanaObjective.h
        RastriginObjective.cpp RastriginObjective.h RosenbrockObjective.cpp RosenbrockObjective.h SalomonObjective.cpp
        SalomonObjective.h Schwefel22Objective.cpp Schwefel22Objective.h Schwefel26Objective.cpp Schwefel26Objective.h
        SixHumpCamelBackObjective.cpp SixHumpCamelBackObjective.h SkewRastriginObjective.cpp SkewRastriginObjective.h
        SphericalObjective.cpp SphericalObjective.h StepObjective.cpp StepObjective.h WeierstrassObjective.cpp
        WeierstrassObjective.h ZakharovObjective.cpp ZakharovObjective.h AckleyObjective.cpp AckleyObjective.h
        ElitistHillClimber.cpp ElitistHillClimber.h GeneticAlgorithm.cpp GeneticAlgorithm.h)

add_library(OPT_SRC ${SOURCE_FILES} ${HEADERS} ${OBJECTIVES_H} ${OBJECTIVES_SRC})
target_link_libraries(OPT_SRC SnapshotManagerSRC)
#add_executable(OPT_exec main.cpp ${SOURCE_FILES} ${OBJECTIVES_H} ${OBJECTIVES_SRC})
#target_link_libraries(OPT_exec SnapshotManagerSRC)