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
include plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/compiler_depend.make

# Include the progress variables for this target.
include plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/progress.make

# Include the compile flags for this target's objects.
include plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/flags.make

plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/demodfreedv_autogen/mocs_compilation.cpp.o: plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/flags.make
plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/demodfreedv_autogen/mocs_compilation.cpp.o: plugins/channelrx/demodfreedv/demodfreedv_autogen/mocs_compilation.cpp
plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/demodfreedv_autogen/mocs_compilation.cpp.o: plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/demodfreedv_autogen/mocs_compilation.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodfreedv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/demodfreedv_autogen/mocs_compilation.cpp.o -MF CMakeFiles/demodfreedv.dir/demodfreedv_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/demodfreedv.dir/demodfreedv_autogen/mocs_compilation.cpp.o -c /opt/build/RPX-100-SDR/build/plugins/channelrx/demodfreedv/demodfreedv_autogen/mocs_compilation.cpp

plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/demodfreedv_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demodfreedv.dir/demodfreedv_autogen/mocs_compilation.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodfreedv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/build/plugins/channelrx/demodfreedv/demodfreedv_autogen/mocs_compilation.cpp > CMakeFiles/demodfreedv.dir/demodfreedv_autogen/mocs_compilation.cpp.i

plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/demodfreedv_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demodfreedv.dir/demodfreedv_autogen/mocs_compilation.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodfreedv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/build/plugins/channelrx/demodfreedv/demodfreedv_autogen/mocs_compilation.cpp -o CMakeFiles/demodfreedv.dir/demodfreedv_autogen/mocs_compilation.cpp.s

plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/freedvdemod.cpp.o: plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/flags.make
plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/freedvdemod.cpp.o: ../plugins/channelrx/demodfreedv/freedvdemod.cpp
plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/freedvdemod.cpp.o: plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/freedvdemod.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodfreedv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/freedvdemod.cpp.o -MF CMakeFiles/demodfreedv.dir/freedvdemod.cpp.o.d -o CMakeFiles/demodfreedv.dir/freedvdemod.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/demodfreedv/freedvdemod.cpp

plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/freedvdemod.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demodfreedv.dir/freedvdemod.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodfreedv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/demodfreedv/freedvdemod.cpp > CMakeFiles/demodfreedv.dir/freedvdemod.cpp.i

plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/freedvdemod.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demodfreedv.dir/freedvdemod.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodfreedv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/demodfreedv/freedvdemod.cpp -o CMakeFiles/demodfreedv.dir/freedvdemod.cpp.s

plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/freedvdemodbaseband.cpp.o: plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/flags.make
plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/freedvdemodbaseband.cpp.o: ../plugins/channelrx/demodfreedv/freedvdemodbaseband.cpp
plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/freedvdemodbaseband.cpp.o: plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/freedvdemodbaseband.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodfreedv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/freedvdemodbaseband.cpp.o -MF CMakeFiles/demodfreedv.dir/freedvdemodbaseband.cpp.o.d -o CMakeFiles/demodfreedv.dir/freedvdemodbaseband.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/demodfreedv/freedvdemodbaseband.cpp

plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/freedvdemodbaseband.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demodfreedv.dir/freedvdemodbaseband.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodfreedv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/demodfreedv/freedvdemodbaseband.cpp > CMakeFiles/demodfreedv.dir/freedvdemodbaseband.cpp.i

plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/freedvdemodbaseband.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demodfreedv.dir/freedvdemodbaseband.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodfreedv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/demodfreedv/freedvdemodbaseband.cpp -o CMakeFiles/demodfreedv.dir/freedvdemodbaseband.cpp.s

plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/freedvdemodsink.cpp.o: plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/flags.make
plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/freedvdemodsink.cpp.o: ../plugins/channelrx/demodfreedv/freedvdemodsink.cpp
plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/freedvdemodsink.cpp.o: plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/freedvdemodsink.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodfreedv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/freedvdemodsink.cpp.o -MF CMakeFiles/demodfreedv.dir/freedvdemodsink.cpp.o.d -o CMakeFiles/demodfreedv.dir/freedvdemodsink.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/demodfreedv/freedvdemodsink.cpp

plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/freedvdemodsink.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demodfreedv.dir/freedvdemodsink.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodfreedv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/demodfreedv/freedvdemodsink.cpp > CMakeFiles/demodfreedv.dir/freedvdemodsink.cpp.i

plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/freedvdemodsink.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demodfreedv.dir/freedvdemodsink.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodfreedv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/demodfreedv/freedvdemodsink.cpp -o CMakeFiles/demodfreedv.dir/freedvdemodsink.cpp.s

plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/freedvdemodsettings.cpp.o: plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/flags.make
plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/freedvdemodsettings.cpp.o: ../plugins/channelrx/demodfreedv/freedvdemodsettings.cpp
plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/freedvdemodsettings.cpp.o: plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/freedvdemodsettings.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodfreedv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/freedvdemodsettings.cpp.o -MF CMakeFiles/demodfreedv.dir/freedvdemodsettings.cpp.o.d -o CMakeFiles/demodfreedv.dir/freedvdemodsettings.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/demodfreedv/freedvdemodsettings.cpp

plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/freedvdemodsettings.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demodfreedv.dir/freedvdemodsettings.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodfreedv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/demodfreedv/freedvdemodsettings.cpp > CMakeFiles/demodfreedv.dir/freedvdemodsettings.cpp.i

plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/freedvdemodsettings.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demodfreedv.dir/freedvdemodsettings.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodfreedv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/demodfreedv/freedvdemodsettings.cpp -o CMakeFiles/demodfreedv.dir/freedvdemodsettings.cpp.s

plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/freedvdemodwebapiadapter.cpp.o: plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/flags.make
plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/freedvdemodwebapiadapter.cpp.o: ../plugins/channelrx/demodfreedv/freedvdemodwebapiadapter.cpp
plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/freedvdemodwebapiadapter.cpp.o: plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/freedvdemodwebapiadapter.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodfreedv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/freedvdemodwebapiadapter.cpp.o -MF CMakeFiles/demodfreedv.dir/freedvdemodwebapiadapter.cpp.o.d -o CMakeFiles/demodfreedv.dir/freedvdemodwebapiadapter.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/demodfreedv/freedvdemodwebapiadapter.cpp

plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/freedvdemodwebapiadapter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demodfreedv.dir/freedvdemodwebapiadapter.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodfreedv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/demodfreedv/freedvdemodwebapiadapter.cpp > CMakeFiles/demodfreedv.dir/freedvdemodwebapiadapter.cpp.i

plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/freedvdemodwebapiadapter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demodfreedv.dir/freedvdemodwebapiadapter.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodfreedv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/demodfreedv/freedvdemodwebapiadapter.cpp -o CMakeFiles/demodfreedv.dir/freedvdemodwebapiadapter.cpp.s

plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/freedvplugin.cpp.o: plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/flags.make
plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/freedvplugin.cpp.o: ../plugins/channelrx/demodfreedv/freedvplugin.cpp
plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/freedvplugin.cpp.o: plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/freedvplugin.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodfreedv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/freedvplugin.cpp.o -MF CMakeFiles/demodfreedv.dir/freedvplugin.cpp.o.d -o CMakeFiles/demodfreedv.dir/freedvplugin.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/demodfreedv/freedvplugin.cpp

plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/freedvplugin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demodfreedv.dir/freedvplugin.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodfreedv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/demodfreedv/freedvplugin.cpp > CMakeFiles/demodfreedv.dir/freedvplugin.cpp.i

plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/freedvplugin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demodfreedv.dir/freedvplugin.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodfreedv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/demodfreedv/freedvplugin.cpp -o CMakeFiles/demodfreedv.dir/freedvplugin.cpp.s

plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/freedvdemodgui.cpp.o: plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/flags.make
plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/freedvdemodgui.cpp.o: ../plugins/channelrx/demodfreedv/freedvdemodgui.cpp
plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/freedvdemodgui.cpp.o: plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/freedvdemodgui.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodfreedv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/freedvdemodgui.cpp.o -MF CMakeFiles/demodfreedv.dir/freedvdemodgui.cpp.o.d -o CMakeFiles/demodfreedv.dir/freedvdemodgui.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/demodfreedv/freedvdemodgui.cpp

plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/freedvdemodgui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demodfreedv.dir/freedvdemodgui.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodfreedv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/demodfreedv/freedvdemodgui.cpp > CMakeFiles/demodfreedv.dir/freedvdemodgui.cpp.i

plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/freedvdemodgui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demodfreedv.dir/freedvdemodgui.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodfreedv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/demodfreedv/freedvdemodgui.cpp -o CMakeFiles/demodfreedv.dir/freedvdemodgui.cpp.s

# Object files for target demodfreedv
demodfreedv_OBJECTS = \
"CMakeFiles/demodfreedv.dir/demodfreedv_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/demodfreedv.dir/freedvdemod.cpp.o" \
"CMakeFiles/demodfreedv.dir/freedvdemodbaseband.cpp.o" \
"CMakeFiles/demodfreedv.dir/freedvdemodsink.cpp.o" \
"CMakeFiles/demodfreedv.dir/freedvdemodsettings.cpp.o" \
"CMakeFiles/demodfreedv.dir/freedvdemodwebapiadapter.cpp.o" \
"CMakeFiles/demodfreedv.dir/freedvplugin.cpp.o" \
"CMakeFiles/demodfreedv.dir/freedvdemodgui.cpp.o"

# External object files for target demodfreedv
demodfreedv_EXTERNAL_OBJECTS =

lib/plugins/libdemodfreedv.so: plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/demodfreedv_autogen/mocs_compilation.cpp.o
lib/plugins/libdemodfreedv.so: plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/freedvdemod.cpp.o
lib/plugins/libdemodfreedv.so: plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/freedvdemodbaseband.cpp.o
lib/plugins/libdemodfreedv.so: plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/freedvdemodsink.cpp.o
lib/plugins/libdemodfreedv.so: plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/freedvdemodsettings.cpp.o
lib/plugins/libdemodfreedv.so: plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/freedvdemodwebapiadapter.cpp.o
lib/plugins/libdemodfreedv.so: plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/freedvplugin.cpp.o
lib/plugins/libdemodfreedv.so: plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/freedvdemodgui.cpp.o
lib/plugins/libdemodfreedv.so: plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/build.make
lib/plugins/libdemodfreedv.so: lib/libsdrgui.so
lib/plugins/libdemodfreedv.so: /opt/install/codec2/lib/libcodec2.so
lib/plugins/libdemodfreedv.so: lib/libsdrbase.so
lib/plugins/libdemodfreedv.so: lib/libswagger.so
lib/plugins/libdemodfreedv.so: /usr/lib/x86_64-linux-gnu/libopus.so
lib/plugins/libdemodfreedv.so: /usr/lib/x86_64-linux-gnu/libm.so
lib/plugins/libdemodfreedv.so: /usr/lib/x86_64-linux-gnu/libfftw3f.so
lib/plugins/libdemodfreedv.so: /opt/install/serialdv/lib/libserialdv.so
lib/plugins/libdemodfreedv.so: /usr/lib/x86_64-linux-gnu/libQt5WebSockets.so.5.15.2
lib/plugins/libdemodfreedv.so: lib/libhttpserver.so
lib/plugins/libdemodfreedv.so: lib/libqrtplib.so
lib/plugins/libdemodfreedv.so: /usr/lib/x86_64-linux-gnu/libQt5Multimedia.so.5.15.2
lib/plugins/libdemodfreedv.so: lib/liblogging.so
lib/plugins/libdemodfreedv.so: /usr/lib/x86_64-linux-gnu/libQt5Network.so.5.15.2
lib/plugins/libdemodfreedv.so: /usr/lib/x86_64-linux-gnu/libQt5OpenGL.so.5.15.2
lib/plugins/libdemodfreedv.so: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.15.2
lib/plugins/libdemodfreedv.so: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.15.2
lib/plugins/libdemodfreedv.so: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.15.2
lib/plugins/libdemodfreedv.so: /usr/lib/x86_64-linux-gnu/libGL.so
lib/plugins/libdemodfreedv.so: /usr/lib/x86_64-linux-gnu/libGLU.so
lib/plugins/libdemodfreedv.so: /opt/install/LimeSuite/lib/libLimeSuite.so
lib/plugins/libdemodfreedv.so: plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX shared library ../../../lib/plugins/libdemodfreedv.so"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodfreedv && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/demodfreedv.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/build: lib/plugins/libdemodfreedv.so
.PHONY : plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/build

plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/clean:
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodfreedv && $(CMAKE_COMMAND) -P CMakeFiles/demodfreedv.dir/cmake_clean.cmake
.PHONY : plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/clean

plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/depend:
	cd /opt/build/RPX-100-SDR/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /opt/build/RPX-100-SDR /opt/build/RPX-100-SDR/plugins/channelrx/demodfreedv /opt/build/RPX-100-SDR/build /opt/build/RPX-100-SDR/build/plugins/channelrx/demodfreedv /opt/build/RPX-100-SDR/build/plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : plugins/channelrx/demodfreedv/CMakeFiles/demodfreedv.dir/depend

