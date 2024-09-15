# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.27.6/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.27.6/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/swesikramineni/github/solarcar/solarcar-training-p2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/swesikramineni/github/solarcar/solarcar-training-p2/build

# Include any dependencies generated for this target.
include src/SolarCar/Array/CMakeFiles/array.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/SolarCar/Array/CMakeFiles/array.dir/compiler_depend.make

# Include the progress variables for this target.
include src/SolarCar/Array/CMakeFiles/array.dir/progress.make

# Include the compile flags for this target's objects.
include src/SolarCar/Array/CMakeFiles/array.dir/flags.make

src/SolarCar/Array/CMakeFiles/array.dir/Array.cpp.o: src/SolarCar/Array/CMakeFiles/array.dir/flags.make
src/SolarCar/Array/CMakeFiles/array.dir/Array.cpp.o: /Users/swesikramineni/github/solarcar/solarcar-training-p2/src/SolarCar/Array/Array.cpp
src/SolarCar/Array/CMakeFiles/array.dir/Array.cpp.o: src/SolarCar/Array/CMakeFiles/array.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/swesikramineni/github/solarcar/solarcar-training-p2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/SolarCar/Array/CMakeFiles/array.dir/Array.cpp.o"
	cd /Users/swesikramineni/github/solarcar/solarcar-training-p2/build/src/SolarCar/Array && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/SolarCar/Array/CMakeFiles/array.dir/Array.cpp.o -MF CMakeFiles/array.dir/Array.cpp.o.d -o CMakeFiles/array.dir/Array.cpp.o -c /Users/swesikramineni/github/solarcar/solarcar-training-p2/src/SolarCar/Array/Array.cpp

src/SolarCar/Array/CMakeFiles/array.dir/Array.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/array.dir/Array.cpp.i"
	cd /Users/swesikramineni/github/solarcar/solarcar-training-p2/build/src/SolarCar/Array && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/swesikramineni/github/solarcar/solarcar-training-p2/src/SolarCar/Array/Array.cpp > CMakeFiles/array.dir/Array.cpp.i

src/SolarCar/Array/CMakeFiles/array.dir/Array.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/array.dir/Array.cpp.s"
	cd /Users/swesikramineni/github/solarcar/solarcar-training-p2/build/src/SolarCar/Array && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/swesikramineni/github/solarcar/solarcar-training-p2/src/SolarCar/Array/Array.cpp -o CMakeFiles/array.dir/Array.cpp.s

# Object files for target array
array_OBJECTS = \
"CMakeFiles/array.dir/Array.cpp.o"

# External object files for target array
array_EXTERNAL_OBJECTS =

src/SolarCar/Array/libarray.a: src/SolarCar/Array/CMakeFiles/array.dir/Array.cpp.o
src/SolarCar/Array/libarray.a: src/SolarCar/Array/CMakeFiles/array.dir/build.make
src/SolarCar/Array/libarray.a: src/SolarCar/Array/CMakeFiles/array.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/swesikramineni/github/solarcar/solarcar-training-p2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libarray.a"
	cd /Users/swesikramineni/github/solarcar/solarcar-training-p2/build/src/SolarCar/Array && $(CMAKE_COMMAND) -P CMakeFiles/array.dir/cmake_clean_target.cmake
	cd /Users/swesikramineni/github/solarcar/solarcar-training-p2/build/src/SolarCar/Array && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/array.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/SolarCar/Array/CMakeFiles/array.dir/build: src/SolarCar/Array/libarray.a
.PHONY : src/SolarCar/Array/CMakeFiles/array.dir/build

src/SolarCar/Array/CMakeFiles/array.dir/clean:
	cd /Users/swesikramineni/github/solarcar/solarcar-training-p2/build/src/SolarCar/Array && $(CMAKE_COMMAND) -P CMakeFiles/array.dir/cmake_clean.cmake
.PHONY : src/SolarCar/Array/CMakeFiles/array.dir/clean

src/SolarCar/Array/CMakeFiles/array.dir/depend:
	cd /Users/swesikramineni/github/solarcar/solarcar-training-p2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/swesikramineni/github/solarcar/solarcar-training-p2 /Users/swesikramineni/github/solarcar/solarcar-training-p2/src/SolarCar/Array /Users/swesikramineni/github/solarcar/solarcar-training-p2/build /Users/swesikramineni/github/solarcar/solarcar-training-p2/build/src/SolarCar/Array /Users/swesikramineni/github/solarcar/solarcar-training-p2/build/src/SolarCar/Array/CMakeFiles/array.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/SolarCar/Array/CMakeFiles/array.dir/depend

