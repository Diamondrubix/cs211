cmake_minimum_required(VERSION 3.8)
project(project7)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES GridDisplay.cpp GridDisplay.h GridMain.cpp creature.h creature.cpp doodlebug.h doodlebug.cpp ant.h dynamicList.h ant.cpp)
add_executable(project7 ${SOURCE_FILES})