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
include CMakeFiles/RPX100srv.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/RPX100srv.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/RPX100srv.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/RPX100srv.dir/flags.make

CMakeFiles/RPX100srv.dir/RPX100srv_autogen/mocs_compilation.cpp.o: CMakeFiles/RPX100srv.dir/flags.make
CMakeFiles/RPX100srv.dir/RPX100srv_autogen/mocs_compilation.cpp.o: RPX100srv_autogen/mocs_compilation.cpp
CMakeFiles/RPX100srv.dir/RPX100srv_autogen/mocs_compilation.cpp.o: CMakeFiles/RPX100srv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/RPX100srv.dir/RPX100srv_autogen/mocs_compilation.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/RPX100srv.dir/RPX100srv_autogen/mocs_compilation.cpp.o -MF CMakeFiles/RPX100srv.dir/RPX100srv_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/RPX100srv.dir/RPX100srv_autogen/mocs_compilation.cpp.o -c /opt/build/RPX-100-SDR/build/RPX100srv_autogen/mocs_compilation.cpp

CMakeFiles/RPX100srv.dir/RPX100srv_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RPX100srv.dir/RPX100srv_autogen/mocs_compilation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/build/RPX100srv_autogen/mocs_compilation.cpp > CMakeFiles/RPX100srv.dir/RPX100srv_autogen/mocs_compilation.cpp.i

CMakeFiles/RPX100srv.dir/RPX100srv_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RPX100srv.dir/RPX100srv_autogen/mocs_compilation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/build/RPX100srv_autogen/mocs_compilation.cpp -o CMakeFiles/RPX100srv.dir/RPX100srv_autogen/mocs_compilation.cpp.s

CMakeFiles/RPX100srv.dir/appsrv/main.cpp.o: CMakeFiles/RPX100srv.dir/flags.make
CMakeFiles/RPX100srv.dir/appsrv/main.cpp.o: ../appsrv/main.cpp
CMakeFiles/RPX100srv.dir/appsrv/main.cpp.o: CMakeFiles/RPX100srv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/RPX100srv.dir/appsrv/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/RPX100srv.dir/appsrv/main.cpp.o -MF CMakeFiles/RPX100srv.dir/appsrv/main.cpp.o.d -o CMakeFiles/RPX100srv.dir/appsrv/main.cpp.o -c /opt/build/RPX-100-SDR/appsrv/main.cpp

CMakeFiles/RPX100srv.dir/appsrv/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RPX100srv.dir/appsrv/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/appsrv/main.cpp > CMakeFiles/RPX100srv.dir/appsrv/main.cpp.i

CMakeFiles/RPX100srv.dir/appsrv/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RPX100srv.dir/appsrv/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/appsrv/main.cpp -o CMakeFiles/RPX100srv.dir/appsrv/main.cpp.s

# Object files for target RPX100srv
RPX100srv_OBJECTS = \
"CMakeFiles/RPX100srv.dir/RPX100srv_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/RPX100srv.dir/appsrv/main.cpp.o"

# External object files for target RPX100srv
RPX100srv_EXTERNAL_OBJECTS =

RPX100srv: CMakeFiles/RPX100srv.dir/RPX100srv_autogen/mocs_compilation.cpp.o
RPX100srv: CMakeFiles/RPX100srv.dir/appsrv/main.cpp.o
RPX100srv: CMakeFiles/RPX100srv.dir/build.make
RPX100srv: lib/libsdrsrv.so
RPX100srv: lib/libsdrbase.so
RPX100srv: /usr/lib/x86_64-linux-gnu/libQt5Multimedia.so.5.15.2
RPX100srv: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.15.2
RPX100srv: /usr/lib/x86_64-linux-gnu/libopus.so
RPX100srv: /usr/lib/x86_64-linux-gnu/libm.so
RPX100srv: /usr/lib/x86_64-linux-gnu/libfftw3f.so
RPX100srv: /opt/install/serialdv/lib/libserialdv.so
RPX100srv: /opt/install/LimeSuite/lib/libLimeSuite.so
RPX100srv: /usr/lib/x86_64-linux-gnu/libQt5WebSockets.so.5.15.2
RPX100srv: lib/libhttpserver.so
RPX100srv: lib/libqrtplib.so
RPX100srv: lib/libswagger.so
RPX100srv: lib/liblogging.so
RPX100srv: /usr/lib/x86_64-linux-gnu/libQt5Network.so.5.15.2
RPX100srv: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.15.2
RPX100srv: CMakeFiles/RPX100srv.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable RPX100srv"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/RPX100srv.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/RPX100srv.dir/build: RPX100srv
.PHONY : CMakeFiles/RPX100srv.dir/build

CMakeFiles/RPX100srv.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/RPX100srv.dir/cmake_clean.cmake
.PHONY : CMakeFiles/RPX100srv.dir/clean

CMakeFiles/RPX100srv.dir/depend:
	cd /opt/build/RPX-100-SDR/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /opt/build/RPX-100-SDR /opt/build/RPX-100-SDR /opt/build/RPX-100-SDR/build /opt/build/RPX-100-SDR/build /opt/build/RPX-100-SDR/build/CMakeFiles/RPX100srv.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/RPX100srv.dir/depend

