# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/student/sayeed/graphics/projection

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/student/sayeed/graphics/projection/build

# Include any dependencies generated for this target.
include CMakeFiles/rotation.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/rotation.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rotation.dir/flags.make

CMakeFiles/rotation.dir/src/main.c.o: CMakeFiles/rotation.dir/flags.make
CMakeFiles/rotation.dir/src/main.c.o: ../src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/sayeed/graphics/projection/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/rotation.dir/src/main.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/rotation.dir/src/main.c.o   -c /home/student/sayeed/graphics/projection/src/main.c

CMakeFiles/rotation.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/rotation.dir/src/main.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/student/sayeed/graphics/projection/src/main.c > CMakeFiles/rotation.dir/src/main.c.i

CMakeFiles/rotation.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/rotation.dir/src/main.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/student/sayeed/graphics/projection/src/main.c -o CMakeFiles/rotation.dir/src/main.c.s

CMakeFiles/rotation.dir/src/main.c.o.requires:

.PHONY : CMakeFiles/rotation.dir/src/main.c.o.requires

CMakeFiles/rotation.dir/src/main.c.o.provides: CMakeFiles/rotation.dir/src/main.c.o.requires
	$(MAKE) -f CMakeFiles/rotation.dir/build.make CMakeFiles/rotation.dir/src/main.c.o.provides.build
.PHONY : CMakeFiles/rotation.dir/src/main.c.o.provides

CMakeFiles/rotation.dir/src/main.c.o.provides.build: CMakeFiles/rotation.dir/src/main.c.o


CMakeFiles/rotation.dir/src/8sym.c.o: CMakeFiles/rotation.dir/flags.make
CMakeFiles/rotation.dir/src/8sym.c.o: ../src/8sym.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/sayeed/graphics/projection/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/rotation.dir/src/8sym.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/rotation.dir/src/8sym.c.o   -c /home/student/sayeed/graphics/projection/src/8sym.c

CMakeFiles/rotation.dir/src/8sym.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/rotation.dir/src/8sym.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/student/sayeed/graphics/projection/src/8sym.c > CMakeFiles/rotation.dir/src/8sym.c.i

CMakeFiles/rotation.dir/src/8sym.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/rotation.dir/src/8sym.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/student/sayeed/graphics/projection/src/8sym.c -o CMakeFiles/rotation.dir/src/8sym.c.s

CMakeFiles/rotation.dir/src/8sym.c.o.requires:

.PHONY : CMakeFiles/rotation.dir/src/8sym.c.o.requires

CMakeFiles/rotation.dir/src/8sym.c.o.provides: CMakeFiles/rotation.dir/src/8sym.c.o.requires
	$(MAKE) -f CMakeFiles/rotation.dir/build.make CMakeFiles/rotation.dir/src/8sym.c.o.provides.build
.PHONY : CMakeFiles/rotation.dir/src/8sym.c.o.provides

CMakeFiles/rotation.dir/src/8sym.c.o.provides.build: CMakeFiles/rotation.dir/src/8sym.c.o


CMakeFiles/rotation.dir/src/draw3d.c.o: CMakeFiles/rotation.dir/flags.make
CMakeFiles/rotation.dir/src/draw3d.c.o: ../src/draw3d.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/sayeed/graphics/projection/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/rotation.dir/src/draw3d.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/rotation.dir/src/draw3d.c.o   -c /home/student/sayeed/graphics/projection/src/draw3d.c

CMakeFiles/rotation.dir/src/draw3d.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/rotation.dir/src/draw3d.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/student/sayeed/graphics/projection/src/draw3d.c > CMakeFiles/rotation.dir/src/draw3d.c.i

CMakeFiles/rotation.dir/src/draw3d.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/rotation.dir/src/draw3d.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/student/sayeed/graphics/projection/src/draw3d.c -o CMakeFiles/rotation.dir/src/draw3d.c.s

CMakeFiles/rotation.dir/src/draw3d.c.o.requires:

.PHONY : CMakeFiles/rotation.dir/src/draw3d.c.o.requires

CMakeFiles/rotation.dir/src/draw3d.c.o.provides: CMakeFiles/rotation.dir/src/draw3d.c.o.requires
	$(MAKE) -f CMakeFiles/rotation.dir/build.make CMakeFiles/rotation.dir/src/draw3d.c.o.provides.build
.PHONY : CMakeFiles/rotation.dir/src/draw3d.c.o.provides

CMakeFiles/rotation.dir/src/draw3d.c.o.provides.build: CMakeFiles/rotation.dir/src/draw3d.c.o


# Object files for target rotation
rotation_OBJECTS = \
"CMakeFiles/rotation.dir/src/main.c.o" \
"CMakeFiles/rotation.dir/src/8sym.c.o" \
"CMakeFiles/rotation.dir/src/draw3d.c.o"

# External object files for target rotation
rotation_EXTERNAL_OBJECTS =

rotation: CMakeFiles/rotation.dir/src/main.c.o
rotation: CMakeFiles/rotation.dir/src/8sym.c.o
rotation: CMakeFiles/rotation.dir/src/draw3d.c.o
rotation: CMakeFiles/rotation.dir/build.make
rotation: /usr/lib/x86_64-linux-gnu/libGLU.so
rotation: /usr/lib/x86_64-linux-gnu/libGL.so
rotation: /usr/lib/x86_64-linux-gnu/libglut.so
rotation: /usr/lib/x86_64-linux-gnu/libXmu.so
rotation: /usr/lib/x86_64-linux-gnu/libXi.so
rotation: CMakeFiles/rotation.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/student/sayeed/graphics/projection/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable rotation"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rotation.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rotation.dir/build: rotation

.PHONY : CMakeFiles/rotation.dir/build

CMakeFiles/rotation.dir/requires: CMakeFiles/rotation.dir/src/main.c.o.requires
CMakeFiles/rotation.dir/requires: CMakeFiles/rotation.dir/src/8sym.c.o.requires
CMakeFiles/rotation.dir/requires: CMakeFiles/rotation.dir/src/draw3d.c.o.requires

.PHONY : CMakeFiles/rotation.dir/requires

CMakeFiles/rotation.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/rotation.dir/cmake_clean.cmake
.PHONY : CMakeFiles/rotation.dir/clean

CMakeFiles/rotation.dir/depend:
	cd /home/student/sayeed/graphics/projection/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/student/sayeed/graphics/projection /home/student/sayeed/graphics/projection /home/student/sayeed/graphics/projection/build /home/student/sayeed/graphics/projection/build /home/student/sayeed/graphics/projection/build/CMakeFiles/rotation.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/rotation.dir/depend

