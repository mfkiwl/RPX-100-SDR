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
include plugins/channelrx/localsink/CMakeFiles/localsink.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include plugins/channelrx/localsink/CMakeFiles/localsink.dir/compiler_depend.make

# Include the progress variables for this target.
include plugins/channelrx/localsink/CMakeFiles/localsink.dir/progress.make

# Include the compile flags for this target's objects.
include plugins/channelrx/localsink/CMakeFiles/localsink.dir/flags.make

plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsink_autogen/mocs_compilation.cpp.o: plugins/channelrx/localsink/CMakeFiles/localsink.dir/flags.make
plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsink_autogen/mocs_compilation.cpp.o: plugins/channelrx/localsink/localsink_autogen/mocs_compilation.cpp
plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsink_autogen/mocs_compilation.cpp.o: plugins/channelrx/localsink/CMakeFiles/localsink.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsink_autogen/mocs_compilation.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/localsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsink_autogen/mocs_compilation.cpp.o -MF CMakeFiles/localsink.dir/localsink_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/localsink.dir/localsink_autogen/mocs_compilation.cpp.o -c /opt/build/RPX-100-SDR/build/plugins/channelrx/localsink/localsink_autogen/mocs_compilation.cpp

plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsink_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/localsink.dir/localsink_autogen/mocs_compilation.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/localsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/build/plugins/channelrx/localsink/localsink_autogen/mocs_compilation.cpp > CMakeFiles/localsink.dir/localsink_autogen/mocs_compilation.cpp.i

plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsink_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/localsink.dir/localsink_autogen/mocs_compilation.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/localsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/build/plugins/channelrx/localsink/localsink_autogen/mocs_compilation.cpp -o CMakeFiles/localsink.dir/localsink_autogen/mocs_compilation.cpp.s

plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsink.cpp.o: plugins/channelrx/localsink/CMakeFiles/localsink.dir/flags.make
plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsink.cpp.o: ../plugins/channelrx/localsink/localsink.cpp
plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsink.cpp.o: plugins/channelrx/localsink/CMakeFiles/localsink.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsink.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/localsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsink.cpp.o -MF CMakeFiles/localsink.dir/localsink.cpp.o.d -o CMakeFiles/localsink.dir/localsink.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/localsink/localsink.cpp

plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsink.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/localsink.dir/localsink.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/localsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/localsink/localsink.cpp > CMakeFiles/localsink.dir/localsink.cpp.i

plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsink.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/localsink.dir/localsink.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/localsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/localsink/localsink.cpp -o CMakeFiles/localsink.dir/localsink.cpp.s

plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsinkbaseband.cpp.o: plugins/channelrx/localsink/CMakeFiles/localsink.dir/flags.make
plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsinkbaseband.cpp.o: ../plugins/channelrx/localsink/localsinkbaseband.cpp
plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsinkbaseband.cpp.o: plugins/channelrx/localsink/CMakeFiles/localsink.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsinkbaseband.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/localsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsinkbaseband.cpp.o -MF CMakeFiles/localsink.dir/localsinkbaseband.cpp.o.d -o CMakeFiles/localsink.dir/localsinkbaseband.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/localsink/localsinkbaseband.cpp

plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsinkbaseband.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/localsink.dir/localsinkbaseband.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/localsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/localsink/localsinkbaseband.cpp > CMakeFiles/localsink.dir/localsinkbaseband.cpp.i

plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsinkbaseband.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/localsink.dir/localsinkbaseband.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/localsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/localsink/localsinkbaseband.cpp -o CMakeFiles/localsink.dir/localsinkbaseband.cpp.s

plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsinksink.cpp.o: plugins/channelrx/localsink/CMakeFiles/localsink.dir/flags.make
plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsinksink.cpp.o: ../plugins/channelrx/localsink/localsinksink.cpp
plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsinksink.cpp.o: plugins/channelrx/localsink/CMakeFiles/localsink.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsinksink.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/localsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsinksink.cpp.o -MF CMakeFiles/localsink.dir/localsinksink.cpp.o.d -o CMakeFiles/localsink.dir/localsinksink.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/localsink/localsinksink.cpp

plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsinksink.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/localsink.dir/localsinksink.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/localsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/localsink/localsinksink.cpp > CMakeFiles/localsink.dir/localsinksink.cpp.i

plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsinksink.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/localsink.dir/localsinksink.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/localsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/localsink/localsinksink.cpp -o CMakeFiles/localsink.dir/localsinksink.cpp.s

plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsinksettings.cpp.o: plugins/channelrx/localsink/CMakeFiles/localsink.dir/flags.make
plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsinksettings.cpp.o: ../plugins/channelrx/localsink/localsinksettings.cpp
plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsinksettings.cpp.o: plugins/channelrx/localsink/CMakeFiles/localsink.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsinksettings.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/localsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsinksettings.cpp.o -MF CMakeFiles/localsink.dir/localsinksettings.cpp.o.d -o CMakeFiles/localsink.dir/localsinksettings.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/localsink/localsinksettings.cpp

plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsinksettings.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/localsink.dir/localsinksettings.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/localsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/localsink/localsinksettings.cpp > CMakeFiles/localsink.dir/localsinksettings.cpp.i

plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsinksettings.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/localsink.dir/localsinksettings.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/localsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/localsink/localsinksettings.cpp -o CMakeFiles/localsink.dir/localsinksettings.cpp.s

plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsinkwebapiadapter.cpp.o: plugins/channelrx/localsink/CMakeFiles/localsink.dir/flags.make
plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsinkwebapiadapter.cpp.o: ../plugins/channelrx/localsink/localsinkwebapiadapter.cpp
plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsinkwebapiadapter.cpp.o: plugins/channelrx/localsink/CMakeFiles/localsink.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsinkwebapiadapter.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/localsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsinkwebapiadapter.cpp.o -MF CMakeFiles/localsink.dir/localsinkwebapiadapter.cpp.o.d -o CMakeFiles/localsink.dir/localsinkwebapiadapter.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/localsink/localsinkwebapiadapter.cpp

plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsinkwebapiadapter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/localsink.dir/localsinkwebapiadapter.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/localsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/localsink/localsinkwebapiadapter.cpp > CMakeFiles/localsink.dir/localsinkwebapiadapter.cpp.i

plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsinkwebapiadapter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/localsink.dir/localsinkwebapiadapter.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/localsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/localsink/localsinkwebapiadapter.cpp -o CMakeFiles/localsink.dir/localsinkwebapiadapter.cpp.s

plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsinkworker.cpp.o: plugins/channelrx/localsink/CMakeFiles/localsink.dir/flags.make
plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsinkworker.cpp.o: ../plugins/channelrx/localsink/localsinkworker.cpp
plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsinkworker.cpp.o: plugins/channelrx/localsink/CMakeFiles/localsink.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsinkworker.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/localsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsinkworker.cpp.o -MF CMakeFiles/localsink.dir/localsinkworker.cpp.o.d -o CMakeFiles/localsink.dir/localsinkworker.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/localsink/localsinkworker.cpp

plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsinkworker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/localsink.dir/localsinkworker.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/localsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/localsink/localsinkworker.cpp > CMakeFiles/localsink.dir/localsinkworker.cpp.i

plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsinkworker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/localsink.dir/localsinkworker.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/localsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/localsink/localsinkworker.cpp -o CMakeFiles/localsink.dir/localsinkworker.cpp.s

plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsinkplugin.cpp.o: plugins/channelrx/localsink/CMakeFiles/localsink.dir/flags.make
plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsinkplugin.cpp.o: ../plugins/channelrx/localsink/localsinkplugin.cpp
plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsinkplugin.cpp.o: plugins/channelrx/localsink/CMakeFiles/localsink.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsinkplugin.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/localsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsinkplugin.cpp.o -MF CMakeFiles/localsink.dir/localsinkplugin.cpp.o.d -o CMakeFiles/localsink.dir/localsinkplugin.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/localsink/localsinkplugin.cpp

plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsinkplugin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/localsink.dir/localsinkplugin.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/localsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/localsink/localsinkplugin.cpp > CMakeFiles/localsink.dir/localsinkplugin.cpp.i

plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsinkplugin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/localsink.dir/localsinkplugin.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/localsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/localsink/localsinkplugin.cpp -o CMakeFiles/localsink.dir/localsinkplugin.cpp.s

plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsinkgui.cpp.o: plugins/channelrx/localsink/CMakeFiles/localsink.dir/flags.make
plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsinkgui.cpp.o: ../plugins/channelrx/localsink/localsinkgui.cpp
plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsinkgui.cpp.o: plugins/channelrx/localsink/CMakeFiles/localsink.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsinkgui.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/localsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsinkgui.cpp.o -MF CMakeFiles/localsink.dir/localsinkgui.cpp.o.d -o CMakeFiles/localsink.dir/localsinkgui.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/localsink/localsinkgui.cpp

plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsinkgui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/localsink.dir/localsinkgui.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/localsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/localsink/localsinkgui.cpp > CMakeFiles/localsink.dir/localsinkgui.cpp.i

plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsinkgui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/localsink.dir/localsinkgui.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/localsink && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/localsink/localsinkgui.cpp -o CMakeFiles/localsink.dir/localsinkgui.cpp.s

# Object files for target localsink
localsink_OBJECTS = \
"CMakeFiles/localsink.dir/localsink_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/localsink.dir/localsink.cpp.o" \
"CMakeFiles/localsink.dir/localsinkbaseband.cpp.o" \
"CMakeFiles/localsink.dir/localsinksink.cpp.o" \
"CMakeFiles/localsink.dir/localsinksettings.cpp.o" \
"CMakeFiles/localsink.dir/localsinkwebapiadapter.cpp.o" \
"CMakeFiles/localsink.dir/localsinkworker.cpp.o" \
"CMakeFiles/localsink.dir/localsinkplugin.cpp.o" \
"CMakeFiles/localsink.dir/localsinkgui.cpp.o"

# External object files for target localsink
localsink_EXTERNAL_OBJECTS =

lib/plugins/liblocalsink.so: plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsink_autogen/mocs_compilation.cpp.o
lib/plugins/liblocalsink.so: plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsink.cpp.o
lib/plugins/liblocalsink.so: plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsinkbaseband.cpp.o
lib/plugins/liblocalsink.so: plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsinksink.cpp.o
lib/plugins/liblocalsink.so: plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsinksettings.cpp.o
lib/plugins/liblocalsink.so: plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsinkwebapiadapter.cpp.o
lib/plugins/liblocalsink.so: plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsinkworker.cpp.o
lib/plugins/liblocalsink.so: plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsinkplugin.cpp.o
lib/plugins/liblocalsink.so: plugins/channelrx/localsink/CMakeFiles/localsink.dir/localsinkgui.cpp.o
lib/plugins/liblocalsink.so: plugins/channelrx/localsink/CMakeFiles/localsink.dir/build.make
lib/plugins/liblocalsink.so: lib/libsdrgui.so
lib/plugins/liblocalsink.so: lib/libsdrbase.so
lib/plugins/liblocalsink.so: lib/libswagger.so
lib/plugins/liblocalsink.so: /usr/lib/x86_64-linux-gnu/libopus.so
lib/plugins/liblocalsink.so: /usr/lib/x86_64-linux-gnu/libm.so
lib/plugins/liblocalsink.so: /usr/lib/x86_64-linux-gnu/libfftw3f.so
lib/plugins/liblocalsink.so: /opt/install/serialdv/lib/libserialdv.so
lib/plugins/liblocalsink.so: /usr/lib/x86_64-linux-gnu/libQt5WebSockets.so.5.15.2
lib/plugins/liblocalsink.so: lib/libhttpserver.so
lib/plugins/liblocalsink.so: lib/libqrtplib.so
lib/plugins/liblocalsink.so: /usr/lib/x86_64-linux-gnu/libQt5Multimedia.so.5.15.2
lib/plugins/liblocalsink.so: lib/liblogging.so
lib/plugins/liblocalsink.so: /usr/lib/x86_64-linux-gnu/libQt5Network.so.5.15.2
lib/plugins/liblocalsink.so: /usr/lib/x86_64-linux-gnu/libQt5OpenGL.so.5.15.2
lib/plugins/liblocalsink.so: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.15.2
lib/plugins/liblocalsink.so: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.15.2
lib/plugins/liblocalsink.so: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.15.2
lib/plugins/liblocalsink.so: /usr/lib/x86_64-linux-gnu/libGL.so
lib/plugins/liblocalsink.so: /usr/lib/x86_64-linux-gnu/libGLU.so
lib/plugins/liblocalsink.so: /opt/install/LimeSuite/lib/libLimeSuite.so
lib/plugins/liblocalsink.so: plugins/channelrx/localsink/CMakeFiles/localsink.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX shared library ../../../lib/plugins/liblocalsink.so"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/localsink && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/localsink.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
plugins/channelrx/localsink/CMakeFiles/localsink.dir/build: lib/plugins/liblocalsink.so
.PHONY : plugins/channelrx/localsink/CMakeFiles/localsink.dir/build

plugins/channelrx/localsink/CMakeFiles/localsink.dir/clean:
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/localsink && $(CMAKE_COMMAND) -P CMakeFiles/localsink.dir/cmake_clean.cmake
.PHONY : plugins/channelrx/localsink/CMakeFiles/localsink.dir/clean

plugins/channelrx/localsink/CMakeFiles/localsink.dir/depend:
	cd /opt/build/RPX-100-SDR/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /opt/build/RPX-100-SDR /opt/build/RPX-100-SDR/plugins/channelrx/localsink /opt/build/RPX-100-SDR/build /opt/build/RPX-100-SDR/build/plugins/channelrx/localsink /opt/build/RPX-100-SDR/build/plugins/channelrx/localsink/CMakeFiles/localsink.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : plugins/channelrx/localsink/CMakeFiles/localsink.dir/depend

