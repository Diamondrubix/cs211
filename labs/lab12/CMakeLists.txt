cmake_minimum_required(VERSION 3.8)
project(lab12)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES tinytest.h Point2d.h Point2d.cpp Point2dTest.cpp dynamicArray.h)
add_executable(lab12 ${SOURCE_FILES})