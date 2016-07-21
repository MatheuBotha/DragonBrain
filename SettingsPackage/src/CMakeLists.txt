project(SettingsPackageSRC)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_INCLUDE_CURRENT_DIR ON)


set (HEADERS graphicssettingspackage.h optimizersettingspackage.h
        problemdomainsettingspackage.h)
set (SRC graphicssettingspackage.cpp optimizersettingspackage.cpp
        problemdomainsettingspackage.cpp settingspackage.cpp)



add_library(SettingsPackageSRC ${SRC} ${HEADERS})
