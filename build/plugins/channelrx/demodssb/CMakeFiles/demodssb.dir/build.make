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
include plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/compiler_depend.make

# Include the progress variables for this target.
include plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/progress.make

# Include the compile flags for this target's objects.
include plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/flags.make

plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/demodssb_autogen/mocs_compilation.cpp.o: plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/flags.make
plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/demodssb_autogen/mocs_compilation.cpp.o: plugins/channelrx/demodssb/demodssb_autogen/mocs_compilation.cpp
plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/demodssb_autogen/mocs_compilation.cpp.o: plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/demodssb_autogen/mocs_compilation.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodssb && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/demodssb_autogen/mocs_compilation.cpp.o -MF CMakeFiles/demodssb.dir/demodssb_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/demodssb.dir/demodssb_autogen/mocs_compilation.cpp.o -c /opt/build/RPX-100-SDR/build/plugins/channelrx/demodssb/demodssb_autogen/mocs_compilation.cpp

plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/demodssb_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demodssb.dir/demodssb_autogen/mocs_compilation.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodssb && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/build/plugins/channelrx/demodssb/demodssb_autogen/mocs_compilation.cpp > CMakeFiles/demodssb.dir/demodssb_autogen/mocs_compilation.cpp.i

plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/demodssb_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demodssb.dir/demodssb_autogen/mocs_compilation.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodssb && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/build/plugins/channelrx/demodssb/demodssb_autogen/mocs_compilation.cpp -o CMakeFiles/demodssb.dir/demodssb_autogen/mocs_compilation.cpp.s

plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/ssbdemod.cpp.o: plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/flags.make
plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/ssbdemod.cpp.o: ../plugins/channelrx/demodssb/ssbdemod.cpp
plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/ssbdemod.cpp.o: plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/ssbdemod.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodssb && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/ssbdemod.cpp.o -MF CMakeFiles/demodssb.dir/ssbdemod.cpp.o.d -o CMakeFiles/demodssb.dir/ssbdemod.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/demodssb/ssbdemod.cpp

plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/ssbdemod.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demodssb.dir/ssbdemod.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodssb && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/demodssb/ssbdemod.cpp > CMakeFiles/demodssb.dir/ssbdemod.cpp.i

plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/ssbdemod.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demodssb.dir/ssbdemod.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodssb && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/demodssb/ssbdemod.cpp -o CMakeFiles/demodssb.dir/ssbdemod.cpp.s

plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/ssbdemodsettings.cpp.o: plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/flags.make
plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/ssbdemodsettings.cpp.o: ../plugins/channelrx/demodssb/ssbdemodsettings.cpp
plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/ssbdemodsettings.cpp.o: plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/ssbdemodsettings.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodssb && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/ssbdemodsettings.cpp.o -MF CMakeFiles/demodssb.dir/ssbdemodsettings.cpp.o.d -o CMakeFiles/demodssb.dir/ssbdemodsettings.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/demodssb/ssbdemodsettings.cpp

plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/ssbdemodsettings.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demodssb.dir/ssbdemodsettings.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodssb && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/demodssb/ssbdemodsettings.cpp > CMakeFiles/demodssb.dir/ssbdemodsettings.cpp.i

plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/ssbdemodsettings.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demodssb.dir/ssbdemodsettings.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodssb && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/demodssb/ssbdemodsettings.cpp -o CMakeFiles/demodssb.dir/ssbdemodsettings.cpp.s

plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/ssbdemodsink.cpp.o: plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/flags.make
plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/ssbdemodsink.cpp.o: ../plugins/channelrx/demodssb/ssbdemodsink.cpp
plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/ssbdemodsink.cpp.o: plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/ssbdemodsink.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodssb && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/ssbdemodsink.cpp.o -MF CMakeFiles/demodssb.dir/ssbdemodsink.cpp.o.d -o CMakeFiles/demodssb.dir/ssbdemodsink.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/demodssb/ssbdemodsink.cpp

plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/ssbdemodsink.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demodssb.dir/ssbdemodsink.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodssb && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/demodssb/ssbdemodsink.cpp > CMakeFiles/demodssb.dir/ssbdemodsink.cpp.i

plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/ssbdemodsink.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demodssb.dir/ssbdemodsink.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodssb && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/demodssb/ssbdemodsink.cpp -o CMakeFiles/demodssb.dir/ssbdemodsink.cpp.s

plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/ssbdemodbaseband.cpp.o: plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/flags.make
plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/ssbdemodbaseband.cpp.o: ../plugins/channelrx/demodssb/ssbdemodbaseband.cpp
plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/ssbdemodbaseband.cpp.o: plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/ssbdemodbaseband.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodssb && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/ssbdemodbaseband.cpp.o -MF CMakeFiles/demodssb.dir/ssbdemodbaseband.cpp.o.d -o CMakeFiles/demodssb.dir/ssbdemodbaseband.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/demodssb/ssbdemodbaseband.cpp

plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/ssbdemodbaseband.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demodssb.dir/ssbdemodbaseband.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodssb && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/demodssb/ssbdemodbaseband.cpp > CMakeFiles/demodssb.dir/ssbdemodbaseband.cpp.i

plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/ssbdemodbaseband.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demodssb.dir/ssbdemodbaseband.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodssb && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/demodssb/ssbdemodbaseband.cpp -o CMakeFiles/demodssb.dir/ssbdemodbaseband.cpp.s

plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/ssbdemodwebapiadapter.cpp.o: plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/flags.make
plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/ssbdemodwebapiadapter.cpp.o: ../plugins/channelrx/demodssb/ssbdemodwebapiadapter.cpp
plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/ssbdemodwebapiadapter.cpp.o: plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/ssbdemodwebapiadapter.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodssb && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/ssbdemodwebapiadapter.cpp.o -MF CMakeFiles/demodssb.dir/ssbdemodwebapiadapter.cpp.o.d -o CMakeFiles/demodssb.dir/ssbdemodwebapiadapter.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/demodssb/ssbdemodwebapiadapter.cpp

plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/ssbdemodwebapiadapter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demodssb.dir/ssbdemodwebapiadapter.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodssb && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/demodssb/ssbdemodwebapiadapter.cpp > CMakeFiles/demodssb.dir/ssbdemodwebapiadapter.cpp.i

plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/ssbdemodwebapiadapter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demodssb.dir/ssbdemodwebapiadapter.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodssb && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/demodssb/ssbdemodwebapiadapter.cpp -o CMakeFiles/demodssb.dir/ssbdemodwebapiadapter.cpp.s

plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/ssbplugin.cpp.o: plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/flags.make
plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/ssbplugin.cpp.o: ../plugins/channelrx/demodssb/ssbplugin.cpp
plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/ssbplugin.cpp.o: plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/ssbplugin.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodssb && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/ssbplugin.cpp.o -MF CMakeFiles/demodssb.dir/ssbplugin.cpp.o.d -o CMakeFiles/demodssb.dir/ssbplugin.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/demodssb/ssbplugin.cpp

plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/ssbplugin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demodssb.dir/ssbplugin.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodssb && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/demodssb/ssbplugin.cpp > CMakeFiles/demodssb.dir/ssbplugin.cpp.i

plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/ssbplugin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demodssb.dir/ssbplugin.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodssb && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/demodssb/ssbplugin.cpp -o CMakeFiles/demodssb.dir/ssbplugin.cpp.s

plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/ssbdemodgui.cpp.o: plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/flags.make
plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/ssbdemodgui.cpp.o: ../plugins/channelrx/demodssb/ssbdemodgui.cpp
plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/ssbdemodgui.cpp.o: plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/ssbdemodgui.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodssb && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/ssbdemodgui.cpp.o -MF CMakeFiles/demodssb.dir/ssbdemodgui.cpp.o.d -o CMakeFiles/demodssb.dir/ssbdemodgui.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/demodssb/ssbdemodgui.cpp

plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/ssbdemodgui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demodssb.dir/ssbdemodgui.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodssb && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/demodssb/ssbdemodgui.cpp > CMakeFiles/demodssb.dir/ssbdemodgui.cpp.i

plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/ssbdemodgui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demodssb.dir/ssbdemodgui.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodssb && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/demodssb/ssbdemodgui.cpp -o CMakeFiles/demodssb.dir/ssbdemodgui.cpp.s

# Object files for target demodssb
demodssb_OBJECTS = \
"CMakeFiles/demodssb.dir/demodssb_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/demodssb.dir/ssbdemod.cpp.o" \
"CMakeFiles/demodssb.dir/ssbdemodsettings.cpp.o" \
"CMakeFiles/demodssb.dir/ssbdemodsink.cpp.o" \
"CMakeFiles/demodssb.dir/ssbdemodbaseband.cpp.o" \
"CMakeFiles/demodssb.dir/ssbdemodwebapiadapter.cpp.o" \
"CMakeFiles/demodssb.dir/ssbplugin.cpp.o" \
"CMakeFiles/demodssb.dir/ssbdemodgui.cpp.o"

# External object files for target demodssb
demodssb_EXTERNAL_OBJECTS =

lib/plugins/libdemodssb.so: plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/demodssb_autogen/mocs_compilation.cpp.o
lib/plugins/libdemodssb.so: plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/ssbdemod.cpp.o
lib/plugins/libdemodssb.so: plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/ssbdemodsettings.cpp.o
lib/plugins/libdemodssb.so: plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/ssbdemodsink.cpp.o
lib/plugins/libdemodssb.so: plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/ssbdemodbaseband.cpp.o
lib/plugins/libdemodssb.so: plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/ssbdemodwebapiadapter.cpp.o
lib/plugins/libdemodssb.so: plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/ssbplugin.cpp.o
lib/plugins/libdemodssb.so: plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/ssbdemodgui.cpp.o
lib/plugins/libdemodssb.so: plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/build.make
lib/plugins/libdemodssb.so: lib/libsdrgui.so
lib/plugins/libdemodssb.so: lib/libsdrbase.so
lib/plugins/libdemodssb.so: lib/libswagger.so
lib/plugins/libdemodssb.so: /usr/lib/x86_64-linux-gnu/libopus.so
lib/plugins/libdemodssb.so: /usr/lib/x86_64-linux-gnu/libm.so
lib/plugins/libdemodssb.so: /usr/lib/x86_64-linux-gnu/libfftw3f.so
lib/plugins/libdemodssb.so: /opt/install/serialdv/lib/libserialdv.so
lib/plugins/libdemodssb.so: /usr/lib/x86_64-linux-gnu/libQt5WebSockets.so.5.15.2
lib/plugins/libdemodssb.so: lib/libhttpserver.so
lib/plugins/libdemodssb.so: lib/libqrtplib.so
lib/plugins/libdemodssb.so: /usr/lib/x86_64-linux-gnu/libQt5Multimedia.so.5.15.2
lib/plugins/libdemodssb.so: lib/liblogging.so
lib/plugins/libdemodssb.so: /usr/lib/x86_64-linux-gnu/libQt5Network.so.5.15.2
lib/plugins/libdemodssb.so: /usr/lib/x86_64-linux-gnu/libQt5OpenGL.so.5.15.2
lib/plugins/libdemodssb.so: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.15.2
lib/plugins/libdemodssb.so: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.15.2
lib/plugins/libdemodssb.so: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.15.2
lib/plugins/libdemodssb.so: /usr/lib/x86_64-linux-gnu/libGL.so
lib/plugins/libdemodssb.so: /usr/lib/x86_64-linux-gnu/libGLU.so
lib/plugins/libdemodssb.so: /opt/install/LimeSuite/lib/libLimeSuite.so
lib/plugins/libdemodssb.so: plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX shared library ../../../lib/plugins/libdemodssb.so"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodssb && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/demodssb.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/build: lib/plugins/libdemodssb.so
.PHONY : plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/build

plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/clean:
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodssb && $(CMAKE_COMMAND) -P CMakeFiles/demodssb.dir/cmake_clean.cmake
.PHONY : plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/clean

plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/depend:
	cd /opt/build/RPX-100-SDR/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /opt/build/RPX-100-SDR /opt/build/RPX-100-SDR/plugins/channelrx/demodssb /opt/build/RPX-100-SDR/build /opt/build/RPX-100-SDR/build/plugins/channelrx/demodssb /opt/build/RPX-100-SDR/build/plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : plugins/channelrx/demodssb/CMakeFiles/demodssb.dir/depend

