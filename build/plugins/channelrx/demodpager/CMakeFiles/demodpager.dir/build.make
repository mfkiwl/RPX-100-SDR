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
include plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/compiler_depend.make

# Include the progress variables for this target.
include plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/progress.make

# Include the compile flags for this target's objects.
include plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/flags.make

plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/demodpager_autogen/mocs_compilation.cpp.o: plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/flags.make
plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/demodpager_autogen/mocs_compilation.cpp.o: plugins/channelrx/demodpager/demodpager_autogen/mocs_compilation.cpp
plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/demodpager_autogen/mocs_compilation.cpp.o: plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/demodpager_autogen/mocs_compilation.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodpager && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/demodpager_autogen/mocs_compilation.cpp.o -MF CMakeFiles/demodpager.dir/demodpager_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/demodpager.dir/demodpager_autogen/mocs_compilation.cpp.o -c /opt/build/RPX-100-SDR/build/plugins/channelrx/demodpager/demodpager_autogen/mocs_compilation.cpp

plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/demodpager_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demodpager.dir/demodpager_autogen/mocs_compilation.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodpager && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/build/plugins/channelrx/demodpager/demodpager_autogen/mocs_compilation.cpp > CMakeFiles/demodpager.dir/demodpager_autogen/mocs_compilation.cpp.i

plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/demodpager_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demodpager.dir/demodpager_autogen/mocs_compilation.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodpager && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/build/plugins/channelrx/demodpager/demodpager_autogen/mocs_compilation.cpp -o CMakeFiles/demodpager.dir/demodpager_autogen/mocs_compilation.cpp.s

plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/pagerdemod.cpp.o: plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/flags.make
plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/pagerdemod.cpp.o: ../plugins/channelrx/demodpager/pagerdemod.cpp
plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/pagerdemod.cpp.o: plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/pagerdemod.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodpager && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/pagerdemod.cpp.o -MF CMakeFiles/demodpager.dir/pagerdemod.cpp.o.d -o CMakeFiles/demodpager.dir/pagerdemod.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/demodpager/pagerdemod.cpp

plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/pagerdemod.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demodpager.dir/pagerdemod.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodpager && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/demodpager/pagerdemod.cpp > CMakeFiles/demodpager.dir/pagerdemod.cpp.i

plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/pagerdemod.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demodpager.dir/pagerdemod.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodpager && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/demodpager/pagerdemod.cpp -o CMakeFiles/demodpager.dir/pagerdemod.cpp.s

plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/pagerdemodsettings.cpp.o: plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/flags.make
plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/pagerdemodsettings.cpp.o: ../plugins/channelrx/demodpager/pagerdemodsettings.cpp
plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/pagerdemodsettings.cpp.o: plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/pagerdemodsettings.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodpager && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/pagerdemodsettings.cpp.o -MF CMakeFiles/demodpager.dir/pagerdemodsettings.cpp.o.d -o CMakeFiles/demodpager.dir/pagerdemodsettings.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/demodpager/pagerdemodsettings.cpp

plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/pagerdemodsettings.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demodpager.dir/pagerdemodsettings.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodpager && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/demodpager/pagerdemodsettings.cpp > CMakeFiles/demodpager.dir/pagerdemodsettings.cpp.i

plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/pagerdemodsettings.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demodpager.dir/pagerdemodsettings.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodpager && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/demodpager/pagerdemodsettings.cpp -o CMakeFiles/demodpager.dir/pagerdemodsettings.cpp.s

plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/pagerdemodbaseband.cpp.o: plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/flags.make
plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/pagerdemodbaseband.cpp.o: ../plugins/channelrx/demodpager/pagerdemodbaseband.cpp
plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/pagerdemodbaseband.cpp.o: plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/pagerdemodbaseband.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodpager && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/pagerdemodbaseband.cpp.o -MF CMakeFiles/demodpager.dir/pagerdemodbaseband.cpp.o.d -o CMakeFiles/demodpager.dir/pagerdemodbaseband.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/demodpager/pagerdemodbaseband.cpp

plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/pagerdemodbaseband.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demodpager.dir/pagerdemodbaseband.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodpager && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/demodpager/pagerdemodbaseband.cpp > CMakeFiles/demodpager.dir/pagerdemodbaseband.cpp.i

plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/pagerdemodbaseband.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demodpager.dir/pagerdemodbaseband.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodpager && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/demodpager/pagerdemodbaseband.cpp -o CMakeFiles/demodpager.dir/pagerdemodbaseband.cpp.s

plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/pagerdemodsink.cpp.o: plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/flags.make
plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/pagerdemodsink.cpp.o: ../plugins/channelrx/demodpager/pagerdemodsink.cpp
plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/pagerdemodsink.cpp.o: plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/pagerdemodsink.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodpager && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/pagerdemodsink.cpp.o -MF CMakeFiles/demodpager.dir/pagerdemodsink.cpp.o.d -o CMakeFiles/demodpager.dir/pagerdemodsink.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/demodpager/pagerdemodsink.cpp

plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/pagerdemodsink.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demodpager.dir/pagerdemodsink.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodpager && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/demodpager/pagerdemodsink.cpp > CMakeFiles/demodpager.dir/pagerdemodsink.cpp.i

plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/pagerdemodsink.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demodpager.dir/pagerdemodsink.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodpager && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/demodpager/pagerdemodsink.cpp -o CMakeFiles/demodpager.dir/pagerdemodsink.cpp.s

plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/pagerdemodplugin.cpp.o: plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/flags.make
plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/pagerdemodplugin.cpp.o: ../plugins/channelrx/demodpager/pagerdemodplugin.cpp
plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/pagerdemodplugin.cpp.o: plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/pagerdemodplugin.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodpager && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/pagerdemodplugin.cpp.o -MF CMakeFiles/demodpager.dir/pagerdemodplugin.cpp.o.d -o CMakeFiles/demodpager.dir/pagerdemodplugin.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/demodpager/pagerdemodplugin.cpp

plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/pagerdemodplugin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demodpager.dir/pagerdemodplugin.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodpager && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/demodpager/pagerdemodplugin.cpp > CMakeFiles/demodpager.dir/pagerdemodplugin.cpp.i

plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/pagerdemodplugin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demodpager.dir/pagerdemodplugin.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodpager && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/demodpager/pagerdemodplugin.cpp -o CMakeFiles/demodpager.dir/pagerdemodplugin.cpp.s

plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/pagerdemodwebapiadapter.cpp.o: plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/flags.make
plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/pagerdemodwebapiadapter.cpp.o: ../plugins/channelrx/demodpager/pagerdemodwebapiadapter.cpp
plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/pagerdemodwebapiadapter.cpp.o: plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/pagerdemodwebapiadapter.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodpager && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/pagerdemodwebapiadapter.cpp.o -MF CMakeFiles/demodpager.dir/pagerdemodwebapiadapter.cpp.o.d -o CMakeFiles/demodpager.dir/pagerdemodwebapiadapter.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/demodpager/pagerdemodwebapiadapter.cpp

plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/pagerdemodwebapiadapter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demodpager.dir/pagerdemodwebapiadapter.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodpager && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/demodpager/pagerdemodwebapiadapter.cpp > CMakeFiles/demodpager.dir/pagerdemodwebapiadapter.cpp.i

plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/pagerdemodwebapiadapter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demodpager.dir/pagerdemodwebapiadapter.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodpager && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/demodpager/pagerdemodwebapiadapter.cpp -o CMakeFiles/demodpager.dir/pagerdemodwebapiadapter.cpp.s

plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/pagerdemodgui.cpp.o: plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/flags.make
plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/pagerdemodgui.cpp.o: ../plugins/channelrx/demodpager/pagerdemodgui.cpp
plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/pagerdemodgui.cpp.o: plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/pagerdemodgui.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodpager && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/pagerdemodgui.cpp.o -MF CMakeFiles/demodpager.dir/pagerdemodgui.cpp.o.d -o CMakeFiles/demodpager.dir/pagerdemodgui.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/demodpager/pagerdemodgui.cpp

plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/pagerdemodgui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demodpager.dir/pagerdemodgui.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodpager && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/demodpager/pagerdemodgui.cpp > CMakeFiles/demodpager.dir/pagerdemodgui.cpp.i

plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/pagerdemodgui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demodpager.dir/pagerdemodgui.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodpager && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/demodpager/pagerdemodgui.cpp -o CMakeFiles/demodpager.dir/pagerdemodgui.cpp.s

plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/pagerdemodcharsetdialog.cpp.o: plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/flags.make
plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/pagerdemodcharsetdialog.cpp.o: ../plugins/channelrx/demodpager/pagerdemodcharsetdialog.cpp
plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/pagerdemodcharsetdialog.cpp.o: plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/pagerdemodcharsetdialog.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodpager && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/pagerdemodcharsetdialog.cpp.o -MF CMakeFiles/demodpager.dir/pagerdemodcharsetdialog.cpp.o.d -o CMakeFiles/demodpager.dir/pagerdemodcharsetdialog.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/demodpager/pagerdemodcharsetdialog.cpp

plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/pagerdemodcharsetdialog.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demodpager.dir/pagerdemodcharsetdialog.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodpager && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/demodpager/pagerdemodcharsetdialog.cpp > CMakeFiles/demodpager.dir/pagerdemodcharsetdialog.cpp.i

plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/pagerdemodcharsetdialog.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demodpager.dir/pagerdemodcharsetdialog.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodpager && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/demodpager/pagerdemodcharsetdialog.cpp -o CMakeFiles/demodpager.dir/pagerdemodcharsetdialog.cpp.s

# Object files for target demodpager
demodpager_OBJECTS = \
"CMakeFiles/demodpager.dir/demodpager_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/demodpager.dir/pagerdemod.cpp.o" \
"CMakeFiles/demodpager.dir/pagerdemodsettings.cpp.o" \
"CMakeFiles/demodpager.dir/pagerdemodbaseband.cpp.o" \
"CMakeFiles/demodpager.dir/pagerdemodsink.cpp.o" \
"CMakeFiles/demodpager.dir/pagerdemodplugin.cpp.o" \
"CMakeFiles/demodpager.dir/pagerdemodwebapiadapter.cpp.o" \
"CMakeFiles/demodpager.dir/pagerdemodgui.cpp.o" \
"CMakeFiles/demodpager.dir/pagerdemodcharsetdialog.cpp.o"

# External object files for target demodpager
demodpager_EXTERNAL_OBJECTS =

lib/plugins/libdemodpager.so: plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/demodpager_autogen/mocs_compilation.cpp.o
lib/plugins/libdemodpager.so: plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/pagerdemod.cpp.o
lib/plugins/libdemodpager.so: plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/pagerdemodsettings.cpp.o
lib/plugins/libdemodpager.so: plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/pagerdemodbaseband.cpp.o
lib/plugins/libdemodpager.so: plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/pagerdemodsink.cpp.o
lib/plugins/libdemodpager.so: plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/pagerdemodplugin.cpp.o
lib/plugins/libdemodpager.so: plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/pagerdemodwebapiadapter.cpp.o
lib/plugins/libdemodpager.so: plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/pagerdemodgui.cpp.o
lib/plugins/libdemodpager.so: plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/pagerdemodcharsetdialog.cpp.o
lib/plugins/libdemodpager.so: plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/build.make
lib/plugins/libdemodpager.so: lib/libsdrgui.so
lib/plugins/libdemodpager.so: lib/libsdrbase.so
lib/plugins/libdemodpager.so: /usr/lib/x86_64-linux-gnu/libopus.so
lib/plugins/libdemodpager.so: /usr/lib/x86_64-linux-gnu/libm.so
lib/plugins/libdemodpager.so: /usr/lib/x86_64-linux-gnu/libfftw3f.so
lib/plugins/libdemodpager.so: /opt/install/serialdv/lib/libserialdv.so
lib/plugins/libdemodpager.so: /usr/lib/x86_64-linux-gnu/libQt5WebSockets.so.5.15.2
lib/plugins/libdemodpager.so: lib/libhttpserver.so
lib/plugins/libdemodpager.so: lib/libqrtplib.so
lib/plugins/libdemodpager.so: lib/libswagger.so
lib/plugins/libdemodpager.so: /usr/lib/x86_64-linux-gnu/libQt5Multimedia.so.5.15.2
lib/plugins/libdemodpager.so: lib/liblogging.so
lib/plugins/libdemodpager.so: /usr/lib/x86_64-linux-gnu/libQt5Network.so.5.15.2
lib/plugins/libdemodpager.so: /usr/lib/x86_64-linux-gnu/libQt5OpenGL.so.5.15.2
lib/plugins/libdemodpager.so: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.15.2
lib/plugins/libdemodpager.so: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.15.2
lib/plugins/libdemodpager.so: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.15.2
lib/plugins/libdemodpager.so: /usr/lib/x86_64-linux-gnu/libGL.so
lib/plugins/libdemodpager.so: /usr/lib/x86_64-linux-gnu/libGLU.so
lib/plugins/libdemodpager.so: /opt/install/LimeSuite/lib/libLimeSuite.so
lib/plugins/libdemodpager.so: plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX shared library ../../../lib/plugins/libdemodpager.so"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodpager && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/demodpager.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/build: lib/plugins/libdemodpager.so
.PHONY : plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/build

plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/clean:
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/demodpager && $(CMAKE_COMMAND) -P CMakeFiles/demodpager.dir/cmake_clean.cmake
.PHONY : plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/clean

plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/depend:
	cd /opt/build/RPX-100-SDR/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /opt/build/RPX-100-SDR /opt/build/RPX-100-SDR/plugins/channelrx/demodpager /opt/build/RPX-100-SDR/build /opt/build/RPX-100-SDR/build/plugins/channelrx/demodpager /opt/build/RPX-100-SDR/build/plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : plugins/channelrx/demodpager/CMakeFiles/demodpager.dir/depend

