project(OPTSrc)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set (HEADERS GenOPT.h Manager.h CPSO.h DummyFunction.h FIPS.h GCPSO.h graphicssettingspackage.h HillClimber.h
        ObjectiveFunction.h OPT_Process.h optimizersettingspackage.h Particle.h problemdomainsettingspackage.h
        PSO.h RandomSearch.h settingspackage.h SnapshotManager.h)
set (SRC GenOPT.cpp Manager.cpp CPSO.cpp DummyFunction.cpp FIPS.cpp GCPSO.cpp graphicssettingspackage.cpp HillClimber.cpp
        ObjectiveFunction.cpp OPT_Process.cpp optimizersettingspackage.cpp Particle.cpp problemdomainsettingspackage.cpp
        PSO.cpp RandomSearch.cpp settingspackage.cpp SnapshotManager.cpp)

add_library(OPTSrc ${SRC} ${HEADERS})