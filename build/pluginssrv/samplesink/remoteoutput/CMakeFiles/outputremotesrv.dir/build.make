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
include pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/compiler_depend.make

# Include the progress variables for this target.
include pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/progress.make

# Include the compile flags for this target's objects.
include pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/flags.make

pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/outputremotesrv_autogen/mocs_compilation.cpp.o: pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/flags.make
pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/outputremotesrv_autogen/mocs_compilation.cpp.o: pluginssrv/samplesink/remoteoutput/outputremotesrv_autogen/mocs_compilation.cpp
pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/outputremotesrv_autogen/mocs_compilation.cpp.o: pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/outputremotesrv_autogen/mocs_compilation.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesink/remoteoutput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/outputremotesrv_autogen/mocs_compilation.cpp.o -MF CMakeFiles/outputremotesrv.dir/outputremotesrv_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/outputremotesrv.dir/outputremotesrv_autogen/mocs_compilation.cpp.o -c /opt/build/RPX-100-SDR/build/pluginssrv/samplesink/remoteoutput/outputremotesrv_autogen/mocs_compilation.cpp

pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/outputremotesrv_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/outputremotesrv.dir/outputremotesrv_autogen/mocs_compilation.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesink/remoteoutput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/build/pluginssrv/samplesink/remoteoutput/outputremotesrv_autogen/mocs_compilation.cpp > CMakeFiles/outputremotesrv.dir/outputremotesrv_autogen/mocs_compilation.cpp.i

pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/outputremotesrv_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/outputremotesrv.dir/outputremotesrv_autogen/mocs_compilation.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesink/remoteoutput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/build/pluginssrv/samplesink/remoteoutput/outputremotesrv_autogen/mocs_compilation.cpp -o CMakeFiles/outputremotesrv.dir/outputremotesrv_autogen/mocs_compilation.cpp.s

pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/remoteoutput.cpp.o: pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/flags.make
pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/remoteoutput.cpp.o: ../plugins/samplesink/remoteoutput/remoteoutput.cpp
pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/remoteoutput.cpp.o: pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/remoteoutput.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesink/remoteoutput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/remoteoutput.cpp.o -MF CMakeFiles/outputremotesrv.dir/remoteoutput.cpp.o.d -o CMakeFiles/outputremotesrv.dir/remoteoutput.cpp.o -c /opt/build/RPX-100-SDR/plugins/samplesink/remoteoutput/remoteoutput.cpp

pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/remoteoutput.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/outputremotesrv.dir/remoteoutput.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesink/remoteoutput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/samplesink/remoteoutput/remoteoutput.cpp > CMakeFiles/outputremotesrv.dir/remoteoutput.cpp.i

pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/remoteoutput.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/outputremotesrv.dir/remoteoutput.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesink/remoteoutput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/samplesink/remoteoutput/remoteoutput.cpp -o CMakeFiles/outputremotesrv.dir/remoteoutput.cpp.s

pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/remoteoutputplugin.cpp.o: pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/flags.make
pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/remoteoutputplugin.cpp.o: ../plugins/samplesink/remoteoutput/remoteoutputplugin.cpp
pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/remoteoutputplugin.cpp.o: pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/remoteoutputplugin.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesink/remoteoutput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/remoteoutputplugin.cpp.o -MF CMakeFiles/outputremotesrv.dir/remoteoutputplugin.cpp.o.d -o CMakeFiles/outputremotesrv.dir/remoteoutputplugin.cpp.o -c /opt/build/RPX-100-SDR/plugins/samplesink/remoteoutput/remoteoutputplugin.cpp

pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/remoteoutputplugin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/outputremotesrv.dir/remoteoutputplugin.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesink/remoteoutput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/samplesink/remoteoutput/remoteoutputplugin.cpp > CMakeFiles/outputremotesrv.dir/remoteoutputplugin.cpp.i

pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/remoteoutputplugin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/outputremotesrv.dir/remoteoutputplugin.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesink/remoteoutput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/samplesink/remoteoutput/remoteoutputplugin.cpp -o CMakeFiles/outputremotesrv.dir/remoteoutputplugin.cpp.s

pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/remoteoutputsettings.cpp.o: pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/flags.make
pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/remoteoutputsettings.cpp.o: ../plugins/samplesink/remoteoutput/remoteoutputsettings.cpp
pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/remoteoutputsettings.cpp.o: pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/remoteoutputsettings.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesink/remoteoutput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/remoteoutputsettings.cpp.o -MF CMakeFiles/outputremotesrv.dir/remoteoutputsettings.cpp.o.d -o CMakeFiles/outputremotesrv.dir/remoteoutputsettings.cpp.o -c /opt/build/RPX-100-SDR/plugins/samplesink/remoteoutput/remoteoutputsettings.cpp

pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/remoteoutputsettings.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/outputremotesrv.dir/remoteoutputsettings.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesink/remoteoutput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/samplesink/remoteoutput/remoteoutputsettings.cpp > CMakeFiles/outputremotesrv.dir/remoteoutputsettings.cpp.i

pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/remoteoutputsettings.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/outputremotesrv.dir/remoteoutputsettings.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesink/remoteoutput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/samplesink/remoteoutput/remoteoutputsettings.cpp -o CMakeFiles/outputremotesrv.dir/remoteoutputsettings.cpp.s

pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/remoteoutputwebapiadapter.cpp.o: pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/flags.make
pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/remoteoutputwebapiadapter.cpp.o: ../plugins/samplesink/remoteoutput/remoteoutputwebapiadapter.cpp
pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/remoteoutputwebapiadapter.cpp.o: pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/remoteoutputwebapiadapter.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesink/remoteoutput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/remoteoutputwebapiadapter.cpp.o -MF CMakeFiles/outputremotesrv.dir/remoteoutputwebapiadapter.cpp.o.d -o CMakeFiles/outputremotesrv.dir/remoteoutputwebapiadapter.cpp.o -c /opt/build/RPX-100-SDR/plugins/samplesink/remoteoutput/remoteoutputwebapiadapter.cpp

pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/remoteoutputwebapiadapter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/outputremotesrv.dir/remoteoutputwebapiadapter.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesink/remoteoutput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/samplesink/remoteoutput/remoteoutputwebapiadapter.cpp > CMakeFiles/outputremotesrv.dir/remoteoutputwebapiadapter.cpp.i

pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/remoteoutputwebapiadapter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/outputremotesrv.dir/remoteoutputwebapiadapter.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesink/remoteoutput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/samplesink/remoteoutput/remoteoutputwebapiadapter.cpp -o CMakeFiles/outputremotesrv.dir/remoteoutputwebapiadapter.cpp.s

pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/remoteoutputworker.cpp.o: pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/flags.make
pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/remoteoutputworker.cpp.o: ../plugins/samplesink/remoteoutput/remoteoutputworker.cpp
pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/remoteoutputworker.cpp.o: pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/remoteoutputworker.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesink/remoteoutput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/remoteoutputworker.cpp.o -MF CMakeFiles/outputremotesrv.dir/remoteoutputworker.cpp.o.d -o CMakeFiles/outputremotesrv.dir/remoteoutputworker.cpp.o -c /opt/build/RPX-100-SDR/plugins/samplesink/remoteoutput/remoteoutputworker.cpp

pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/remoteoutputworker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/outputremotesrv.dir/remoteoutputworker.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesink/remoteoutput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/samplesink/remoteoutput/remoteoutputworker.cpp > CMakeFiles/outputremotesrv.dir/remoteoutputworker.cpp.i

pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/remoteoutputworker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/outputremotesrv.dir/remoteoutputworker.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesink/remoteoutput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/samplesink/remoteoutput/remoteoutputworker.cpp -o CMakeFiles/outputremotesrv.dir/remoteoutputworker.cpp.s

pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/udpsinkfec.cpp.o: pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/flags.make
pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/udpsinkfec.cpp.o: ../plugins/samplesink/remoteoutput/udpsinkfec.cpp
pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/udpsinkfec.cpp.o: pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/udpsinkfec.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesink/remoteoutput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/udpsinkfec.cpp.o -MF CMakeFiles/outputremotesrv.dir/udpsinkfec.cpp.o.d -o CMakeFiles/outputremotesrv.dir/udpsinkfec.cpp.o -c /opt/build/RPX-100-SDR/plugins/samplesink/remoteoutput/udpsinkfec.cpp

pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/udpsinkfec.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/outputremotesrv.dir/udpsinkfec.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesink/remoteoutput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/samplesink/remoteoutput/udpsinkfec.cpp > CMakeFiles/outputremotesrv.dir/udpsinkfec.cpp.i

pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/udpsinkfec.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/outputremotesrv.dir/udpsinkfec.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesink/remoteoutput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/samplesink/remoteoutput/udpsinkfec.cpp -o CMakeFiles/outputremotesrv.dir/udpsinkfec.cpp.s

pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/remoteoutputsender.cpp.o: pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/flags.make
pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/remoteoutputsender.cpp.o: ../plugins/samplesink/remoteoutput/remoteoutputsender.cpp
pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/remoteoutputsender.cpp.o: pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/remoteoutputsender.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesink/remoteoutput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/remoteoutputsender.cpp.o -MF CMakeFiles/outputremotesrv.dir/remoteoutputsender.cpp.o.d -o CMakeFiles/outputremotesrv.dir/remoteoutputsender.cpp.o -c /opt/build/RPX-100-SDR/plugins/samplesink/remoteoutput/remoteoutputsender.cpp

pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/remoteoutputsender.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/outputremotesrv.dir/remoteoutputsender.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesink/remoteoutput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/samplesink/remoteoutput/remoteoutputsender.cpp > CMakeFiles/outputremotesrv.dir/remoteoutputsender.cpp.i

pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/remoteoutputsender.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/outputremotesrv.dir/remoteoutputsender.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesink/remoteoutput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/samplesink/remoteoutput/remoteoutputsender.cpp -o CMakeFiles/outputremotesrv.dir/remoteoutputsender.cpp.s

pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/remoteoutputfifo.cpp.o: pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/flags.make
pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/remoteoutputfifo.cpp.o: ../plugins/samplesink/remoteoutput/remoteoutputfifo.cpp
pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/remoteoutputfifo.cpp.o: pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/remoteoutputfifo.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesink/remoteoutput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/remoteoutputfifo.cpp.o -MF CMakeFiles/outputremotesrv.dir/remoteoutputfifo.cpp.o.d -o CMakeFiles/outputremotesrv.dir/remoteoutputfifo.cpp.o -c /opt/build/RPX-100-SDR/plugins/samplesink/remoteoutput/remoteoutputfifo.cpp

pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/remoteoutputfifo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/outputremotesrv.dir/remoteoutputfifo.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesink/remoteoutput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/samplesink/remoteoutput/remoteoutputfifo.cpp > CMakeFiles/outputremotesrv.dir/remoteoutputfifo.cpp.i

pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/remoteoutputfifo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/outputremotesrv.dir/remoteoutputfifo.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesink/remoteoutput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/samplesink/remoteoutput/remoteoutputfifo.cpp -o CMakeFiles/outputremotesrv.dir/remoteoutputfifo.cpp.s

# Object files for target outputremotesrv
outputremotesrv_OBJECTS = \
"CMakeFiles/outputremotesrv.dir/outputremotesrv_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/outputremotesrv.dir/remoteoutput.cpp.o" \
"CMakeFiles/outputremotesrv.dir/remoteoutputplugin.cpp.o" \
"CMakeFiles/outputremotesrv.dir/remoteoutputsettings.cpp.o" \
"CMakeFiles/outputremotesrv.dir/remoteoutputwebapiadapter.cpp.o" \
"CMakeFiles/outputremotesrv.dir/remoteoutputworker.cpp.o" \
"CMakeFiles/outputremotesrv.dir/udpsinkfec.cpp.o" \
"CMakeFiles/outputremotesrv.dir/remoteoutputsender.cpp.o" \
"CMakeFiles/outputremotesrv.dir/remoteoutputfifo.cpp.o"

# External object files for target outputremotesrv
outputremotesrv_EXTERNAL_OBJECTS =

lib/pluginssrv/liboutputremotesrv.so: pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/outputremotesrv_autogen/mocs_compilation.cpp.o
lib/pluginssrv/liboutputremotesrv.so: pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/remoteoutput.cpp.o
lib/pluginssrv/liboutputremotesrv.so: pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/remoteoutputplugin.cpp.o
lib/pluginssrv/liboutputremotesrv.so: pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/remoteoutputsettings.cpp.o
lib/pluginssrv/liboutputremotesrv.so: pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/remoteoutputwebapiadapter.cpp.o
lib/pluginssrv/liboutputremotesrv.so: pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/remoteoutputworker.cpp.o
lib/pluginssrv/liboutputremotesrv.so: pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/udpsinkfec.cpp.o
lib/pluginssrv/liboutputremotesrv.so: pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/remoteoutputsender.cpp.o
lib/pluginssrv/liboutputremotesrv.so: pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/remoteoutputfifo.cpp.o
lib/pluginssrv/liboutputremotesrv.so: pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/build.make
lib/pluginssrv/liboutputremotesrv.so: lib/libsdrbase.so
lib/pluginssrv/liboutputremotesrv.so: lib/libswagger.so
lib/pluginssrv/liboutputremotesrv.so: /opt/install/cm256cc/lib/libcm256cc.so
lib/pluginssrv/liboutputremotesrv.so: /usr/lib/x86_64-linux-gnu/libopus.so
lib/pluginssrv/liboutputremotesrv.so: /usr/lib/x86_64-linux-gnu/libm.so
lib/pluginssrv/liboutputremotesrv.so: /usr/lib/x86_64-linux-gnu/libfftw3f.so
lib/pluginssrv/liboutputremotesrv.so: /opt/install/serialdv/lib/libserialdv.so
lib/pluginssrv/liboutputremotesrv.so: /opt/install/LimeSuite/lib/libLimeSuite.so
lib/pluginssrv/liboutputremotesrv.so: /usr/lib/x86_64-linux-gnu/libQt5Multimedia.so.5.15.2
lib/pluginssrv/liboutputremotesrv.so: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.15.2
lib/pluginssrv/liboutputremotesrv.so: /usr/lib/x86_64-linux-gnu/libQt5WebSockets.so.5.15.2
lib/pluginssrv/liboutputremotesrv.so: lib/libhttpserver.so
lib/pluginssrv/liboutputremotesrv.so: lib/liblogging.so
lib/pluginssrv/liboutputremotesrv.so: lib/libqrtplib.so
lib/pluginssrv/liboutputremotesrv.so: /usr/lib/x86_64-linux-gnu/libQt5Network.so.5.15.2
lib/pluginssrv/liboutputremotesrv.so: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.15.2
lib/pluginssrv/liboutputremotesrv.so: pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX shared library ../../../lib/pluginssrv/liboutputremotesrv.so"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesink/remoteoutput && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/outputremotesrv.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/build: lib/pluginssrv/liboutputremotesrv.so
.PHONY : pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/build

pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/clean:
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesink/remoteoutput && $(CMAKE_COMMAND) -P CMakeFiles/outputremotesrv.dir/cmake_clean.cmake
.PHONY : pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/clean

pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/depend:
	cd /opt/build/RPX-100-SDR/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /opt/build/RPX-100-SDR /opt/build/RPX-100-SDR/plugins/samplesink/remoteoutput /opt/build/RPX-100-SDR/build /opt/build/RPX-100-SDR/build/pluginssrv/samplesink/remoteoutput /opt/build/RPX-100-SDR/build/pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : pluginssrv/samplesink/remoteoutput/CMakeFiles/outputremotesrv.dir/depend

