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
include pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/compiler_depend.make

# Include the progress variables for this target.
include pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/progress.make

# Include the compile flags for this target's objects.
include pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/flags.make

pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/aprssrv_autogen/mocs_compilation.cpp.o: pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/flags.make
pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/aprssrv_autogen/mocs_compilation.cpp.o: pluginssrv/feature/aprs/aprssrv_autogen/mocs_compilation.cpp
pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/aprssrv_autogen/mocs_compilation.cpp.o: pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/aprssrv_autogen/mocs_compilation.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/aprs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/aprssrv_autogen/mocs_compilation.cpp.o -MF CMakeFiles/aprssrv.dir/aprssrv_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/aprssrv.dir/aprssrv_autogen/mocs_compilation.cpp.o -c /opt/build/RPX-100-SDR/build/pluginssrv/feature/aprs/aprssrv_autogen/mocs_compilation.cpp

pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/aprssrv_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/aprssrv.dir/aprssrv_autogen/mocs_compilation.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/aprs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/build/pluginssrv/feature/aprs/aprssrv_autogen/mocs_compilation.cpp > CMakeFiles/aprssrv.dir/aprssrv_autogen/mocs_compilation.cpp.i

pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/aprssrv_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/aprssrv.dir/aprssrv_autogen/mocs_compilation.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/aprs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/build/pluginssrv/feature/aprs/aprssrv_autogen/mocs_compilation.cpp -o CMakeFiles/aprssrv.dir/aprssrv_autogen/mocs_compilation.cpp.s

pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/aprs.cpp.o: pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/flags.make
pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/aprs.cpp.o: ../plugins/feature/aprs/aprs.cpp
pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/aprs.cpp.o: pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/aprs.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/aprs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/aprs.cpp.o -MF CMakeFiles/aprssrv.dir/aprs.cpp.o.d -o CMakeFiles/aprssrv.dir/aprs.cpp.o -c /opt/build/RPX-100-SDR/plugins/feature/aprs/aprs.cpp

pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/aprs.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/aprssrv.dir/aprs.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/aprs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/feature/aprs/aprs.cpp > CMakeFiles/aprssrv.dir/aprs.cpp.i

pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/aprs.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/aprssrv.dir/aprs.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/aprs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/feature/aprs/aprs.cpp -o CMakeFiles/aprssrv.dir/aprs.cpp.s

pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/aprssettings.cpp.o: pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/flags.make
pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/aprssettings.cpp.o: ../plugins/feature/aprs/aprssettings.cpp
pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/aprssettings.cpp.o: pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/aprssettings.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/aprs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/aprssettings.cpp.o -MF CMakeFiles/aprssrv.dir/aprssettings.cpp.o.d -o CMakeFiles/aprssrv.dir/aprssettings.cpp.o -c /opt/build/RPX-100-SDR/plugins/feature/aprs/aprssettings.cpp

pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/aprssettings.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/aprssrv.dir/aprssettings.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/aprs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/feature/aprs/aprssettings.cpp > CMakeFiles/aprssrv.dir/aprssettings.cpp.i

pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/aprssettings.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/aprssrv.dir/aprssettings.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/aprs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/feature/aprs/aprssettings.cpp -o CMakeFiles/aprssrv.dir/aprssettings.cpp.s

pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/aprsplugin.cpp.o: pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/flags.make
pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/aprsplugin.cpp.o: ../plugins/feature/aprs/aprsplugin.cpp
pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/aprsplugin.cpp.o: pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/aprsplugin.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/aprs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/aprsplugin.cpp.o -MF CMakeFiles/aprssrv.dir/aprsplugin.cpp.o.d -o CMakeFiles/aprssrv.dir/aprsplugin.cpp.o -c /opt/build/RPX-100-SDR/plugins/feature/aprs/aprsplugin.cpp

pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/aprsplugin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/aprssrv.dir/aprsplugin.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/aprs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/feature/aprs/aprsplugin.cpp > CMakeFiles/aprssrv.dir/aprsplugin.cpp.i

pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/aprsplugin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/aprssrv.dir/aprsplugin.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/aprs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/feature/aprs/aprsplugin.cpp -o CMakeFiles/aprssrv.dir/aprsplugin.cpp.s

pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/aprsworker.cpp.o: pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/flags.make
pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/aprsworker.cpp.o: ../plugins/feature/aprs/aprsworker.cpp
pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/aprsworker.cpp.o: pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/aprsworker.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/aprs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/aprsworker.cpp.o -MF CMakeFiles/aprssrv.dir/aprsworker.cpp.o.d -o CMakeFiles/aprssrv.dir/aprsworker.cpp.o -c /opt/build/RPX-100-SDR/plugins/feature/aprs/aprsworker.cpp

pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/aprsworker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/aprssrv.dir/aprsworker.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/aprs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/feature/aprs/aprsworker.cpp > CMakeFiles/aprssrv.dir/aprsworker.cpp.i

pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/aprsworker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/aprssrv.dir/aprsworker.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/aprs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/feature/aprs/aprsworker.cpp -o CMakeFiles/aprssrv.dir/aprsworker.cpp.s

pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/aprswebapiadapter.cpp.o: pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/flags.make
pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/aprswebapiadapter.cpp.o: ../plugins/feature/aprs/aprswebapiadapter.cpp
pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/aprswebapiadapter.cpp.o: pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/aprswebapiadapter.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/aprs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/aprswebapiadapter.cpp.o -MF CMakeFiles/aprssrv.dir/aprswebapiadapter.cpp.o.d -o CMakeFiles/aprssrv.dir/aprswebapiadapter.cpp.o -c /opt/build/RPX-100-SDR/plugins/feature/aprs/aprswebapiadapter.cpp

pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/aprswebapiadapter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/aprssrv.dir/aprswebapiadapter.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/aprs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/feature/aprs/aprswebapiadapter.cpp > CMakeFiles/aprssrv.dir/aprswebapiadapter.cpp.i

pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/aprswebapiadapter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/aprssrv.dir/aprswebapiadapter.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/aprs && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/feature/aprs/aprswebapiadapter.cpp -o CMakeFiles/aprssrv.dir/aprswebapiadapter.cpp.s

# Object files for target aprssrv
aprssrv_OBJECTS = \
"CMakeFiles/aprssrv.dir/aprssrv_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/aprssrv.dir/aprs.cpp.o" \
"CMakeFiles/aprssrv.dir/aprssettings.cpp.o" \
"CMakeFiles/aprssrv.dir/aprsplugin.cpp.o" \
"CMakeFiles/aprssrv.dir/aprsworker.cpp.o" \
"CMakeFiles/aprssrv.dir/aprswebapiadapter.cpp.o"

# External object files for target aprssrv
aprssrv_EXTERNAL_OBJECTS =

lib/pluginssrv/libaprssrv.so: pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/aprssrv_autogen/mocs_compilation.cpp.o
lib/pluginssrv/libaprssrv.so: pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/aprs.cpp.o
lib/pluginssrv/libaprssrv.so: pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/aprssettings.cpp.o
lib/pluginssrv/libaprssrv.so: pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/aprsplugin.cpp.o
lib/pluginssrv/libaprssrv.so: pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/aprsworker.cpp.o
lib/pluginssrv/libaprssrv.so: pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/aprswebapiadapter.cpp.o
lib/pluginssrv/libaprssrv.so: pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/build.make
lib/pluginssrv/libaprssrv.so: lib/libsdrbase.so
lib/pluginssrv/libaprssrv.so: /usr/lib/x86_64-linux-gnu/libopus.so
lib/pluginssrv/libaprssrv.so: /usr/lib/x86_64-linux-gnu/libm.so
lib/pluginssrv/libaprssrv.so: /usr/lib/x86_64-linux-gnu/libfftw3f.so
lib/pluginssrv/libaprssrv.so: /opt/install/serialdv/lib/libserialdv.so
lib/pluginssrv/libaprssrv.so: /opt/install/LimeSuite/lib/libLimeSuite.so
lib/pluginssrv/libaprssrv.so: /usr/lib/x86_64-linux-gnu/libQt5Multimedia.so.5.15.2
lib/pluginssrv/libaprssrv.so: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.15.2
lib/pluginssrv/libaprssrv.so: /usr/lib/x86_64-linux-gnu/libQt5WebSockets.so.5.15.2
lib/pluginssrv/libaprssrv.so: lib/libhttpserver.so
lib/pluginssrv/libaprssrv.so: lib/liblogging.so
lib/pluginssrv/libaprssrv.so: lib/libqrtplib.so
lib/pluginssrv/libaprssrv.so: lib/libswagger.so
lib/pluginssrv/libaprssrv.so: /usr/lib/x86_64-linux-gnu/libQt5Network.so.5.15.2
lib/pluginssrv/libaprssrv.so: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.15.2
lib/pluginssrv/libaprssrv.so: pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX shared library ../../../lib/pluginssrv/libaprssrv.so"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/aprs && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/aprssrv.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/build: lib/pluginssrv/libaprssrv.so
.PHONY : pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/build

pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/clean:
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/aprs && $(CMAKE_COMMAND) -P CMakeFiles/aprssrv.dir/cmake_clean.cmake
.PHONY : pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/clean

pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/depend:
	cd /opt/build/RPX-100-SDR/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /opt/build/RPX-100-SDR /opt/build/RPX-100-SDR/plugins/feature/aprs /opt/build/RPX-100-SDR/build /opt/build/RPX-100-SDR/build/pluginssrv/feature/aprs /opt/build/RPX-100-SDR/build/pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : pluginssrv/feature/aprs/CMakeFiles/aprssrv.dir/depend
