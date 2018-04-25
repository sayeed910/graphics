cmake_minimum_required(VERSION 3.5)
project(halftone)

set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_FLAGS "-std=c99")

add_executable(halftone src/main.c)
include_directories(include)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )
target_link_libraries(halftone ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} m)

