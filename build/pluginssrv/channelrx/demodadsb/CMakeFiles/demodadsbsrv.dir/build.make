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
include pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/compiler_depend.make

# Include the progress variables for this target.
include pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/progress.make

# Include the compile flags for this target's objects.
include pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/flags.make

pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/demodadsbsrv_autogen/mocs_compilation.cpp.o: pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/flags.make
pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/demodadsbsrv_autogen/mocs_compilation.cpp.o: pluginssrv/channelrx/demodadsb/demodadsbsrv_autogen/mocs_compilation.cpp
pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/demodadsbsrv_autogen/mocs_compilation.cpp.o: pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/demodadsbsrv_autogen/mocs_compilation.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodadsb && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/demodadsbsrv_autogen/mocs_compilation.cpp.o -MF CMakeFiles/demodadsbsrv.dir/demodadsbsrv_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/demodadsbsrv.dir/demodadsbsrv_autogen/mocs_compilation.cpp.o -c /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodadsb/demodadsbsrv_autogen/mocs_compilation.cpp

pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/demodadsbsrv_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demodadsbsrv.dir/demodadsbsrv_autogen/mocs_compilation.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodadsb && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodadsb/demodadsbsrv_autogen/mocs_compilation.cpp > CMakeFiles/demodadsbsrv.dir/demodadsbsrv_autogen/mocs_compilation.cpp.i

pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/demodadsbsrv_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demodadsbsrv.dir/demodadsbsrv_autogen/mocs_compilation.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodadsb && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodadsb/demodadsbsrv_autogen/mocs_compilation.cpp -o CMakeFiles/demodadsbsrv.dir/demodadsbsrv_autogen/mocs_compilation.cpp.s

pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbdemod.cpp.o: pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/flags.make
pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbdemod.cpp.o: ../plugins/channelrx/demodadsb/adsbdemod.cpp
pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbdemod.cpp.o: pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbdemod.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodadsb && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbdemod.cpp.o -MF CMakeFiles/demodadsbsrv.dir/adsbdemod.cpp.o.d -o CMakeFiles/demodadsbsrv.dir/adsbdemod.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/demodadsb/adsbdemod.cpp

pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbdemod.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demodadsbsrv.dir/adsbdemod.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodadsb && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/demodadsb/adsbdemod.cpp > CMakeFiles/demodadsbsrv.dir/adsbdemod.cpp.i

pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbdemod.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demodadsbsrv.dir/adsbdemod.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodadsb && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/demodadsb/adsbdemod.cpp -o CMakeFiles/demodadsbsrv.dir/adsbdemod.cpp.s

pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbdemodsettings.cpp.o: pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/flags.make
pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbdemodsettings.cpp.o: ../plugins/channelrx/demodadsb/adsbdemodsettings.cpp
pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbdemodsettings.cpp.o: pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbdemodsettings.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodadsb && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbdemodsettings.cpp.o -MF CMakeFiles/demodadsbsrv.dir/adsbdemodsettings.cpp.o.d -o CMakeFiles/demodadsbsrv.dir/adsbdemodsettings.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/demodadsb/adsbdemodsettings.cpp

pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbdemodsettings.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demodadsbsrv.dir/adsbdemodsettings.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodadsb && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/demodadsb/adsbdemodsettings.cpp > CMakeFiles/demodadsbsrv.dir/adsbdemodsettings.cpp.i

pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbdemodsettings.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demodadsbsrv.dir/adsbdemodsettings.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodadsb && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/demodadsb/adsbdemodsettings.cpp -o CMakeFiles/demodadsbsrv.dir/adsbdemodsettings.cpp.s

pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbdemodwebapiadapter.cpp.o: pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/flags.make
pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbdemodwebapiadapter.cpp.o: ../plugins/channelrx/demodadsb/adsbdemodwebapiadapter.cpp
pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbdemodwebapiadapter.cpp.o: pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbdemodwebapiadapter.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodadsb && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbdemodwebapiadapter.cpp.o -MF CMakeFiles/demodadsbsrv.dir/adsbdemodwebapiadapter.cpp.o.d -o CMakeFiles/demodadsbsrv.dir/adsbdemodwebapiadapter.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/demodadsb/adsbdemodwebapiadapter.cpp

pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbdemodwebapiadapter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demodadsbsrv.dir/adsbdemodwebapiadapter.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodadsb && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/demodadsb/adsbdemodwebapiadapter.cpp > CMakeFiles/demodadsbsrv.dir/adsbdemodwebapiadapter.cpp.i

pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbdemodwebapiadapter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demodadsbsrv.dir/adsbdemodwebapiadapter.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodadsb && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/demodadsb/adsbdemodwebapiadapter.cpp -o CMakeFiles/demodadsbsrv.dir/adsbdemodwebapiadapter.cpp.s

pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbplugin.cpp.o: pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/flags.make
pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbplugin.cpp.o: ../plugins/channelrx/demodadsb/adsbplugin.cpp
pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbplugin.cpp.o: pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbplugin.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodadsb && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbplugin.cpp.o -MF CMakeFiles/demodadsbsrv.dir/adsbplugin.cpp.o.d -o CMakeFiles/demodadsbsrv.dir/adsbplugin.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/demodadsb/adsbplugin.cpp

pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbplugin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demodadsbsrv.dir/adsbplugin.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodadsb && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/demodadsb/adsbplugin.cpp > CMakeFiles/demodadsbsrv.dir/adsbplugin.cpp.i

pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbplugin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demodadsbsrv.dir/adsbplugin.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodadsb && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/demodadsb/adsbplugin.cpp -o CMakeFiles/demodadsbsrv.dir/adsbplugin.cpp.s

pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbdemodsink.cpp.o: pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/flags.make
pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbdemodsink.cpp.o: ../plugins/channelrx/demodadsb/adsbdemodsink.cpp
pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbdemodsink.cpp.o: pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbdemodsink.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodadsb && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbdemodsink.cpp.o -MF CMakeFiles/demodadsbsrv.dir/adsbdemodsink.cpp.o.d -o CMakeFiles/demodadsbsrv.dir/adsbdemodsink.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/demodadsb/adsbdemodsink.cpp

pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbdemodsink.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demodadsbsrv.dir/adsbdemodsink.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodadsb && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/demodadsb/adsbdemodsink.cpp > CMakeFiles/demodadsbsrv.dir/adsbdemodsink.cpp.i

pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbdemodsink.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demodadsbsrv.dir/adsbdemodsink.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodadsb && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/demodadsb/adsbdemodsink.cpp -o CMakeFiles/demodadsbsrv.dir/adsbdemodsink.cpp.s

pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbdemodsinkworker.cpp.o: pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/flags.make
pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbdemodsinkworker.cpp.o: ../plugins/channelrx/demodadsb/adsbdemodsinkworker.cpp
pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbdemodsinkworker.cpp.o: pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbdemodsinkworker.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodadsb && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbdemodsinkworker.cpp.o -MF CMakeFiles/demodadsbsrv.dir/adsbdemodsinkworker.cpp.o.d -o CMakeFiles/demodadsbsrv.dir/adsbdemodsinkworker.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/demodadsb/adsbdemodsinkworker.cpp

pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbdemodsinkworker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demodadsbsrv.dir/adsbdemodsinkworker.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodadsb && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/demodadsb/adsbdemodsinkworker.cpp > CMakeFiles/demodadsbsrv.dir/adsbdemodsinkworker.cpp.i

pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbdemodsinkworker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demodadsbsrv.dir/adsbdemodsinkworker.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodadsb && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/demodadsb/adsbdemodsinkworker.cpp -o CMakeFiles/demodadsbsrv.dir/adsbdemodsinkworker.cpp.s

pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbdemodbaseband.cpp.o: pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/flags.make
pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbdemodbaseband.cpp.o: ../plugins/channelrx/demodadsb/adsbdemodbaseband.cpp
pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbdemodbaseband.cpp.o: pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbdemodbaseband.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodadsb && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbdemodbaseband.cpp.o -MF CMakeFiles/demodadsbsrv.dir/adsbdemodbaseband.cpp.o.d -o CMakeFiles/demodadsbsrv.dir/adsbdemodbaseband.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/demodadsb/adsbdemodbaseband.cpp

pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbdemodbaseband.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demodadsbsrv.dir/adsbdemodbaseband.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodadsb && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/demodadsb/adsbdemodbaseband.cpp > CMakeFiles/demodadsbsrv.dir/adsbdemodbaseband.cpp.i

pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbdemodbaseband.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demodadsbsrv.dir/adsbdemodbaseband.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodadsb && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/demodadsb/adsbdemodbaseband.cpp -o CMakeFiles/demodadsbsrv.dir/adsbdemodbaseband.cpp.s

pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbdemodreport.cpp.o: pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/flags.make
pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbdemodreport.cpp.o: ../plugins/channelrx/demodadsb/adsbdemodreport.cpp
pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbdemodreport.cpp.o: pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbdemodreport.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodadsb && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbdemodreport.cpp.o -MF CMakeFiles/demodadsbsrv.dir/adsbdemodreport.cpp.o.d -o CMakeFiles/demodadsbsrv.dir/adsbdemodreport.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/demodadsb/adsbdemodreport.cpp

pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbdemodreport.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demodadsbsrv.dir/adsbdemodreport.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodadsb && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/demodadsb/adsbdemodreport.cpp > CMakeFiles/demodadsbsrv.dir/adsbdemodreport.cpp.i

pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbdemodreport.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demodadsbsrv.dir/adsbdemodreport.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodadsb && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/demodadsb/adsbdemodreport.cpp -o CMakeFiles/demodadsbsrv.dir/adsbdemodreport.cpp.s

pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbdemodworker.cpp.o: pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/flags.make
pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbdemodworker.cpp.o: ../plugins/channelrx/demodadsb/adsbdemodworker.cpp
pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbdemodworker.cpp.o: pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbdemodworker.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodadsb && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbdemodworker.cpp.o -MF CMakeFiles/demodadsbsrv.dir/adsbdemodworker.cpp.o.d -o CMakeFiles/demodadsbsrv.dir/adsbdemodworker.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/demodadsb/adsbdemodworker.cpp

pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbdemodworker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demodadsbsrv.dir/adsbdemodworker.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodadsb && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/demodadsb/adsbdemodworker.cpp > CMakeFiles/demodadsbsrv.dir/adsbdemodworker.cpp.i

pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbdemodworker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demodadsbsrv.dir/adsbdemodworker.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodadsb && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/demodadsb/adsbdemodworker.cpp -o CMakeFiles/demodadsbsrv.dir/adsbdemodworker.cpp.s

# Object files for target demodadsbsrv
demodadsbsrv_OBJECTS = \
"CMakeFiles/demodadsbsrv.dir/demodadsbsrv_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/demodadsbsrv.dir/adsbdemod.cpp.o" \
"CMakeFiles/demodadsbsrv.dir/adsbdemodsettings.cpp.o" \
"CMakeFiles/demodadsbsrv.dir/adsbdemodwebapiadapter.cpp.o" \
"CMakeFiles/demodadsbsrv.dir/adsbplugin.cpp.o" \
"CMakeFiles/demodadsbsrv.dir/adsbdemodsink.cpp.o" \
"CMakeFiles/demodadsbsrv.dir/adsbdemodsinkworker.cpp.o" \
"CMakeFiles/demodadsbsrv.dir/adsbdemodbaseband.cpp.o" \
"CMakeFiles/demodadsbsrv.dir/adsbdemodreport.cpp.o" \
"CMakeFiles/demodadsbsrv.dir/adsbdemodworker.cpp.o"

# External object files for target demodadsbsrv
demodadsbsrv_EXTERNAL_OBJECTS =

lib/pluginssrv/libdemodadsbsrv.so: pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/demodadsbsrv_autogen/mocs_compilation.cpp.o
lib/pluginssrv/libdemodadsbsrv.so: pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbdemod.cpp.o
lib/pluginssrv/libdemodadsbsrv.so: pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbdemodsettings.cpp.o
lib/pluginssrv/libdemodadsbsrv.so: pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbdemodwebapiadapter.cpp.o
lib/pluginssrv/libdemodadsbsrv.so: pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbplugin.cpp.o
lib/pluginssrv/libdemodadsbsrv.so: pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbdemodsink.cpp.o
lib/pluginssrv/libdemodadsbsrv.so: pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbdemodsinkworker.cpp.o
lib/pluginssrv/libdemodadsbsrv.so: pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbdemodbaseband.cpp.o
lib/pluginssrv/libdemodadsbsrv.so: pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbdemodreport.cpp.o
lib/pluginssrv/libdemodadsbsrv.so: pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/adsbdemodworker.cpp.o
lib/pluginssrv/libdemodadsbsrv.so: pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/build.make
lib/pluginssrv/libdemodadsbsrv.so: lib/libsdrbase.so
lib/pluginssrv/libdemodadsbsrv.so: lib/libswagger.so
lib/pluginssrv/libdemodadsbsrv.so: /usr/lib/x86_64-linux-gnu/libopus.so
lib/pluginssrv/libdemodadsbsrv.so: /usr/lib/x86_64-linux-gnu/libm.so
lib/pluginssrv/libdemodadsbsrv.so: /usr/lib/x86_64-linux-gnu/libfftw3f.so
lib/pluginssrv/libdemodadsbsrv.so: /opt/install/serialdv/lib/libserialdv.so
lib/pluginssrv/libdemodadsbsrv.so: /opt/install/LimeSuite/lib/libLimeSuite.so
lib/pluginssrv/libdemodadsbsrv.so: /usr/lib/x86_64-linux-gnu/libQt5Multimedia.so.5.15.2
lib/pluginssrv/libdemodadsbsrv.so: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.15.2
lib/pluginssrv/libdemodadsbsrv.so: /usr/lib/x86_64-linux-gnu/libQt5WebSockets.so.5.15.2
lib/pluginssrv/libdemodadsbsrv.so: lib/libhttpserver.so
lib/pluginssrv/libdemodadsbsrv.so: lib/liblogging.so
lib/pluginssrv/libdemodadsbsrv.so: lib/libqrtplib.so
lib/pluginssrv/libdemodadsbsrv.so: /usr/lib/x86_64-linux-gnu/libQt5Network.so.5.15.2
lib/pluginssrv/libdemodadsbsrv.so: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.15.2
lib/pluginssrv/libdemodadsbsrv.so: pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX shared library ../../../lib/pluginssrv/libdemodadsbsrv.so"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodadsb && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/demodadsbsrv.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/build: lib/pluginssrv/libdemodadsbsrv.so
.PHONY : pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/build

pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/clean:
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodadsb && $(CMAKE_COMMAND) -P CMakeFiles/demodadsbsrv.dir/cmake_clean.cmake
.PHONY : pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/clean

pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/depend:
	cd /opt/build/RPX-100-SDR/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /opt/build/RPX-100-SDR /opt/build/RPX-100-SDR/plugins/channelrx/demodadsb /opt/build/RPX-100-SDR/build /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodadsb /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : pluginssrv/channelrx/demodadsb/CMakeFiles/demodadsbsrv.dir/depend
