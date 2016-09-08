cmake_minimum_required(VERSION 3.6)

message("STARTING")

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



#add_subdirectory(./GraphicsEngine GraphicsEngine)
#include_directories(${GRAPHICSENGINE_INCLUDE_DIR})

#Include Graphics Library


set(SOURCE_FILES
        main.cpp
        GraphicsProcessor.cpp
        )

add_executable(GraphicsProcessor ${SOURCE_FILES})
target_link_libraries(GraphicsProcessor)

#add_custom_command(TARGET GraphicsProcessor POST_BUILD
#        COMMAND ${CMAKE_COMMAND} -E copy_directory
#        ${CMAKE_SOURCE_DIR}/shaders $<TARGET_FILE_DIR:GraphicsProcessor>/shaders)
