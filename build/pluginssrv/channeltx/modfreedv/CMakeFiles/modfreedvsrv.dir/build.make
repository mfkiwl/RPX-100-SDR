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
include pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/compiler_depend.make

# Include the progress variables for this target.
include pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/progress.make

# Include the compile flags for this target's objects.
include pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/flags.make

pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/modfreedvsrv_autogen/mocs_compilation.cpp.o: pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/flags.make
pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/modfreedvsrv_autogen/mocs_compilation.cpp.o: pluginssrv/channeltx/modfreedv/modfreedvsrv_autogen/mocs_compilation.cpp
pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/modfreedvsrv_autogen/mocs_compilation.cpp.o: pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/modfreedvsrv_autogen/mocs_compilation.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channeltx/modfreedv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/modfreedvsrv_autogen/mocs_compilation.cpp.o -MF CMakeFiles/modfreedvsrv.dir/modfreedvsrv_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/modfreedvsrv.dir/modfreedvsrv_autogen/mocs_compilation.cpp.o -c /opt/build/RPX-100-SDR/build/pluginssrv/channeltx/modfreedv/modfreedvsrv_autogen/mocs_compilation.cpp

pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/modfreedvsrv_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/modfreedvsrv.dir/modfreedvsrv_autogen/mocs_compilation.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channeltx/modfreedv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/build/pluginssrv/channeltx/modfreedv/modfreedvsrv_autogen/mocs_compilation.cpp > CMakeFiles/modfreedvsrv.dir/modfreedvsrv_autogen/mocs_compilation.cpp.i

pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/modfreedvsrv_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/modfreedvsrv.dir/modfreedvsrv_autogen/mocs_compilation.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channeltx/modfreedv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/build/pluginssrv/channeltx/modfreedv/modfreedvsrv_autogen/mocs_compilation.cpp -o CMakeFiles/modfreedvsrv.dir/modfreedvsrv_autogen/mocs_compilation.cpp.s

pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/freedvmod.cpp.o: pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/flags.make
pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/freedvmod.cpp.o: ../plugins/channeltx/modfreedv/freedvmod.cpp
pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/freedvmod.cpp.o: pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/freedvmod.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channeltx/modfreedv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/freedvmod.cpp.o -MF CMakeFiles/modfreedvsrv.dir/freedvmod.cpp.o.d -o CMakeFiles/modfreedvsrv.dir/freedvmod.cpp.o -c /opt/build/RPX-100-SDR/plugins/channeltx/modfreedv/freedvmod.cpp

pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/freedvmod.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/modfreedvsrv.dir/freedvmod.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channeltx/modfreedv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channeltx/modfreedv/freedvmod.cpp > CMakeFiles/modfreedvsrv.dir/freedvmod.cpp.i

pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/freedvmod.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/modfreedvsrv.dir/freedvmod.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channeltx/modfreedv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channeltx/modfreedv/freedvmod.cpp -o CMakeFiles/modfreedvsrv.dir/freedvmod.cpp.s

pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/freedvmodbaseband.cpp.o: pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/flags.make
pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/freedvmodbaseband.cpp.o: ../plugins/channeltx/modfreedv/freedvmodbaseband.cpp
pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/freedvmodbaseband.cpp.o: pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/freedvmodbaseband.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channeltx/modfreedv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/freedvmodbaseband.cpp.o -MF CMakeFiles/modfreedvsrv.dir/freedvmodbaseband.cpp.o.d -o CMakeFiles/modfreedvsrv.dir/freedvmodbaseband.cpp.o -c /opt/build/RPX-100-SDR/plugins/channeltx/modfreedv/freedvmodbaseband.cpp

pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/freedvmodbaseband.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/modfreedvsrv.dir/freedvmodbaseband.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channeltx/modfreedv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channeltx/modfreedv/freedvmodbaseband.cpp > CMakeFiles/modfreedvsrv.dir/freedvmodbaseband.cpp.i

pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/freedvmodbaseband.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/modfreedvsrv.dir/freedvmodbaseband.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channeltx/modfreedv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channeltx/modfreedv/freedvmodbaseband.cpp -o CMakeFiles/modfreedvsrv.dir/freedvmodbaseband.cpp.s

pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/freedvmodsource.cpp.o: pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/flags.make
pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/freedvmodsource.cpp.o: ../plugins/channeltx/modfreedv/freedvmodsource.cpp
pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/freedvmodsource.cpp.o: pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/freedvmodsource.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channeltx/modfreedv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/freedvmodsource.cpp.o -MF CMakeFiles/modfreedvsrv.dir/freedvmodsource.cpp.o.d -o CMakeFiles/modfreedvsrv.dir/freedvmodsource.cpp.o -c /opt/build/RPX-100-SDR/plugins/channeltx/modfreedv/freedvmodsource.cpp

pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/freedvmodsource.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/modfreedvsrv.dir/freedvmodsource.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channeltx/modfreedv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channeltx/modfreedv/freedvmodsource.cpp > CMakeFiles/modfreedvsrv.dir/freedvmodsource.cpp.i

pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/freedvmodsource.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/modfreedvsrv.dir/freedvmodsource.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channeltx/modfreedv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channeltx/modfreedv/freedvmodsource.cpp -o CMakeFiles/modfreedvsrv.dir/freedvmodsource.cpp.s

pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/freedvmodplugin.cpp.o: pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/flags.make
pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/freedvmodplugin.cpp.o: ../plugins/channeltx/modfreedv/freedvmodplugin.cpp
pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/freedvmodplugin.cpp.o: pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/freedvmodplugin.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channeltx/modfreedv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/freedvmodplugin.cpp.o -MF CMakeFiles/modfreedvsrv.dir/freedvmodplugin.cpp.o.d -o CMakeFiles/modfreedvsrv.dir/freedvmodplugin.cpp.o -c /opt/build/RPX-100-SDR/plugins/channeltx/modfreedv/freedvmodplugin.cpp

pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/freedvmodplugin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/modfreedvsrv.dir/freedvmodplugin.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channeltx/modfreedv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channeltx/modfreedv/freedvmodplugin.cpp > CMakeFiles/modfreedvsrv.dir/freedvmodplugin.cpp.i

pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/freedvmodplugin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/modfreedvsrv.dir/freedvmodplugin.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channeltx/modfreedv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channeltx/modfreedv/freedvmodplugin.cpp -o CMakeFiles/modfreedvsrv.dir/freedvmodplugin.cpp.s

pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/freedvmodsettings.cpp.o: pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/flags.make
pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/freedvmodsettings.cpp.o: ../plugins/channeltx/modfreedv/freedvmodsettings.cpp
pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/freedvmodsettings.cpp.o: pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/freedvmodsettings.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channeltx/modfreedv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/freedvmodsettings.cpp.o -MF CMakeFiles/modfreedvsrv.dir/freedvmodsettings.cpp.o.d -o CMakeFiles/modfreedvsrv.dir/freedvmodsettings.cpp.o -c /opt/build/RPX-100-SDR/plugins/channeltx/modfreedv/freedvmodsettings.cpp

pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/freedvmodsettings.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/modfreedvsrv.dir/freedvmodsettings.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channeltx/modfreedv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channeltx/modfreedv/freedvmodsettings.cpp > CMakeFiles/modfreedvsrv.dir/freedvmodsettings.cpp.i

pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/freedvmodsettings.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/modfreedvsrv.dir/freedvmodsettings.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channeltx/modfreedv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channeltx/modfreedv/freedvmodsettings.cpp -o CMakeFiles/modfreedvsrv.dir/freedvmodsettings.cpp.s

pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/freedvmodwebapiadapter.cpp.o: pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/flags.make
pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/freedvmodwebapiadapter.cpp.o: ../plugins/channeltx/modfreedv/freedvmodwebapiadapter.cpp
pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/freedvmodwebapiadapter.cpp.o: pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/freedvmodwebapiadapter.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channeltx/modfreedv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/freedvmodwebapiadapter.cpp.o -MF CMakeFiles/modfreedvsrv.dir/freedvmodwebapiadapter.cpp.o.d -o CMakeFiles/modfreedvsrv.dir/freedvmodwebapiadapter.cpp.o -c /opt/build/RPX-100-SDR/plugins/channeltx/modfreedv/freedvmodwebapiadapter.cpp

pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/freedvmodwebapiadapter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/modfreedvsrv.dir/freedvmodwebapiadapter.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channeltx/modfreedv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channeltx/modfreedv/freedvmodwebapiadapter.cpp > CMakeFiles/modfreedvsrv.dir/freedvmodwebapiadapter.cpp.i

pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/freedvmodwebapiadapter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/modfreedvsrv.dir/freedvmodwebapiadapter.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channeltx/modfreedv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channeltx/modfreedv/freedvmodwebapiadapter.cpp -o CMakeFiles/modfreedvsrv.dir/freedvmodwebapiadapter.cpp.s

# Object files for target modfreedvsrv
modfreedvsrv_OBJECTS = \
"CMakeFiles/modfreedvsrv.dir/modfreedvsrv_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/modfreedvsrv.dir/freedvmod.cpp.o" \
"CMakeFiles/modfreedvsrv.dir/freedvmodbaseband.cpp.o" \
"CMakeFiles/modfreedvsrv.dir/freedvmodsource.cpp.o" \
"CMakeFiles/modfreedvsrv.dir/freedvmodplugin.cpp.o" \
"CMakeFiles/modfreedvsrv.dir/freedvmodsettings.cpp.o" \
"CMakeFiles/modfreedvsrv.dir/freedvmodwebapiadapter.cpp.o"

# External object files for target modfreedvsrv
modfreedvsrv_EXTERNAL_OBJECTS =

lib/pluginssrv/libmodfreedvsrv.so: pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/modfreedvsrv_autogen/mocs_compilation.cpp.o
lib/pluginssrv/libmodfreedvsrv.so: pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/freedvmod.cpp.o
lib/pluginssrv/libmodfreedvsrv.so: pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/freedvmodbaseband.cpp.o
lib/pluginssrv/libmodfreedvsrv.so: pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/freedvmodsource.cpp.o
lib/pluginssrv/libmodfreedvsrv.so: pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/freedvmodplugin.cpp.o
lib/pluginssrv/libmodfreedvsrv.so: pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/freedvmodsettings.cpp.o
lib/pluginssrv/libmodfreedvsrv.so: pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/freedvmodwebapiadapter.cpp.o
lib/pluginssrv/libmodfreedvsrv.so: pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/build.make
lib/pluginssrv/libmodfreedvsrv.so: lib/libsdrbase.so
lib/pluginssrv/libmodfreedvsrv.so: lib/libswagger.so
lib/pluginssrv/libmodfreedvsrv.so: /opt/install/codec2/lib/libcodec2.so
lib/pluginssrv/libmodfreedvsrv.so: /usr/lib/x86_64-linux-gnu/libopus.so
lib/pluginssrv/libmodfreedvsrv.so: /usr/lib/x86_64-linux-gnu/libm.so
lib/pluginssrv/libmodfreedvsrv.so: /usr/lib/x86_64-linux-gnu/libfftw3f.so
lib/pluginssrv/libmodfreedvsrv.so: /opt/install/serialdv/lib/libserialdv.so
lib/pluginssrv/libmodfreedvsrv.so: /opt/install/LimeSuite/lib/libLimeSuite.so
lib/pluginssrv/libmodfreedvsrv.so: /usr/lib/x86_64-linux-gnu/libQt5Multimedia.so.5.15.2
lib/pluginssrv/libmodfreedvsrv.so: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.15.2
lib/pluginssrv/libmodfreedvsrv.so: /usr/lib/x86_64-linux-gnu/libQt5WebSockets.so.5.15.2
lib/pluginssrv/libmodfreedvsrv.so: lib/libhttpserver.so
lib/pluginssrv/libmodfreedvsrv.so: lib/liblogging.so
lib/pluginssrv/libmodfreedvsrv.so: lib/libqrtplib.so
lib/pluginssrv/libmodfreedvsrv.so: /usr/lib/x86_64-linux-gnu/libQt5Network.so.5.15.2
lib/pluginssrv/libmodfreedvsrv.so: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.15.2
lib/pluginssrv/libmodfreedvsrv.so: pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX shared library ../../../lib/pluginssrv/libmodfreedvsrv.so"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channeltx/modfreedv && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/modfreedvsrv.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/build: lib/pluginssrv/libmodfreedvsrv.so
.PHONY : pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/build

pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/clean:
	cd /opt/build/RPX-100-SDR/build/pluginssrv/channeltx/modfreedv && $(CMAKE_COMMAND) -P CMakeFiles/modfreedvsrv.dir/cmake_clean.cmake
.PHONY : pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/clean

pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/depend:
	cd /opt/build/RPX-100-SDR/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /opt/build/RPX-100-SDR /opt/build/RPX-100-SDR/plugins/channeltx/modfreedv /opt/build/RPX-100-SDR/build /opt/build/RPX-100-SDR/build/pluginssrv/channeltx/modfreedv /opt/build/RPX-100-SDR/build/pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : pluginssrv/channeltx/modfreedv/CMakeFiles/modfreedvsrv.dir/depend
