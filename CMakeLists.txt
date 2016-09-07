cmake_minimum_required(VERSION 3.6)
project(DragonBrain)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#add_subdirectory(GraphicsProcessor)

set(SOURCE_FILES
        main.cpp
        GraphicsProcessor/GraphicsProcessor.cpp

        shader_utils.cpp
        )

add_executable(DragonBrain ${SOURCE_FILES})
target_link_libraries(DragonBrain glew32 opengl32)