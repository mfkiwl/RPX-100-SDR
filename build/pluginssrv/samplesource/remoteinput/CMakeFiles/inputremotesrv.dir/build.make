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
include pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/compiler_depend.make

# Include the progress variables for this target.
include pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/progress.make

# Include the compile flags for this target's objects.
include pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/flags.make

pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/inputremotesrv_autogen/mocs_compilation.cpp.o: pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/flags.make
pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/inputremotesrv_autogen/mocs_compilation.cpp.o: pluginssrv/samplesource/remoteinput/inputremotesrv_autogen/mocs_compilation.cpp
pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/inputremotesrv_autogen/mocs_compilation.cpp.o: pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/inputremotesrv_autogen/mocs_compilation.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/remoteinput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/inputremotesrv_autogen/mocs_compilation.cpp.o -MF CMakeFiles/inputremotesrv.dir/inputremotesrv_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/inputremotesrv.dir/inputremotesrv_autogen/mocs_compilation.cpp.o -c /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/remoteinput/inputremotesrv_autogen/mocs_compilation.cpp

pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/inputremotesrv_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/inputremotesrv.dir/inputremotesrv_autogen/mocs_compilation.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/remoteinput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/remoteinput/inputremotesrv_autogen/mocs_compilation.cpp > CMakeFiles/inputremotesrv.dir/inputremotesrv_autogen/mocs_compilation.cpp.i

pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/inputremotesrv_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/inputremotesrv.dir/inputremotesrv_autogen/mocs_compilation.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/remoteinput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/remoteinput/inputremotesrv_autogen/mocs_compilation.cpp -o CMakeFiles/inputremotesrv.dir/inputremotesrv_autogen/mocs_compilation.cpp.s

pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/remoteinputbuffer.cpp.o: pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/flags.make
pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/remoteinputbuffer.cpp.o: ../plugins/samplesource/remoteinput/remoteinputbuffer.cpp
pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/remoteinputbuffer.cpp.o: pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/remoteinputbuffer.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/remoteinput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/remoteinputbuffer.cpp.o -MF CMakeFiles/inputremotesrv.dir/remoteinputbuffer.cpp.o.d -o CMakeFiles/inputremotesrv.dir/remoteinputbuffer.cpp.o -c /opt/build/RPX-100-SDR/plugins/samplesource/remoteinput/remoteinputbuffer.cpp

pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/remoteinputbuffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/inputremotesrv.dir/remoteinputbuffer.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/remoteinput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/samplesource/remoteinput/remoteinputbuffer.cpp > CMakeFiles/inputremotesrv.dir/remoteinputbuffer.cpp.i

pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/remoteinputbuffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/inputremotesrv.dir/remoteinputbuffer.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/remoteinput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/samplesource/remoteinput/remoteinputbuffer.cpp -o CMakeFiles/inputremotesrv.dir/remoteinputbuffer.cpp.s

pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/remoteinputudphandler.cpp.o: pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/flags.make
pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/remoteinputudphandler.cpp.o: ../plugins/samplesource/remoteinput/remoteinputudphandler.cpp
pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/remoteinputudphandler.cpp.o: pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/remoteinputudphandler.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/remoteinput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/remoteinputudphandler.cpp.o -MF CMakeFiles/inputremotesrv.dir/remoteinputudphandler.cpp.o.d -o CMakeFiles/inputremotesrv.dir/remoteinputudphandler.cpp.o -c /opt/build/RPX-100-SDR/plugins/samplesource/remoteinput/remoteinputudphandler.cpp

pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/remoteinputudphandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/inputremotesrv.dir/remoteinputudphandler.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/remoteinput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/samplesource/remoteinput/remoteinputudphandler.cpp > CMakeFiles/inputremotesrv.dir/remoteinputudphandler.cpp.i

pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/remoteinputudphandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/inputremotesrv.dir/remoteinputudphandler.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/remoteinput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/samplesource/remoteinput/remoteinputudphandler.cpp -o CMakeFiles/inputremotesrv.dir/remoteinputudphandler.cpp.s

pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/remoteinput.cpp.o: pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/flags.make
pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/remoteinput.cpp.o: ../plugins/samplesource/remoteinput/remoteinput.cpp
pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/remoteinput.cpp.o: pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/remoteinput.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/remoteinput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/remoteinput.cpp.o -MF CMakeFiles/inputremotesrv.dir/remoteinput.cpp.o.d -o CMakeFiles/inputremotesrv.dir/remoteinput.cpp.o -c /opt/build/RPX-100-SDR/plugins/samplesource/remoteinput/remoteinput.cpp

pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/remoteinput.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/inputremotesrv.dir/remoteinput.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/remoteinput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/samplesource/remoteinput/remoteinput.cpp > CMakeFiles/inputremotesrv.dir/remoteinput.cpp.i

pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/remoteinput.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/inputremotesrv.dir/remoteinput.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/remoteinput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/samplesource/remoteinput/remoteinput.cpp -o CMakeFiles/inputremotesrv.dir/remoteinput.cpp.s

pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/remoteinputsettings.cpp.o: pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/flags.make
pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/remoteinputsettings.cpp.o: ../plugins/samplesource/remoteinput/remoteinputsettings.cpp
pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/remoteinputsettings.cpp.o: pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/remoteinputsettings.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/remoteinput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/remoteinputsettings.cpp.o -MF CMakeFiles/inputremotesrv.dir/remoteinputsettings.cpp.o.d -o CMakeFiles/inputremotesrv.dir/remoteinputsettings.cpp.o -c /opt/build/RPX-100-SDR/plugins/samplesource/remoteinput/remoteinputsettings.cpp

pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/remoteinputsettings.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/inputremotesrv.dir/remoteinputsettings.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/remoteinput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/samplesource/remoteinput/remoteinputsettings.cpp > CMakeFiles/inputremotesrv.dir/remoteinputsettings.cpp.i

pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/remoteinputsettings.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/inputremotesrv.dir/remoteinputsettings.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/remoteinput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/samplesource/remoteinput/remoteinputsettings.cpp -o CMakeFiles/inputremotesrv.dir/remoteinputsettings.cpp.s

pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/remoteinputwebapiadapter.cpp.o: pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/flags.make
pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/remoteinputwebapiadapter.cpp.o: ../plugins/samplesource/remoteinput/remoteinputwebapiadapter.cpp
pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/remoteinputwebapiadapter.cpp.o: pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/remoteinputwebapiadapter.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/remoteinput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/remoteinputwebapiadapter.cpp.o -MF CMakeFiles/inputremotesrv.dir/remoteinputwebapiadapter.cpp.o.d -o CMakeFiles/inputremotesrv.dir/remoteinputwebapiadapter.cpp.o -c /opt/build/RPX-100-SDR/plugins/samplesource/remoteinput/remoteinputwebapiadapter.cpp

pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/remoteinputwebapiadapter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/inputremotesrv.dir/remoteinputwebapiadapter.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/remoteinput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/samplesource/remoteinput/remoteinputwebapiadapter.cpp > CMakeFiles/inputremotesrv.dir/remoteinputwebapiadapter.cpp.i

pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/remoteinputwebapiadapter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/inputremotesrv.dir/remoteinputwebapiadapter.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/remoteinput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/samplesource/remoteinput/remoteinputwebapiadapter.cpp -o CMakeFiles/inputremotesrv.dir/remoteinputwebapiadapter.cpp.s

pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/remoteinputplugin.cpp.o: pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/flags.make
pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/remoteinputplugin.cpp.o: ../plugins/samplesource/remoteinput/remoteinputplugin.cpp
pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/remoteinputplugin.cpp.o: pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/remoteinputplugin.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/remoteinput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/remoteinputplugin.cpp.o -MF CMakeFiles/inputremotesrv.dir/remoteinputplugin.cpp.o.d -o CMakeFiles/inputremotesrv.dir/remoteinputplugin.cpp.o -c /opt/build/RPX-100-SDR/plugins/samplesource/remoteinput/remoteinputplugin.cpp

pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/remoteinputplugin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/inputremotesrv.dir/remoteinputplugin.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/remoteinput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/samplesource/remoteinput/remoteinputplugin.cpp > CMakeFiles/inputremotesrv.dir/remoteinputplugin.cpp.i

pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/remoteinputplugin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/inputremotesrv.dir/remoteinputplugin.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/remoteinput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/samplesource/remoteinput/remoteinputplugin.cpp -o CMakeFiles/inputremotesrv.dir/remoteinputplugin.cpp.s

# Object files for target inputremotesrv
inputremotesrv_OBJECTS = \
"CMakeFiles/inputremotesrv.dir/inputremotesrv_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/inputremotesrv.dir/remoteinputbuffer.cpp.o" \
"CMakeFiles/inputremotesrv.dir/remoteinputudphandler.cpp.o" \
"CMakeFiles/inputremotesrv.dir/remoteinput.cpp.o" \
"CMakeFiles/inputremotesrv.dir/remoteinputsettings.cpp.o" \
"CMakeFiles/inputremotesrv.dir/remoteinputwebapiadapter.cpp.o" \
"CMakeFiles/inputremotesrv.dir/remoteinputplugin.cpp.o"

# External object files for target inputremotesrv
inputremotesrv_EXTERNAL_OBJECTS =

lib/pluginssrv/libinputremotesrv.so: pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/inputremotesrv_autogen/mocs_compilation.cpp.o
lib/pluginssrv/libinputremotesrv.so: pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/remoteinputbuffer.cpp.o
lib/pluginssrv/libinputremotesrv.so: pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/remoteinputudphandler.cpp.o
lib/pluginssrv/libinputremotesrv.so: pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/remoteinput.cpp.o
lib/pluginssrv/libinputremotesrv.so: pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/remoteinputsettings.cpp.o
lib/pluginssrv/libinputremotesrv.so: pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/remoteinputwebapiadapter.cpp.o
lib/pluginssrv/libinputremotesrv.so: pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/remoteinputplugin.cpp.o
lib/pluginssrv/libinputremotesrv.so: pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/build.make
lib/pluginssrv/libinputremotesrv.so: lib/libsdrbase.so
lib/pluginssrv/libinputremotesrv.so: lib/libswagger.so
lib/pluginssrv/libinputremotesrv.so: /opt/install/cm256cc/lib/libcm256cc.so
lib/pluginssrv/libinputremotesrv.so: /usr/lib/x86_64-linux-gnu/libopus.so
lib/pluginssrv/libinputremotesrv.so: /usr/lib/x86_64-linux-gnu/libm.so
lib/pluginssrv/libinputremotesrv.so: /usr/lib/x86_64-linux-gnu/libfftw3f.so
lib/pluginssrv/libinputremotesrv.so: /opt/install/serialdv/lib/libserialdv.so
lib/pluginssrv/libinputremotesrv.so: /opt/install/LimeSuite/lib/libLimeSuite.so
lib/pluginssrv/libinputremotesrv.so: /usr/lib/x86_64-linux-gnu/libQt5Multimedia.so.5.15.2
lib/pluginssrv/libinputremotesrv.so: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.15.2
lib/pluginssrv/libinputremotesrv.so: /usr/lib/x86_64-linux-gnu/libQt5WebSockets.so.5.15.2
lib/pluginssrv/libinputremotesrv.so: lib/libhttpserver.so
lib/pluginssrv/libinputremotesrv.so: lib/liblogging.so
lib/pluginssrv/libinputremotesrv.so: lib/libqrtplib.so
lib/pluginssrv/libinputremotesrv.so: /usr/lib/x86_64-linux-gnu/libQt5Network.so.5.15.2
lib/pluginssrv/libinputremotesrv.so: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.15.2
lib/pluginssrv/libinputremotesrv.so: pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX shared library ../../../lib/pluginssrv/libinputremotesrv.so"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/remoteinput && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/inputremotesrv.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/build: lib/pluginssrv/libinputremotesrv.so
.PHONY : pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/build

pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/clean:
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/remoteinput && $(CMAKE_COMMAND) -P CMakeFiles/inputremotesrv.dir/cmake_clean.cmake
.PHONY : pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/clean

pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/depend:
	cd /opt/build/RPX-100-SDR/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /opt/build/RPX-100-SDR /opt/build/RPX-100-SDR/plugins/samplesource/remoteinput /opt/build/RPX-100-SDR/build /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/remoteinput /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : pluginssrv/samplesource/remoteinput/CMakeFiles/inputremotesrv.dir/depend

