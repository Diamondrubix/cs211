cmake_minimum_required(VERSION 3.8)
project(lab10)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES lab10Main.cpp lab10List.cpp lab10List.h)
add_executable(lab10 ${SOURCE_FILES})