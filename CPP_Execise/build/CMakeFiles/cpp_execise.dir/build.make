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
CMAKE_SOURCE_DIR = /home/lhj/projects/CPP_Execise

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lhj/projects/CPP_Execise/build

# Include any dependencies generated for this target.
include CMakeFiles/cpp_execise.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cpp_execise.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cpp_execise.dir/flags.make

CMakeFiles/cpp_execise.dir/main.cpp.o: CMakeFiles/cpp_execise.dir/flags.make
CMakeFiles/cpp_execise.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lhj/projects/CPP_Execise/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cpp_execise.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpp_execise.dir/main.cpp.o -c /home/lhj/projects/CPP_Execise/main.cpp

CMakeFiles/cpp_execise.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpp_execise.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lhj/projects/CPP_Execise/main.cpp > CMakeFiles/cpp_execise.dir/main.cpp.i

CMakeFiles/cpp_execise.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpp_execise.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lhj/projects/CPP_Execise/main.cpp -o CMakeFiles/cpp_execise.dir/main.cpp.s

CMakeFiles/cpp_execise.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/cpp_execise.dir/main.cpp.o.requires

CMakeFiles/cpp_execise.dir/main.cpp.o.provides: CMakeFiles/cpp_execise.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/cpp_execise.dir/build.make CMakeFiles/cpp_execise.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/cpp_execise.dir/main.cpp.o.provides

CMakeFiles/cpp_execise.dir/main.cpp.o.provides.build: CMakeFiles/cpp_execise.dir/main.cpp.o


# Object files for target cpp_execise
cpp_execise_OBJECTS = \
"CMakeFiles/cpp_execise.dir/main.cpp.o"

# External object files for target cpp_execise
cpp_execise_EXTERNAL_OBJECTS =

cpp_execise: CMakeFiles/cpp_execise.dir/main.cpp.o
cpp_execise: CMakeFiles/cpp_execise.dir/build.make
cpp_execise: CMakeFiles/cpp_execise.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lhj/projects/CPP_Execise/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable cpp_execise"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cpp_execise.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cpp_execise.dir/build: cpp_execise

.PHONY : CMakeFiles/cpp_execise.dir/build

CMakeFiles/cpp_execise.dir/requires: CMakeFiles/cpp_execise.dir/main.cpp.o.requires

.PHONY : CMakeFiles/cpp_execise.dir/requires

CMakeFiles/cpp_execise.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cpp_execise.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cpp_execise.dir/clean

CMakeFiles/cpp_execise.dir/depend:
	cd /home/lhj/projects/CPP_Execise/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lhj/projects/CPP_Execise /home/lhj/projects/CPP_Execise /home/lhj/projects/CPP_Execise/build /home/lhj/projects/CPP_Execise/build /home/lhj/projects/CPP_Execise/build/CMakeFiles/cpp_execise.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cpp_execise.dir/depend

