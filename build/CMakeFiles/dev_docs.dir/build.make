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

# Utility rule file for dev_docs.

# Include any custom commands dependencies for this target.
include CMakeFiles/dev_docs.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/dev_docs.dir/progress.make

dev_docs: CMakeFiles/dev_docs.dir/build.make
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating developer documentation with Doxygen"
	/usr/bin/doxygen /opt/build/RPX-100-SDR/build/Doxyfile
.PHONY : dev_docs

# Rule to build all files generated by this target.
CMakeFiles/dev_docs.dir/build: dev_docs
.PHONY : CMakeFiles/dev_docs.dir/build

CMakeFiles/dev_docs.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/dev_docs.dir/cmake_clean.cmake
.PHONY : CMakeFiles/dev_docs.dir/clean

CMakeFiles/dev_docs.dir/depend:
	cd /opt/build/RPX-100-SDR/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /opt/build/RPX-100-SDR /opt/build/RPX-100-SDR /opt/build/RPX-100-SDR/build /opt/build/RPX-100-SDR/build /opt/build/RPX-100-SDR/build/CMakeFiles/dev_docs.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/dev_docs.dir/depend

