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
include plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/compiler_depend.make

# Include the progress variables for this target.
include plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/progress.make

# Include the compile flags for this target's objects.
include plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/flags.make

plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/featuresimpleptt_autogen/mocs_compilation.cpp.o: plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/flags.make
plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/featuresimpleptt_autogen/mocs_compilation.cpp.o: plugins/feature/simpleptt/featuresimpleptt_autogen/mocs_compilation.cpp
plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/featuresimpleptt_autogen/mocs_compilation.cpp.o: plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/featuresimpleptt_autogen/mocs_compilation.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/feature/simpleptt && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/featuresimpleptt_autogen/mocs_compilation.cpp.o -MF CMakeFiles/featuresimpleptt.dir/featuresimpleptt_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/featuresimpleptt.dir/featuresimpleptt_autogen/mocs_compilation.cpp.o -c /opt/build/RPX-100-SDR/build/plugins/feature/simpleptt/featuresimpleptt_autogen/mocs_compilation.cpp

plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/featuresimpleptt_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/featuresimpleptt.dir/featuresimpleptt_autogen/mocs_compilation.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/feature/simpleptt && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/build/plugins/feature/simpleptt/featuresimpleptt_autogen/mocs_compilation.cpp > CMakeFiles/featuresimpleptt.dir/featuresimpleptt_autogen/mocs_compilation.cpp.i

plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/featuresimpleptt_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/featuresimpleptt.dir/featuresimpleptt_autogen/mocs_compilation.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/feature/simpleptt && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/build/plugins/feature/simpleptt/featuresimpleptt_autogen/mocs_compilation.cpp -o CMakeFiles/featuresimpleptt.dir/featuresimpleptt_autogen/mocs_compilation.cpp.s

plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/simpleptt.cpp.o: plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/flags.make
plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/simpleptt.cpp.o: ../plugins/feature/simpleptt/simpleptt.cpp
plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/simpleptt.cpp.o: plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/simpleptt.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/feature/simpleptt && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/simpleptt.cpp.o -MF CMakeFiles/featuresimpleptt.dir/simpleptt.cpp.o.d -o CMakeFiles/featuresimpleptt.dir/simpleptt.cpp.o -c /opt/build/RPX-100-SDR/plugins/feature/simpleptt/simpleptt.cpp

plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/simpleptt.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/featuresimpleptt.dir/simpleptt.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/feature/simpleptt && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/feature/simpleptt/simpleptt.cpp > CMakeFiles/featuresimpleptt.dir/simpleptt.cpp.i

plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/simpleptt.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/featuresimpleptt.dir/simpleptt.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/feature/simpleptt && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/feature/simpleptt/simpleptt.cpp -o CMakeFiles/featuresimpleptt.dir/simpleptt.cpp.s

plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/simplepttsettings.cpp.o: plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/flags.make
plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/simplepttsettings.cpp.o: ../plugins/feature/simpleptt/simplepttsettings.cpp
plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/simplepttsettings.cpp.o: plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/simplepttsettings.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/feature/simpleptt && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/simplepttsettings.cpp.o -MF CMakeFiles/featuresimpleptt.dir/simplepttsettings.cpp.o.d -o CMakeFiles/featuresimpleptt.dir/simplepttsettings.cpp.o -c /opt/build/RPX-100-SDR/plugins/feature/simpleptt/simplepttsettings.cpp

plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/simplepttsettings.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/featuresimpleptt.dir/simplepttsettings.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/feature/simpleptt && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/feature/simpleptt/simplepttsettings.cpp > CMakeFiles/featuresimpleptt.dir/simplepttsettings.cpp.i

plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/simplepttsettings.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/featuresimpleptt.dir/simplepttsettings.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/feature/simpleptt && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/feature/simpleptt/simplepttsettings.cpp -o CMakeFiles/featuresimpleptt.dir/simplepttsettings.cpp.s

plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/simplepttplugin.cpp.o: plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/flags.make
plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/simplepttplugin.cpp.o: ../plugins/feature/simpleptt/simplepttplugin.cpp
plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/simplepttplugin.cpp.o: plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/simplepttplugin.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/feature/simpleptt && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/simplepttplugin.cpp.o -MF CMakeFiles/featuresimpleptt.dir/simplepttplugin.cpp.o.d -o CMakeFiles/featuresimpleptt.dir/simplepttplugin.cpp.o -c /opt/build/RPX-100-SDR/plugins/feature/simpleptt/simplepttplugin.cpp

plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/simplepttplugin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/featuresimpleptt.dir/simplepttplugin.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/feature/simpleptt && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/feature/simpleptt/simplepttplugin.cpp > CMakeFiles/featuresimpleptt.dir/simplepttplugin.cpp.i

plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/simplepttplugin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/featuresimpleptt.dir/simplepttplugin.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/feature/simpleptt && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/feature/simpleptt/simplepttplugin.cpp -o CMakeFiles/featuresimpleptt.dir/simplepttplugin.cpp.s

plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/simplepttworker.cpp.o: plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/flags.make
plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/simplepttworker.cpp.o: ../plugins/feature/simpleptt/simplepttworker.cpp
plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/simplepttworker.cpp.o: plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/simplepttworker.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/feature/simpleptt && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/simplepttworker.cpp.o -MF CMakeFiles/featuresimpleptt.dir/simplepttworker.cpp.o.d -o CMakeFiles/featuresimpleptt.dir/simplepttworker.cpp.o -c /opt/build/RPX-100-SDR/plugins/feature/simpleptt/simplepttworker.cpp

plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/simplepttworker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/featuresimpleptt.dir/simplepttworker.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/feature/simpleptt && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/feature/simpleptt/simplepttworker.cpp > CMakeFiles/featuresimpleptt.dir/simplepttworker.cpp.i

plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/simplepttworker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/featuresimpleptt.dir/simplepttworker.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/feature/simpleptt && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/feature/simpleptt/simplepttworker.cpp -o CMakeFiles/featuresimpleptt.dir/simplepttworker.cpp.s

plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/simplepttreport.cpp.o: plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/flags.make
plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/simplepttreport.cpp.o: ../plugins/feature/simpleptt/simplepttreport.cpp
plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/simplepttreport.cpp.o: plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/simplepttreport.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/feature/simpleptt && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/simplepttreport.cpp.o -MF CMakeFiles/featuresimpleptt.dir/simplepttreport.cpp.o.d -o CMakeFiles/featuresimpleptt.dir/simplepttreport.cpp.o -c /opt/build/RPX-100-SDR/plugins/feature/simpleptt/simplepttreport.cpp

plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/simplepttreport.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/featuresimpleptt.dir/simplepttreport.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/feature/simpleptt && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/feature/simpleptt/simplepttreport.cpp > CMakeFiles/featuresimpleptt.dir/simplepttreport.cpp.i

plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/simplepttreport.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/featuresimpleptt.dir/simplepttreport.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/feature/simpleptt && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/feature/simpleptt/simplepttreport.cpp -o CMakeFiles/featuresimpleptt.dir/simplepttreport.cpp.s

plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/simplepttwebapiadapter.cpp.o: plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/flags.make
plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/simplepttwebapiadapter.cpp.o: ../plugins/feature/simpleptt/simplepttwebapiadapter.cpp
plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/simplepttwebapiadapter.cpp.o: plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/simplepttwebapiadapter.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/feature/simpleptt && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/simplepttwebapiadapter.cpp.o -MF CMakeFiles/featuresimpleptt.dir/simplepttwebapiadapter.cpp.o.d -o CMakeFiles/featuresimpleptt.dir/simplepttwebapiadapter.cpp.o -c /opt/build/RPX-100-SDR/plugins/feature/simpleptt/simplepttwebapiadapter.cpp

plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/simplepttwebapiadapter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/featuresimpleptt.dir/simplepttwebapiadapter.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/feature/simpleptt && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/feature/simpleptt/simplepttwebapiadapter.cpp > CMakeFiles/featuresimpleptt.dir/simplepttwebapiadapter.cpp.i

plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/simplepttwebapiadapter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/featuresimpleptt.dir/simplepttwebapiadapter.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/feature/simpleptt && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/feature/simpleptt/simplepttwebapiadapter.cpp -o CMakeFiles/featuresimpleptt.dir/simplepttwebapiadapter.cpp.s

plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/simplepttgui.cpp.o: plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/flags.make
plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/simplepttgui.cpp.o: ../plugins/feature/simpleptt/simplepttgui.cpp
plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/simplepttgui.cpp.o: plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/simplepttgui.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/feature/simpleptt && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/simplepttgui.cpp.o -MF CMakeFiles/featuresimpleptt.dir/simplepttgui.cpp.o.d -o CMakeFiles/featuresimpleptt.dir/simplepttgui.cpp.o -c /opt/build/RPX-100-SDR/plugins/feature/simpleptt/simplepttgui.cpp

plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/simplepttgui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/featuresimpleptt.dir/simplepttgui.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/feature/simpleptt && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/feature/simpleptt/simplepttgui.cpp > CMakeFiles/featuresimpleptt.dir/simplepttgui.cpp.i

plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/simplepttgui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/featuresimpleptt.dir/simplepttgui.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/feature/simpleptt && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/feature/simpleptt/simplepttgui.cpp -o CMakeFiles/featuresimpleptt.dir/simplepttgui.cpp.s

# Object files for target featuresimpleptt
featuresimpleptt_OBJECTS = \
"CMakeFiles/featuresimpleptt.dir/featuresimpleptt_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/featuresimpleptt.dir/simpleptt.cpp.o" \
"CMakeFiles/featuresimpleptt.dir/simplepttsettings.cpp.o" \
"CMakeFiles/featuresimpleptt.dir/simplepttplugin.cpp.o" \
"CMakeFiles/featuresimpleptt.dir/simplepttworker.cpp.o" \
"CMakeFiles/featuresimpleptt.dir/simplepttreport.cpp.o" \
"CMakeFiles/featuresimpleptt.dir/simplepttwebapiadapter.cpp.o" \
"CMakeFiles/featuresimpleptt.dir/simplepttgui.cpp.o"

# External object files for target featuresimpleptt
featuresimpleptt_EXTERNAL_OBJECTS =

lib/plugins/libfeaturesimpleptt.so: plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/featuresimpleptt_autogen/mocs_compilation.cpp.o
lib/plugins/libfeaturesimpleptt.so: plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/simpleptt.cpp.o
lib/plugins/libfeaturesimpleptt.so: plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/simplepttsettings.cpp.o
lib/plugins/libfeaturesimpleptt.so: plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/simplepttplugin.cpp.o
lib/plugins/libfeaturesimpleptt.so: plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/simplepttworker.cpp.o
lib/plugins/libfeaturesimpleptt.so: plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/simplepttreport.cpp.o
lib/plugins/libfeaturesimpleptt.so: plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/simplepttwebapiadapter.cpp.o
lib/plugins/libfeaturesimpleptt.so: plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/simplepttgui.cpp.o
lib/plugins/libfeaturesimpleptt.so: plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/build.make
lib/plugins/libfeaturesimpleptt.so: lib/libsdrgui.so
lib/plugins/libfeaturesimpleptt.so: lib/libsdrbase.so
lib/plugins/libfeaturesimpleptt.so: /usr/lib/x86_64-linux-gnu/libopus.so
lib/plugins/libfeaturesimpleptt.so: /usr/lib/x86_64-linux-gnu/libm.so
lib/plugins/libfeaturesimpleptt.so: /usr/lib/x86_64-linux-gnu/libfftw3f.so
lib/plugins/libfeaturesimpleptt.so: /opt/install/serialdv/lib/libserialdv.so
lib/plugins/libfeaturesimpleptt.so: /usr/lib/x86_64-linux-gnu/libQt5WebSockets.so.5.15.2
lib/plugins/libfeaturesimpleptt.so: lib/libhttpserver.so
lib/plugins/libfeaturesimpleptt.so: lib/libqrtplib.so
lib/plugins/libfeaturesimpleptt.so: lib/libswagger.so
lib/plugins/libfeaturesimpleptt.so: /usr/lib/x86_64-linux-gnu/libQt5Multimedia.so.5.15.2
lib/plugins/libfeaturesimpleptt.so: lib/liblogging.so
lib/plugins/libfeaturesimpleptt.so: /usr/lib/x86_64-linux-gnu/libQt5Network.so.5.15.2
lib/plugins/libfeaturesimpleptt.so: /usr/lib/x86_64-linux-gnu/libQt5OpenGL.so.5.15.2
lib/plugins/libfeaturesimpleptt.so: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.15.2
lib/plugins/libfeaturesimpleptt.so: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.15.2
lib/plugins/libfeaturesimpleptt.so: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.15.2
lib/plugins/libfeaturesimpleptt.so: /usr/lib/x86_64-linux-gnu/libGL.so
lib/plugins/libfeaturesimpleptt.so: /usr/lib/x86_64-linux-gnu/libGLU.so
lib/plugins/libfeaturesimpleptt.so: /opt/install/LimeSuite/lib/libLimeSuite.so
lib/plugins/libfeaturesimpleptt.so: plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX shared library ../../../lib/plugins/libfeaturesimpleptt.so"
	cd /opt/build/RPX-100-SDR/build/plugins/feature/simpleptt && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/featuresimpleptt.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/build: lib/plugins/libfeaturesimpleptt.so
.PHONY : plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/build

plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/clean:
	cd /opt/build/RPX-100-SDR/build/plugins/feature/simpleptt && $(CMAKE_COMMAND) -P CMakeFiles/featuresimpleptt.dir/cmake_clean.cmake
.PHONY : plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/clean

plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/depend:
	cd /opt/build/RPX-100-SDR/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /opt/build/RPX-100-SDR /opt/build/RPX-100-SDR/plugins/feature/simpleptt /opt/build/RPX-100-SDR/build /opt/build/RPX-100-SDR/build/plugins/feature/simpleptt /opt/build/RPX-100-SDR/build/plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : plugins/feature/simpleptt/CMakeFiles/featuresimpleptt.dir/depend

