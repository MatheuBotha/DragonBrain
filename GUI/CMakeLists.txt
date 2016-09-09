project(GUI_SRC)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR  ON)

set (SRC Interface.cpp)




find_package(Qt5 COMPONENTS Quick Core Network)
qt5_add_resources(RES qml.qrc)

add_executable(GUI_SRC ${SRC} ${RES})
target_link_libraries(GUI_SRC Qt5::Quick Qt5::Core Qt5::Network)
target_link_libraries(GUI_SRC SettingsPackageSRC)