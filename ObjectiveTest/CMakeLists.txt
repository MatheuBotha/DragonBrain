cmake_minimum_required(VERSION 3.6)
project(ObjectiveTest)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp ObjectiveFunction.cpp SinObjective.cpp SaddleObjective.cpp AlpineObjective.cpp AlpineObjective.h BealeObjective.cpp BealeObjective.h BohachevskyObjective.cpp BohachevskyObjective.h EggHolderObjective.cpp EggHolderObjective.h GoldSteinPriceObjective.cpp GoldSteinPriceObjective.h GriewankObjective.cpp GriewankObjective.h Levy13Objective.cpp Levy13Objective.h Michalewicz.cpp Michalewicz.h PathologicalObjective.cpp PathologicalObjective.h QuadricObjective.cpp QuadricObjective.h QuarticObjective.cpp QuarticObjective.h RanaObjective.cpp RanaObjective.h RastriginObjective.cpp RastriginObjective.h RosenbrockObjective.cpp RosenbrockObjective.h SalomonObjective.cpp SalomonObjective.h Schwefel22Objective.cpp Schwefel22Objective.h Schwefel26Objective.cpp Schwefel26Objective.h SixHumpCamelBackObjective.cpp SixHumpCamelBackObjective.h SkewRastriginObjective.cpp SkewRastriginObjective.h SphericalObjective.cpp SphericalObjective.h StepObjective.cpp StepObjective.h WeierstrassObjective.cpp WeierstrassObjective.h ZakharovObjective.cpp ZakharovObjective.h AckleyObjective.cpp AckleyObjective.h)

add_executable(ObjectiveTest ${SOURCE_FILES})