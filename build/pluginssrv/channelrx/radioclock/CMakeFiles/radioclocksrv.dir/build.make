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
include pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/compiler_depend.make

# Include the progress variables for this target.
include pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/progress.make

# Include the compile flags for this target's objects.
include pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/flags.make

pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/radioclocksrv_autogen/mocs_compilation.cpp.o: pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/flags.make
pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/radioclocksrv_autogen/mocs_compilation.cpp.o: pluginssrv/channelrx/radioclock/radioclocksrv_autogen/mocs_compilation.cpp
pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/radioclocksrv_autogen/mocs_compilation.cpp.o: pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/radioclocksrv_autogen/mocs_compilation.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/radioclock && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/radioclocksrv_autogen/mocs_compilation.cpp.o -MF CMakeFiles/radioclocksrv.dir/radioclocksrv_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/radioclocksrv.dir/radioclocksrv_autogen/mocs_compilation.cpp.o -c /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/radioclock/radioclocksrv_autogen/mocs_compilation.cpp

pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/radioclocksrv_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/radioclocksrv.dir/radioclocksrv_autogen/mocs_compilation.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/radioclock && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/radioclock/radioclocksrv_autogen/mocs_compilation.cpp > CMakeFiles/radioclocksrv.dir/radioclocksrv_autogen/mocs_compilation.cpp.i

pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/radioclocksrv_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/radioclocksrv.dir/radioclocksrv_autogen/mocs_compilation.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/radioclock && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/radioclock/radioclocksrv_autogen/mocs_compilation.cpp -o CMakeFiles/radioclocksrv.dir/radioclocksrv_autogen/mocs_compilation.cpp.s

pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/radioclock.cpp.o: pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/flags.make
pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/radioclock.cpp.o: ../plugins/channelrx/radioclock/radioclock.cpp
pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/radioclock.cpp.o: pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/radioclock.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/radioclock && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/radioclock.cpp.o -MF CMakeFiles/radioclocksrv.dir/radioclock.cpp.o.d -o CMakeFiles/radioclocksrv.dir/radioclock.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/radioclock/radioclock.cpp

pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/radioclock.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/radioclocksrv.dir/radioclock.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/radioclock && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/radioclock/radioclock.cpp > CMakeFiles/radioclocksrv.dir/radioclock.cpp.i

pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/radioclock.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/radioclocksrv.dir/radioclock.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/radioclock && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/radioclock/radioclock.cpp -o CMakeFiles/radioclocksrv.dir/radioclock.cpp.s

pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/radioclocksettings.cpp.o: pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/flags.make
pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/radioclocksettings.cpp.o: ../plugins/channelrx/radioclock/radioclocksettings.cpp
pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/radioclocksettings.cpp.o: pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/radioclocksettings.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/radioclock && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/radioclocksettings.cpp.o -MF CMakeFiles/radioclocksrv.dir/radioclocksettings.cpp.o.d -o CMakeFiles/radioclocksrv.dir/radioclocksettings.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/radioclock/radioclocksettings.cpp

pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/radioclocksettings.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/radioclocksrv.dir/radioclocksettings.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/radioclock && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/radioclock/radioclocksettings.cpp > CMakeFiles/radioclocksrv.dir/radioclocksettings.cpp.i

pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/radioclocksettings.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/radioclocksrv.dir/radioclocksettings.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/radioclock && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/radioclock/radioclocksettings.cpp -o CMakeFiles/radioclocksrv.dir/radioclocksettings.cpp.s

pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/radioclockbaseband.cpp.o: pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/flags.make
pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/radioclockbaseband.cpp.o: ../plugins/channelrx/radioclock/radioclockbaseband.cpp
pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/radioclockbaseband.cpp.o: pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/radioclockbaseband.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/radioclock && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/radioclockbaseband.cpp.o -MF CMakeFiles/radioclocksrv.dir/radioclockbaseband.cpp.o.d -o CMakeFiles/radioclocksrv.dir/radioclockbaseband.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/radioclock/radioclockbaseband.cpp

pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/radioclockbaseband.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/radioclocksrv.dir/radioclockbaseband.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/radioclock && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/radioclock/radioclockbaseband.cpp > CMakeFiles/radioclocksrv.dir/radioclockbaseband.cpp.i

pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/radioclockbaseband.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/radioclocksrv.dir/radioclockbaseband.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/radioclock && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/radioclock/radioclockbaseband.cpp -o CMakeFiles/radioclocksrv.dir/radioclockbaseband.cpp.s

pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/radioclocksink.cpp.o: pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/flags.make
pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/radioclocksink.cpp.o: ../plugins/channelrx/radioclock/radioclocksink.cpp
pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/radioclocksink.cpp.o: pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/radioclocksink.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/radioclock && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/radioclocksink.cpp.o -MF CMakeFiles/radioclocksrv.dir/radioclocksink.cpp.o.d -o CMakeFiles/radioclocksrv.dir/radioclocksink.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/radioclock/radioclocksink.cpp

pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/radioclocksink.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/radioclocksrv.dir/radioclocksink.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/radioclock && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/radioclock/radioclocksink.cpp > CMakeFiles/radioclocksrv.dir/radioclocksink.cpp.i

pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/radioclocksink.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/radioclocksrv.dir/radioclocksink.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/radioclock && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/radioclock/radioclocksink.cpp -o CMakeFiles/radioclocksrv.dir/radioclocksink.cpp.s

pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/radioclockplugin.cpp.o: pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/flags.make
pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/radioclockplugin.cpp.o: ../plugins/channelrx/radioclock/radioclockplugin.cpp
pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/radioclockplugin.cpp.o: pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/radioclockplugin.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/radioclock && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/radioclockplugin.cpp.o -MF CMakeFiles/radioclocksrv.dir/radioclockplugin.cpp.o.d -o CMakeFiles/radioclocksrv.dir/radioclockplugin.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/radioclock/radioclockplugin.cpp

pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/radioclockplugin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/radioclocksrv.dir/radioclockplugin.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/radioclock && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/radioclock/radioclockplugin.cpp > CMakeFiles/radioclocksrv.dir/radioclockplugin.cpp.i

pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/radioclockplugin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/radioclocksrv.dir/radioclockplugin.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/radioclock && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/radioclock/radioclockplugin.cpp -o CMakeFiles/radioclocksrv.dir/radioclockplugin.cpp.s

pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/radioclockwebapiadapter.cpp.o: pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/flags.make
pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/radioclockwebapiadapter.cpp.o: ../plugins/channelrx/radioclock/radioclockwebapiadapter.cpp
pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/radioclockwebapiadapter.cpp.o: pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/radioclockwebapiadapter.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/radioclock && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/radioclockwebapiadapter.cpp.o -MF CMakeFiles/radioclocksrv.dir/radioclockwebapiadapter.cpp.o.d -o CMakeFiles/radioclocksrv.dir/radioclockwebapiadapter.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/radioclock/radioclockwebapiadapter.cpp

pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/radioclockwebapiadapter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/radioclocksrv.dir/radioclockwebapiadapter.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/radioclock && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/radioclock/radioclockwebapiadapter.cpp > CMakeFiles/radioclocksrv.dir/radioclockwebapiadapter.cpp.i

pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/radioclockwebapiadapter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/radioclocksrv.dir/radioclockwebapiadapter.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/radioclock && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/radioclock/radioclockwebapiadapter.cpp -o CMakeFiles/radioclocksrv.dir/radioclockwebapiadapter.cpp.s

# Object files for target radioclocksrv
radioclocksrv_OBJECTS = \
"CMakeFiles/radioclocksrv.dir/radioclocksrv_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/radioclocksrv.dir/radioclock.cpp.o" \
"CMakeFiles/radioclocksrv.dir/radioclocksettings.cpp.o" \
"CMakeFiles/radioclocksrv.dir/radioclockbaseband.cpp.o" \
"CMakeFiles/radioclocksrv.dir/radioclocksink.cpp.o" \
"CMakeFiles/radioclocksrv.dir/radioclockplugin.cpp.o" \
"CMakeFiles/radioclocksrv.dir/radioclockwebapiadapter.cpp.o"

# External object files for target radioclocksrv
radioclocksrv_EXTERNAL_OBJECTS =

lib/pluginssrv/libradioclocksrv.so: pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/radioclocksrv_autogen/mocs_compilation.cpp.o
lib/pluginssrv/libradioclocksrv.so: pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/radioclock.cpp.o
lib/pluginssrv/libradioclocksrv.so: pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/radioclocksettings.cpp.o
lib/pluginssrv/libradioclocksrv.so: pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/radioclockbaseband.cpp.o
lib/pluginssrv/libradioclocksrv.so: pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/radioclocksink.cpp.o
lib/pluginssrv/libradioclocksrv.so: pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/radioclockplugin.cpp.o
lib/pluginssrv/libradioclocksrv.so: pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/radioclockwebapiadapter.cpp.o
lib/pluginssrv/libradioclocksrv.so: pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/build.make
lib/pluginssrv/libradioclocksrv.so: lib/libsdrbase.so
lib/pluginssrv/libradioclocksrv.so: /usr/lib/x86_64-linux-gnu/libopus.so
lib/pluginssrv/libradioclocksrv.so: /usr/lib/x86_64-linux-gnu/libm.so
lib/pluginssrv/libradioclocksrv.so: /usr/lib/x86_64-linux-gnu/libfftw3f.so
lib/pluginssrv/libradioclocksrv.so: /opt/install/serialdv/lib/libserialdv.so
lib/pluginssrv/libradioclocksrv.so: /opt/install/LimeSuite/lib/libLimeSuite.so
lib/pluginssrv/libradioclocksrv.so: /usr/lib/x86_64-linux-gnu/libQt5Multimedia.so.5.15.2
lib/pluginssrv/libradioclocksrv.so: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.15.2
lib/pluginssrv/libradioclocksrv.so: /usr/lib/x86_64-linux-gnu/libQt5WebSockets.so.5.15.2
lib/pluginssrv/libradioclocksrv.so: lib/libhttpserver.so
lib/pluginssrv/libradioclocksrv.so: lib/liblogging.so
lib/pluginssrv/libradioclocksrv.so: lib/libqrtplib.so
lib/pluginssrv/libradioclocksrv.so: lib/libswagger.so
lib/pluginssrv/libradioclocksrv.so: /usr/lib/x86_64-linux-gnu/libQt5Network.so.5.15.2
lib/pluginssrv/libradioclocksrv.so: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.15.2
lib/pluginssrv/libradioclocksrv.so: pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX shared library ../../../lib/pluginssrv/libradioclocksrv.so"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/radioclock && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/radioclocksrv.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/build: lib/pluginssrv/libradioclocksrv.so
.PHONY : pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/build

pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/clean:
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/radioclock && $(CMAKE_COMMAND) -P CMakeFiles/radioclocksrv.dir/cmake_clean.cmake
.PHONY : pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/clean

pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/depend:
	cd /opt/build/RPX-100-SDR/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /opt/build/RPX-100-SDR /opt/build/RPX-100-SDR/plugins/channelrx/radioclock /opt/build/RPX-100-SDR/build /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/radioclock /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : pluginssrv/channelrx/radioclock/CMakeFiles/radioclocksrv.dir/depend
