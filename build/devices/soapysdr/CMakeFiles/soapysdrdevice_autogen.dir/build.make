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
CMAKE_COMMAND = /home/bernhard/Qt/Tools/CMake/bin/cmake

# The command to remove a file.
RM = /home/bernhard/Qt/Tools/CMake/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /opt/build/RPX-100-SDR

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /opt/build/RPX-100-SDR/build

# Utility rule file for soapysdrdevice_autogen.

# Include any custom commands dependencies for this target.
include devices/soapysdr/CMakeFiles/soapysdrdevice_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include devices/soapysdr/CMakeFiles/soapysdrdevice_autogen.dir/progress.make

devices/soapysdr/CMakeFiles/soapysdrdevice_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target soapysdrdevice"
	cd /opt/build/RPX-100-SDR/build/devices/soapysdr && /home/bernhard/Qt/Tools/CMake/bin/cmake -E cmake_autogen /opt/build/RPX-100-SDR/build/devices/soapysdr/CMakeFiles/soapysdrdevice_autogen.dir/AutogenInfo.json RelWithDebInfo

soapysdrdevice_autogen: devices/soapysdr/CMakeFiles/soapysdrdevice_autogen
soapysdrdevice_autogen: devices/soapysdr/CMakeFiles/soapysdrdevice_autogen.dir/build.make
.PHONY : soapysdrdevice_autogen

# Rule to build all files generated by this target.
devices/soapysdr/CMakeFiles/soapysdrdevice_autogen.dir/build: soapysdrdevice_autogen
.PHONY : devices/soapysdr/CMakeFiles/soapysdrdevice_autogen.dir/build

devices/soapysdr/CMakeFiles/soapysdrdevice_autogen.dir/clean:
	cd /opt/build/RPX-100-SDR/build/devices/soapysdr && $(CMAKE_COMMAND) -P CMakeFiles/soapysdrdevice_autogen.dir/cmake_clean.cmake
.PHONY : devices/soapysdr/CMakeFiles/soapysdrdevice_autogen.dir/clean

devices/soapysdr/CMakeFiles/soapysdrdevice_autogen.dir/depend:
	cd /opt/build/RPX-100-SDR/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /opt/build/RPX-100-SDR /opt/build/RPX-100-SDR/devices/soapysdr /opt/build/RPX-100-SDR/build /opt/build/RPX-100-SDR/build/devices/soapysdr /opt/build/RPX-100-SDR/build/devices/soapysdr/CMakeFiles/soapysdrdevice_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : devices/soapysdr/CMakeFiles/soapysdrdevice_autogen.dir/depend

