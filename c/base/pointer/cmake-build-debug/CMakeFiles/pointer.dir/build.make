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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/miclefengzss/workspace/system/c/base/pointer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/miclefengzss/workspace/system/c/base/pointer/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/pointer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/pointer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pointer.dir/flags.make

CMakeFiles/pointer.dir/pointer/main.cpp.o: CMakeFiles/pointer.dir/flags.make
CMakeFiles/pointer.dir/pointer/main.cpp.o: ../pointer/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/miclefengzss/workspace/system/c/base/pointer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pointer.dir/pointer/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pointer.dir/pointer/main.cpp.o -c /Users/miclefengzss/workspace/system/c/base/pointer/pointer/main.cpp

CMakeFiles/pointer.dir/pointer/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pointer.dir/pointer/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/miclefengzss/workspace/system/c/base/pointer/pointer/main.cpp > CMakeFiles/pointer.dir/pointer/main.cpp.i

CMakeFiles/pointer.dir/pointer/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pointer.dir/pointer/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/miclefengzss/workspace/system/c/base/pointer/pointer/main.cpp -o CMakeFiles/pointer.dir/pointer/main.cpp.s

# Object files for target pointer
pointer_OBJECTS = \
"CMakeFiles/pointer.dir/pointer/main.cpp.o"

# External object files for target pointer
pointer_EXTERNAL_OBJECTS =

pointer: CMakeFiles/pointer.dir/pointer/main.cpp.o
pointer: CMakeFiles/pointer.dir/build.make
pointer: CMakeFiles/pointer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/miclefengzss/workspace/system/c/base/pointer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable pointer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pointer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pointer.dir/build: pointer

.PHONY : CMakeFiles/pointer.dir/build

CMakeFiles/pointer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pointer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pointer.dir/clean

CMakeFiles/pointer.dir/depend:
	cd /Users/miclefengzss/workspace/system/c/base/pointer/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/miclefengzss/workspace/system/c/base/pointer /Users/miclefengzss/workspace/system/c/base/pointer /Users/miclefengzss/workspace/system/c/base/pointer/cmake-build-debug /Users/miclefengzss/workspace/system/c/base/pointer/cmake-build-debug /Users/miclefengzss/workspace/system/c/base/pointer/cmake-build-debug/CMakeFiles/pointer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pointer.dir/depend

