cmake_minimum_required(VERSION 3.8)
project(project6)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp dynamicArray.h airport.cpp airport.h myNode.h myNode.cpp)
add_executable(project6 ${SOURCE_FILES})