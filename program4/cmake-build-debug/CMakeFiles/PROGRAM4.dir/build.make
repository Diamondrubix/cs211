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
CMAKE_SOURCE_DIR = "/home/diamondrubix/CLionProjects/cs 211/program4"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/diamondrubix/CLionProjects/cs 211/program4/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/PROGRAM4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PROGRAM4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PROGRAM4.dir/flags.make

CMakeFiles/PROGRAM4.dir/proj4base.c.o: CMakeFiles/PROGRAM4.dir/flags.make
CMakeFiles/PROGRAM4.dir/proj4base.c.o: ../proj4base.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/diamondrubix/CLionProjects/cs 211/program4/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/PROGRAM4.dir/proj4base.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/PROGRAM4.dir/proj4base.c.o   -c "/home/diamondrubix/CLionProjects/cs 211/program4/proj4base.c"

CMakeFiles/PROGRAM4.dir/proj4base.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/PROGRAM4.dir/proj4base.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/diamondrubix/CLionProjects/cs 211/program4/proj4base.c" > CMakeFiles/PROGRAM4.dir/proj4base.c.i

CMakeFiles/PROGRAM4.dir/proj4base.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/PROGRAM4.dir/proj4base.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/diamondrubix/CLionProjects/cs 211/program4/proj4base.c" -o CMakeFiles/PROGRAM4.dir/proj4base.c.s

CMakeFiles/PROGRAM4.dir/proj4base.c.o.requires:

.PHONY : CMakeFiles/PROGRAM4.dir/proj4base.c.o.requires

CMakeFiles/PROGRAM4.dir/proj4base.c.o.provides: CMakeFiles/PROGRAM4.dir/proj4base.c.o.requires
	$(MAKE) -f CMakeFiles/PROGRAM4.dir/build.make CMakeFiles/PROGRAM4.dir/proj4base.c.o.provides.build
.PHONY : CMakeFiles/PROGRAM4.dir/proj4base.c.o.provides

CMakeFiles/PROGRAM4.dir/proj4base.c.o.provides.build: CMakeFiles/PROGRAM4.dir/proj4base.c.o


# Object files for target PROGRAM4
PROGRAM4_OBJECTS = \
"CMakeFiles/PROGRAM4.dir/proj4base.c.o"

# External object files for target PROGRAM4
PROGRAM4_EXTERNAL_OBJECTS =

PROGRAM4: CMakeFiles/PROGRAM4.dir/proj4base.c.o
PROGRAM4: CMakeFiles/PROGRAM4.dir/build.make
PROGRAM4: CMakeFiles/PROGRAM4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/diamondrubix/CLionProjects/cs 211/program4/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable PROGRAM4"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PROGRAM4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PROGRAM4.dir/build: PROGRAM4

.PHONY : CMakeFiles/PROGRAM4.dir/build

CMakeFiles/PROGRAM4.dir/requires: CMakeFiles/PROGRAM4.dir/proj4base.c.o.requires

.PHONY : CMakeFiles/PROGRAM4.dir/requires

CMakeFiles/PROGRAM4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PROGRAM4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PROGRAM4.dir/clean

CMakeFiles/PROGRAM4.dir/depend:
	cd "/home/diamondrubix/CLionProjects/cs 211/program4/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/diamondrubix/CLionProjects/cs 211/program4" "/home/diamondrubix/CLionProjects/cs 211/program4" "/home/diamondrubix/CLionProjects/cs 211/program4/cmake-build-debug" "/home/diamondrubix/CLionProjects/cs 211/program4/cmake-build-debug" "/home/diamondrubix/CLionProjects/cs 211/program4/cmake-build-debug/CMakeFiles/PROGRAM4.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/PROGRAM4.dir/depend
