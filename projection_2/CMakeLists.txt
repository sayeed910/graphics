cmake_minimum_required(VERSION 2.5)
project(rotation)

set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_FLAGS "-std=c99")

add_executable(projection src/main.c src/projection.c )
include_directories(include)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )
target_link_libraries(projection ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} m)

