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
include pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/compiler_depend.make

# Include the progress variables for this target.
include pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/progress.make

# Include the compile flags for this target's objects.
include pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/flags.make

pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/noisefiguresrv_autogen/mocs_compilation.cpp.o: pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/flags.make
pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/noisefiguresrv_autogen/mocs_compilation.cpp.o: pluginssrv/channelrx/noisefigure/noisefiguresrv_autogen/mocs_compilation.cpp
pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/noisefiguresrv_autogen/mocs_compilation.cpp.o: pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/noisefiguresrv_autogen/mocs_compilation.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/noisefigure && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/noisefiguresrv_autogen/mocs_compilation.cpp.o -MF CMakeFiles/noisefiguresrv.dir/noisefiguresrv_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/noisefiguresrv.dir/noisefiguresrv_autogen/mocs_compilation.cpp.o -c /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/noisefigure/noisefiguresrv_autogen/mocs_compilation.cpp

pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/noisefiguresrv_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/noisefiguresrv.dir/noisefiguresrv_autogen/mocs_compilation.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/noisefigure && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/noisefigure/noisefiguresrv_autogen/mocs_compilation.cpp > CMakeFiles/noisefiguresrv.dir/noisefiguresrv_autogen/mocs_compilation.cpp.i

pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/noisefiguresrv_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/noisefiguresrv.dir/noisefiguresrv_autogen/mocs_compilation.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/noisefigure && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/noisefigure/noisefiguresrv_autogen/mocs_compilation.cpp -o CMakeFiles/noisefiguresrv.dir/noisefiguresrv_autogen/mocs_compilation.cpp.s

pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/noisefigure.cpp.o: pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/flags.make
pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/noisefigure.cpp.o: ../plugins/channelrx/noisefigure/noisefigure.cpp
pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/noisefigure.cpp.o: pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/noisefigure.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/noisefigure && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/noisefigure.cpp.o -MF CMakeFiles/noisefiguresrv.dir/noisefigure.cpp.o.d -o CMakeFiles/noisefiguresrv.dir/noisefigure.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/noisefigure/noisefigure.cpp

pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/noisefigure.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/noisefiguresrv.dir/noisefigure.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/noisefigure && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/noisefigure/noisefigure.cpp > CMakeFiles/noisefiguresrv.dir/noisefigure.cpp.i

pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/noisefigure.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/noisefiguresrv.dir/noisefigure.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/noisefigure && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/noisefigure/noisefigure.cpp -o CMakeFiles/noisefiguresrv.dir/noisefigure.cpp.s

pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/noisefiguresettings.cpp.o: pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/flags.make
pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/noisefiguresettings.cpp.o: ../plugins/channelrx/noisefigure/noisefiguresettings.cpp
pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/noisefiguresettings.cpp.o: pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/noisefiguresettings.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/noisefigure && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/noisefiguresettings.cpp.o -MF CMakeFiles/noisefiguresrv.dir/noisefiguresettings.cpp.o.d -o CMakeFiles/noisefiguresrv.dir/noisefiguresettings.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/noisefigure/noisefiguresettings.cpp

pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/noisefiguresettings.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/noisefiguresrv.dir/noisefiguresettings.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/noisefigure && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/noisefigure/noisefiguresettings.cpp > CMakeFiles/noisefiguresrv.dir/noisefiguresettings.cpp.i

pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/noisefiguresettings.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/noisefiguresrv.dir/noisefiguresettings.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/noisefigure && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/noisefigure/noisefiguresettings.cpp -o CMakeFiles/noisefiguresrv.dir/noisefiguresettings.cpp.s

pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/noisefigurebaseband.cpp.o: pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/flags.make
pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/noisefigurebaseband.cpp.o: ../plugins/channelrx/noisefigure/noisefigurebaseband.cpp
pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/noisefigurebaseband.cpp.o: pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/noisefigurebaseband.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/noisefigure && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/noisefigurebaseband.cpp.o -MF CMakeFiles/noisefiguresrv.dir/noisefigurebaseband.cpp.o.d -o CMakeFiles/noisefiguresrv.dir/noisefigurebaseband.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/noisefigure/noisefigurebaseband.cpp

pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/noisefigurebaseband.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/noisefiguresrv.dir/noisefigurebaseband.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/noisefigure && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/noisefigure/noisefigurebaseband.cpp > CMakeFiles/noisefiguresrv.dir/noisefigurebaseband.cpp.i

pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/noisefigurebaseband.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/noisefiguresrv.dir/noisefigurebaseband.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/noisefigure && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/noisefigure/noisefigurebaseband.cpp -o CMakeFiles/noisefiguresrv.dir/noisefigurebaseband.cpp.s

pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/noisefiguresink.cpp.o: pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/flags.make
pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/noisefiguresink.cpp.o: ../plugins/channelrx/noisefigure/noisefiguresink.cpp
pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/noisefiguresink.cpp.o: pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/noisefiguresink.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/noisefigure && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/noisefiguresink.cpp.o -MF CMakeFiles/noisefiguresrv.dir/noisefiguresink.cpp.o.d -o CMakeFiles/noisefiguresrv.dir/noisefiguresink.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/noisefigure/noisefiguresink.cpp

pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/noisefiguresink.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/noisefiguresrv.dir/noisefiguresink.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/noisefigure && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/noisefigure/noisefiguresink.cpp > CMakeFiles/noisefiguresrv.dir/noisefiguresink.cpp.i

pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/noisefiguresink.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/noisefiguresrv.dir/noisefiguresink.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/noisefigure && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/noisefigure/noisefiguresink.cpp -o CMakeFiles/noisefiguresrv.dir/noisefiguresink.cpp.s

pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/noisefigureplugin.cpp.o: pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/flags.make
pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/noisefigureplugin.cpp.o: ../plugins/channelrx/noisefigure/noisefigureplugin.cpp
pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/noisefigureplugin.cpp.o: pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/noisefigureplugin.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/noisefigure && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/noisefigureplugin.cpp.o -MF CMakeFiles/noisefiguresrv.dir/noisefigureplugin.cpp.o.d -o CMakeFiles/noisefiguresrv.dir/noisefigureplugin.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/noisefigure/noisefigureplugin.cpp

pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/noisefigureplugin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/noisefiguresrv.dir/noisefigureplugin.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/noisefigure && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/noisefigure/noisefigureplugin.cpp > CMakeFiles/noisefiguresrv.dir/noisefigureplugin.cpp.i

pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/noisefigureplugin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/noisefiguresrv.dir/noisefigureplugin.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/noisefigure && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/noisefigure/noisefigureplugin.cpp -o CMakeFiles/noisefiguresrv.dir/noisefigureplugin.cpp.s

pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/noisefigurewebapiadapter.cpp.o: pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/flags.make
pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/noisefigurewebapiadapter.cpp.o: ../plugins/channelrx/noisefigure/noisefigurewebapiadapter.cpp
pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/noisefigurewebapiadapter.cpp.o: pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/noisefigurewebapiadapter.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/noisefigure && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/noisefigurewebapiadapter.cpp.o -MF CMakeFiles/noisefiguresrv.dir/noisefigurewebapiadapter.cpp.o.d -o CMakeFiles/noisefiguresrv.dir/noisefigurewebapiadapter.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/noisefigure/noisefigurewebapiadapter.cpp

pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/noisefigurewebapiadapter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/noisefiguresrv.dir/noisefigurewebapiadapter.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/noisefigure && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/noisefigure/noisefigurewebapiadapter.cpp > CMakeFiles/noisefiguresrv.dir/noisefigurewebapiadapter.cpp.i

pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/noisefigurewebapiadapter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/noisefiguresrv.dir/noisefigurewebapiadapter.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/noisefigure && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/noisefigure/noisefigurewebapiadapter.cpp -o CMakeFiles/noisefiguresrv.dir/noisefigurewebapiadapter.cpp.s

# Object files for target noisefiguresrv
noisefiguresrv_OBJECTS = \
"CMakeFiles/noisefiguresrv.dir/noisefiguresrv_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/noisefiguresrv.dir/noisefigure.cpp.o" \
"CMakeFiles/noisefiguresrv.dir/noisefiguresettings.cpp.o" \
"CMakeFiles/noisefiguresrv.dir/noisefigurebaseband.cpp.o" \
"CMakeFiles/noisefiguresrv.dir/noisefiguresink.cpp.o" \
"CMakeFiles/noisefiguresrv.dir/noisefigureplugin.cpp.o" \
"CMakeFiles/noisefiguresrv.dir/noisefigurewebapiadapter.cpp.o"

# External object files for target noisefiguresrv
noisefiguresrv_EXTERNAL_OBJECTS =

lib/pluginssrv/libnoisefiguresrv.so: pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/noisefiguresrv_autogen/mocs_compilation.cpp.o
lib/pluginssrv/libnoisefiguresrv.so: pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/noisefigure.cpp.o
lib/pluginssrv/libnoisefiguresrv.so: pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/noisefiguresettings.cpp.o
lib/pluginssrv/libnoisefiguresrv.so: pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/noisefigurebaseband.cpp.o
lib/pluginssrv/libnoisefiguresrv.so: pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/noisefiguresink.cpp.o
lib/pluginssrv/libnoisefiguresrv.so: pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/noisefigureplugin.cpp.o
lib/pluginssrv/libnoisefiguresrv.so: pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/noisefigurewebapiadapter.cpp.o
lib/pluginssrv/libnoisefiguresrv.so: pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/build.make
lib/pluginssrv/libnoisefiguresrv.so: lib/libsdrbase.so
lib/pluginssrv/libnoisefiguresrv.so: /usr/lib/x86_64-linux-gnu/libopus.so
lib/pluginssrv/libnoisefiguresrv.so: /usr/lib/x86_64-linux-gnu/libm.so
lib/pluginssrv/libnoisefiguresrv.so: /usr/lib/x86_64-linux-gnu/libfftw3f.so
lib/pluginssrv/libnoisefiguresrv.so: /opt/install/serialdv/lib/libserialdv.so
lib/pluginssrv/libnoisefiguresrv.so: /opt/install/LimeSuite/lib/libLimeSuite.so
lib/pluginssrv/libnoisefiguresrv.so: /usr/lib/x86_64-linux-gnu/libQt5Multimedia.so.5.15.2
lib/pluginssrv/libnoisefiguresrv.so: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.15.2
lib/pluginssrv/libnoisefiguresrv.so: /usr/lib/x86_64-linux-gnu/libQt5WebSockets.so.5.15.2
lib/pluginssrv/libnoisefiguresrv.so: lib/libhttpserver.so
lib/pluginssrv/libnoisefiguresrv.so: lib/liblogging.so
lib/pluginssrv/libnoisefiguresrv.so: lib/libqrtplib.so
lib/pluginssrv/libnoisefiguresrv.so: lib/libswagger.so
lib/pluginssrv/libnoisefiguresrv.so: /usr/lib/x86_64-linux-gnu/libQt5Network.so.5.15.2
lib/pluginssrv/libnoisefiguresrv.so: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.15.2
lib/pluginssrv/libnoisefiguresrv.so: pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX shared library ../../../lib/pluginssrv/libnoisefiguresrv.so"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/noisefigure && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/noisefiguresrv.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/build: lib/pluginssrv/libnoisefiguresrv.so
.PHONY : pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/build

pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/clean:
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/noisefigure && $(CMAKE_COMMAND) -P CMakeFiles/noisefiguresrv.dir/cmake_clean.cmake
.PHONY : pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/clean

pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/depend:
	cd /opt/build/RPX-100-SDR/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /opt/build/RPX-100-SDR /opt/build/RPX-100-SDR/plugins/channelrx/noisefigure /opt/build/RPX-100-SDR/build /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/noisefigure /opt/build/RPX-100-SDR/build/pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : pluginssrv/channelrx/noisefigure/CMakeFiles/noisefiguresrv.dir/depend

