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
include pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/compiler_depend.make

# Include the progress variables for this target.
include pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/progress.make

# Include the compile flags for this target's objects.
include pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/flags.make

pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/vorlocalizersrv_autogen/mocs_compilation.cpp.o: pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/flags.make
pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/vorlocalizersrv_autogen/mocs_compilation.cpp.o: pluginssrv/feature/vorlocalizer/vorlocalizersrv_autogen/mocs_compilation.cpp
pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/vorlocalizersrv_autogen/mocs_compilation.cpp.o: pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/vorlocalizersrv_autogen/mocs_compilation.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/vorlocalizer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/vorlocalizersrv_autogen/mocs_compilation.cpp.o -MF CMakeFiles/vorlocalizersrv.dir/vorlocalizersrv_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/vorlocalizersrv.dir/vorlocalizersrv_autogen/mocs_compilation.cpp.o -c /opt/build/RPX-100-SDR/build/pluginssrv/feature/vorlocalizer/vorlocalizersrv_autogen/mocs_compilation.cpp

pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/vorlocalizersrv_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vorlocalizersrv.dir/vorlocalizersrv_autogen/mocs_compilation.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/vorlocalizer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/build/pluginssrv/feature/vorlocalizer/vorlocalizersrv_autogen/mocs_compilation.cpp > CMakeFiles/vorlocalizersrv.dir/vorlocalizersrv_autogen/mocs_compilation.cpp.i

pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/vorlocalizersrv_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vorlocalizersrv.dir/vorlocalizersrv_autogen/mocs_compilation.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/vorlocalizer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/build/pluginssrv/feature/vorlocalizer/vorlocalizersrv_autogen/mocs_compilation.cpp -o CMakeFiles/vorlocalizersrv.dir/vorlocalizersrv_autogen/mocs_compilation.cpp.s

pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/vorlocalizer.cpp.o: pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/flags.make
pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/vorlocalizer.cpp.o: ../plugins/feature/vorlocalizer/vorlocalizer.cpp
pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/vorlocalizer.cpp.o: pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/vorlocalizer.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/vorlocalizer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/vorlocalizer.cpp.o -MF CMakeFiles/vorlocalizersrv.dir/vorlocalizer.cpp.o.d -o CMakeFiles/vorlocalizersrv.dir/vorlocalizer.cpp.o -c /opt/build/RPX-100-SDR/plugins/feature/vorlocalizer/vorlocalizer.cpp

pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/vorlocalizer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vorlocalizersrv.dir/vorlocalizer.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/vorlocalizer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/feature/vorlocalizer/vorlocalizer.cpp > CMakeFiles/vorlocalizersrv.dir/vorlocalizer.cpp.i

pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/vorlocalizer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vorlocalizersrv.dir/vorlocalizer.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/vorlocalizer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/feature/vorlocalizer/vorlocalizer.cpp -o CMakeFiles/vorlocalizersrv.dir/vorlocalizer.cpp.s

pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/vorlocalizersettings.cpp.o: pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/flags.make
pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/vorlocalizersettings.cpp.o: ../plugins/feature/vorlocalizer/vorlocalizersettings.cpp
pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/vorlocalizersettings.cpp.o: pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/vorlocalizersettings.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/vorlocalizer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/vorlocalizersettings.cpp.o -MF CMakeFiles/vorlocalizersrv.dir/vorlocalizersettings.cpp.o.d -o CMakeFiles/vorlocalizersrv.dir/vorlocalizersettings.cpp.o -c /opt/build/RPX-100-SDR/plugins/feature/vorlocalizer/vorlocalizersettings.cpp

pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/vorlocalizersettings.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vorlocalizersrv.dir/vorlocalizersettings.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/vorlocalizer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/feature/vorlocalizer/vorlocalizersettings.cpp > CMakeFiles/vorlocalizersrv.dir/vorlocalizersettings.cpp.i

pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/vorlocalizersettings.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vorlocalizersrv.dir/vorlocalizersettings.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/vorlocalizer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/feature/vorlocalizer/vorlocalizersettings.cpp -o CMakeFiles/vorlocalizersrv.dir/vorlocalizersettings.cpp.s

pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/vorlocalizerworker.cpp.o: pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/flags.make
pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/vorlocalizerworker.cpp.o: ../plugins/feature/vorlocalizer/vorlocalizerworker.cpp
pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/vorlocalizerworker.cpp.o: pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/vorlocalizerworker.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/vorlocalizer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/vorlocalizerworker.cpp.o -MF CMakeFiles/vorlocalizersrv.dir/vorlocalizerworker.cpp.o.d -o CMakeFiles/vorlocalizersrv.dir/vorlocalizerworker.cpp.o -c /opt/build/RPX-100-SDR/plugins/feature/vorlocalizer/vorlocalizerworker.cpp

pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/vorlocalizerworker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vorlocalizersrv.dir/vorlocalizerworker.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/vorlocalizer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/feature/vorlocalizer/vorlocalizerworker.cpp > CMakeFiles/vorlocalizersrv.dir/vorlocalizerworker.cpp.i

pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/vorlocalizerworker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vorlocalizersrv.dir/vorlocalizerworker.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/vorlocalizer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/feature/vorlocalizer/vorlocalizerworker.cpp -o CMakeFiles/vorlocalizersrv.dir/vorlocalizerworker.cpp.s

pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/vorlocalizerplugin.cpp.o: pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/flags.make
pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/vorlocalizerplugin.cpp.o: ../plugins/feature/vorlocalizer/vorlocalizerplugin.cpp
pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/vorlocalizerplugin.cpp.o: pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/vorlocalizerplugin.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/vorlocalizer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/vorlocalizerplugin.cpp.o -MF CMakeFiles/vorlocalizersrv.dir/vorlocalizerplugin.cpp.o.d -o CMakeFiles/vorlocalizersrv.dir/vorlocalizerplugin.cpp.o -c /opt/build/RPX-100-SDR/plugins/feature/vorlocalizer/vorlocalizerplugin.cpp

pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/vorlocalizerplugin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vorlocalizersrv.dir/vorlocalizerplugin.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/vorlocalizer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/feature/vorlocalizer/vorlocalizerplugin.cpp > CMakeFiles/vorlocalizersrv.dir/vorlocalizerplugin.cpp.i

pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/vorlocalizerplugin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vorlocalizersrv.dir/vorlocalizerplugin.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/vorlocalizer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/feature/vorlocalizer/vorlocalizerplugin.cpp -o CMakeFiles/vorlocalizersrv.dir/vorlocalizerplugin.cpp.s

pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/vorlocalizerwebapiadapter.cpp.o: pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/flags.make
pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/vorlocalizerwebapiadapter.cpp.o: ../plugins/feature/vorlocalizer/vorlocalizerwebapiadapter.cpp
pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/vorlocalizerwebapiadapter.cpp.o: pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/vorlocalizerwebapiadapter.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/vorlocalizer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/vorlocalizerwebapiadapter.cpp.o -MF CMakeFiles/vorlocalizersrv.dir/vorlocalizerwebapiadapter.cpp.o.d -o CMakeFiles/vorlocalizersrv.dir/vorlocalizerwebapiadapter.cpp.o -c /opt/build/RPX-100-SDR/plugins/feature/vorlocalizer/vorlocalizerwebapiadapter.cpp

pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/vorlocalizerwebapiadapter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vorlocalizersrv.dir/vorlocalizerwebapiadapter.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/vorlocalizer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/feature/vorlocalizer/vorlocalizerwebapiadapter.cpp > CMakeFiles/vorlocalizersrv.dir/vorlocalizerwebapiadapter.cpp.i

pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/vorlocalizerwebapiadapter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vorlocalizersrv.dir/vorlocalizerwebapiadapter.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/vorlocalizer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/feature/vorlocalizer/vorlocalizerwebapiadapter.cpp -o CMakeFiles/vorlocalizersrv.dir/vorlocalizerwebapiadapter.cpp.s

pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/vorlocalizerreport.cpp.o: pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/flags.make
pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/vorlocalizerreport.cpp.o: ../plugins/feature/vorlocalizer/vorlocalizerreport.cpp
pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/vorlocalizerreport.cpp.o: pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/vorlocalizerreport.cpp.o"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/vorlocalizer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/vorlocalizerreport.cpp.o -MF CMakeFiles/vorlocalizersrv.dir/vorlocalizerreport.cpp.o.d -o CMakeFiles/vorlocalizersrv.dir/vorlocalizerreport.cpp.o -c /opt/build/RPX-100-SDR/plugins/feature/vorlocalizer/vorlocalizerreport.cpp

pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/vorlocalizerreport.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vorlocalizersrv.dir/vorlocalizerreport.cpp.i"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/vorlocalizer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/feature/vorlocalizer/vorlocalizerreport.cpp > CMakeFiles/vorlocalizersrv.dir/vorlocalizerreport.cpp.i

pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/vorlocalizerreport.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vorlocalizersrv.dir/vorlocalizerreport.cpp.s"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/vorlocalizer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/feature/vorlocalizer/vorlocalizerreport.cpp -o CMakeFiles/vorlocalizersrv.dir/vorlocalizerreport.cpp.s

# Object files for target vorlocalizersrv
vorlocalizersrv_OBJECTS = \
"CMakeFiles/vorlocalizersrv.dir/vorlocalizersrv_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/vorlocalizersrv.dir/vorlocalizer.cpp.o" \
"CMakeFiles/vorlocalizersrv.dir/vorlocalizersettings.cpp.o" \
"CMakeFiles/vorlocalizersrv.dir/vorlocalizerworker.cpp.o" \
"CMakeFiles/vorlocalizersrv.dir/vorlocalizerplugin.cpp.o" \
"CMakeFiles/vorlocalizersrv.dir/vorlocalizerwebapiadapter.cpp.o" \
"CMakeFiles/vorlocalizersrv.dir/vorlocalizerreport.cpp.o"

# External object files for target vorlocalizersrv
vorlocalizersrv_EXTERNAL_OBJECTS =

lib/pluginssrv/libvorlocalizersrv.so: pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/vorlocalizersrv_autogen/mocs_compilation.cpp.o
lib/pluginssrv/libvorlocalizersrv.so: pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/vorlocalizer.cpp.o
lib/pluginssrv/libvorlocalizersrv.so: pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/vorlocalizersettings.cpp.o
lib/pluginssrv/libvorlocalizersrv.so: pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/vorlocalizerworker.cpp.o
lib/pluginssrv/libvorlocalizersrv.so: pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/vorlocalizerplugin.cpp.o
lib/pluginssrv/libvorlocalizersrv.so: pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/vorlocalizerwebapiadapter.cpp.o
lib/pluginssrv/libvorlocalizersrv.so: pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/vorlocalizerreport.cpp.o
lib/pluginssrv/libvorlocalizersrv.so: pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/build.make
lib/pluginssrv/libvorlocalizersrv.so: lib/libsdrbase.so
lib/pluginssrv/libvorlocalizersrv.so: /usr/lib/x86_64-linux-gnu/libopus.so
lib/pluginssrv/libvorlocalizersrv.so: /usr/lib/x86_64-linux-gnu/libm.so
lib/pluginssrv/libvorlocalizersrv.so: /usr/lib/x86_64-linux-gnu/libfftw3f.so
lib/pluginssrv/libvorlocalizersrv.so: /opt/install/serialdv/lib/libserialdv.so
lib/pluginssrv/libvorlocalizersrv.so: /opt/install/LimeSuite/lib/libLimeSuite.so
lib/pluginssrv/libvorlocalizersrv.so: /usr/lib/x86_64-linux-gnu/libQt5Multimedia.so.5.15.2
lib/pluginssrv/libvorlocalizersrv.so: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.15.2
lib/pluginssrv/libvorlocalizersrv.so: /usr/lib/x86_64-linux-gnu/libQt5WebSockets.so.5.15.2
lib/pluginssrv/libvorlocalizersrv.so: lib/libhttpserver.so
lib/pluginssrv/libvorlocalizersrv.so: lib/liblogging.so
lib/pluginssrv/libvorlocalizersrv.so: lib/libqrtplib.so
lib/pluginssrv/libvorlocalizersrv.so: lib/libswagger.so
lib/pluginssrv/libvorlocalizersrv.so: /usr/lib/x86_64-linux-gnu/libQt5Network.so.5.15.2
lib/pluginssrv/libvorlocalizersrv.so: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.15.2
lib/pluginssrv/libvorlocalizersrv.so: pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX shared library ../../../lib/pluginssrv/libvorlocalizersrv.so"
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/vorlocalizer && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/vorlocalizersrv.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/build: lib/pluginssrv/libvorlocalizersrv.so
.PHONY : pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/build

pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/clean:
	cd /opt/build/RPX-100-SDR/build/pluginssrv/feature/vorlocalizer && $(CMAKE_COMMAND) -P CMakeFiles/vorlocalizersrv.dir/cmake_clean.cmake
.PHONY : pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/clean

pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/depend:
	cd /opt/build/RPX-100-SDR/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /opt/build/RPX-100-SDR /opt/build/RPX-100-SDR/plugins/feature/vorlocalizer /opt/build/RPX-100-SDR/build /opt/build/RPX-100-SDR/build/pluginssrv/feature/vorlocalizer /opt/build/RPX-100-SDR/build/pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : pluginssrv/feature/vorlocalizer/CMakeFiles/vorlocalizersrv.dir/depend

