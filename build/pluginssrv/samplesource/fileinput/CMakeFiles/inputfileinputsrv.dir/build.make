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
include pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/compiler_depend.make

# Include the progress variables for this target.
include pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/progress.make

# Include the compile flags for this target's objects.
include pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/flags.make

pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/inputfileinputsrv_autogen/mocs_compilation.cpp.o: pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/flags.make
pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/inputfileinputsrv_autogen/mocs_compilation.cpp.o: pluginssrv/samplesource/fileinput/inputfileinputsrv_autogen/mocs_compilation.cpp
pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/inputfileinputsrv_autogen/mocs_compilation.cpp.o: pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/inputfileinputsrv_autogen/mocs_compilation.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/fileinput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/inputfileinputsrv_autogen/mocs_compilation.cpp.o -MF CMakeFiles/inputfileinputsrv.dir/inputfileinputsrv_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/inputfileinputsrv.dir/inputfileinputsrv_autogen/mocs_compilation.cpp.o -c /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/fileinput/inputfileinputsrv_autogen/mocs_compilation.cpp

pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/inputfileinputsrv_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/inputfileinputsrv.dir/inputfileinputsrv_autogen/mocs_compilation.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/fileinput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/fileinput/inputfileinputsrv_autogen/mocs_compilation.cpp > CMakeFiles/inputfileinputsrv.dir/inputfileinputsrv_autogen/mocs_compilation.cpp.i

pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/inputfileinputsrv_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/inputfileinputsrv.dir/inputfileinputsrv_autogen/mocs_compilation.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/fileinput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/fileinput/inputfileinputsrv_autogen/mocs_compilation.cpp -o CMakeFiles/inputfileinputsrv.dir/inputfileinputsrv_autogen/mocs_compilation.cpp.s

pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/fileinput.cpp.o: pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/flags.make
pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/fileinput.cpp.o: ../plugins/samplesource/fileinput/fileinput.cpp
pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/fileinput.cpp.o: pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/fileinput.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/fileinput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/fileinput.cpp.o -MF CMakeFiles/inputfileinputsrv.dir/fileinput.cpp.o.d -o CMakeFiles/inputfileinputsrv.dir/fileinput.cpp.o -c /opt/build/RPX-100-SDR/plugins/samplesource/fileinput/fileinput.cpp

pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/fileinput.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/inputfileinputsrv.dir/fileinput.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/fileinput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/samplesource/fileinput/fileinput.cpp > CMakeFiles/inputfileinputsrv.dir/fileinput.cpp.i

pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/fileinput.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/inputfileinputsrv.dir/fileinput.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/fileinput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/samplesource/fileinput/fileinput.cpp -o CMakeFiles/inputfileinputsrv.dir/fileinput.cpp.s

pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/fileinputplugin.cpp.o: pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/flags.make
pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/fileinputplugin.cpp.o: ../plugins/samplesource/fileinput/fileinputplugin.cpp
pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/fileinputplugin.cpp.o: pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/fileinputplugin.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/fileinput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/fileinputplugin.cpp.o -MF CMakeFiles/inputfileinputsrv.dir/fileinputplugin.cpp.o.d -o CMakeFiles/inputfileinputsrv.dir/fileinputplugin.cpp.o -c /opt/build/RPX-100-SDR/plugins/samplesource/fileinput/fileinputplugin.cpp

pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/fileinputplugin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/inputfileinputsrv.dir/fileinputplugin.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/fileinput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/samplesource/fileinput/fileinputplugin.cpp > CMakeFiles/inputfileinputsrv.dir/fileinputplugin.cpp.i

pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/fileinputplugin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/inputfileinputsrv.dir/fileinputplugin.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/fileinput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/samplesource/fileinput/fileinputplugin.cpp -o CMakeFiles/inputfileinputsrv.dir/fileinputplugin.cpp.s

pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/fileinputworker.cpp.o: pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/flags.make
pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/fileinputworker.cpp.o: ../plugins/samplesource/fileinput/fileinputworker.cpp
pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/fileinputworker.cpp.o: pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/fileinputworker.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/fileinput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/fileinputworker.cpp.o -MF CMakeFiles/inputfileinputsrv.dir/fileinputworker.cpp.o.d -o CMakeFiles/inputfileinputsrv.dir/fileinputworker.cpp.o -c /opt/build/RPX-100-SDR/plugins/samplesource/fileinput/fileinputworker.cpp

pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/fileinputworker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/inputfileinputsrv.dir/fileinputworker.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/fileinput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/samplesource/fileinput/fileinputworker.cpp > CMakeFiles/inputfileinputsrv.dir/fileinputworker.cpp.i

pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/fileinputworker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/inputfileinputsrv.dir/fileinputworker.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/fileinput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/samplesource/fileinput/fileinputworker.cpp -o CMakeFiles/inputfileinputsrv.dir/fileinputworker.cpp.s

pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/fileinputsettings.cpp.o: pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/flags.make
pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/fileinputsettings.cpp.o: ../plugins/samplesource/fileinput/fileinputsettings.cpp
pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/fileinputsettings.cpp.o: pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/fileinputsettings.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/fileinput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/fileinputsettings.cpp.o -MF CMakeFiles/inputfileinputsrv.dir/fileinputsettings.cpp.o.d -o CMakeFiles/inputfileinputsrv.dir/fileinputsettings.cpp.o -c /opt/build/RPX-100-SDR/plugins/samplesource/fileinput/fileinputsettings.cpp

pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/fileinputsettings.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/inputfileinputsrv.dir/fileinputsettings.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/fileinput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/samplesource/fileinput/fileinputsettings.cpp > CMakeFiles/inputfileinputsrv.dir/fileinputsettings.cpp.i

pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/fileinputsettings.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/inputfileinputsrv.dir/fileinputsettings.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/fileinput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/samplesource/fileinput/fileinputsettings.cpp -o CMakeFiles/inputfileinputsrv.dir/fileinputsettings.cpp.s

pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/fileinputwebapiadapter.cpp.o: pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/flags.make
pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/fileinputwebapiadapter.cpp.o: ../plugins/samplesource/fileinput/fileinputwebapiadapter.cpp
pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/fileinputwebapiadapter.cpp.o: pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/fileinputwebapiadapter.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/fileinput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/fileinputwebapiadapter.cpp.o -MF CMakeFiles/inputfileinputsrv.dir/fileinputwebapiadapter.cpp.o.d -o CMakeFiles/inputfileinputsrv.dir/fileinputwebapiadapter.cpp.o -c /opt/build/RPX-100-SDR/plugins/samplesource/fileinput/fileinputwebapiadapter.cpp

pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/fileinputwebapiadapter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/inputfileinputsrv.dir/fileinputwebapiadapter.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/fileinput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/samplesource/fileinput/fileinputwebapiadapter.cpp > CMakeFiles/inputfileinputsrv.dir/fileinputwebapiadapter.cpp.i

pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/fileinputwebapiadapter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/inputfileinputsrv.dir/fileinputwebapiadapter.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/fileinput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/samplesource/fileinput/fileinputwebapiadapter.cpp -o CMakeFiles/inputfileinputsrv.dir/fileinputwebapiadapter.cpp.s

# Object files for target inputfileinputsrv
inputfileinputsrv_OBJECTS = \
"CMakeFiles/inputfileinputsrv.dir/inputfileinputsrv_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/inputfileinputsrv.dir/fileinput.cpp.o" \
"CMakeFiles/inputfileinputsrv.dir/fileinputplugin.cpp.o" \
"CMakeFiles/inputfileinputsrv.dir/fileinputworker.cpp.o" \
"CMakeFiles/inputfileinputsrv.dir/fileinputsettings.cpp.o" \
"CMakeFiles/inputfileinputsrv.dir/fileinputwebapiadapter.cpp.o"

# External object files for target inputfileinputsrv
inputfileinputsrv_EXTERNAL_OBJECTS =

lib/pluginssrv/libinputfileinputsrv.so: pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/inputfileinputsrv_autogen/mocs_compilation.cpp.o
lib/pluginssrv/libinputfileinputsrv.so: pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/fileinput.cpp.o
lib/pluginssrv/libinputfileinputsrv.so: pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/fileinputplugin.cpp.o
lib/pluginssrv/libinputfileinputsrv.so: pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/fileinputworker.cpp.o
lib/pluginssrv/libinputfileinputsrv.so: pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/fileinputsettings.cpp.o
lib/pluginssrv/libinputfileinputsrv.so: pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/fileinputwebapiadapter.cpp.o
lib/pluginssrv/libinputfileinputsrv.so: pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/build.make
lib/pluginssrv/libinputfileinputsrv.so: lib/libsdrbase.so
lib/pluginssrv/libinputfileinputsrv.so: lib/libswagger.so
lib/pluginssrv/libinputfileinputsrv.so: /usr/lib/x86_64-linux-gnu/libopus.so
lib/pluginssrv/libinputfileinputsrv.so: /usr/lib/x86_64-linux-gnu/libm.so
lib/pluginssrv/libinputfileinputsrv.so: /usr/lib/x86_64-linux-gnu/libfftw3f.so
lib/pluginssrv/libinputfileinputsrv.so: /opt/install/serialdv/lib/libserialdv.so
lib/pluginssrv/libinputfileinputsrv.so: /opt/install/LimeSuite/lib/libLimeSuite.so
lib/pluginssrv/libinputfileinputsrv.so: /usr/lib/x86_64-linux-gnu/libQt5Multimedia.so.5.15.2
lib/pluginssrv/libinputfileinputsrv.so: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.15.2
lib/pluginssrv/libinputfileinputsrv.so: /usr/lib/x86_64-linux-gnu/libQt5WebSockets.so.5.15.2
lib/pluginssrv/libinputfileinputsrv.so: lib/libhttpserver.so
lib/pluginssrv/libinputfileinputsrv.so: lib/liblogging.so
lib/pluginssrv/libinputfileinputsrv.so: lib/libqrtplib.so
lib/pluginssrv/libinputfileinputsrv.so: /usr/lib/x86_64-linux-gnu/libQt5Network.so.5.15.2
lib/pluginssrv/libinputfileinputsrv.so: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.15.2
lib/pluginssrv/libinputfileinputsrv.so: pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX shared library ../../../lib/pluginssrv/libinputfileinputsrv.so"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/fileinput && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/inputfileinputsrv.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/build: lib/pluginssrv/libinputfileinputsrv.so
.PHONY : pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/build

pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/clean:
	cd /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/fileinput && $(CMAKE_COMMAND) -P CMakeFiles/inputfileinputsrv.dir/cmake_clean.cmake
.PHONY : pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/clean

pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/depend:
	cd /opt/build/RPX-100-SDR/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /opt/build/RPX-100-SDR /opt/build/RPX-100-SDR/plugins/samplesource/fileinput /opt/build/RPX-100-SDR/build /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/fileinput /opt/build/RPX-100-SDR/build/pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : pluginssrv/samplesource/fileinput/CMakeFiles/inputfileinputsrv.dir/depend

