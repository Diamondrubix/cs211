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
CMAKE_COMMAND = /home/diamondrubix/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/172.3968.17/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/diamondrubix/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/172.3968.17/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/diamondrubix/CLionProjects/cs 211/Lab2"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/diamondrubix/CLionProjects/cs 211/Lab2/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Lab2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Lab2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lab2.dir/flags.make

CMakeFiles/Lab2.dir/main.c.o: CMakeFiles/Lab2.dir/flags.make
CMakeFiles/Lab2.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/diamondrubix/CLionProjects/cs 211/Lab2/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Lab2.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Lab2.dir/main.c.o   -c "/home/diamondrubix/CLionProjects/cs 211/Lab2/main.c"

CMakeFiles/Lab2.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Lab2.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/diamondrubix/CLionProjects/cs 211/Lab2/main.c" > CMakeFiles/Lab2.dir/main.c.i

CMakeFiles/Lab2.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Lab2.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/diamondrubix/CLionProjects/cs 211/Lab2/main.c" -o CMakeFiles/Lab2.dir/main.c.s

CMakeFiles/Lab2.dir/main.c.o.requires:

.PHONY : CMakeFiles/Lab2.dir/main.c.o.requires

CMakeFiles/Lab2.dir/main.c.o.provides: CMakeFiles/Lab2.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/Lab2.dir/build.make CMakeFiles/Lab2.dir/main.c.o.provides.build
.PHONY : CMakeFiles/Lab2.dir/main.c.o.provides

CMakeFiles/Lab2.dir/main.c.o.provides.build: CMakeFiles/Lab2.dir/main.c.o


# Object files for target Lab2
Lab2_OBJECTS = \
"CMakeFiles/Lab2.dir/main.c.o"

# External object files for target Lab2
Lab2_EXTERNAL_OBJECTS =

Lab2: CMakeFiles/Lab2.dir/main.c.o
Lab2: CMakeFiles/Lab2.dir/build.make
Lab2: CMakeFiles/Lab2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/diamondrubix/CLionProjects/cs 211/Lab2/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Lab2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Lab2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lab2.dir/build: Lab2

.PHONY : CMakeFiles/Lab2.dir/build

CMakeFiles/Lab2.dir/requires: CMakeFiles/Lab2.dir/main.c.o.requires

.PHONY : CMakeFiles/Lab2.dir/requires

CMakeFiles/Lab2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Lab2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Lab2.dir/clean

CMakeFiles/Lab2.dir/depend:
	cd "/home/diamondrubix/CLionProjects/cs 211/Lab2/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/diamondrubix/CLionProjects/cs 211/Lab2" "/home/diamondrubix/CLionProjects/cs 211/Lab2" "/home/diamondrubix/CLionProjects/cs 211/Lab2/cmake-build-debug" "/home/diamondrubix/CLionProjects/cs 211/Lab2/cmake-build-debug" "/home/diamondrubix/CLionProjects/cs 211/Lab2/cmake-build-debug/CMakeFiles/Lab2.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Lab2.dir/depend

