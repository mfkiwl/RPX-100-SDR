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
include pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/compiler_depend.make

# Include the progress variables for this target.
include pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/progress.make

# Include the compile flags for this target's objects.
include pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/flags.make

pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/inputaudiosrv_autogen/mocs_compilation.cpp.o: pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/flags.make
pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/inputaudiosrv_autogen/mocs_compilation.cpp.o: pluginssrv/samplesource/audioinput/inputaudiosrv_autogen/mocs_compilation.cpp
pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/inputaudiosrv_autogen/mocs_compilation.cpp.o: pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/inputaudiosrv_autogen/mocs_compilation.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/audioinput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/inputaudiosrv_autogen/mocs_compilation.cpp.o -MF CMakeFiles/inputaudiosrv.dir/inputaudiosrv_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/inputaudiosrv.dir/inputaudiosrv_autogen/mocs_compilation.cpp.o -c /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/audioinput/inputaudiosrv_autogen/mocs_compilation.cpp

pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/inputaudiosrv_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/inputaudiosrv.dir/inputaudiosrv_autogen/mocs_compilation.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/audioinput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/audioinput/inputaudiosrv_autogen/mocs_compilation.cpp > CMakeFiles/inputaudiosrv.dir/inputaudiosrv_autogen/mocs_compilation.cpp.i

pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/inputaudiosrv_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/inputaudiosrv.dir/inputaudiosrv_autogen/mocs_compilation.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/audioinput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/audioinput/inputaudiosrv_autogen/mocs_compilation.cpp -o CMakeFiles/inputaudiosrv.dir/inputaudiosrv_autogen/mocs_compilation.cpp.s

pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/audioinput.cpp.o: pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/flags.make
pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/audioinput.cpp.o: ../plugins/samplesource/audioinput/audioinput.cpp
pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/audioinput.cpp.o: pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/audioinput.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/audioinput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/audioinput.cpp.o -MF CMakeFiles/inputaudiosrv.dir/audioinput.cpp.o.d -o CMakeFiles/inputaudiosrv.dir/audioinput.cpp.o -c /opt/build/RPX-100-SDR/plugins/samplesource/audioinput/audioinput.cpp

pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/audioinput.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/inputaudiosrv.dir/audioinput.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/audioinput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/samplesource/audioinput/audioinput.cpp > CMakeFiles/inputaudiosrv.dir/audioinput.cpp.i

pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/audioinput.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/inputaudiosrv.dir/audioinput.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/audioinput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/samplesource/audioinput/audioinput.cpp -o CMakeFiles/inputaudiosrv.dir/audioinput.cpp.s

pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/audioinputplugin.cpp.o: pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/flags.make
pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/audioinputplugin.cpp.o: ../plugins/samplesource/audioinput/audioinputplugin.cpp
pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/audioinputplugin.cpp.o: pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/audioinputplugin.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/audioinput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/audioinputplugin.cpp.o -MF CMakeFiles/inputaudiosrv.dir/audioinputplugin.cpp.o.d -o CMakeFiles/inputaudiosrv.dir/audioinputplugin.cpp.o -c /opt/build/RPX-100-SDR/plugins/samplesource/audioinput/audioinputplugin.cpp

pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/audioinputplugin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/inputaudiosrv.dir/audioinputplugin.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/audioinput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/samplesource/audioinput/audioinputplugin.cpp > CMakeFiles/inputaudiosrv.dir/audioinputplugin.cpp.i

pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/audioinputplugin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/inputaudiosrv.dir/audioinputplugin.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/audioinput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/samplesource/audioinput/audioinputplugin.cpp -o CMakeFiles/inputaudiosrv.dir/audioinputplugin.cpp.s

pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/audioinputsettings.cpp.o: pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/flags.make
pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/audioinputsettings.cpp.o: ../plugins/samplesource/audioinput/audioinputsettings.cpp
pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/audioinputsettings.cpp.o: pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/audioinputsettings.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/audioinput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/audioinputsettings.cpp.o -MF CMakeFiles/inputaudiosrv.dir/audioinputsettings.cpp.o.d -o CMakeFiles/inputaudiosrv.dir/audioinputsettings.cpp.o -c /opt/build/RPX-100-SDR/plugins/samplesource/audioinput/audioinputsettings.cpp

pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/audioinputsettings.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/inputaudiosrv.dir/audioinputsettings.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/audioinput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/samplesource/audioinput/audioinputsettings.cpp > CMakeFiles/inputaudiosrv.dir/audioinputsettings.cpp.i

pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/audioinputsettings.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/inputaudiosrv.dir/audioinputsettings.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/audioinput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/samplesource/audioinput/audioinputsettings.cpp -o CMakeFiles/inputaudiosrv.dir/audioinputsettings.cpp.s

pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/audioinputwebapiadapter.cpp.o: pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/flags.make
pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/audioinputwebapiadapter.cpp.o: ../plugins/samplesource/audioinput/audioinputwebapiadapter.cpp
pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/audioinputwebapiadapter.cpp.o: pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/audioinputwebapiadapter.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/audioinput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/audioinputwebapiadapter.cpp.o -MF CMakeFiles/inputaudiosrv.dir/audioinputwebapiadapter.cpp.o.d -o CMakeFiles/inputaudiosrv.dir/audioinputwebapiadapter.cpp.o -c /opt/build/RPX-100-SDR/plugins/samplesource/audioinput/audioinputwebapiadapter.cpp

pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/audioinputwebapiadapter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/inputaudiosrv.dir/audioinputwebapiadapter.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/audioinput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/samplesource/audioinput/audioinputwebapiadapter.cpp > CMakeFiles/inputaudiosrv.dir/audioinputwebapiadapter.cpp.i

pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/audioinputwebapiadapter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/inputaudiosrv.dir/audioinputwebapiadapter.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/audioinput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/samplesource/audioinput/audioinputwebapiadapter.cpp -o CMakeFiles/inputaudiosrv.dir/audioinputwebapiadapter.cpp.s

pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/audioinputworker.cpp.o: pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/flags.make
pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/audioinputworker.cpp.o: ../plugins/samplesource/audioinput/audioinputworker.cpp
pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/audioinputworker.cpp.o: pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/audioinputworker.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/audioinput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/audioinputworker.cpp.o -MF CMakeFiles/inputaudiosrv.dir/audioinputworker.cpp.o.d -o CMakeFiles/inputaudiosrv.dir/audioinputworker.cpp.o -c /opt/build/RPX-100-SDR/plugins/samplesource/audioinput/audioinputworker.cpp

pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/audioinputworker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/inputaudiosrv.dir/audioinputworker.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/audioinput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/samplesource/audioinput/audioinputworker.cpp > CMakeFiles/inputaudiosrv.dir/audioinputworker.cpp.i

pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/audioinputworker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/inputaudiosrv.dir/audioinputworker.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/audioinput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/samplesource/audioinput/audioinputworker.cpp -o CMakeFiles/inputaudiosrv.dir/audioinputworker.cpp.s

# Object files for target inputaudiosrv
inputaudiosrv_OBJECTS = \
"CMakeFiles/inputaudiosrv.dir/inputaudiosrv_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/inputaudiosrv.dir/audioinput.cpp.o" \
"CMakeFiles/inputaudiosrv.dir/audioinputplugin.cpp.o" \
"CMakeFiles/inputaudiosrv.dir/audioinputsettings.cpp.o" \
"CMakeFiles/inputaudiosrv.dir/audioinputwebapiadapter.cpp.o" \
"CMakeFiles/inputaudiosrv.dir/audioinputworker.cpp.o"

# External object files for target inputaudiosrv
inputaudiosrv_EXTERNAL_OBJECTS =

lib/pluginssrv/libinputaudiosrv.so: pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/inputaudiosrv_autogen/mocs_compilation.cpp.o
lib/pluginssrv/libinputaudiosrv.so: pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/audioinput.cpp.o
lib/pluginssrv/libinputaudiosrv.so: pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/audioinputplugin.cpp.o
lib/pluginssrv/libinputaudiosrv.so: pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/audioinputsettings.cpp.o
lib/pluginssrv/libinputaudiosrv.so: pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/audioinputwebapiadapter.cpp.o
lib/pluginssrv/libinputaudiosrv.so: pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/audioinputworker.cpp.o
lib/pluginssrv/libinputaudiosrv.so: pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/build.make
lib/pluginssrv/libinputaudiosrv.so: lib/libsdrbase.so
lib/pluginssrv/libinputaudiosrv.so: lib/libswagger.so
lib/pluginssrv/libinputaudiosrv.so: /usr/lib/x86_64-linux-gnu/libopus.so
lib/pluginssrv/libinputaudiosrv.so: /usr/lib/x86_64-linux-gnu/libm.so
lib/pluginssrv/libinputaudiosrv.so: /usr/lib/x86_64-linux-gnu/libfftw3f.so
lib/pluginssrv/libinputaudiosrv.so: /opt/install/serialdv/lib/libserialdv.so
lib/pluginssrv/libinputaudiosrv.so: /opt/install/LimeSuite/lib/libLimeSuite.so
lib/pluginssrv/libinputaudiosrv.so: /usr/lib/x86_64-linux-gnu/libQt5Multimedia.so.5.15.2
lib/pluginssrv/libinputaudiosrv.so: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.15.2
lib/pluginssrv/libinputaudiosrv.so: /usr/lib/x86_64-linux-gnu/libQt5WebSockets.so.5.15.2
lib/pluginssrv/libinputaudiosrv.so: lib/libhttpserver.so
lib/pluginssrv/libinputaudiosrv.so: lib/liblogging.so
lib/pluginssrv/libinputaudiosrv.so: lib/libqrtplib.so
lib/pluginssrv/libinputaudiosrv.so: /usr/lib/x86_64-linux-gnu/libQt5Network.so.5.15.2
lib/pluginssrv/libinputaudiosrv.so: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.15.2
lib/pluginssrv/libinputaudiosrv.so: pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX shared library ../../../lib/pluginssrv/libinputaudiosrv.so"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/audioinput && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/inputaudiosrv.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/build: lib/pluginssrv/libinputaudiosrv.so
.PHONY : pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/build

pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/clean:
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/audioinput && $(CMAKE_COMMAND) -P CMakeFiles/inputaudiosrv.dir/cmake_clean.cmake
.PHONY : pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/clean

pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/depend:
	cd /opt/build/RPX-100-SDR/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /opt/build/RPX-100-SDR /opt/build/RPX-100-SDR/plugins/samplesource/audioinput /opt/build/RPX-100-SDR/build /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/audioinput /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : pluginssrv/samplesource/audioinput/CMakeFiles/inputaudiosrv.dir/depend

