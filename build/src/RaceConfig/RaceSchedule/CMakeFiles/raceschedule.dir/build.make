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
include src/RaceConfig/RaceSchedule/CMakeFiles/raceschedule.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/RaceConfig/RaceSchedule/CMakeFiles/raceschedule.dir/compiler_depend.make

# Include the progress variables for this target.
include src/RaceConfig/RaceSchedule/CMakeFiles/raceschedule.dir/progress.make

# Include the compile flags for this target's objects.
include src/RaceConfig/RaceSchedule/CMakeFiles/raceschedule.dir/flags.make

src/RaceConfig/RaceSchedule/CMakeFiles/raceschedule.dir/RaceSchedule.cpp.o: src/RaceConfig/RaceSchedule/CMakeFiles/raceschedule.dir/flags.make
src/RaceConfig/RaceSchedule/CMakeFiles/raceschedule.dir/RaceSchedule.cpp.o: /Users/swesikramineni/github/solarcar/solarcar-training-p2/src/RaceConfig/RaceSchedule/RaceSchedule.cpp
src/RaceConfig/RaceSchedule/CMakeFiles/raceschedule.dir/RaceSchedule.cpp.o: src/RaceConfig/RaceSchedule/CMakeFiles/raceschedule.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/swesikramineni/github/solarcar/solarcar-training-p2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/RaceConfig/RaceSchedule/CMakeFiles/raceschedule.dir/RaceSchedule.cpp.o"
	cd /Users/swesikramineni/github/solarcar/solarcar-training-p2/build/src/RaceConfig/RaceSchedule && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/RaceConfig/RaceSchedule/CMakeFiles/raceschedule.dir/RaceSchedule.cpp.o -MF CMakeFiles/raceschedule.dir/RaceSchedule.cpp.o.d -o CMakeFiles/raceschedule.dir/RaceSchedule.cpp.o -c /Users/swesikramineni/github/solarcar/solarcar-training-p2/src/RaceConfig/RaceSchedule/RaceSchedule.cpp

src/RaceConfig/RaceSchedule/CMakeFiles/raceschedule.dir/RaceSchedule.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/raceschedule.dir/RaceSchedule.cpp.i"
	cd /Users/swesikramineni/github/solarcar/solarcar-training-p2/build/src/RaceConfig/RaceSchedule && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/swesikramineni/github/solarcar/solarcar-training-p2/src/RaceConfig/RaceSchedule/RaceSchedule.cpp > CMakeFiles/raceschedule.dir/RaceSchedule.cpp.i

src/RaceConfig/RaceSchedule/CMakeFiles/raceschedule.dir/RaceSchedule.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/raceschedule.dir/RaceSchedule.cpp.s"
	cd /Users/swesikramineni/github/solarcar/solarcar-training-p2/build/src/RaceConfig/RaceSchedule && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/swesikramineni/github/solarcar/solarcar-training-p2/src/RaceConfig/RaceSchedule/RaceSchedule.cpp -o CMakeFiles/raceschedule.dir/RaceSchedule.cpp.s

# Object files for target raceschedule
raceschedule_OBJECTS = \
"CMakeFiles/raceschedule.dir/RaceSchedule.cpp.o"

# External object files for target raceschedule
raceschedule_EXTERNAL_OBJECTS =

src/RaceConfig/RaceSchedule/libraceschedule.a: src/RaceConfig/RaceSchedule/CMakeFiles/raceschedule.dir/RaceSchedule.cpp.o
src/RaceConfig/RaceSchedule/libraceschedule.a: src/RaceConfig/RaceSchedule/CMakeFiles/raceschedule.dir/build.make
src/RaceConfig/RaceSchedule/libraceschedule.a: src/RaceConfig/RaceSchedule/CMakeFiles/raceschedule.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/swesikramineni/github/solarcar/solarcar-training-p2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libraceschedule.a"
	cd /Users/swesikramineni/github/solarcar/solarcar-training-p2/build/src/RaceConfig/RaceSchedule && $(CMAKE_COMMAND) -P CMakeFiles/raceschedule.dir/cmake_clean_target.cmake
	cd /Users/swesikramineni/github/solarcar/solarcar-training-p2/build/src/RaceConfig/RaceSchedule && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/raceschedule.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/RaceConfig/RaceSchedule/CMakeFiles/raceschedule.dir/build: src/RaceConfig/RaceSchedule/libraceschedule.a
.PHONY : src/RaceConfig/RaceSchedule/CMakeFiles/raceschedule.dir/build

src/RaceConfig/RaceSchedule/CMakeFiles/raceschedule.dir/clean:
	cd /Users/swesikramineni/github/solarcar/solarcar-training-p2/build/src/RaceConfig/RaceSchedule && $(CMAKE_COMMAND) -P CMakeFiles/raceschedule.dir/cmake_clean.cmake
.PHONY : src/RaceConfig/RaceSchedule/CMakeFiles/raceschedule.dir/clean

src/RaceConfig/RaceSchedule/CMakeFiles/raceschedule.dir/depend:
	cd /Users/swesikramineni/github/solarcar/solarcar-training-p2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/swesikramineni/github/solarcar/solarcar-training-p2 /Users/swesikramineni/github/solarcar/solarcar-training-p2/src/RaceConfig/RaceSchedule /Users/swesikramineni/github/solarcar/solarcar-training-p2/build /Users/swesikramineni/github/solarcar/solarcar-training-p2/build/src/RaceConfig/RaceSchedule /Users/swesikramineni/github/solarcar/solarcar-training-p2/build/src/RaceConfig/RaceSchedule/CMakeFiles/raceschedule.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/RaceConfig/RaceSchedule/CMakeFiles/raceschedule.dir/depend

