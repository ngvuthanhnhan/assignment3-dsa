# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/ngvuthanhnhan/Desktop/hai không hai (buồn)/Data Structure & Algorithms/Assignment 3/assignment3-dsa/initial/src"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/ngvuthanhnhan/Desktop/hai không hai (buồn)/Data Structure & Algorithms/Assignment 3/assignment3-dsa/initial/src/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/initial.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/initial.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/initial.dir/flags.make

CMakeFiles/initial.dir/main.cpp.o: CMakeFiles/initial.dir/flags.make
CMakeFiles/initial.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/ngvuthanhnhan/Desktop/hai không hai (buồn)/Data Structure & Algorithms/Assignment 3/assignment3-dsa/initial/src/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/initial.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/initial.dir/main.cpp.o -c "/Users/ngvuthanhnhan/Desktop/hai không hai (buồn)/Data Structure & Algorithms/Assignment 3/assignment3-dsa/initial/src/main.cpp"

CMakeFiles/initial.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/initial.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/ngvuthanhnhan/Desktop/hai không hai (buồn)/Data Structure & Algorithms/Assignment 3/assignment3-dsa/initial/src/main.cpp" > CMakeFiles/initial.dir/main.cpp.i

CMakeFiles/initial.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/initial.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/ngvuthanhnhan/Desktop/hai không hai (buồn)/Data Structure & Algorithms/Assignment 3/assignment3-dsa/initial/src/main.cpp" -o CMakeFiles/initial.dir/main.cpp.s

# Object files for target initial
initial_OBJECTS = \
"CMakeFiles/initial.dir/main.cpp.o"

# External object files for target initial
initial_EXTERNAL_OBJECTS =

initial: CMakeFiles/initial.dir/main.cpp.o
initial: CMakeFiles/initial.dir/build.make
initial: CMakeFiles/initial.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/ngvuthanhnhan/Desktop/hai không hai (buồn)/Data Structure & Algorithms/Assignment 3/assignment3-dsa/initial/src/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable initial"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/initial.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/initial.dir/build: initial

.PHONY : CMakeFiles/initial.dir/build

CMakeFiles/initial.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/initial.dir/cmake_clean.cmake
.PHONY : CMakeFiles/initial.dir/clean

CMakeFiles/initial.dir/depend:
	cd "/Users/ngvuthanhnhan/Desktop/hai không hai (buồn)/Data Structure & Algorithms/Assignment 3/assignment3-dsa/initial/src/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/ngvuthanhnhan/Desktop/hai không hai (buồn)/Data Structure & Algorithms/Assignment 3/assignment3-dsa/initial/src" "/Users/ngvuthanhnhan/Desktop/hai không hai (buồn)/Data Structure & Algorithms/Assignment 3/assignment3-dsa/initial/src" "/Users/ngvuthanhnhan/Desktop/hai không hai (buồn)/Data Structure & Algorithms/Assignment 3/assignment3-dsa/initial/src/cmake-build-debug" "/Users/ngvuthanhnhan/Desktop/hai không hai (buồn)/Data Structure & Algorithms/Assignment 3/assignment3-dsa/initial/src/cmake-build-debug" "/Users/ngvuthanhnhan/Desktop/hai không hai (buồn)/Data Structure & Algorithms/Assignment 3/assignment3-dsa/initial/src/cmake-build-debug/CMakeFiles/initial.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/initial.dir/depend

