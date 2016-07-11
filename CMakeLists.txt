cmake_minimum_required(VERSION 3.5)
project(DragonBrain)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    .idea/DragonBrain.iml
    .idea/misc.xml
    .idea/modules.xml
    .idea/vcs.xml
    .idea/workspace.xml
    .gitignore
    main.cpp)

add_executable(DragonBrain ${SOURCE_FILES})