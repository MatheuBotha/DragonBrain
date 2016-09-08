cmake_minimum_required(VERSION 3.6)

set(GRAPHICSENGINE_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

set(GRAPHICSENGINE_INCLUDE_DIR ${GRAPHICSENGINE_INCLUDE_DIR} PARENT_SCOPE)

if(TARGET GraphicsEngine)

    message("GRAPHICSENGINE is already defined")

else()

    include_directories(${GRAPHICSENGINE_INCLUDE_DIR})

    set(LIB_SRCS
            GLSLProgram.cpp
            GLSLProgram.h
            Errors.cpp
            Errors.h
            IOManager.cpp
            IOManager.h
            Window.cpp
            Window.h
            Camera2D.cpp
            Camera2D.h
            InputManager.cpp
            InputManager.h
            )

    add_library(GraphicsEngine STATIC ${LIB_SRCS})

endif()