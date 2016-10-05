cmake_minimum_required(VERSION 3.3)

project(OBJECTIVES_SRC)

set(SOURCE_FILES 
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
        )

add_library(OBJECTIVES_SRC ${SOURCE_FILES})