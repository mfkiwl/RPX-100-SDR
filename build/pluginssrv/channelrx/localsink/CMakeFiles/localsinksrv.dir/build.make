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
include pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/compiler_depend.make

# Include the progress variables for this target.
include pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/progress.make

# Include the compile flags for this target's objects.
include pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/flags.make

pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/localsinksrv_autogen/mocs_compilation.cpp.o: pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/flags.make
pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/localsinksrv_autogen/mocs_compilation.cpp.o: pluginssrv/channelrx/localsink/localsinksrv_autogen/mocs_compilation.cpp
pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/localsinksrv_autogen/mocs_compilation.cpp.o: pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/localsinksrv_autogen/mocs_compilation.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/localsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/localsinksrv_autogen/mocs_compilation.cpp.o -MF CMakeFiles/localsinksrv.dir/localsinksrv_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/localsinksrv.dir/localsinksrv_autogen/mocs_compilation.cpp.o -c /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/localsink/localsinksrv_autogen/mocs_compilation.cpp

pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/localsinksrv_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/localsinksrv.dir/localsinksrv_autogen/mocs_compilation.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/localsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/localsink/localsinksrv_autogen/mocs_compilation.cpp > CMakeFiles/localsinksrv.dir/localsinksrv_autogen/mocs_compilation.cpp.i

pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/localsinksrv_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/localsinksrv.dir/localsinksrv_autogen/mocs_compilation.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/localsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/localsink/localsinksrv_autogen/mocs_compilation.cpp -o CMakeFiles/localsinksrv.dir/localsinksrv_autogen/mocs_compilation.cpp.s

pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/localsink.cpp.o: pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/flags.make
pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/localsink.cpp.o: ../plugins/channelrx/localsink/localsink.cpp
pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/localsink.cpp.o: pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/localsink.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/localsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/localsink.cpp.o -MF CMakeFiles/localsinksrv.dir/localsink.cpp.o.d -o CMakeFiles/localsinksrv.dir/localsink.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/localsink/localsink.cpp

pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/localsink.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/localsinksrv.dir/localsink.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/localsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/localsink/localsink.cpp > CMakeFiles/localsinksrv.dir/localsink.cpp.i

pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/localsink.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/localsinksrv.dir/localsink.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/localsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/localsink/localsink.cpp -o CMakeFiles/localsinksrv.dir/localsink.cpp.s

pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/localsinkbaseband.cpp.o: pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/flags.make
pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/localsinkbaseband.cpp.o: ../plugins/channelrx/localsink/localsinkbaseband.cpp
pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/localsinkbaseband.cpp.o: pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/localsinkbaseband.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/localsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/localsinkbaseband.cpp.o -MF CMakeFiles/localsinksrv.dir/localsinkbaseband.cpp.o.d -o CMakeFiles/localsinksrv.dir/localsinkbaseband.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/localsink/localsinkbaseband.cpp

pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/localsinkbaseband.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/localsinksrv.dir/localsinkbaseband.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/localsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/localsink/localsinkbaseband.cpp > CMakeFiles/localsinksrv.dir/localsinkbaseband.cpp.i

pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/localsinkbaseband.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/localsinksrv.dir/localsinkbaseband.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/localsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/localsink/localsinkbaseband.cpp -o CMakeFiles/localsinksrv.dir/localsinkbaseband.cpp.s

pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/localsinksink.cpp.o: pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/flags.make
pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/localsinksink.cpp.o: ../plugins/channelrx/localsink/localsinksink.cpp
pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/localsinksink.cpp.o: pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/localsinksink.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/localsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/localsinksink.cpp.o -MF CMakeFiles/localsinksrv.dir/localsinksink.cpp.o.d -o CMakeFiles/localsinksrv.dir/localsinksink.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/localsink/localsinksink.cpp

pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/localsinksink.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/localsinksrv.dir/localsinksink.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/localsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/localsink/localsinksink.cpp > CMakeFiles/localsinksrv.dir/localsinksink.cpp.i

pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/localsinksink.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/localsinksrv.dir/localsinksink.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/localsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/localsink/localsinksink.cpp -o CMakeFiles/localsinksrv.dir/localsinksink.cpp.s

pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/localsinksettings.cpp.o: pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/flags.make
pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/localsinksettings.cpp.o: ../plugins/channelrx/localsink/localsinksettings.cpp
pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/localsinksettings.cpp.o: pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/localsinksettings.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/localsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/localsinksettings.cpp.o -MF CMakeFiles/localsinksrv.dir/localsinksettings.cpp.o.d -o CMakeFiles/localsinksrv.dir/localsinksettings.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/localsink/localsinksettings.cpp

pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/localsinksettings.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/localsinksrv.dir/localsinksettings.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/localsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/localsink/localsinksettings.cpp > CMakeFiles/localsinksrv.dir/localsinksettings.cpp.i

pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/localsinksettings.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/localsinksrv.dir/localsinksettings.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/localsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/localsink/localsinksettings.cpp -o CMakeFiles/localsinksrv.dir/localsinksettings.cpp.s

pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/localsinkwebapiadapter.cpp.o: pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/flags.make
pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/localsinkwebapiadapter.cpp.o: ../plugins/channelrx/localsink/localsinkwebapiadapter.cpp
pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/localsinkwebapiadapter.cpp.o: pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/localsinkwebapiadapter.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/localsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/localsinkwebapiadapter.cpp.o -MF CMakeFiles/localsinksrv.dir/localsinkwebapiadapter.cpp.o.d -o CMakeFiles/localsinksrv.dir/localsinkwebapiadapter.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/localsink/localsinkwebapiadapter.cpp

pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/localsinkwebapiadapter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/localsinksrv.dir/localsinkwebapiadapter.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/localsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/localsink/localsinkwebapiadapter.cpp > CMakeFiles/localsinksrv.dir/localsinkwebapiadapter.cpp.i

pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/localsinkwebapiadapter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/localsinksrv.dir/localsinkwebapiadapter.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/localsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/localsink/localsinkwebapiadapter.cpp -o CMakeFiles/localsinksrv.dir/localsinkwebapiadapter.cpp.s

pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/localsinkworker.cpp.o: pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/flags.make
pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/localsinkworker.cpp.o: ../plugins/channelrx/localsink/localsinkworker.cpp
pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/localsinkworker.cpp.o: pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/localsinkworker.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/localsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/localsinkworker.cpp.o -MF CMakeFiles/localsinksrv.dir/localsinkworker.cpp.o.d -o CMakeFiles/localsinksrv.dir/localsinkworker.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/localsink/localsinkworker.cpp

pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/localsinkworker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/localsinksrv.dir/localsinkworker.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/localsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/localsink/localsinkworker.cpp > CMakeFiles/localsinksrv.dir/localsinkworker.cpp.i

pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/localsinkworker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/localsinksrv.dir/localsinkworker.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/localsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/localsink/localsinkworker.cpp -o CMakeFiles/localsinksrv.dir/localsinkworker.cpp.s

pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/localsinkplugin.cpp.o: pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/flags.make
pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/localsinkplugin.cpp.o: ../plugins/channelrx/localsink/localsinkplugin.cpp
pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/localsinkplugin.cpp.o: pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/localsinkplugin.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/localsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/localsinkplugin.cpp.o -MF CMakeFiles/localsinksrv.dir/localsinkplugin.cpp.o.d -o CMakeFiles/localsinksrv.dir/localsinkplugin.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/localsink/localsinkplugin.cpp

pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/localsinkplugin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/localsinksrv.dir/localsinkplugin.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/localsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/localsink/localsinkplugin.cpp > CMakeFiles/localsinksrv.dir/localsinkplugin.cpp.i

pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/localsinkplugin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/localsinksrv.dir/localsinkplugin.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/localsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/localsink/localsinkplugin.cpp -o CMakeFiles/localsinksrv.dir/localsinkplugin.cpp.s

# Object files for target localsinksrv
localsinksrv_OBJECTS = \
"CMakeFiles/localsinksrv.dir/localsinksrv_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/localsinksrv.dir/localsink.cpp.o" \
"CMakeFiles/localsinksrv.dir/localsinkbaseband.cpp.o" \
"CMakeFiles/localsinksrv.dir/localsinksink.cpp.o" \
"CMakeFiles/localsinksrv.dir/localsinksettings.cpp.o" \
"CMakeFiles/localsinksrv.dir/localsinkwebapiadapter.cpp.o" \
"CMakeFiles/localsinksrv.dir/localsinkworker.cpp.o" \
"CMakeFiles/localsinksrv.dir/localsinkplugin.cpp.o"

# External object files for target localsinksrv
localsinksrv_EXTERNAL_OBJECTS =

lib/pluginssrv/liblocalsinksrv.so: pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/localsinksrv_autogen/mocs_compilation.cpp.o
lib/pluginssrv/liblocalsinksrv.so: pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/localsink.cpp.o
lib/pluginssrv/liblocalsinksrv.so: pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/localsinkbaseband.cpp.o
lib/pluginssrv/liblocalsinksrv.so: pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/localsinksink.cpp.o
lib/pluginssrv/liblocalsinksrv.so: pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/localsinksettings.cpp.o
lib/pluginssrv/liblocalsinksrv.so: pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/localsinkwebapiadapter.cpp.o
lib/pluginssrv/liblocalsinksrv.so: pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/localsinkworker.cpp.o
lib/pluginssrv/liblocalsinksrv.so: pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/localsinkplugin.cpp.o
lib/pluginssrv/liblocalsinksrv.so: pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/build.make
lib/pluginssrv/liblocalsinksrv.so: lib/libsdrbase.so
lib/pluginssrv/liblocalsinksrv.so: lib/libswagger.so
lib/pluginssrv/liblocalsinksrv.so: /usr/lib/x86_64-linux-gnu/libopus.so
lib/pluginssrv/liblocalsinksrv.so: /usr/lib/x86_64-linux-gnu/libm.so
lib/pluginssrv/liblocalsinksrv.so: /usr/lib/x86_64-linux-gnu/libfftw3f.so
lib/pluginssrv/liblocalsinksrv.so: /opt/install/serialdv/lib/libserialdv.so
lib/pluginssrv/liblocalsinksrv.so: /opt/install/LimeSuite/lib/libLimeSuite.so
lib/pluginssrv/liblocalsinksrv.so: /usr/lib/x86_64-linux-gnu/libQt5Multimedia.so.5.15.2
lib/pluginssrv/liblocalsinksrv.so: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.15.2
lib/pluginssrv/liblocalsinksrv.so: /usr/lib/x86_64-linux-gnu/libQt5WebSockets.so.5.15.2
lib/pluginssrv/liblocalsinksrv.so: lib/libhttpserver.so
lib/pluginssrv/liblocalsinksrv.so: lib/liblogging.so
lib/pluginssrv/liblocalsinksrv.so: lib/libqrtplib.so
lib/pluginssrv/liblocalsinksrv.so: /usr/lib/x86_64-linux-gnu/libQt5Network.so.5.15.2
lib/pluginssrv/liblocalsinksrv.so: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.15.2
lib/pluginssrv/liblocalsinksrv.so: pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX shared library ../../../lib/pluginssrv/liblocalsinksrv.so"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/localsink && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/localsinksrv.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/build: lib/pluginssrv/liblocalsinksrv.so
.PHONY : pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/build

pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/clean:
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/localsink && $(CMAKE_COMMAND) -P CMakeFiles/localsinksrv.dir/cmake_clean.cmake
.PHONY : pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/clean

pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/depend:
	cd /opt/build/RPX-100-SDR/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /opt/build/RPX-100-SDR /opt/build/RPX-100-SDR/plugins/channelrx/localsink /opt/build/RPX-100-SDR/build /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/localsink /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : pluginssrv/channelrx/localsink/CMakeFiles/localsinksrv.dir/depend
