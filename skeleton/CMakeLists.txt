cmake_minimum_required(VERSION 3.9)
project(skeleton)

set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_STANDARD 11)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

message("${CMAKE_BUILD_TYPE}")

add_executable(skeleton src/main.c )
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories(include ${GLUT_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIRS})
target_link_libraries(skeleton ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})


