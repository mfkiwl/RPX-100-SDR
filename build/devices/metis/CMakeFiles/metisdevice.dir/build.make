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

# Include any dependencies generated for this target.
include devices/metis/CMakeFiles/metisdevice.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include devices/metis/CMakeFiles/metisdevice.dir/compiler_depend.make

# Include the progress variables for this target.
include devices/metis/CMakeFiles/metisdevice.dir/progress.make

# Include the compile flags for this target's objects.
include devices/metis/CMakeFiles/metisdevice.dir/flags.make

devices/metis/CMakeFiles/metisdevice.dir/metisdevice_autogen/mocs_compilation.cpp.o: devices/metis/CMakeFiles/metisdevice.dir/flags.make
devices/metis/CMakeFiles/metisdevice.dir/metisdevice_autogen/mocs_compilation.cpp.o: devices/metis/metisdevice_autogen/mocs_compilation.cpp
devices/metis/CMakeFiles/metisdevice.dir/metisdevice_autogen/mocs_compilation.cpp.o: devices/metis/CMakeFiles/metisdevice.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object devices/metis/CMakeFiles/metisdevice.dir/metisdevice_autogen/mocs_compilation.cpp.o"
	cd /opt/build/RPX-100-SDR/build/devices/metis && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT devices/metis/CMakeFiles/metisdevice.dir/metisdevice_autogen/mocs_compilation.cpp.o -MF CMakeFiles/metisdevice.dir/metisdevice_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/metisdevice.dir/metisdevice_autogen/mocs_compilation.cpp.o -c /opt/build/RPX-100-SDR/build/devices/metis/metisdevice_autogen/mocs_compilation.cpp

devices/metis/CMakeFiles/metisdevice.dir/metisdevice_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/metisdevice.dir/metisdevice_autogen/mocs_compilation.cpp.i"
	cd /opt/build/RPX-100-SDR/build/devices/metis && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/build/devices/metis/metisdevice_autogen/mocs_compilation.cpp > CMakeFiles/metisdevice.dir/metisdevice_autogen/mocs_compilation.cpp.i

devices/metis/CMakeFiles/metisdevice.dir/metisdevice_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/metisdevice.dir/metisdevice_autogen/mocs_compilation.cpp.s"
	cd /opt/build/RPX-100-SDR/build/devices/metis && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/build/devices/metis/metisdevice_autogen/mocs_compilation.cpp -o CMakeFiles/metisdevice.dir/metisdevice_autogen/mocs_compilation.cpp.s

devices/metis/CMakeFiles/metisdevice.dir/devicemetis.cpp.o: devices/metis/CMakeFiles/metisdevice.dir/flags.make
devices/metis/CMakeFiles/metisdevice.dir/devicemetis.cpp.o: ../devices/metis/devicemetis.cpp
devices/metis/CMakeFiles/metisdevice.dir/devicemetis.cpp.o: devices/metis/CMakeFiles/metisdevice.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object devices/metis/CMakeFiles/metisdevice.dir/devicemetis.cpp.o"
	cd /opt/build/RPX-100-SDR/build/devices/metis && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT devices/metis/CMakeFiles/metisdevice.dir/devicemetis.cpp.o -MF CMakeFiles/metisdevice.dir/devicemetis.cpp.o.d -o CMakeFiles/metisdevice.dir/devicemetis.cpp.o -c /opt/build/RPX-100-SDR/devices/metis/devicemetis.cpp

devices/metis/CMakeFiles/metisdevice.dir/devicemetis.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/metisdevice.dir/devicemetis.cpp.i"
	cd /opt/build/RPX-100-SDR/build/devices/metis && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/devices/metis/devicemetis.cpp > CMakeFiles/metisdevice.dir/devicemetis.cpp.i

devices/metis/CMakeFiles/metisdevice.dir/devicemetis.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/metisdevice.dir/devicemetis.cpp.s"
	cd /opt/build/RPX-100-SDR/build/devices/metis && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/devices/metis/devicemetis.cpp -o CMakeFiles/metisdevice.dir/devicemetis.cpp.s

devices/metis/CMakeFiles/metisdevice.dir/devicemetisscan.cpp.o: devices/metis/CMakeFiles/metisdevice.dir/flags.make
devices/metis/CMakeFiles/metisdevice.dir/devicemetisscan.cpp.o: ../devices/metis/devicemetisscan.cpp
devices/metis/CMakeFiles/metisdevice.dir/devicemetisscan.cpp.o: devices/metis/CMakeFiles/metisdevice.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object devices/metis/CMakeFiles/metisdevice.dir/devicemetisscan.cpp.o"
	cd /opt/build/RPX-100-SDR/build/devices/metis && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT devices/metis/CMakeFiles/metisdevice.dir/devicemetisscan.cpp.o -MF CMakeFiles/metisdevice.dir/devicemetisscan.cpp.o.d -o CMakeFiles/metisdevice.dir/devicemetisscan.cpp.o -c /opt/build/RPX-100-SDR/devices/metis/devicemetisscan.cpp

devices/metis/CMakeFiles/metisdevice.dir/devicemetisscan.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/metisdevice.dir/devicemetisscan.cpp.i"
	cd /opt/build/RPX-100-SDR/build/devices/metis && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/devices/metis/devicemetisscan.cpp > CMakeFiles/metisdevice.dir/devicemetisscan.cpp.i

devices/metis/CMakeFiles/metisdevice.dir/devicemetisscan.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/metisdevice.dir/devicemetisscan.cpp.s"
	cd /opt/build/RPX-100-SDR/build/devices/metis && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/devices/metis/devicemetisscan.cpp -o CMakeFiles/metisdevice.dir/devicemetisscan.cpp.s

# Object files for target metisdevice
metisdevice_OBJECTS = \
"CMakeFiles/metisdevice.dir/metisdevice_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/metisdevice.dir/devicemetis.cpp.o" \
"CMakeFiles/metisdevice.dir/devicemetisscan.cpp.o"

# External object files for target metisdevice
metisdevice_EXTERNAL_OBJECTS =

lib/libmetisdevice.so: devices/metis/CMakeFiles/metisdevice.dir/metisdevice_autogen/mocs_compilation.cpp.o
lib/libmetisdevice.so: devices/metis/CMakeFiles/metisdevice.dir/devicemetis.cpp.o
lib/libmetisdevice.so: devices/metis/CMakeFiles/metisdevice.dir/devicemetisscan.cpp.o
lib/libmetisdevice.so: devices/metis/CMakeFiles/metisdevice.dir/build.make
lib/libmetisdevice.so: lib/libsdrbase.so
lib/libmetisdevice.so: /usr/lib/x86_64-linux-gnu/libopus.so
lib/libmetisdevice.so: /usr/lib/x86_64-linux-gnu/libm.so
lib/libmetisdevice.so: /usr/lib/x86_64-linux-gnu/libfftw3f.so
lib/libmetisdevice.so: /opt/install/serialdv/lib/libserialdv.so
lib/libmetisdevice.so: /opt/install/LimeSuite/lib/libLimeSuite.so
lib/libmetisdevice.so: /usr/lib/x86_64-linux-gnu/libQt5Multimedia.so.5.15.2
lib/libmetisdevice.so: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.15.2
lib/libmetisdevice.so: /usr/lib/x86_64-linux-gnu/libQt5WebSockets.so.5.15.2
lib/libmetisdevice.so: lib/libhttpserver.so
lib/libmetisdevice.so: lib/liblogging.so
lib/libmetisdevice.so: lib/libqrtplib.so
lib/libmetisdevice.so: lib/libswagger.so
lib/libmetisdevice.so: /usr/lib/x86_64-linux-gnu/libQt5Network.so.5.15.2
lib/libmetisdevice.so: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.15.2
lib/libmetisdevice.so: devices/metis/CMakeFiles/metisdevice.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX shared library ../../lib/libmetisdevice.so"
	cd /opt/build/RPX-100-SDR/build/devices/metis && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/metisdevice.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
devices/metis/CMakeFiles/metisdevice.dir/build: lib/libmetisdevice.so
.PHONY : devices/metis/CMakeFiles/metisdevice.dir/build

devices/metis/CMakeFiles/metisdevice.dir/clean:
	cd /opt/build/RPX-100-SDR/build/devices/metis && $(CMAKE_COMMAND) -P CMakeFiles/metisdevice.dir/cmake_clean.cmake
.PHONY : devices/metis/CMakeFiles/metisdevice.dir/clean

devices/metis/CMakeFiles/metisdevice.dir/depend:
	cd /opt/build/RPX-100-SDR/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /opt/build/RPX-100-SDR /opt/build/RPX-100-SDR/devices/metis /opt/build/RPX-100-SDR/build /opt/build/RPX-100-SDR/build/devices/metis /opt/build/RPX-100-SDR/build/devices/metis/CMakeFiles/metisdevice.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : devices/metis/CMakeFiles/metisdevice.dir/depend
