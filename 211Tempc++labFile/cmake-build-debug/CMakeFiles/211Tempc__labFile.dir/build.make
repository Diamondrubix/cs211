# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/diamondrubix/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/172.4343.16/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/diamondrubix/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/172.4343.16/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/diamondrubix/CLionProjects/cs 211/211Tempc++labFile"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/diamondrubix/CLionProjects/cs 211/211Tempc++labFile/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/211Tempc__labFile.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/211Tempc__labFile.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/211Tempc__labFile.dir/flags.make

CMakeFiles/211Tempc__labFile.dir/main.cpp.o: CMakeFiles/211Tempc__labFile.dir/flags.make
CMakeFiles/211Tempc__labFile.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/diamondrubix/CLionProjects/cs 211/211Tempc++labFile/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/211Tempc__labFile.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/211Tempc__labFile.dir/main.cpp.o -c "/home/diamondrubix/CLionProjects/cs 211/211Tempc++labFile/main.cpp"

CMakeFiles/211Tempc__labFile.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/211Tempc__labFile.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/diamondrubix/CLionProjects/cs 211/211Tempc++labFile/main.cpp" > CMakeFiles/211Tempc__labFile.dir/main.cpp.i

CMakeFiles/211Tempc__labFile.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/211Tempc__labFile.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/diamondrubix/CLionProjects/cs 211/211Tempc++labFile/main.cpp" -o CMakeFiles/211Tempc__labFile.dir/main.cpp.s

CMakeFiles/211Tempc__labFile.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/211Tempc__labFile.dir/main.cpp.o.requires

CMakeFiles/211Tempc__labFile.dir/main.cpp.o.provides: CMakeFiles/211Tempc__labFile.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/211Tempc__labFile.dir/build.make CMakeFiles/211Tempc__labFile.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/211Tempc__labFile.dir/main.cpp.o.provides

CMakeFiles/211Tempc__labFile.dir/main.cpp.o.provides.build: CMakeFiles/211Tempc__labFile.dir/main.cpp.o


# Object files for target 211Tempc__labFile
211Tempc__labFile_OBJECTS = \
"CMakeFiles/211Tempc__labFile.dir/main.cpp.o"

# External object files for target 211Tempc__labFile
211Tempc__labFile_EXTERNAL_OBJECTS =

211Tempc__labFile: CMakeFiles/211Tempc__labFile.dir/main.cpp.o
211Tempc__labFile: CMakeFiles/211Tempc__labFile.dir/build.make
211Tempc__labFile: CMakeFiles/211Tempc__labFile.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/diamondrubix/CLionProjects/cs 211/211Tempc++labFile/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 211Tempc__labFile"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/211Tempc__labFile.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/211Tempc__labFile.dir/build: 211Tempc__labFile

.PHONY : CMakeFiles/211Tempc__labFile.dir/build

CMakeFiles/211Tempc__labFile.dir/requires: CMakeFiles/211Tempc__labFile.dir/main.cpp.o.requires

.PHONY : CMakeFiles/211Tempc__labFile.dir/requires

CMakeFiles/211Tempc__labFile.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/211Tempc__labFile.dir/cmake_clean.cmake
.PHONY : CMakeFiles/211Tempc__labFile.dir/clean

CMakeFiles/211Tempc__labFile.dir/depend:
	cd "/home/diamondrubix/CLionProjects/cs 211/211Tempc++labFile/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/diamondrubix/CLionProjects/cs 211/211Tempc++labFile" "/home/diamondrubix/CLionProjects/cs 211/211Tempc++labFile" "/home/diamondrubix/CLionProjects/cs 211/211Tempc++labFile/cmake-build-debug" "/home/diamondrubix/CLionProjects/cs 211/211Tempc++labFile/cmake-build-debug" "/home/diamondrubix/CLionProjects/cs 211/211Tempc++labFile/cmake-build-debug/CMakeFiles/211Tempc__labFile.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/211Tempc__labFile.dir/depend

