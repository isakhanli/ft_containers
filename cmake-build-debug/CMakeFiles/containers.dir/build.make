# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/clion/175/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/175/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/isakhanli/Desktop/containers

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/isakhanli/Desktop/containers/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/containers.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/containers.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/containers.dir/flags.make

CMakeFiles/containers.dir/Map/main.cpp.o: CMakeFiles/containers.dir/flags.make
CMakeFiles/containers.dir/Map/main.cpp.o: ../Map/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/isakhanli/Desktop/containers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/containers.dir/Map/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/containers.dir/Map/main.cpp.o -c /home/isakhanli/Desktop/containers/Map/main.cpp

CMakeFiles/containers.dir/Map/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/containers.dir/Map/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/isakhanli/Desktop/containers/Map/main.cpp > CMakeFiles/containers.dir/Map/main.cpp.i

CMakeFiles/containers.dir/Map/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/containers.dir/Map/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/isakhanli/Desktop/containers/Map/main.cpp -o CMakeFiles/containers.dir/Map/main.cpp.s

# Object files for target containers
containers_OBJECTS = \
"CMakeFiles/containers.dir/Map/main.cpp.o"

# External object files for target containers
containers_EXTERNAL_OBJECTS =

containers: CMakeFiles/containers.dir/Map/main.cpp.o
containers: CMakeFiles/containers.dir/build.make
containers: CMakeFiles/containers.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/isakhanli/Desktop/containers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable containers"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/containers.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/containers.dir/build: containers
.PHONY : CMakeFiles/containers.dir/build

CMakeFiles/containers.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/containers.dir/cmake_clean.cmake
.PHONY : CMakeFiles/containers.dir/clean

CMakeFiles/containers.dir/depend:
	cd /home/isakhanli/Desktop/containers/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/isakhanli/Desktop/containers /home/isakhanli/Desktop/containers /home/isakhanli/Desktop/containers/cmake-build-debug /home/isakhanli/Desktop/containers/cmake-build-debug /home/isakhanli/Desktop/containers/cmake-build-debug/CMakeFiles/containers.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/containers.dir/depend

