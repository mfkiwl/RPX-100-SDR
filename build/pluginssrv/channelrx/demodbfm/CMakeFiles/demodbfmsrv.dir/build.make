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
include pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/compiler_depend.make

# Include the progress variables for this target.
include pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/progress.make

# Include the compile flags for this target's objects.
include pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/flags.make

pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/demodbfmsrv_autogen/mocs_compilation.cpp.o: pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/flags.make
pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/demodbfmsrv_autogen/mocs_compilation.cpp.o: pluginssrv/channelrx/demodbfm/demodbfmsrv_autogen/mocs_compilation.cpp
pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/demodbfmsrv_autogen/mocs_compilation.cpp.o: pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/demodbfmsrv_autogen/mocs_compilation.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodbfm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/demodbfmsrv_autogen/mocs_compilation.cpp.o -MF CMakeFiles/demodbfmsrv.dir/demodbfmsrv_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/demodbfmsrv.dir/demodbfmsrv_autogen/mocs_compilation.cpp.o -c /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodbfm/demodbfmsrv_autogen/mocs_compilation.cpp

pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/demodbfmsrv_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demodbfmsrv.dir/demodbfmsrv_autogen/mocs_compilation.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodbfm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodbfm/demodbfmsrv_autogen/mocs_compilation.cpp > CMakeFiles/demodbfmsrv.dir/demodbfmsrv_autogen/mocs_compilation.cpp.i

pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/demodbfmsrv_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demodbfmsrv.dir/demodbfmsrv_autogen/mocs_compilation.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodbfm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodbfm/demodbfmsrv_autogen/mocs_compilation.cpp -o CMakeFiles/demodbfmsrv.dir/demodbfmsrv_autogen/mocs_compilation.cpp.s

pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/bfmdemod.cpp.o: pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/flags.make
pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/bfmdemod.cpp.o: ../plugins/channelrx/demodbfm/bfmdemod.cpp
pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/bfmdemod.cpp.o: pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/bfmdemod.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodbfm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/bfmdemod.cpp.o -MF CMakeFiles/demodbfmsrv.dir/bfmdemod.cpp.o.d -o CMakeFiles/demodbfmsrv.dir/bfmdemod.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/demodbfm/bfmdemod.cpp

pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/bfmdemod.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demodbfmsrv.dir/bfmdemod.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodbfm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/demodbfm/bfmdemod.cpp > CMakeFiles/demodbfmsrv.dir/bfmdemod.cpp.i

pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/bfmdemod.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demodbfmsrv.dir/bfmdemod.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodbfm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/demodbfm/bfmdemod.cpp -o CMakeFiles/demodbfmsrv.dir/bfmdemod.cpp.s

pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/bfmdemodsettings.cpp.o: pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/flags.make
pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/bfmdemodsettings.cpp.o: ../plugins/channelrx/demodbfm/bfmdemodsettings.cpp
pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/bfmdemodsettings.cpp.o: pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/bfmdemodsettings.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodbfm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/bfmdemodsettings.cpp.o -MF CMakeFiles/demodbfmsrv.dir/bfmdemodsettings.cpp.o.d -o CMakeFiles/demodbfmsrv.dir/bfmdemodsettings.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/demodbfm/bfmdemodsettings.cpp

pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/bfmdemodsettings.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demodbfmsrv.dir/bfmdemodsettings.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodbfm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/demodbfm/bfmdemodsettings.cpp > CMakeFiles/demodbfmsrv.dir/bfmdemodsettings.cpp.i

pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/bfmdemodsettings.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demodbfmsrv.dir/bfmdemodsettings.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodbfm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/demodbfm/bfmdemodsettings.cpp -o CMakeFiles/demodbfmsrv.dir/bfmdemodsettings.cpp.s

pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/bfmdemodsink.cpp.o: pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/flags.make
pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/bfmdemodsink.cpp.o: ../plugins/channelrx/demodbfm/bfmdemodsink.cpp
pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/bfmdemodsink.cpp.o: pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/bfmdemodsink.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodbfm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/bfmdemodsink.cpp.o -MF CMakeFiles/demodbfmsrv.dir/bfmdemodsink.cpp.o.d -o CMakeFiles/demodbfmsrv.dir/bfmdemodsink.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/demodbfm/bfmdemodsink.cpp

pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/bfmdemodsink.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demodbfmsrv.dir/bfmdemodsink.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodbfm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/demodbfm/bfmdemodsink.cpp > CMakeFiles/demodbfmsrv.dir/bfmdemodsink.cpp.i

pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/bfmdemodsink.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demodbfmsrv.dir/bfmdemodsink.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodbfm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/demodbfm/bfmdemodsink.cpp -o CMakeFiles/demodbfmsrv.dir/bfmdemodsink.cpp.s

pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/bfmdemodbaseband.cpp.o: pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/flags.make
pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/bfmdemodbaseband.cpp.o: ../plugins/channelrx/demodbfm/bfmdemodbaseband.cpp
pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/bfmdemodbaseband.cpp.o: pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/bfmdemodbaseband.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodbfm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/bfmdemodbaseband.cpp.o -MF CMakeFiles/demodbfmsrv.dir/bfmdemodbaseband.cpp.o.d -o CMakeFiles/demodbfmsrv.dir/bfmdemodbaseband.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/demodbfm/bfmdemodbaseband.cpp

pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/bfmdemodbaseband.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demodbfmsrv.dir/bfmdemodbaseband.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodbfm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/demodbfm/bfmdemodbaseband.cpp > CMakeFiles/demodbfmsrv.dir/bfmdemodbaseband.cpp.i

pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/bfmdemodbaseband.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demodbfmsrv.dir/bfmdemodbaseband.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodbfm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/demodbfm/bfmdemodbaseband.cpp -o CMakeFiles/demodbfmsrv.dir/bfmdemodbaseband.cpp.s

pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/bfmdemodreport.cpp.o: pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/flags.make
pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/bfmdemodreport.cpp.o: ../plugins/channelrx/demodbfm/bfmdemodreport.cpp
pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/bfmdemodreport.cpp.o: pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/bfmdemodreport.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodbfm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/bfmdemodreport.cpp.o -MF CMakeFiles/demodbfmsrv.dir/bfmdemodreport.cpp.o.d -o CMakeFiles/demodbfmsrv.dir/bfmdemodreport.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/demodbfm/bfmdemodreport.cpp

pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/bfmdemodreport.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demodbfmsrv.dir/bfmdemodreport.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodbfm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/demodbfm/bfmdemodreport.cpp > CMakeFiles/demodbfmsrv.dir/bfmdemodreport.cpp.i

pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/bfmdemodreport.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demodbfmsrv.dir/bfmdemodreport.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodbfm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/demodbfm/bfmdemodreport.cpp -o CMakeFiles/demodbfmsrv.dir/bfmdemodreport.cpp.s

pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/bfmdemodwebapiadapter.cpp.o: pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/flags.make
pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/bfmdemodwebapiadapter.cpp.o: ../plugins/channelrx/demodbfm/bfmdemodwebapiadapter.cpp
pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/bfmdemodwebapiadapter.cpp.o: pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/bfmdemodwebapiadapter.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodbfm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/bfmdemodwebapiadapter.cpp.o -MF CMakeFiles/demodbfmsrv.dir/bfmdemodwebapiadapter.cpp.o.d -o CMakeFiles/demodbfmsrv.dir/bfmdemodwebapiadapter.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/demodbfm/bfmdemodwebapiadapter.cpp

pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/bfmdemodwebapiadapter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demodbfmsrv.dir/bfmdemodwebapiadapter.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodbfm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/demodbfm/bfmdemodwebapiadapter.cpp > CMakeFiles/demodbfmsrv.dir/bfmdemodwebapiadapter.cpp.i

pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/bfmdemodwebapiadapter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demodbfmsrv.dir/bfmdemodwebapiadapter.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodbfm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/demodbfm/bfmdemodwebapiadapter.cpp -o CMakeFiles/demodbfmsrv.dir/bfmdemodwebapiadapter.cpp.s

pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/bfmplugin.cpp.o: pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/flags.make
pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/bfmplugin.cpp.o: ../plugins/channelrx/demodbfm/bfmplugin.cpp
pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/bfmplugin.cpp.o: pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/bfmplugin.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodbfm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/bfmplugin.cpp.o -MF CMakeFiles/demodbfmsrv.dir/bfmplugin.cpp.o.d -o CMakeFiles/demodbfmsrv.dir/bfmplugin.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/demodbfm/bfmplugin.cpp

pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/bfmplugin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demodbfmsrv.dir/bfmplugin.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodbfm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/demodbfm/bfmplugin.cpp > CMakeFiles/demodbfmsrv.dir/bfmplugin.cpp.i

pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/bfmplugin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demodbfmsrv.dir/bfmplugin.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodbfm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/demodbfm/bfmplugin.cpp -o CMakeFiles/demodbfmsrv.dir/bfmplugin.cpp.s

pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/rdsdemod.cpp.o: pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/flags.make
pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/rdsdemod.cpp.o: ../plugins/channelrx/demodbfm/rdsdemod.cpp
pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/rdsdemod.cpp.o: pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/rdsdemod.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodbfm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/rdsdemod.cpp.o -MF CMakeFiles/demodbfmsrv.dir/rdsdemod.cpp.o.d -o CMakeFiles/demodbfmsrv.dir/rdsdemod.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/demodbfm/rdsdemod.cpp

pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/rdsdemod.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demodbfmsrv.dir/rdsdemod.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodbfm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/demodbfm/rdsdemod.cpp > CMakeFiles/demodbfmsrv.dir/rdsdemod.cpp.i

pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/rdsdemod.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demodbfmsrv.dir/rdsdemod.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodbfm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/demodbfm/rdsdemod.cpp -o CMakeFiles/demodbfmsrv.dir/rdsdemod.cpp.s

pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/rdsdecoder.cpp.o: pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/flags.make
pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/rdsdecoder.cpp.o: ../plugins/channelrx/demodbfm/rdsdecoder.cpp
pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/rdsdecoder.cpp.o: pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/rdsdecoder.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodbfm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/rdsdecoder.cpp.o -MF CMakeFiles/demodbfmsrv.dir/rdsdecoder.cpp.o.d -o CMakeFiles/demodbfmsrv.dir/rdsdecoder.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/demodbfm/rdsdecoder.cpp

pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/rdsdecoder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demodbfmsrv.dir/rdsdecoder.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodbfm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/demodbfm/rdsdecoder.cpp > CMakeFiles/demodbfmsrv.dir/rdsdecoder.cpp.i

pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/rdsdecoder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demodbfmsrv.dir/rdsdecoder.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodbfm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/demodbfm/rdsdecoder.cpp -o CMakeFiles/demodbfmsrv.dir/rdsdecoder.cpp.s

pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/rdsparser.cpp.o: pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/flags.make
pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/rdsparser.cpp.o: ../plugins/channelrx/demodbfm/rdsparser.cpp
pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/rdsparser.cpp.o: pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/rdsparser.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodbfm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/rdsparser.cpp.o -MF CMakeFiles/demodbfmsrv.dir/rdsparser.cpp.o.d -o CMakeFiles/demodbfmsrv.dir/rdsparser.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/demodbfm/rdsparser.cpp

pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/rdsparser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demodbfmsrv.dir/rdsparser.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodbfm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/demodbfm/rdsparser.cpp > CMakeFiles/demodbfmsrv.dir/rdsparser.cpp.i

pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/rdsparser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demodbfmsrv.dir/rdsparser.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodbfm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/demodbfm/rdsparser.cpp -o CMakeFiles/demodbfmsrv.dir/rdsparser.cpp.s

pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/rdstmc.cpp.o: pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/flags.make
pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/rdstmc.cpp.o: ../plugins/channelrx/demodbfm/rdstmc.cpp
pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/rdstmc.cpp.o: pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/rdstmc.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodbfm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/rdstmc.cpp.o -MF CMakeFiles/demodbfmsrv.dir/rdstmc.cpp.o.d -o CMakeFiles/demodbfmsrv.dir/rdstmc.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/demodbfm/rdstmc.cpp

pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/rdstmc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demodbfmsrv.dir/rdstmc.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodbfm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/demodbfm/rdstmc.cpp > CMakeFiles/demodbfmsrv.dir/rdstmc.cpp.i

pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/rdstmc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demodbfmsrv.dir/rdstmc.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodbfm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/demodbfm/rdstmc.cpp -o CMakeFiles/demodbfmsrv.dir/rdstmc.cpp.s

# Object files for target demodbfmsrv
demodbfmsrv_OBJECTS = \
"CMakeFiles/demodbfmsrv.dir/demodbfmsrv_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/demodbfmsrv.dir/bfmdemod.cpp.o" \
"CMakeFiles/demodbfmsrv.dir/bfmdemodsettings.cpp.o" \
"CMakeFiles/demodbfmsrv.dir/bfmdemodsink.cpp.o" \
"CMakeFiles/demodbfmsrv.dir/bfmdemodbaseband.cpp.o" \
"CMakeFiles/demodbfmsrv.dir/bfmdemodreport.cpp.o" \
"CMakeFiles/demodbfmsrv.dir/bfmdemodwebapiadapter.cpp.o" \
"CMakeFiles/demodbfmsrv.dir/bfmplugin.cpp.o" \
"CMakeFiles/demodbfmsrv.dir/rdsdemod.cpp.o" \
"CMakeFiles/demodbfmsrv.dir/rdsdecoder.cpp.o" \
"CMakeFiles/demodbfmsrv.dir/rdsparser.cpp.o" \
"CMakeFiles/demodbfmsrv.dir/rdstmc.cpp.o"

# External object files for target demodbfmsrv
demodbfmsrv_EXTERNAL_OBJECTS =

lib/pluginssrv/libdemodbfmsrv.so: pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/demodbfmsrv_autogen/mocs_compilation.cpp.o
lib/pluginssrv/libdemodbfmsrv.so: pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/bfmdemod.cpp.o
lib/pluginssrv/libdemodbfmsrv.so: pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/bfmdemodsettings.cpp.o
lib/pluginssrv/libdemodbfmsrv.so: pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/bfmdemodsink.cpp.o
lib/pluginssrv/libdemodbfmsrv.so: pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/bfmdemodbaseband.cpp.o
lib/pluginssrv/libdemodbfmsrv.so: pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/bfmdemodreport.cpp.o
lib/pluginssrv/libdemodbfmsrv.so: pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/bfmdemodwebapiadapter.cpp.o
lib/pluginssrv/libdemodbfmsrv.so: pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/bfmplugin.cpp.o
lib/pluginssrv/libdemodbfmsrv.so: pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/rdsdemod.cpp.o
lib/pluginssrv/libdemodbfmsrv.so: pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/rdsdecoder.cpp.o
lib/pluginssrv/libdemodbfmsrv.so: pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/rdsparser.cpp.o
lib/pluginssrv/libdemodbfmsrv.so: pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/rdstmc.cpp.o
lib/pluginssrv/libdemodbfmsrv.so: pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/build.make
lib/pluginssrv/libdemodbfmsrv.so: lib/libsdrbase.so
lib/pluginssrv/libdemodbfmsrv.so: /usr/lib/x86_64-linux-gnu/libopus.so
lib/pluginssrv/libdemodbfmsrv.so: /usr/lib/x86_64-linux-gnu/libm.so
lib/pluginssrv/libdemodbfmsrv.so: /usr/lib/x86_64-linux-gnu/libfftw3f.so
lib/pluginssrv/libdemodbfmsrv.so: /opt/install/serialdv/lib/libserialdv.so
lib/pluginssrv/libdemodbfmsrv.so: /opt/install/LimeSuite/lib/libLimeSuite.so
lib/pluginssrv/libdemodbfmsrv.so: /usr/lib/x86_64-linux-gnu/libQt5Multimedia.so.5.15.2
lib/pluginssrv/libdemodbfmsrv.so: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.15.2
lib/pluginssrv/libdemodbfmsrv.so: /usr/lib/x86_64-linux-gnu/libQt5WebSockets.so.5.15.2
lib/pluginssrv/libdemodbfmsrv.so: lib/libhttpserver.so
lib/pluginssrv/libdemodbfmsrv.so: lib/liblogging.so
lib/pluginssrv/libdemodbfmsrv.so: lib/libqrtplib.so
lib/pluginssrv/libdemodbfmsrv.so: lib/libswagger.so
lib/pluginssrv/libdemodbfmsrv.so: /usr/lib/x86_64-linux-gnu/libQt5Network.so.5.15.2
lib/pluginssrv/libdemodbfmsrv.so: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.15.2
lib/pluginssrv/libdemodbfmsrv.so: pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX shared library ../../../lib/pluginssrv/libdemodbfmsrv.so"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodbfm && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/demodbfmsrv.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/build: lib/pluginssrv/libdemodbfmsrv.so
.PHONY : pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/build

pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/clean:
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodbfm && $(CMAKE_COMMAND) -P CMakeFiles/demodbfmsrv.dir/cmake_clean.cmake
.PHONY : pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/clean

pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/depend:
	cd /opt/build/RPX-100-SDR/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /opt/build/RPX-100-SDR /opt/build/RPX-100-SDR/plugins/channelrx/demodbfm /opt/build/RPX-100-SDR/build /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodbfm /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : pluginssrv/channelrx/demodbfm/CMakeFiles/demodbfmsrv.dir/depend

