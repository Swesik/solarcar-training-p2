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
include src/RaceConfig/WeatherStations/CMakeFiles/weather_stations.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/RaceConfig/WeatherStations/CMakeFiles/weather_stations.dir/compiler_depend.make

# Include the progress variables for this target.
include src/RaceConfig/WeatherStations/CMakeFiles/weather_stations.dir/progress.make

# Include the compile flags for this target's objects.
include src/RaceConfig/WeatherStations/CMakeFiles/weather_stations.dir/flags.make

src/RaceConfig/WeatherStations/CMakeFiles/weather_stations.dir/WeatherStations.cpp.o: src/RaceConfig/WeatherStations/CMakeFiles/weather_stations.dir/flags.make
src/RaceConfig/WeatherStations/CMakeFiles/weather_stations.dir/WeatherStations.cpp.o: /Users/swesikramineni/github/solarcar/solarcar-training-p2/src/RaceConfig/WeatherStations/WeatherStations.cpp
src/RaceConfig/WeatherStations/CMakeFiles/weather_stations.dir/WeatherStations.cpp.o: src/RaceConfig/WeatherStations/CMakeFiles/weather_stations.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/swesikramineni/github/solarcar/solarcar-training-p2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/RaceConfig/WeatherStations/CMakeFiles/weather_stations.dir/WeatherStations.cpp.o"
	cd /Users/swesikramineni/github/solarcar/solarcar-training-p2/build/src/RaceConfig/WeatherStations && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/RaceConfig/WeatherStations/CMakeFiles/weather_stations.dir/WeatherStations.cpp.o -MF CMakeFiles/weather_stations.dir/WeatherStations.cpp.o.d -o CMakeFiles/weather_stations.dir/WeatherStations.cpp.o -c /Users/swesikramineni/github/solarcar/solarcar-training-p2/src/RaceConfig/WeatherStations/WeatherStations.cpp

src/RaceConfig/WeatherStations/CMakeFiles/weather_stations.dir/WeatherStations.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/weather_stations.dir/WeatherStations.cpp.i"
	cd /Users/swesikramineni/github/solarcar/solarcar-training-p2/build/src/RaceConfig/WeatherStations && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/swesikramineni/github/solarcar/solarcar-training-p2/src/RaceConfig/WeatherStations/WeatherStations.cpp > CMakeFiles/weather_stations.dir/WeatherStations.cpp.i

src/RaceConfig/WeatherStations/CMakeFiles/weather_stations.dir/WeatherStations.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/weather_stations.dir/WeatherStations.cpp.s"
	cd /Users/swesikramineni/github/solarcar/solarcar-training-p2/build/src/RaceConfig/WeatherStations && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/swesikramineni/github/solarcar/solarcar-training-p2/src/RaceConfig/WeatherStations/WeatherStations.cpp -o CMakeFiles/weather_stations.dir/WeatherStations.cpp.s

# Object files for target weather_stations
weather_stations_OBJECTS = \
"CMakeFiles/weather_stations.dir/WeatherStations.cpp.o"

# External object files for target weather_stations
weather_stations_EXTERNAL_OBJECTS =

src/RaceConfig/WeatherStations/libweather_stations.a: src/RaceConfig/WeatherStations/CMakeFiles/weather_stations.dir/WeatherStations.cpp.o
src/RaceConfig/WeatherStations/libweather_stations.a: src/RaceConfig/WeatherStations/CMakeFiles/weather_stations.dir/build.make
src/RaceConfig/WeatherStations/libweather_stations.a: src/RaceConfig/WeatherStations/CMakeFiles/weather_stations.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/swesikramineni/github/solarcar/solarcar-training-p2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libweather_stations.a"
	cd /Users/swesikramineni/github/solarcar/solarcar-training-p2/build/src/RaceConfig/WeatherStations && $(CMAKE_COMMAND) -P CMakeFiles/weather_stations.dir/cmake_clean_target.cmake
	cd /Users/swesikramineni/github/solarcar/solarcar-training-p2/build/src/RaceConfig/WeatherStations && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/weather_stations.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/RaceConfig/WeatherStations/CMakeFiles/weather_stations.dir/build: src/RaceConfig/WeatherStations/libweather_stations.a
.PHONY : src/RaceConfig/WeatherStations/CMakeFiles/weather_stations.dir/build

src/RaceConfig/WeatherStations/CMakeFiles/weather_stations.dir/clean:
	cd /Users/swesikramineni/github/solarcar/solarcar-training-p2/build/src/RaceConfig/WeatherStations && $(CMAKE_COMMAND) -P CMakeFiles/weather_stations.dir/cmake_clean.cmake
.PHONY : src/RaceConfig/WeatherStations/CMakeFiles/weather_stations.dir/clean

src/RaceConfig/WeatherStations/CMakeFiles/weather_stations.dir/depend:
	cd /Users/swesikramineni/github/solarcar/solarcar-training-p2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/swesikramineni/github/solarcar/solarcar-training-p2 /Users/swesikramineni/github/solarcar/solarcar-training-p2/src/RaceConfig/WeatherStations /Users/swesikramineni/github/solarcar/solarcar-training-p2/build /Users/swesikramineni/github/solarcar/solarcar-training-p2/build/src/RaceConfig/WeatherStations /Users/swesikramineni/github/solarcar/solarcar-training-p2/build/src/RaceConfig/WeatherStations/CMakeFiles/weather_stations.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/RaceConfig/WeatherStations/CMakeFiles/weather_stations.dir/depend

