project(SettingsPackageSRC)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR  ON)


set (HEADERS graphicssettingspackage.h optimizersettingspackage.h
        problemdomainsettingspackage.h)
set (SRC graphicssettingspackage.cpp optimizersettingspackage.cpp
        problemdomainsettingspackage.cpp settingspackage.cpp)

find_package(Qt5 COMPONENTS Widgets)

add_library(SettingsPackageSRC ${HEADERS} ${SRC})
target_link_libraries(SettingsPackageSRC Qt5::Widgets)