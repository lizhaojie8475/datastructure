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
include CMakeFiles/concurrentAcc.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/concurrentAcc.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/concurrentAcc.dir/flags.make

CMakeFiles/concurrentAcc.dir/concurrentAcumulate.cpp.o: CMakeFiles/concurrentAcc.dir/flags.make
CMakeFiles/concurrentAcc.dir/concurrentAcumulate.cpp.o: ../concurrentAcumulate.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Duke-mac/Work/datastructure/ccia/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/concurrentAcc.dir/concurrentAcumulate.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/concurrentAcc.dir/concurrentAcumulate.cpp.o -c /Users/Duke-mac/Work/datastructure/ccia/concurrentAcumulate.cpp

CMakeFiles/concurrentAcc.dir/concurrentAcumulate.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/concurrentAcc.dir/concurrentAcumulate.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Duke-mac/Work/datastructure/ccia/concurrentAcumulate.cpp > CMakeFiles/concurrentAcc.dir/concurrentAcumulate.cpp.i

CMakeFiles/concurrentAcc.dir/concurrentAcumulate.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/concurrentAcc.dir/concurrentAcumulate.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Duke-mac/Work/datastructure/ccia/concurrentAcumulate.cpp -o CMakeFiles/concurrentAcc.dir/concurrentAcumulate.cpp.s

# Object files for target concurrentAcc
concurrentAcc_OBJECTS = \
"CMakeFiles/concurrentAcc.dir/concurrentAcumulate.cpp.o"

# External object files for target concurrentAcc
concurrentAcc_EXTERNAL_OBJECTS =

concurrentAcc: CMakeFiles/concurrentAcc.dir/concurrentAcumulate.cpp.o
concurrentAcc: CMakeFiles/concurrentAcc.dir/build.make
concurrentAcc: CMakeFiles/concurrentAcc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Duke-mac/Work/datastructure/ccia/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable concurrentAcc"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/concurrentAcc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/concurrentAcc.dir/build: concurrentAcc

.PHONY : CMakeFiles/concurrentAcc.dir/build

CMakeFiles/concurrentAcc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/concurrentAcc.dir/cmake_clean.cmake
.PHONY : CMakeFiles/concurrentAcc.dir/clean

CMakeFiles/concurrentAcc.dir/depend:
	cd /Users/Duke-mac/Work/datastructure/ccia/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Duke-mac/Work/datastructure/ccia /Users/Duke-mac/Work/datastructure/ccia /Users/Duke-mac/Work/datastructure/ccia/build /Users/Duke-mac/Work/datastructure/ccia/build /Users/Duke-mac/Work/datastructure/ccia/build/CMakeFiles/concurrentAcc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/concurrentAcc.dir/depend

