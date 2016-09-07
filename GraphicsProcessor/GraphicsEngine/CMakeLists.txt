cmake_minimum_required(VERSION 3.6)

set(GRAPHICSENGINE_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

set(GRAPHICSENGINE_INCLUDE_DIR ${GRAPHICSENGINE_INCLUDE_DIR} PARENT_SCOPE)

if(TARGET GraphicsEngine)

    message("GRAPHICSENGINE is already defined")

else()

    include_directories(${GRAPHICSENGINE_INCLUDE_DIR})

    set(LIBRARY_SOURCES

            GLSLProgram.cpp
            GLSLProgram.h

            Errors.cpp
            Errors.h

            IOManager.cpp
            IOManager.h
            )

    add_library(GraphicsEngine STATIC ${LIBRARY_SOURCES})

endif()