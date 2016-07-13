cmake_minimum_required(VERSION 3.5)
project(OpenGL)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_definitions(-DGLEW_STATIC)

include_directories(${PROJECT_SOURCE_DIR}/GLFW/include)
include_directories(${PROJECT_SOURCE_DIR}/GLEW/include)

link_directories(${PROJECT_SOURCE_DIR}/GLFW/lib)
link_directories(${PROJECT_SOURCE_DIR}/GLEW/lib)

set(SOURCE_FILES main.cpp)
add_executable(OpenGL ${SOURCE_FILES})

target_link_libraries(OpenGL glfw3 glew32s opengl32)