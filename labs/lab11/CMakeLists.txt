cmake_minimum_required(VERSION 3.8)
project(lab11)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Point2d.cpp Point2d.h lab11.cpp)
add_executable(lab11 ${SOURCE_FILES})