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
include plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/compiler_depend.make

# Include the progress variables for this target.
include plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/progress.make

# Include the compile flags for this target's objects.
include plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/flags.make

plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/udpsink_autogen/mocs_compilation.cpp.o: plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/flags.make
plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/udpsink_autogen/mocs_compilation.cpp.o: plugins/channelrx/udpsink/udpsink_autogen/mocs_compilation.cpp
plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/udpsink_autogen/mocs_compilation.cpp.o: plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/udpsink_autogen/mocs_compilation.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/udpsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/udpsink_autogen/mocs_compilation.cpp.o -MF CMakeFiles/udpsink.dir/udpsink_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/udpsink.dir/udpsink_autogen/mocs_compilation.cpp.o -c /opt/build/RPX-100-SDR/build/plugins/channelrx/udpsink/udpsink_autogen/mocs_compilation.cpp

plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/udpsink_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/udpsink.dir/udpsink_autogen/mocs_compilation.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/udpsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/build/plugins/channelrx/udpsink/udpsink_autogen/mocs_compilation.cpp > CMakeFiles/udpsink.dir/udpsink_autogen/mocs_compilation.cpp.i

plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/udpsink_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/udpsink.dir/udpsink_autogen/mocs_compilation.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/udpsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/build/plugins/channelrx/udpsink/udpsink_autogen/mocs_compilation.cpp -o CMakeFiles/udpsink.dir/udpsink_autogen/mocs_compilation.cpp.s

plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/udpsink.cpp.o: plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/flags.make
plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/udpsink.cpp.o: ../plugins/channelrx/udpsink/udpsink.cpp
plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/udpsink.cpp.o: plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/udpsink.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/udpsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/udpsink.cpp.o -MF CMakeFiles/udpsink.dir/udpsink.cpp.o.d -o CMakeFiles/udpsink.dir/udpsink.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/udpsink/udpsink.cpp

plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/udpsink.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/udpsink.dir/udpsink.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/udpsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/udpsink/udpsink.cpp > CMakeFiles/udpsink.dir/udpsink.cpp.i

plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/udpsink.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/udpsink.dir/udpsink.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/udpsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/udpsink/udpsink.cpp -o CMakeFiles/udpsink.dir/udpsink.cpp.s

plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/udpsinksink.cpp.o: plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/flags.make
plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/udpsinksink.cpp.o: ../plugins/channelrx/udpsink/udpsinksink.cpp
plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/udpsinksink.cpp.o: plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/udpsinksink.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/udpsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/udpsinksink.cpp.o -MF CMakeFiles/udpsink.dir/udpsinksink.cpp.o.d -o CMakeFiles/udpsink.dir/udpsinksink.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/udpsink/udpsinksink.cpp

plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/udpsinksink.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/udpsink.dir/udpsinksink.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/udpsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/udpsink/udpsinksink.cpp > CMakeFiles/udpsink.dir/udpsinksink.cpp.i

plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/udpsinksink.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/udpsink.dir/udpsinksink.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/udpsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/udpsink/udpsinksink.cpp -o CMakeFiles/udpsink.dir/udpsinksink.cpp.s

plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/udpsinkbaseband.cpp.o: plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/flags.make
plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/udpsinkbaseband.cpp.o: ../plugins/channelrx/udpsink/udpsinkbaseband.cpp
plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/udpsinkbaseband.cpp.o: plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/udpsinkbaseband.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/udpsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/udpsinkbaseband.cpp.o -MF CMakeFiles/udpsink.dir/udpsinkbaseband.cpp.o.d -o CMakeFiles/udpsink.dir/udpsinkbaseband.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/udpsink/udpsinkbaseband.cpp

plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/udpsinkbaseband.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/udpsink.dir/udpsinkbaseband.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/udpsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/udpsink/udpsinkbaseband.cpp > CMakeFiles/udpsink.dir/udpsinkbaseband.cpp.i

plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/udpsinkbaseband.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/udpsink.dir/udpsinkbaseband.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/udpsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/udpsink/udpsinkbaseband.cpp -o CMakeFiles/udpsink.dir/udpsinkbaseband.cpp.s

plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/udpsinkplugin.cpp.o: plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/flags.make
plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/udpsinkplugin.cpp.o: ../plugins/channelrx/udpsink/udpsinkplugin.cpp
plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/udpsinkplugin.cpp.o: plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/udpsinkplugin.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/udpsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/udpsinkplugin.cpp.o -MF CMakeFiles/udpsink.dir/udpsinkplugin.cpp.o.d -o CMakeFiles/udpsink.dir/udpsinkplugin.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/udpsink/udpsinkplugin.cpp

plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/udpsinkplugin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/udpsink.dir/udpsinkplugin.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/udpsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/udpsink/udpsinkplugin.cpp > CMakeFiles/udpsink.dir/udpsinkplugin.cpp.i

plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/udpsinkplugin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/udpsink.dir/udpsinkplugin.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/udpsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/udpsink/udpsinkplugin.cpp -o CMakeFiles/udpsink.dir/udpsinkplugin.cpp.s

plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/udpsinksettings.cpp.o: plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/flags.make
plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/udpsinksettings.cpp.o: ../plugins/channelrx/udpsink/udpsinksettings.cpp
plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/udpsinksettings.cpp.o: plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/udpsinksettings.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/udpsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/udpsinksettings.cpp.o -MF CMakeFiles/udpsink.dir/udpsinksettings.cpp.o.d -o CMakeFiles/udpsink.dir/udpsinksettings.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/udpsink/udpsinksettings.cpp

plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/udpsinksettings.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/udpsink.dir/udpsinksettings.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/udpsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/udpsink/udpsinksettings.cpp > CMakeFiles/udpsink.dir/udpsinksettings.cpp.i

plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/udpsinksettings.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/udpsink.dir/udpsinksettings.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/udpsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/udpsink/udpsinksettings.cpp -o CMakeFiles/udpsink.dir/udpsinksettings.cpp.s

plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/udpsinkwebapiadapter.cpp.o: plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/flags.make
plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/udpsinkwebapiadapter.cpp.o: ../plugins/channelrx/udpsink/udpsinkwebapiadapter.cpp
plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/udpsinkwebapiadapter.cpp.o: plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/udpsinkwebapiadapter.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/udpsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/udpsinkwebapiadapter.cpp.o -MF CMakeFiles/udpsink.dir/udpsinkwebapiadapter.cpp.o.d -o CMakeFiles/udpsink.dir/udpsinkwebapiadapter.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/udpsink/udpsinkwebapiadapter.cpp

plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/udpsinkwebapiadapter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/udpsink.dir/udpsinkwebapiadapter.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/udpsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/udpsink/udpsinkwebapiadapter.cpp > CMakeFiles/udpsink.dir/udpsinkwebapiadapter.cpp.i

plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/udpsinkwebapiadapter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/udpsink.dir/udpsinkwebapiadapter.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/udpsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/udpsink/udpsinkwebapiadapter.cpp -o CMakeFiles/udpsink.dir/udpsinkwebapiadapter.cpp.s

plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/udpsinkgui.cpp.o: plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/flags.make
plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/udpsinkgui.cpp.o: ../plugins/channelrx/udpsink/udpsinkgui.cpp
plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/udpsinkgui.cpp.o: plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/udpsinkgui.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/udpsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/udpsinkgui.cpp.o -MF CMakeFiles/udpsink.dir/udpsinkgui.cpp.o.d -o CMakeFiles/udpsink.dir/udpsinkgui.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/udpsink/udpsinkgui.cpp

plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/udpsinkgui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/udpsink.dir/udpsinkgui.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/udpsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/udpsink/udpsinkgui.cpp > CMakeFiles/udpsink.dir/udpsinkgui.cpp.i

plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/udpsinkgui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/udpsink.dir/udpsinkgui.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/udpsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/udpsink/udpsinkgui.cpp -o CMakeFiles/udpsink.dir/udpsinkgui.cpp.s

# Object files for target udpsink
udpsink_OBJECTS = \
"CMakeFiles/udpsink.dir/udpsink_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/udpsink.dir/udpsink.cpp.o" \
"CMakeFiles/udpsink.dir/udpsinksink.cpp.o" \
"CMakeFiles/udpsink.dir/udpsinkbaseband.cpp.o" \
"CMakeFiles/udpsink.dir/udpsinkplugin.cpp.o" \
"CMakeFiles/udpsink.dir/udpsinksettings.cpp.o" \
"CMakeFiles/udpsink.dir/udpsinkwebapiadapter.cpp.o" \
"CMakeFiles/udpsink.dir/udpsinkgui.cpp.o"

# External object files for target udpsink
udpsink_EXTERNAL_OBJECTS =

lib/plugins/libudpsink.so: plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/udpsink_autogen/mocs_compilation.cpp.o
lib/plugins/libudpsink.so: plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/udpsink.cpp.o
lib/plugins/libudpsink.so: plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/udpsinksink.cpp.o
lib/plugins/libudpsink.so: plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/udpsinkbaseband.cpp.o
lib/plugins/libudpsink.so: plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/udpsinkplugin.cpp.o
lib/plugins/libudpsink.so: plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/udpsinksettings.cpp.o
lib/plugins/libudpsink.so: plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/udpsinkwebapiadapter.cpp.o
lib/plugins/libudpsink.so: plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/udpsinkgui.cpp.o
lib/plugins/libudpsink.so: plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/build.make
lib/plugins/libudpsink.so: lib/libsdrgui.so
lib/plugins/libudpsink.so: lib/libsdrbase.so
lib/plugins/libudpsink.so: /usr/lib/x86_64-linux-gnu/libopus.so
lib/plugins/libudpsink.so: /usr/lib/x86_64-linux-gnu/libm.so
lib/plugins/libudpsink.so: /usr/lib/x86_64-linux-gnu/libfftw3f.so
lib/plugins/libudpsink.so: /opt/install/serialdv/lib/libserialdv.so
lib/plugins/libudpsink.so: /usr/lib/x86_64-linux-gnu/libQt5WebSockets.so.5.15.2
lib/plugins/libudpsink.so: lib/libhttpserver.so
lib/plugins/libudpsink.so: lib/libqrtplib.so
lib/plugins/libudpsink.so: lib/libswagger.so
lib/plugins/libudpsink.so: /usr/lib/x86_64-linux-gnu/libQt5Multimedia.so.5.15.2
lib/plugins/libudpsink.so: lib/liblogging.so
lib/plugins/libudpsink.so: /usr/lib/x86_64-linux-gnu/libQt5Network.so.5.15.2
lib/plugins/libudpsink.so: /usr/lib/x86_64-linux-gnu/libQt5OpenGL.so.5.15.2
lib/plugins/libudpsink.so: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.15.2
lib/plugins/libudpsink.so: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.15.2
lib/plugins/libudpsink.so: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.15.2
lib/plugins/libudpsink.so: /usr/lib/x86_64-linux-gnu/libGL.so
lib/plugins/libudpsink.so: /usr/lib/x86_64-linux-gnu/libGLU.so
lib/plugins/libudpsink.so: /opt/install/LimeSuite/lib/libLimeSuite.so
lib/plugins/libudpsink.so: plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX shared library ../../../lib/plugins/libudpsink.so"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/udpsink && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/udpsink.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/build: lib/plugins/libudpsink.so
.PHONY : plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/build

plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/clean:
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/udpsink && $(CMAKE_COMMAND) -P CMakeFiles/udpsink.dir/cmake_clean.cmake
.PHONY : plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/clean

plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/depend:
	cd /opt/build/RPX-100-SDR/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /opt/build/RPX-100-SDR /opt/build/RPX-100-SDR/plugins/channelrx/udpsink /opt/build/RPX-100-SDR/build /opt/build/RPX-100-SDR/build/plugins/channelrx/udpsink /opt/build/RPX-100-SDR/build/plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : plugins/channelrx/udpsink/CMakeFiles/udpsink.dir/depend
