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
include pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/compiler_depend.make

# Include the progress variables for this target.
include pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/progress.make

# Include the compile flags for this target's objects.
include pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/flags.make

pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/featurestartrackersrv_autogen/mocs_compilation.cpp.o: pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/flags.make
pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/featurestartrackersrv_autogen/mocs_compilation.cpp.o: pluginssrv/feature/startracker/featurestartrackersrv_autogen/mocs_compilation.cpp
pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/featurestartrackersrv_autogen/mocs_compilation.cpp.o: pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/featurestartrackersrv_autogen/mocs_compilation.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/startracker && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/featurestartrackersrv_autogen/mocs_compilation.cpp.o -MF CMakeFiles/featurestartrackersrv.dir/featurestartrackersrv_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/featurestartrackersrv.dir/featurestartrackersrv_autogen/mocs_compilation.cpp.o -c /opt/build/RPX-100-SDR/build/pluginssrv/feature/startracker/featurestartrackersrv_autogen/mocs_compilation.cpp

pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/featurestartrackersrv_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/featurestartrackersrv.dir/featurestartrackersrv_autogen/mocs_compilation.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/startracker && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/build/pluginssrv/feature/startracker/featurestartrackersrv_autogen/mocs_compilation.cpp > CMakeFiles/featurestartrackersrv.dir/featurestartrackersrv_autogen/mocs_compilation.cpp.i

pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/featurestartrackersrv_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/featurestartrackersrv.dir/featurestartrackersrv_autogen/mocs_compilation.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/startracker && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/build/pluginssrv/feature/startracker/featurestartrackersrv_autogen/mocs_compilation.cpp -o CMakeFiles/featurestartrackersrv.dir/featurestartrackersrv_autogen/mocs_compilation.cpp.s

pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/startracker.cpp.o: pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/flags.make
pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/startracker.cpp.o: ../plugins/feature/startracker/startracker.cpp
pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/startracker.cpp.o: pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/startracker.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/startracker && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/startracker.cpp.o -MF CMakeFiles/featurestartrackersrv.dir/startracker.cpp.o.d -o CMakeFiles/featurestartrackersrv.dir/startracker.cpp.o -c /opt/build/RPX-100-SDR/plugins/feature/startracker/startracker.cpp

pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/startracker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/featurestartrackersrv.dir/startracker.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/startracker && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/feature/startracker/startracker.cpp > CMakeFiles/featurestartrackersrv.dir/startracker.cpp.i

pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/startracker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/featurestartrackersrv.dir/startracker.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/startracker && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/feature/startracker/startracker.cpp -o CMakeFiles/featurestartrackersrv.dir/startracker.cpp.s

pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/startrackersettings.cpp.o: pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/flags.make
pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/startrackersettings.cpp.o: ../plugins/feature/startracker/startrackersettings.cpp
pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/startrackersettings.cpp.o: pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/startrackersettings.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/startracker && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/startrackersettings.cpp.o -MF CMakeFiles/featurestartrackersrv.dir/startrackersettings.cpp.o.d -o CMakeFiles/featurestartrackersrv.dir/startrackersettings.cpp.o -c /opt/build/RPX-100-SDR/plugins/feature/startracker/startrackersettings.cpp

pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/startrackersettings.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/featurestartrackersrv.dir/startrackersettings.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/startracker && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/feature/startracker/startrackersettings.cpp > CMakeFiles/featurestartrackersrv.dir/startrackersettings.cpp.i

pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/startrackersettings.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/featurestartrackersrv.dir/startrackersettings.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/startracker && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/feature/startracker/startrackersettings.cpp -o CMakeFiles/featurestartrackersrv.dir/startrackersettings.cpp.s

pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/startrackerplugin.cpp.o: pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/flags.make
pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/startrackerplugin.cpp.o: ../plugins/feature/startracker/startrackerplugin.cpp
pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/startrackerplugin.cpp.o: pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/startrackerplugin.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/startracker && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/startrackerplugin.cpp.o -MF CMakeFiles/featurestartrackersrv.dir/startrackerplugin.cpp.o.d -o CMakeFiles/featurestartrackersrv.dir/startrackerplugin.cpp.o -c /opt/build/RPX-100-SDR/plugins/feature/startracker/startrackerplugin.cpp

pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/startrackerplugin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/featurestartrackersrv.dir/startrackerplugin.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/startracker && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/feature/startracker/startrackerplugin.cpp > CMakeFiles/featurestartrackersrv.dir/startrackerplugin.cpp.i

pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/startrackerplugin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/featurestartrackersrv.dir/startrackerplugin.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/startracker && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/feature/startracker/startrackerplugin.cpp -o CMakeFiles/featurestartrackersrv.dir/startrackerplugin.cpp.s

pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/startrackerworker.cpp.o: pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/flags.make
pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/startrackerworker.cpp.o: ../plugins/feature/startracker/startrackerworker.cpp
pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/startrackerworker.cpp.o: pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/startrackerworker.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/startracker && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/startrackerworker.cpp.o -MF CMakeFiles/featurestartrackersrv.dir/startrackerworker.cpp.o.d -o CMakeFiles/featurestartrackersrv.dir/startrackerworker.cpp.o -c /opt/build/RPX-100-SDR/plugins/feature/startracker/startrackerworker.cpp

pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/startrackerworker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/featurestartrackersrv.dir/startrackerworker.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/startracker && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/feature/startracker/startrackerworker.cpp > CMakeFiles/featurestartrackersrv.dir/startrackerworker.cpp.i

pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/startrackerworker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/featurestartrackersrv.dir/startrackerworker.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/startracker && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/feature/startracker/startrackerworker.cpp -o CMakeFiles/featurestartrackersrv.dir/startrackerworker.cpp.s

pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/startrackerwebapiadapter.cpp.o: pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/flags.make
pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/startrackerwebapiadapter.cpp.o: ../plugins/feature/startracker/startrackerwebapiadapter.cpp
pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/startrackerwebapiadapter.cpp.o: pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/startrackerwebapiadapter.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/startracker && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/startrackerwebapiadapter.cpp.o -MF CMakeFiles/featurestartrackersrv.dir/startrackerwebapiadapter.cpp.o.d -o CMakeFiles/featurestartrackersrv.dir/startrackerwebapiadapter.cpp.o -c /opt/build/RPX-100-SDR/plugins/feature/startracker/startrackerwebapiadapter.cpp

pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/startrackerwebapiadapter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/featurestartrackersrv.dir/startrackerwebapiadapter.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/startracker && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/feature/startracker/startrackerwebapiadapter.cpp > CMakeFiles/featurestartrackersrv.dir/startrackerwebapiadapter.cpp.i

pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/startrackerwebapiadapter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/featurestartrackersrv.dir/startrackerwebapiadapter.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/startracker && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/feature/startracker/startrackerwebapiadapter.cpp -o CMakeFiles/featurestartrackersrv.dir/startrackerwebapiadapter.cpp.s

# Object files for target featurestartrackersrv
featurestartrackersrv_OBJECTS = \
"CMakeFiles/featurestartrackersrv.dir/featurestartrackersrv_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/featurestartrackersrv.dir/startracker.cpp.o" \
"CMakeFiles/featurestartrackersrv.dir/startrackersettings.cpp.o" \
"CMakeFiles/featurestartrackersrv.dir/startrackerplugin.cpp.o" \
"CMakeFiles/featurestartrackersrv.dir/startrackerworker.cpp.o" \
"CMakeFiles/featurestartrackersrv.dir/startrackerwebapiadapter.cpp.o"

# External object files for target featurestartrackersrv
featurestartrackersrv_EXTERNAL_OBJECTS =

lib/pluginssrv/libfeaturestartrackersrv.so: pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/featurestartrackersrv_autogen/mocs_compilation.cpp.o
lib/pluginssrv/libfeaturestartrackersrv.so: pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/startracker.cpp.o
lib/pluginssrv/libfeaturestartrackersrv.so: pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/startrackersettings.cpp.o
lib/pluginssrv/libfeaturestartrackersrv.so: pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/startrackerplugin.cpp.o
lib/pluginssrv/libfeaturestartrackersrv.so: pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/startrackerworker.cpp.o
lib/pluginssrv/libfeaturestartrackersrv.so: pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/startrackerwebapiadapter.cpp.o
lib/pluginssrv/libfeaturestartrackersrv.so: pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/build.make
lib/pluginssrv/libfeaturestartrackersrv.so: lib/libsdrbase.so
lib/pluginssrv/libfeaturestartrackersrv.so: /usr/lib/x86_64-linux-gnu/libopus.so
lib/pluginssrv/libfeaturestartrackersrv.so: /usr/lib/x86_64-linux-gnu/libm.so
lib/pluginssrv/libfeaturestartrackersrv.so: /usr/lib/x86_64-linux-gnu/libfftw3f.so
lib/pluginssrv/libfeaturestartrackersrv.so: /opt/install/serialdv/lib/libserialdv.so
lib/pluginssrv/libfeaturestartrackersrv.so: /opt/install/LimeSuite/lib/libLimeSuite.so
lib/pluginssrv/libfeaturestartrackersrv.so: /usr/lib/x86_64-linux-gnu/libQt5Multimedia.so.5.15.2
lib/pluginssrv/libfeaturestartrackersrv.so: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.15.2
lib/pluginssrv/libfeaturestartrackersrv.so: /usr/lib/x86_64-linux-gnu/libQt5WebSockets.so.5.15.2
lib/pluginssrv/libfeaturestartrackersrv.so: lib/libhttpserver.so
lib/pluginssrv/libfeaturestartrackersrv.so: lib/liblogging.so
lib/pluginssrv/libfeaturestartrackersrv.so: lib/libqrtplib.so
lib/pluginssrv/libfeaturestartrackersrv.so: lib/libswagger.so
lib/pluginssrv/libfeaturestartrackersrv.so: /usr/lib/x86_64-linux-gnu/libQt5Network.so.5.15.2
lib/pluginssrv/libfeaturestartrackersrv.so: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.15.2
lib/pluginssrv/libfeaturestartrackersrv.so: pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX shared library ../../../lib/pluginssrv/libfeaturestartrackersrv.so"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/startracker && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/featurestartrackersrv.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/build: lib/pluginssrv/libfeaturestartrackersrv.so
.PHONY : pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/build

pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/clean:
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/startracker && $(CMAKE_COMMAND) -P CMakeFiles/featurestartrackersrv.dir/cmake_clean.cmake
.PHONY : pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/clean

pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/depend:
	cd /opt/build/RPX-100-SDR/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /opt/build/RPX-100-SDR /opt/build/RPX-100-SDR/plugins/feature/startracker /opt/build/RPX-100-SDR/build /opt/build/RPX-100-SDR/build/pluginssrv/feature/startracker /opt/build/RPX-100-SDR/build/pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : pluginssrv/feature/startracker/CMakeFiles/featurestartrackersrv.dir/depend

