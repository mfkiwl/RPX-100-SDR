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
include pluginssrv/feature/ais/CMakeFiles/featureaissrv.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include pluginssrv/feature/ais/CMakeFiles/featureaissrv.dir/compiler_depend.make

# Include the progress variables for this target.
include pluginssrv/feature/ais/CMakeFiles/featureaissrv.dir/progress.make

# Include the compile flags for this target's objects.
include pluginssrv/feature/ais/CMakeFiles/featureaissrv.dir/flags.make

pluginssrv/feature/ais/CMakeFiles/featureaissrv.dir/featureaissrv_autogen/mocs_compilation.cpp.o: pluginssrv/feature/ais/CMakeFiles/featureaissrv.dir/flags.make
pluginssrv/feature/ais/CMakeFiles/featureaissrv.dir/featureaissrv_autogen/mocs_compilation.cpp.o: pluginssrv/feature/ais/featureaissrv_autogen/mocs_compilation.cpp
pluginssrv/feature/ais/CMakeFiles/featureaissrv.dir/featureaissrv_autogen/mocs_compilation.cpp.o: pluginssrv/feature/ais/CMakeFiles/featureaissrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object pluginssrv/feature/ais/CMakeFiles/featureaissrv.dir/featureaissrv_autogen/mocs_compilation.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/ais && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/feature/ais/CMakeFiles/featureaissrv.dir/featureaissrv_autogen/mocs_compilation.cpp.o -MF CMakeFiles/featureaissrv.dir/featureaissrv_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/featureaissrv.dir/featureaissrv_autogen/mocs_compilation.cpp.o -c /opt/build/RPX-100-SDR/build/pluginssrv/feature/ais/featureaissrv_autogen/mocs_compilation.cpp

pluginssrv/feature/ais/CMakeFiles/featureaissrv.dir/featureaissrv_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/featureaissrv.dir/featureaissrv_autogen/mocs_compilation.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/ais && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/build/pluginssrv/feature/ais/featureaissrv_autogen/mocs_compilation.cpp > CMakeFiles/featureaissrv.dir/featureaissrv_autogen/mocs_compilation.cpp.i

pluginssrv/feature/ais/CMakeFiles/featureaissrv.dir/featureaissrv_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/featureaissrv.dir/featureaissrv_autogen/mocs_compilation.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/ais && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/build/pluginssrv/feature/ais/featureaissrv_autogen/mocs_compilation.cpp -o CMakeFiles/featureaissrv.dir/featureaissrv_autogen/mocs_compilation.cpp.s

pluginssrv/feature/ais/CMakeFiles/featureaissrv.dir/ais.cpp.o: pluginssrv/feature/ais/CMakeFiles/featureaissrv.dir/flags.make
pluginssrv/feature/ais/CMakeFiles/featureaissrv.dir/ais.cpp.o: ../plugins/feature/ais/ais.cpp
pluginssrv/feature/ais/CMakeFiles/featureaissrv.dir/ais.cpp.o: pluginssrv/feature/ais/CMakeFiles/featureaissrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object pluginssrv/feature/ais/CMakeFiles/featureaissrv.dir/ais.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/ais && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/feature/ais/CMakeFiles/featureaissrv.dir/ais.cpp.o -MF CMakeFiles/featureaissrv.dir/ais.cpp.o.d -o CMakeFiles/featureaissrv.dir/ais.cpp.o -c /opt/build/RPX-100-SDR/plugins/feature/ais/ais.cpp

pluginssrv/feature/ais/CMakeFiles/featureaissrv.dir/ais.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/featureaissrv.dir/ais.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/ais && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/feature/ais/ais.cpp > CMakeFiles/featureaissrv.dir/ais.cpp.i

pluginssrv/feature/ais/CMakeFiles/featureaissrv.dir/ais.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/featureaissrv.dir/ais.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/ais && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/feature/ais/ais.cpp -o CMakeFiles/featureaissrv.dir/ais.cpp.s

pluginssrv/feature/ais/CMakeFiles/featureaissrv.dir/aissettings.cpp.o: pluginssrv/feature/ais/CMakeFiles/featureaissrv.dir/flags.make
pluginssrv/feature/ais/CMakeFiles/featureaissrv.dir/aissettings.cpp.o: ../plugins/feature/ais/aissettings.cpp
pluginssrv/feature/ais/CMakeFiles/featureaissrv.dir/aissettings.cpp.o: pluginssrv/feature/ais/CMakeFiles/featureaissrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object pluginssrv/feature/ais/CMakeFiles/featureaissrv.dir/aissettings.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/ais && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/feature/ais/CMakeFiles/featureaissrv.dir/aissettings.cpp.o -MF CMakeFiles/featureaissrv.dir/aissettings.cpp.o.d -o CMakeFiles/featureaissrv.dir/aissettings.cpp.o -c /opt/build/RPX-100-SDR/plugins/feature/ais/aissettings.cpp

pluginssrv/feature/ais/CMakeFiles/featureaissrv.dir/aissettings.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/featureaissrv.dir/aissettings.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/ais && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/feature/ais/aissettings.cpp > CMakeFiles/featureaissrv.dir/aissettings.cpp.i

pluginssrv/feature/ais/CMakeFiles/featureaissrv.dir/aissettings.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/featureaissrv.dir/aissettings.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/ais && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/feature/ais/aissettings.cpp -o CMakeFiles/featureaissrv.dir/aissettings.cpp.s

pluginssrv/feature/ais/CMakeFiles/featureaissrv.dir/aisplugin.cpp.o: pluginssrv/feature/ais/CMakeFiles/featureaissrv.dir/flags.make
pluginssrv/feature/ais/CMakeFiles/featureaissrv.dir/aisplugin.cpp.o: ../plugins/feature/ais/aisplugin.cpp
pluginssrv/feature/ais/CMakeFiles/featureaissrv.dir/aisplugin.cpp.o: pluginssrv/feature/ais/CMakeFiles/featureaissrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object pluginssrv/feature/ais/CMakeFiles/featureaissrv.dir/aisplugin.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/ais && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/feature/ais/CMakeFiles/featureaissrv.dir/aisplugin.cpp.o -MF CMakeFiles/featureaissrv.dir/aisplugin.cpp.o.d -o CMakeFiles/featureaissrv.dir/aisplugin.cpp.o -c /opt/build/RPX-100-SDR/plugins/feature/ais/aisplugin.cpp

pluginssrv/feature/ais/CMakeFiles/featureaissrv.dir/aisplugin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/featureaissrv.dir/aisplugin.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/ais && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/feature/ais/aisplugin.cpp > CMakeFiles/featureaissrv.dir/aisplugin.cpp.i

pluginssrv/feature/ais/CMakeFiles/featureaissrv.dir/aisplugin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/featureaissrv.dir/aisplugin.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/ais && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/feature/ais/aisplugin.cpp -o CMakeFiles/featureaissrv.dir/aisplugin.cpp.s

pluginssrv/feature/ais/CMakeFiles/featureaissrv.dir/aiswebapiadapter.cpp.o: pluginssrv/feature/ais/CMakeFiles/featureaissrv.dir/flags.make
pluginssrv/feature/ais/CMakeFiles/featureaissrv.dir/aiswebapiadapter.cpp.o: ../plugins/feature/ais/aiswebapiadapter.cpp
pluginssrv/feature/ais/CMakeFiles/featureaissrv.dir/aiswebapiadapter.cpp.o: pluginssrv/feature/ais/CMakeFiles/featureaissrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object pluginssrv/feature/ais/CMakeFiles/featureaissrv.dir/aiswebapiadapter.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/ais && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/feature/ais/CMakeFiles/featureaissrv.dir/aiswebapiadapter.cpp.o -MF CMakeFiles/featureaissrv.dir/aiswebapiadapter.cpp.o.d -o CMakeFiles/featureaissrv.dir/aiswebapiadapter.cpp.o -c /opt/build/RPX-100-SDR/plugins/feature/ais/aiswebapiadapter.cpp

pluginssrv/feature/ais/CMakeFiles/featureaissrv.dir/aiswebapiadapter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/featureaissrv.dir/aiswebapiadapter.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/ais && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/feature/ais/aiswebapiadapter.cpp > CMakeFiles/featureaissrv.dir/aiswebapiadapter.cpp.i

pluginssrv/feature/ais/CMakeFiles/featureaissrv.dir/aiswebapiadapter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/featureaissrv.dir/aiswebapiadapter.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/ais && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/feature/ais/aiswebapiadapter.cpp -o CMakeFiles/featureaissrv.dir/aiswebapiadapter.cpp.s

# Object files for target featureaissrv
featureaissrv_OBJECTS = \
"CMakeFiles/featureaissrv.dir/featureaissrv_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/featureaissrv.dir/ais.cpp.o" \
"CMakeFiles/featureaissrv.dir/aissettings.cpp.o" \
"CMakeFiles/featureaissrv.dir/aisplugin.cpp.o" \
"CMakeFiles/featureaissrv.dir/aiswebapiadapter.cpp.o"

# External object files for target featureaissrv
featureaissrv_EXTERNAL_OBJECTS =

lib/pluginssrv/libfeatureaissrv.so: pluginssrv/feature/ais/CMakeFiles/featureaissrv.dir/featureaissrv_autogen/mocs_compilation.cpp.o
lib/pluginssrv/libfeatureaissrv.so: pluginssrv/feature/ais/CMakeFiles/featureaissrv.dir/ais.cpp.o
lib/pluginssrv/libfeatureaissrv.so: pluginssrv/feature/ais/CMakeFiles/featureaissrv.dir/aissettings.cpp.o
lib/pluginssrv/libfeatureaissrv.so: pluginssrv/feature/ais/CMakeFiles/featureaissrv.dir/aisplugin.cpp.o
lib/pluginssrv/libfeatureaissrv.so: pluginssrv/feature/ais/CMakeFiles/featureaissrv.dir/aiswebapiadapter.cpp.o
lib/pluginssrv/libfeatureaissrv.so: pluginssrv/feature/ais/CMakeFiles/featureaissrv.dir/build.make
lib/pluginssrv/libfeatureaissrv.so: lib/libsdrbase.so
lib/pluginssrv/libfeatureaissrv.so: /usr/lib/x86_64-linux-gnu/libopus.so
lib/pluginssrv/libfeatureaissrv.so: /usr/lib/x86_64-linux-gnu/libm.so
lib/pluginssrv/libfeatureaissrv.so: /usr/lib/x86_64-linux-gnu/libfftw3f.so
lib/pluginssrv/libfeatureaissrv.so: /opt/install/serialdv/lib/libserialdv.so
lib/pluginssrv/libfeatureaissrv.so: /opt/install/LimeSuite/lib/libLimeSuite.so
lib/pluginssrv/libfeatureaissrv.so: /usr/lib/x86_64-linux-gnu/libQt5Multimedia.so.5.15.2
lib/pluginssrv/libfeatureaissrv.so: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.15.2
lib/pluginssrv/libfeatureaissrv.so: /usr/lib/x86_64-linux-gnu/libQt5WebSockets.so.5.15.2
lib/pluginssrv/libfeatureaissrv.so: lib/libhttpserver.so
lib/pluginssrv/libfeatureaissrv.so: lib/liblogging.so
lib/pluginssrv/libfeatureaissrv.so: lib/libqrtplib.so
lib/pluginssrv/libfeatureaissrv.so: lib/libswagger.so
lib/pluginssrv/libfeatureaissrv.so: /usr/lib/x86_64-linux-gnu/libQt5Network.so.5.15.2
lib/pluginssrv/libfeatureaissrv.so: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.15.2
lib/pluginssrv/libfeatureaissrv.so: pluginssrv/feature/ais/CMakeFiles/featureaissrv.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX shared library ../../../lib/pluginssrv/libfeatureaissrv.so"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/ais && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/featureaissrv.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
pluginssrv/feature/ais/CMakeFiles/featureaissrv.dir/build: lib/pluginssrv/libfeatureaissrv.so
.PHONY : pluginssrv/feature/ais/CMakeFiles/featureaissrv.dir/build

pluginssrv/feature/ais/CMakeFiles/featureaissrv.dir/clean:
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/ais && $(CMAKE_COMMAND) -P CMakeFiles/featureaissrv.dir/cmake_clean.cmake
.PHONY : pluginssrv/feature/ais/CMakeFiles/featureaissrv.dir/clean

pluginssrv/feature/ais/CMakeFiles/featureaissrv.dir/depend:
	cd /opt/build/RPX-100-SDR/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /opt/build/RPX-100-SDR /opt/build/RPX-100-SDR/plugins/feature/ais /opt/build/RPX-100-SDR/build /opt/build/RPX-100-SDR/build/pluginssrv/feature/ais /opt/build/RPX-100-SDR/build/pluginssrv/feature/ais/CMakeFiles/featureaissrv.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : pluginssrv/feature/ais/CMakeFiles/featureaissrv.dir/depend

