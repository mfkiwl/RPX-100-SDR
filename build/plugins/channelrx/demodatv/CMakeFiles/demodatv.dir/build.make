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
include plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/compiler_depend.make

# Include the progress variables for this target.
include plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/progress.make

# Include the compile flags for this target's objects.
include plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/flags.make

plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/demodatv_autogen/mocs_compilation.cpp.o: plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/flags.make
plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/demodatv_autogen/mocs_compilation.cpp.o: plugins/channelrx/demodatv/demodatv_autogen/mocs_compilation.cpp
plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/demodatv_autogen/mocs_compilation.cpp.o: plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/demodatv_autogen/mocs_compilation.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodatv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/demodatv_autogen/mocs_compilation.cpp.o -MF CMakeFiles/demodatv.dir/demodatv_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/demodatv.dir/demodatv_autogen/mocs_compilation.cpp.o -c /opt/build/RPX-100-SDR/build/plugins/channelrx/demodatv/demodatv_autogen/mocs_compilation.cpp

plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/demodatv_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demodatv.dir/demodatv_autogen/mocs_compilation.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodatv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/build/plugins/channelrx/demodatv/demodatv_autogen/mocs_compilation.cpp > CMakeFiles/demodatv.dir/demodatv_autogen/mocs_compilation.cpp.i

plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/demodatv_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demodatv.dir/demodatv_autogen/mocs_compilation.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodatv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/build/plugins/channelrx/demodatv/demodatv_autogen/mocs_compilation.cpp -o CMakeFiles/demodatv.dir/demodatv_autogen/mocs_compilation.cpp.s

plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/atvdemod.cpp.o: plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/flags.make
plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/atvdemod.cpp.o: ../plugins/channelrx/demodatv/atvdemod.cpp
plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/atvdemod.cpp.o: plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/atvdemod.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodatv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/atvdemod.cpp.o -MF CMakeFiles/demodatv.dir/atvdemod.cpp.o.d -o CMakeFiles/demodatv.dir/atvdemod.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/demodatv/atvdemod.cpp

plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/atvdemod.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demodatv.dir/atvdemod.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodatv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/demodatv/atvdemod.cpp > CMakeFiles/demodatv.dir/atvdemod.cpp.i

plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/atvdemod.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demodatv.dir/atvdemod.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodatv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/demodatv/atvdemod.cpp -o CMakeFiles/demodatv.dir/atvdemod.cpp.s

plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/atvdemodbaseband.cpp.o: plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/flags.make
plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/atvdemodbaseband.cpp.o: ../plugins/channelrx/demodatv/atvdemodbaseband.cpp
plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/atvdemodbaseband.cpp.o: plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/atvdemodbaseband.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodatv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/atvdemodbaseband.cpp.o -MF CMakeFiles/demodatv.dir/atvdemodbaseband.cpp.o.d -o CMakeFiles/demodatv.dir/atvdemodbaseband.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/demodatv/atvdemodbaseband.cpp

plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/atvdemodbaseband.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demodatv.dir/atvdemodbaseband.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodatv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/demodatv/atvdemodbaseband.cpp > CMakeFiles/demodatv.dir/atvdemodbaseband.cpp.i

plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/atvdemodbaseband.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demodatv.dir/atvdemodbaseband.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodatv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/demodatv/atvdemodbaseband.cpp -o CMakeFiles/demodatv.dir/atvdemodbaseband.cpp.s

plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/atvdemodsink.cpp.o: plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/flags.make
plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/atvdemodsink.cpp.o: ../plugins/channelrx/demodatv/atvdemodsink.cpp
plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/atvdemodsink.cpp.o: plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/atvdemodsink.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodatv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/atvdemodsink.cpp.o -MF CMakeFiles/demodatv.dir/atvdemodsink.cpp.o.d -o CMakeFiles/demodatv.dir/atvdemodsink.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/demodatv/atvdemodsink.cpp

plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/atvdemodsink.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demodatv.dir/atvdemodsink.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodatv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/demodatv/atvdemodsink.cpp > CMakeFiles/demodatv.dir/atvdemodsink.cpp.i

plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/atvdemodsink.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demodatv.dir/atvdemodsink.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodatv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/demodatv/atvdemodsink.cpp -o CMakeFiles/demodatv.dir/atvdemodsink.cpp.s

plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/atvdemodsettings.cpp.o: plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/flags.make
plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/atvdemodsettings.cpp.o: ../plugins/channelrx/demodatv/atvdemodsettings.cpp
plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/atvdemodsettings.cpp.o: plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/atvdemodsettings.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodatv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/atvdemodsettings.cpp.o -MF CMakeFiles/demodatv.dir/atvdemodsettings.cpp.o.d -o CMakeFiles/demodatv.dir/atvdemodsettings.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/demodatv/atvdemodsettings.cpp

plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/atvdemodsettings.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demodatv.dir/atvdemodsettings.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodatv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/demodatv/atvdemodsettings.cpp > CMakeFiles/demodatv.dir/atvdemodsettings.cpp.i

plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/atvdemodsettings.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demodatv.dir/atvdemodsettings.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodatv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/demodatv/atvdemodsettings.cpp -o CMakeFiles/demodatv.dir/atvdemodsettings.cpp.s

plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/atvdemodwebapiadapter.cpp.o: plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/flags.make
plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/atvdemodwebapiadapter.cpp.o: ../plugins/channelrx/demodatv/atvdemodwebapiadapter.cpp
plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/atvdemodwebapiadapter.cpp.o: plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/atvdemodwebapiadapter.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodatv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/atvdemodwebapiadapter.cpp.o -MF CMakeFiles/demodatv.dir/atvdemodwebapiadapter.cpp.o.d -o CMakeFiles/demodatv.dir/atvdemodwebapiadapter.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/demodatv/atvdemodwebapiadapter.cpp

plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/atvdemodwebapiadapter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demodatv.dir/atvdemodwebapiadapter.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodatv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/demodatv/atvdemodwebapiadapter.cpp > CMakeFiles/demodatv.dir/atvdemodwebapiadapter.cpp.i

plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/atvdemodwebapiadapter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demodatv.dir/atvdemodwebapiadapter.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodatv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/demodatv/atvdemodwebapiadapter.cpp -o CMakeFiles/demodatv.dir/atvdemodwebapiadapter.cpp.s

plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/atvdemodgui.cpp.o: plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/flags.make
plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/atvdemodgui.cpp.o: ../plugins/channelrx/demodatv/atvdemodgui.cpp
plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/atvdemodgui.cpp.o: plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/atvdemodgui.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodatv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/atvdemodgui.cpp.o -MF CMakeFiles/demodatv.dir/atvdemodgui.cpp.o.d -o CMakeFiles/demodatv.dir/atvdemodgui.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/demodatv/atvdemodgui.cpp

plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/atvdemodgui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demodatv.dir/atvdemodgui.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodatv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/demodatv/atvdemodgui.cpp > CMakeFiles/demodatv.dir/atvdemodgui.cpp.i

plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/atvdemodgui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demodatv.dir/atvdemodgui.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodatv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/demodatv/atvdemodgui.cpp -o CMakeFiles/demodatv.dir/atvdemodgui.cpp.s

plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/atvdemodplugin.cpp.o: plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/flags.make
plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/atvdemodplugin.cpp.o: ../plugins/channelrx/demodatv/atvdemodplugin.cpp
plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/atvdemodplugin.cpp.o: plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/atvdemodplugin.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodatv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/atvdemodplugin.cpp.o -MF CMakeFiles/demodatv.dir/atvdemodplugin.cpp.o.d -o CMakeFiles/demodatv.dir/atvdemodplugin.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/demodatv/atvdemodplugin.cpp

plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/atvdemodplugin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demodatv.dir/atvdemodplugin.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodatv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/demodatv/atvdemodplugin.cpp > CMakeFiles/demodatv.dir/atvdemodplugin.cpp.i

plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/atvdemodplugin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demodatv.dir/atvdemodplugin.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodatv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/demodatv/atvdemodplugin.cpp -o CMakeFiles/demodatv.dir/atvdemodplugin.cpp.s

# Object files for target demodatv
demodatv_OBJECTS = \
"CMakeFiles/demodatv.dir/demodatv_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/demodatv.dir/atvdemod.cpp.o" \
"CMakeFiles/demodatv.dir/atvdemodbaseband.cpp.o" \
"CMakeFiles/demodatv.dir/atvdemodsink.cpp.o" \
"CMakeFiles/demodatv.dir/atvdemodsettings.cpp.o" \
"CMakeFiles/demodatv.dir/atvdemodwebapiadapter.cpp.o" \
"CMakeFiles/demodatv.dir/atvdemodgui.cpp.o" \
"CMakeFiles/demodatv.dir/atvdemodplugin.cpp.o"

# External object files for target demodatv
demodatv_EXTERNAL_OBJECTS =

lib/plugins/libdemodatv.so: plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/demodatv_autogen/mocs_compilation.cpp.o
lib/plugins/libdemodatv.so: plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/atvdemod.cpp.o
lib/plugins/libdemodatv.so: plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/atvdemodbaseband.cpp.o
lib/plugins/libdemodatv.so: plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/atvdemodsink.cpp.o
lib/plugins/libdemodatv.so: plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/atvdemodsettings.cpp.o
lib/plugins/libdemodatv.so: plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/atvdemodwebapiadapter.cpp.o
lib/plugins/libdemodatv.so: plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/atvdemodgui.cpp.o
lib/plugins/libdemodatv.so: plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/atvdemodplugin.cpp.o
lib/plugins/libdemodatv.so: plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/build.make
lib/plugins/libdemodatv.so: lib/libsdrgui.so
lib/plugins/libdemodatv.so: lib/libsdrbase.so
lib/plugins/libdemodatv.so: /usr/lib/x86_64-linux-gnu/libopus.so
lib/plugins/libdemodatv.so: /usr/lib/x86_64-linux-gnu/libm.so
lib/plugins/libdemodatv.so: /usr/lib/x86_64-linux-gnu/libfftw3f.so
lib/plugins/libdemodatv.so: /opt/install/serialdv/lib/libserialdv.so
lib/plugins/libdemodatv.so: /usr/lib/x86_64-linux-gnu/libQt5WebSockets.so.5.15.2
lib/plugins/libdemodatv.so: lib/libhttpserver.so
lib/plugins/libdemodatv.so: lib/libqrtplib.so
lib/plugins/libdemodatv.so: lib/libswagger.so
lib/plugins/libdemodatv.so: /usr/lib/x86_64-linux-gnu/libQt5Multimedia.so.5.15.2
lib/plugins/libdemodatv.so: lib/liblogging.so
lib/plugins/libdemodatv.so: /usr/lib/x86_64-linux-gnu/libQt5Network.so.5.15.2
lib/plugins/libdemodatv.so: /usr/lib/x86_64-linux-gnu/libQt5OpenGL.so.5.15.2
lib/plugins/libdemodatv.so: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.15.2
lib/plugins/libdemodatv.so: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.15.2
lib/plugins/libdemodatv.so: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.15.2
lib/plugins/libdemodatv.so: /usr/lib/x86_64-linux-gnu/libGL.so
lib/plugins/libdemodatv.so: /usr/lib/x86_64-linux-gnu/libGLU.so
lib/plugins/libdemodatv.so: /opt/install/LimeSuite/lib/libLimeSuite.so
lib/plugins/libdemodatv.so: plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX shared library ../../../lib/plugins/libdemodatv.so"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodatv && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/demodatv.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/build: lib/plugins/libdemodatv.so
.PHONY : plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/build

plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/clean:
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodatv && $(CMAKE_COMMAND) -P CMakeFiles/demodatv.dir/cmake_clean.cmake
.PHONY : plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/clean

plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/depend:
	cd /opt/build/RPX-100-SDR/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /opt/build/RPX-100-SDR /opt/build/RPX-100-SDR/plugins/channelrx/demodatv /opt/build/RPX-100-SDR/build /opt/build/RPX-100-SDR/build/plugins/channelrx/demodatv /opt/build/RPX-100-SDR/build/plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : plugins/channelrx/demodatv/CMakeFiles/demodatv.dir/depend

