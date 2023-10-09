cmake_minimum_required(VERSION 3.10)
project(pa2-223)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE Debug)

file(GLOB_RECURSE SOURCES src/*.cpp)

foreach(SOURCE ${SOURCES})
    message("Found source file: ${SOURCE}")
endforeach()

add_executable(pa2 ${SOURCES})