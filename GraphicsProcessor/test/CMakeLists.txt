cmake_minimum_required(VERSION 3.6)
project(GraphicsProcessorTest)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/GraphicsProcessor/cmake/modules/")

#Get all the necessary packages
find_package(OpenGL REQUIRED)
if (OPENGL_FOUND)
    include_directories(${OPENGL_INCLUDE_DIRS})
    link_libraries(${OPENGL_LIBRARIES})
endif()

find_package(GLEW REQUIRED)
if (GLEW_FOUND)
    include_directories(${GLEW_INCLUDE_DIRS})
    link_libraries(${GLEW_LIBRARIES})
endif()

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
if (SDL2_FOUND)
    include_directories(${SDL2_INCLUDE_DIRS})
    link_libraries(${SDL2_LIBRARIES})
endif()

PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
if (SDL2IMAGE_FOUND)
    include_directories(${SDL2IMAGE_INCLUDE_DIRS})
    link_libraries(${SDL2IMAGE_LIBRARIES})
endif()

find_package(SOIL REQUIRED)
if (SOIL_FOUND)
    include_directories(${SOIL_INCLUDE_DIRS})
    link_libraries(${SOIL_LIBRARIES})
endif()

find_package(Freetype REQUIRED)
include_directories(${FREETYPE_INCLUDE_DIRS})
link_libraries(${FREETYPE_LIBRARIES})


set(SOURCE_FILES

        main.cpp

        ../Engine/Debug.cpp

        ../Engine/Engine.cpp

        ../Engine/Window.cpp

        ../Engine/IOManager.cpp

        ../Engine/GLSLProgram.cpp

        ../Engine/Errors.cpp

        ../Engine/Cube.cpp

        ../Engine/Sphere.cpp
        ../Engine/Sphere2.cpp

        ../Engine/Landscape2D.cpp

        ../Engine/Camera.h

        ../GraphicsProcessor.cpp
        ../GraphicsProcessor.h

        ../Engine/Mesh.cpp
        ../Engine/Mesh.h

        ../Engine/Texture.cpp
        ../Engine/Texture.h

        ../Engine/ParticleSystem.cpp
        ../Engine/ParticleSystem.h

        ../Engine/BoundingBox.cpp
        ../Engine/BoundingBox.h

        ../Engine/SkyBox.cpp
        ../Engine/SkyBox.h

        ../Engine/Timer.cpp
        ../Engine/Timer.h

        ../Engine/TextRenderer.cpp
        ../Engine/TextRenderer.h

        ../../OPT/GenOPT/src/ObjectiveFunction.h
        ../../OPT/GenOPT/src/SaddleObjective.cpp
        ../../OPT/GenOPT/src/SinObjective.cpp
        ../../OPT/GenOPT/src/AckleyObjective.cpp
        ../../SettingsPackage/src/problemdomainsettingspackage.cpp
        ../../OPT/GenOPT/src/WeierstrassObjective.cpp
        ../../OPT/GenOPT/src/QuadricObjective.cpp
        ../../OPT/GenOPT/src/HillClimber.cpp
        ../../OPT/GenOPT/src/ElitistHillClimber.cpp
        ../../OPT/GenOPT/src/OPT_Process.cpp
        ../../SnapshotManager/SnapshotManager.cpp
        ../../SnapshotManager/snapshot.cpp
        ../../OPT/GenOPT/src/RosenbrockObjective.cpp
        )
add_executable(GraphicsProcessorTest ${SOURCE_FILES})

add_custom_command(TARGET GraphicsProcessorTest POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/GraphicsProcessor/Shaders $<TARGET_FILE_DIR:GraphicsProcessorTest>/Shaders)

add_custom_command(TARGET GraphicsProcessorTest POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/GraphicsProcessor/Textures $<TARGET_FILE_DIR:GraphicsProcessorTest>/Textures)

add_custom_command(TARGET GraphicsProcessorTest POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/GraphicsProcessor/Fonts $<TARGET_FILE_DIR:GraphicsProcessorTest>/Fonts)