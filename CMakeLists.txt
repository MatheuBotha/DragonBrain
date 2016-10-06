cmake_minimum_required(VERSION 3.5)
project(SwarmViz)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

add_subdirectory(GUI)
add_subdirectory(SettingsPackage)
add_subdirectory(gtest)
add_subdirectory(OPT)
add_subdirectory(SnapshotManager)
add_subdirectory(GraphicsProcessor)
add_subdirectory(GraphicsProcessorMK2_old)

add_executable(SwarmViz main.cpp  Manager.cpp Manager.h)
target_link_libraries(SwarmViz SettingsPackageSRC)
target_link_libraries(SwarmViz OPT_SRC)
target_link_libraries(SwarmViz GUI_SRC)
target_link_libraries(SwarmViz SnapshotManagerSRC)
target_link_libraries(SwarmViz GraphicsProcessor)