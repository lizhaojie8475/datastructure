# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/Duke-mac/Work/datastructure/ccia

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Duke-mac/Work/datastructure/ccia/build

# Include any dependencies generated for this target.
include CMakeFiles/threadsafeMap.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/threadsafeMap.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/threadsafeMap.dir/flags.make

CMakeFiles/threadsafeMap.dir/threadsafeMap.cpp.o: CMakeFiles/threadsafeMap.dir/flags.make
CMakeFiles/threadsafeMap.dir/threadsafeMap.cpp.o: ../threadsafeMap.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Duke-mac/Work/datastructure/ccia/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/threadsafeMap.dir/threadsafeMap.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/threadsafeMap.dir/threadsafeMap.cpp.o -c /Users/Duke-mac/Work/datastructure/ccia/threadsafeMap.cpp

CMakeFiles/threadsafeMap.dir/threadsafeMap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/threadsafeMap.dir/threadsafeMap.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Duke-mac/Work/datastructure/ccia/threadsafeMap.cpp > CMakeFiles/threadsafeMap.dir/threadsafeMap.cpp.i

CMakeFiles/threadsafeMap.dir/threadsafeMap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/threadsafeMap.dir/threadsafeMap.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Duke-mac/Work/datastructure/ccia/threadsafeMap.cpp -o CMakeFiles/threadsafeMap.dir/threadsafeMap.cpp.s

# Object files for target threadsafeMap
threadsafeMap_OBJECTS = \
"CMakeFiles/threadsafeMap.dir/threadsafeMap.cpp.o"

# External object files for target threadsafeMap
threadsafeMap_EXTERNAL_OBJECTS =

threadsafeMap: CMakeFiles/threadsafeMap.dir/threadsafeMap.cpp.o
threadsafeMap: CMakeFiles/threadsafeMap.dir/build.make
threadsafeMap: CMakeFiles/threadsafeMap.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Duke-mac/Work/datastructure/ccia/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable threadsafeMap"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/threadsafeMap.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/threadsafeMap.dir/build: threadsafeMap

.PHONY : CMakeFiles/threadsafeMap.dir/build

CMakeFiles/threadsafeMap.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/threadsafeMap.dir/cmake_clean.cmake
.PHONY : CMakeFiles/threadsafeMap.dir/clean

CMakeFiles/threadsafeMap.dir/depend:
	cd /Users/Duke-mac/Work/datastructure/ccia/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Duke-mac/Work/datastructure/ccia /Users/Duke-mac/Work/datastructure/ccia /Users/Duke-mac/Work/datastructure/ccia/build /Users/Duke-mac/Work/datastructure/ccia/build /Users/Duke-mac/Work/datastructure/ccia/build/CMakeFiles/threadsafeMap.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/threadsafeMap.dir/depend

