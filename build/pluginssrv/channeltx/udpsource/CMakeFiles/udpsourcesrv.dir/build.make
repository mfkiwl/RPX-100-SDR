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
include pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/compiler_depend.make

# Include the progress variables for this target.
include pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/progress.make

# Include the compile flags for this target's objects.
include pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/flags.make

pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsourcesrv_autogen/mocs_compilation.cpp.o: pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/flags.make
pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsourcesrv_autogen/mocs_compilation.cpp.o: pluginssrv/channeltx/udpsource/udpsourcesrv_autogen/mocs_compilation.cpp
pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsourcesrv_autogen/mocs_compilation.cpp.o: pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsourcesrv_autogen/mocs_compilation.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channeltx/udpsource && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsourcesrv_autogen/mocs_compilation.cpp.o -MF CMakeFiles/udpsourcesrv.dir/udpsourcesrv_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/udpsourcesrv.dir/udpsourcesrv_autogen/mocs_compilation.cpp.o -c /opt/build/RPX-100-SDR/build/pluginssrv/channeltx/udpsource/udpsourcesrv_autogen/mocs_compilation.cpp

pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsourcesrv_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/udpsourcesrv.dir/udpsourcesrv_autogen/mocs_compilation.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channeltx/udpsource && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/build/pluginssrv/channeltx/udpsource/udpsourcesrv_autogen/mocs_compilation.cpp > CMakeFiles/udpsourcesrv.dir/udpsourcesrv_autogen/mocs_compilation.cpp.i

pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsourcesrv_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/udpsourcesrv.dir/udpsourcesrv_autogen/mocs_compilation.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channeltx/udpsource && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/build/pluginssrv/channeltx/udpsource/udpsourcesrv_autogen/mocs_compilation.cpp -o CMakeFiles/udpsourcesrv.dir/udpsourcesrv_autogen/mocs_compilation.cpp.s

pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsource.cpp.o: pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/flags.make
pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsource.cpp.o: ../plugins/channeltx/udpsource/udpsource.cpp
pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsource.cpp.o: pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsource.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channeltx/udpsource && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsource.cpp.o -MF CMakeFiles/udpsourcesrv.dir/udpsource.cpp.o.d -o CMakeFiles/udpsourcesrv.dir/udpsource.cpp.o -c /opt/build/RPX-100-SDR/plugins/channeltx/udpsource/udpsource.cpp

pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsource.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/udpsourcesrv.dir/udpsource.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channeltx/udpsource && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channeltx/udpsource/udpsource.cpp > CMakeFiles/udpsourcesrv.dir/udpsource.cpp.i

pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsource.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/udpsourcesrv.dir/udpsource.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channeltx/udpsource && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channeltx/udpsource/udpsource.cpp -o CMakeFiles/udpsourcesrv.dir/udpsource.cpp.s

pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsourcebaseband.cpp.o: pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/flags.make
pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsourcebaseband.cpp.o: ../plugins/channeltx/udpsource/udpsourcebaseband.cpp
pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsourcebaseband.cpp.o: pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsourcebaseband.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channeltx/udpsource && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsourcebaseband.cpp.o -MF CMakeFiles/udpsourcesrv.dir/udpsourcebaseband.cpp.o.d -o CMakeFiles/udpsourcesrv.dir/udpsourcebaseband.cpp.o -c /opt/build/RPX-100-SDR/plugins/channeltx/udpsource/udpsourcebaseband.cpp

pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsourcebaseband.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/udpsourcesrv.dir/udpsourcebaseband.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channeltx/udpsource && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channeltx/udpsource/udpsourcebaseband.cpp > CMakeFiles/udpsourcesrv.dir/udpsourcebaseband.cpp.i

pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsourcebaseband.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/udpsourcesrv.dir/udpsourcebaseband.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channeltx/udpsource && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channeltx/udpsource/udpsourcebaseband.cpp -o CMakeFiles/udpsourcesrv.dir/udpsourcebaseband.cpp.s

pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsourcesource.cpp.o: pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/flags.make
pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsourcesource.cpp.o: ../plugins/channeltx/udpsource/udpsourcesource.cpp
pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsourcesource.cpp.o: pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsourcesource.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channeltx/udpsource && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsourcesource.cpp.o -MF CMakeFiles/udpsourcesrv.dir/udpsourcesource.cpp.o.d -o CMakeFiles/udpsourcesrv.dir/udpsourcesource.cpp.o -c /opt/build/RPX-100-SDR/plugins/channeltx/udpsource/udpsourcesource.cpp

pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsourcesource.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/udpsourcesrv.dir/udpsourcesource.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channeltx/udpsource && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channeltx/udpsource/udpsourcesource.cpp > CMakeFiles/udpsourcesrv.dir/udpsourcesource.cpp.i

pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsourcesource.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/udpsourcesrv.dir/udpsourcesource.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channeltx/udpsource && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channeltx/udpsource/udpsourcesource.cpp -o CMakeFiles/udpsourcesrv.dir/udpsourcesource.cpp.s

pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsourceplugin.cpp.o: pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/flags.make
pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsourceplugin.cpp.o: ../plugins/channeltx/udpsource/udpsourceplugin.cpp
pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsourceplugin.cpp.o: pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsourceplugin.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channeltx/udpsource && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsourceplugin.cpp.o -MF CMakeFiles/udpsourcesrv.dir/udpsourceplugin.cpp.o.d -o CMakeFiles/udpsourcesrv.dir/udpsourceplugin.cpp.o -c /opt/build/RPX-100-SDR/plugins/channeltx/udpsource/udpsourceplugin.cpp

pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsourceplugin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/udpsourcesrv.dir/udpsourceplugin.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channeltx/udpsource && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channeltx/udpsource/udpsourceplugin.cpp > CMakeFiles/udpsourcesrv.dir/udpsourceplugin.cpp.i

pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsourceplugin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/udpsourcesrv.dir/udpsourceplugin.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channeltx/udpsource && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channeltx/udpsource/udpsourceplugin.cpp -o CMakeFiles/udpsourcesrv.dir/udpsourceplugin.cpp.s

pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsourceudphandler.cpp.o: pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/flags.make
pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsourceudphandler.cpp.o: ../plugins/channeltx/udpsource/udpsourceudphandler.cpp
pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsourceudphandler.cpp.o: pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsourceudphandler.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channeltx/udpsource && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsourceudphandler.cpp.o -MF CMakeFiles/udpsourcesrv.dir/udpsourceudphandler.cpp.o.d -o CMakeFiles/udpsourcesrv.dir/udpsourceudphandler.cpp.o -c /opt/build/RPX-100-SDR/plugins/channeltx/udpsource/udpsourceudphandler.cpp

pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsourceudphandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/udpsourcesrv.dir/udpsourceudphandler.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channeltx/udpsource && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channeltx/udpsource/udpsourceudphandler.cpp > CMakeFiles/udpsourcesrv.dir/udpsourceudphandler.cpp.i

pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsourceudphandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/udpsourcesrv.dir/udpsourceudphandler.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channeltx/udpsource && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channeltx/udpsource/udpsourceudphandler.cpp -o CMakeFiles/udpsourcesrv.dir/udpsourceudphandler.cpp.s

pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsourcemsg.cpp.o: pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/flags.make
pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsourcemsg.cpp.o: ../plugins/channeltx/udpsource/udpsourcemsg.cpp
pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsourcemsg.cpp.o: pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsourcemsg.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channeltx/udpsource && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsourcemsg.cpp.o -MF CMakeFiles/udpsourcesrv.dir/udpsourcemsg.cpp.o.d -o CMakeFiles/udpsourcesrv.dir/udpsourcemsg.cpp.o -c /opt/build/RPX-100-SDR/plugins/channeltx/udpsource/udpsourcemsg.cpp

pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsourcemsg.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/udpsourcesrv.dir/udpsourcemsg.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channeltx/udpsource && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channeltx/udpsource/udpsourcemsg.cpp > CMakeFiles/udpsourcesrv.dir/udpsourcemsg.cpp.i

pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsourcemsg.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/udpsourcesrv.dir/udpsourcemsg.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channeltx/udpsource && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channeltx/udpsource/udpsourcemsg.cpp -o CMakeFiles/udpsourcesrv.dir/udpsourcemsg.cpp.s

pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsourcesettings.cpp.o: pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/flags.make
pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsourcesettings.cpp.o: ../plugins/channeltx/udpsource/udpsourcesettings.cpp
pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsourcesettings.cpp.o: pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsourcesettings.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channeltx/udpsource && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsourcesettings.cpp.o -MF CMakeFiles/udpsourcesrv.dir/udpsourcesettings.cpp.o.d -o CMakeFiles/udpsourcesrv.dir/udpsourcesettings.cpp.o -c /opt/build/RPX-100-SDR/plugins/channeltx/udpsource/udpsourcesettings.cpp

pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsourcesettings.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/udpsourcesrv.dir/udpsourcesettings.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channeltx/udpsource && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channeltx/udpsource/udpsourcesettings.cpp > CMakeFiles/udpsourcesrv.dir/udpsourcesettings.cpp.i

pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsourcesettings.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/udpsourcesrv.dir/udpsourcesettings.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channeltx/udpsource && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channeltx/udpsource/udpsourcesettings.cpp -o CMakeFiles/udpsourcesrv.dir/udpsourcesettings.cpp.s

pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsourcewebapiadapter.cpp.o: pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/flags.make
pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsourcewebapiadapter.cpp.o: ../plugins/channeltx/udpsource/udpsourcewebapiadapter.cpp
pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsourcewebapiadapter.cpp.o: pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsourcewebapiadapter.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channeltx/udpsource && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsourcewebapiadapter.cpp.o -MF CMakeFiles/udpsourcesrv.dir/udpsourcewebapiadapter.cpp.o.d -o CMakeFiles/udpsourcesrv.dir/udpsourcewebapiadapter.cpp.o -c /opt/build/RPX-100-SDR/plugins/channeltx/udpsource/udpsourcewebapiadapter.cpp

pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsourcewebapiadapter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/udpsourcesrv.dir/udpsourcewebapiadapter.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channeltx/udpsource && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channeltx/udpsource/udpsourcewebapiadapter.cpp > CMakeFiles/udpsourcesrv.dir/udpsourcewebapiadapter.cpp.i

pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsourcewebapiadapter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/udpsourcesrv.dir/udpsourcewebapiadapter.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channeltx/udpsource && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channeltx/udpsource/udpsourcewebapiadapter.cpp -o CMakeFiles/udpsourcesrv.dir/udpsourcewebapiadapter.cpp.s

# Object files for target udpsourcesrv
udpsourcesrv_OBJECTS = \
"CMakeFiles/udpsourcesrv.dir/udpsourcesrv_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/udpsourcesrv.dir/udpsource.cpp.o" \
"CMakeFiles/udpsourcesrv.dir/udpsourcebaseband.cpp.o" \
"CMakeFiles/udpsourcesrv.dir/udpsourcesource.cpp.o" \
"CMakeFiles/udpsourcesrv.dir/udpsourceplugin.cpp.o" \
"CMakeFiles/udpsourcesrv.dir/udpsourceudphandler.cpp.o" \
"CMakeFiles/udpsourcesrv.dir/udpsourcemsg.cpp.o" \
"CMakeFiles/udpsourcesrv.dir/udpsourcesettings.cpp.o" \
"CMakeFiles/udpsourcesrv.dir/udpsourcewebapiadapter.cpp.o"

# External object files for target udpsourcesrv
udpsourcesrv_EXTERNAL_OBJECTS =

lib/pluginssrv/libudpsourcesrv.so: pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsourcesrv_autogen/mocs_compilation.cpp.o
lib/pluginssrv/libudpsourcesrv.so: pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsource.cpp.o
lib/pluginssrv/libudpsourcesrv.so: pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsourcebaseband.cpp.o
lib/pluginssrv/libudpsourcesrv.so: pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsourcesource.cpp.o
lib/pluginssrv/libudpsourcesrv.so: pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsourceplugin.cpp.o
lib/pluginssrv/libudpsourcesrv.so: pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsourceudphandler.cpp.o
lib/pluginssrv/libudpsourcesrv.so: pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsourcemsg.cpp.o
lib/pluginssrv/libudpsourcesrv.so: pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsourcesettings.cpp.o
lib/pluginssrv/libudpsourcesrv.so: pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/udpsourcewebapiadapter.cpp.o
lib/pluginssrv/libudpsourcesrv.so: pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/build.make
lib/pluginssrv/libudpsourcesrv.so: lib/libsdrbase.so
lib/pluginssrv/libudpsourcesrv.so: lib/libswagger.so
lib/pluginssrv/libudpsourcesrv.so: /usr/lib/x86_64-linux-gnu/libopus.so
lib/pluginssrv/libudpsourcesrv.so: /usr/lib/x86_64-linux-gnu/libm.so
lib/pluginssrv/libudpsourcesrv.so: /usr/lib/x86_64-linux-gnu/libfftw3f.so
lib/pluginssrv/libudpsourcesrv.so: /opt/install/serialdv/lib/libserialdv.so
lib/pluginssrv/libudpsourcesrv.so: /opt/install/LimeSuite/lib/libLimeSuite.so
lib/pluginssrv/libudpsourcesrv.so: /usr/lib/x86_64-linux-gnu/libQt5Multimedia.so.5.15.2
lib/pluginssrv/libudpsourcesrv.so: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.15.2
lib/pluginssrv/libudpsourcesrv.so: /usr/lib/x86_64-linux-gnu/libQt5WebSockets.so.5.15.2
lib/pluginssrv/libudpsourcesrv.so: lib/libhttpserver.so
lib/pluginssrv/libudpsourcesrv.so: lib/liblogging.so
lib/pluginssrv/libudpsourcesrv.so: lib/libqrtplib.so
lib/pluginssrv/libudpsourcesrv.so: /usr/lib/x86_64-linux-gnu/libQt5Network.so.5.15.2
lib/pluginssrv/libudpsourcesrv.so: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.15.2
lib/pluginssrv/libudpsourcesrv.so: pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX shared library ../../../lib/pluginssrv/libudpsourcesrv.so"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channeltx/udpsource && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/udpsourcesrv.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/build: lib/pluginssrv/libudpsourcesrv.so
.PHONY : pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/build

pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/clean:
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channeltx/udpsource && $(CMAKE_COMMAND) -P CMakeFiles/udpsourcesrv.dir/cmake_clean.cmake
.PHONY : pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/clean

pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/depend:
	cd /opt/build/RPX-100-SDR/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /opt/build/RPX-100-SDR /opt/build/RPX-100-SDR/plugins/channeltx/udpsource /opt/build/RPX-100-SDR/build /opt/build/RPX-100-SDR/build/pluginssrv/channeltx/udpsource /opt/build/RPX-100-SDR/build/pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : pluginssrv/channeltx/udpsource/CMakeFiles/udpsourcesrv.dir/depend
