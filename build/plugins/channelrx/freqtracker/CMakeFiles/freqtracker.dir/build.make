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
include plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/compiler_depend.make

# Include the progress variables for this target.
include plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/progress.make

# Include the compile flags for this target's objects.
include plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/flags.make

plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtracker_autogen/mocs_compilation.cpp.o: plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/flags.make
plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtracker_autogen/mocs_compilation.cpp.o: plugins/channelrx/freqtracker/freqtracker_autogen/mocs_compilation.cpp
plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtracker_autogen/mocs_compilation.cpp.o: plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtracker_autogen/mocs_compilation.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/freqtracker && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtracker_autogen/mocs_compilation.cpp.o -MF CMakeFiles/freqtracker.dir/freqtracker_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/freqtracker.dir/freqtracker_autogen/mocs_compilation.cpp.o -c /opt/build/RPX-100-SDR/build/plugins/channelrx/freqtracker/freqtracker_autogen/mocs_compilation.cpp

plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtracker_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/freqtracker.dir/freqtracker_autogen/mocs_compilation.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/freqtracker && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/build/plugins/channelrx/freqtracker/freqtracker_autogen/mocs_compilation.cpp > CMakeFiles/freqtracker.dir/freqtracker_autogen/mocs_compilation.cpp.i

plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtracker_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/freqtracker.dir/freqtracker_autogen/mocs_compilation.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/freqtracker && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/build/plugins/channelrx/freqtracker/freqtracker_autogen/mocs_compilation.cpp -o CMakeFiles/freqtracker.dir/freqtracker_autogen/mocs_compilation.cpp.s

plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtracker.cpp.o: plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/flags.make
plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtracker.cpp.o: ../plugins/channelrx/freqtracker/freqtracker.cpp
plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtracker.cpp.o: plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtracker.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/freqtracker && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtracker.cpp.o -MF CMakeFiles/freqtracker.dir/freqtracker.cpp.o.d -o CMakeFiles/freqtracker.dir/freqtracker.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/freqtracker/freqtracker.cpp

plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtracker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/freqtracker.dir/freqtracker.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/freqtracker && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/freqtracker/freqtracker.cpp > CMakeFiles/freqtracker.dir/freqtracker.cpp.i

plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtracker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/freqtracker.dir/freqtracker.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/freqtracker && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/freqtracker/freqtracker.cpp -o CMakeFiles/freqtracker.dir/freqtracker.cpp.s

plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtrackerbaseband.cpp.o: plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/flags.make
plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtrackerbaseband.cpp.o: ../plugins/channelrx/freqtracker/freqtrackerbaseband.cpp
plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtrackerbaseband.cpp.o: plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtrackerbaseband.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/freqtracker && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtrackerbaseband.cpp.o -MF CMakeFiles/freqtracker.dir/freqtrackerbaseband.cpp.o.d -o CMakeFiles/freqtracker.dir/freqtrackerbaseband.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/freqtracker/freqtrackerbaseband.cpp

plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtrackerbaseband.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/freqtracker.dir/freqtrackerbaseband.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/freqtracker && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/freqtracker/freqtrackerbaseband.cpp > CMakeFiles/freqtracker.dir/freqtrackerbaseband.cpp.i

plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtrackerbaseband.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/freqtracker.dir/freqtrackerbaseband.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/freqtracker && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/freqtracker/freqtrackerbaseband.cpp -o CMakeFiles/freqtracker.dir/freqtrackerbaseband.cpp.s

plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtrackersink.cpp.o: plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/flags.make
plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtrackersink.cpp.o: ../plugins/channelrx/freqtracker/freqtrackersink.cpp
plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtrackersink.cpp.o: plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtrackersink.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/freqtracker && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtrackersink.cpp.o -MF CMakeFiles/freqtracker.dir/freqtrackersink.cpp.o.d -o CMakeFiles/freqtracker.dir/freqtrackersink.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/freqtracker/freqtrackersink.cpp

plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtrackersink.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/freqtracker.dir/freqtrackersink.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/freqtracker && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/freqtracker/freqtrackersink.cpp > CMakeFiles/freqtracker.dir/freqtrackersink.cpp.i

plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtrackersink.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/freqtracker.dir/freqtrackersink.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/freqtracker && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/freqtracker/freqtrackersink.cpp -o CMakeFiles/freqtracker.dir/freqtrackersink.cpp.s

plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtrackerreport.cpp.o: plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/flags.make
plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtrackerreport.cpp.o: ../plugins/channelrx/freqtracker/freqtrackerreport.cpp
plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtrackerreport.cpp.o: plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtrackerreport.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/freqtracker && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtrackerreport.cpp.o -MF CMakeFiles/freqtracker.dir/freqtrackerreport.cpp.o.d -o CMakeFiles/freqtracker.dir/freqtrackerreport.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/freqtracker/freqtrackerreport.cpp

plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtrackerreport.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/freqtracker.dir/freqtrackerreport.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/freqtracker && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/freqtracker/freqtrackerreport.cpp > CMakeFiles/freqtracker.dir/freqtrackerreport.cpp.i

plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtrackerreport.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/freqtracker.dir/freqtrackerreport.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/freqtracker && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/freqtracker/freqtrackerreport.cpp -o CMakeFiles/freqtracker.dir/freqtrackerreport.cpp.s

plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtrackersettings.cpp.o: plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/flags.make
plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtrackersettings.cpp.o: ../plugins/channelrx/freqtracker/freqtrackersettings.cpp
plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtrackersettings.cpp.o: plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtrackersettings.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/freqtracker && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtrackersettings.cpp.o -MF CMakeFiles/freqtracker.dir/freqtrackersettings.cpp.o.d -o CMakeFiles/freqtracker.dir/freqtrackersettings.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/freqtracker/freqtrackersettings.cpp

plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtrackersettings.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/freqtracker.dir/freqtrackersettings.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/freqtracker && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/freqtracker/freqtrackersettings.cpp > CMakeFiles/freqtracker.dir/freqtrackersettings.cpp.i

plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtrackersettings.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/freqtracker.dir/freqtrackersettings.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/freqtracker && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/freqtracker/freqtrackersettings.cpp -o CMakeFiles/freqtracker.dir/freqtrackersettings.cpp.s

plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtrackerwebapiadapter.cpp.o: plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/flags.make
plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtrackerwebapiadapter.cpp.o: ../plugins/channelrx/freqtracker/freqtrackerwebapiadapter.cpp
plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtrackerwebapiadapter.cpp.o: plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtrackerwebapiadapter.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/freqtracker && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtrackerwebapiadapter.cpp.o -MF CMakeFiles/freqtracker.dir/freqtrackerwebapiadapter.cpp.o.d -o CMakeFiles/freqtracker.dir/freqtrackerwebapiadapter.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/freqtracker/freqtrackerwebapiadapter.cpp

plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtrackerwebapiadapter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/freqtracker.dir/freqtrackerwebapiadapter.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/freqtracker && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/freqtracker/freqtrackerwebapiadapter.cpp > CMakeFiles/freqtracker.dir/freqtrackerwebapiadapter.cpp.i

plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtrackerwebapiadapter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/freqtracker.dir/freqtrackerwebapiadapter.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/freqtracker && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/freqtracker/freqtrackerwebapiadapter.cpp -o CMakeFiles/freqtracker.dir/freqtrackerwebapiadapter.cpp.s

plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtrackerplugin.cpp.o: plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/flags.make
plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtrackerplugin.cpp.o: ../plugins/channelrx/freqtracker/freqtrackerplugin.cpp
plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtrackerplugin.cpp.o: plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtrackerplugin.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/freqtracker && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtrackerplugin.cpp.o -MF CMakeFiles/freqtracker.dir/freqtrackerplugin.cpp.o.d -o CMakeFiles/freqtracker.dir/freqtrackerplugin.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/freqtracker/freqtrackerplugin.cpp

plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtrackerplugin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/freqtracker.dir/freqtrackerplugin.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/freqtracker && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/freqtracker/freqtrackerplugin.cpp > CMakeFiles/freqtracker.dir/freqtrackerplugin.cpp.i

plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtrackerplugin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/freqtracker.dir/freqtrackerplugin.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/freqtracker && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/freqtracker/freqtrackerplugin.cpp -o CMakeFiles/freqtracker.dir/freqtrackerplugin.cpp.s

plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtrackergui.cpp.o: plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/flags.make
plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtrackergui.cpp.o: ../plugins/channelrx/freqtracker/freqtrackergui.cpp
plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtrackergui.cpp.o: plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtrackergui.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/freqtracker && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtrackergui.cpp.o -MF CMakeFiles/freqtracker.dir/freqtrackergui.cpp.o.d -o CMakeFiles/freqtracker.dir/freqtrackergui.cpp.o -c /opt/build/RPX-100-SDR/plugins/channelrx/freqtracker/freqtrackergui.cpp

plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtrackergui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/freqtracker.dir/freqtrackergui.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/freqtracker && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/channelrx/freqtracker/freqtrackergui.cpp > CMakeFiles/freqtracker.dir/freqtrackergui.cpp.i

plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtrackergui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/freqtracker.dir/freqtrackergui.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/freqtracker && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/channelrx/freqtracker/freqtrackergui.cpp -o CMakeFiles/freqtracker.dir/freqtrackergui.cpp.s

# Object files for target freqtracker
freqtracker_OBJECTS = \
"CMakeFiles/freqtracker.dir/freqtracker_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/freqtracker.dir/freqtracker.cpp.o" \
"CMakeFiles/freqtracker.dir/freqtrackerbaseband.cpp.o" \
"CMakeFiles/freqtracker.dir/freqtrackersink.cpp.o" \
"CMakeFiles/freqtracker.dir/freqtrackerreport.cpp.o" \
"CMakeFiles/freqtracker.dir/freqtrackersettings.cpp.o" \
"CMakeFiles/freqtracker.dir/freqtrackerwebapiadapter.cpp.o" \
"CMakeFiles/freqtracker.dir/freqtrackerplugin.cpp.o" \
"CMakeFiles/freqtracker.dir/freqtrackergui.cpp.o"

# External object files for target freqtracker
freqtracker_EXTERNAL_OBJECTS =

lib/plugins/libfreqtracker.so: plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtracker_autogen/mocs_compilation.cpp.o
lib/plugins/libfreqtracker.so: plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtracker.cpp.o
lib/plugins/libfreqtracker.so: plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtrackerbaseband.cpp.o
lib/plugins/libfreqtracker.so: plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtrackersink.cpp.o
lib/plugins/libfreqtracker.so: plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtrackerreport.cpp.o
lib/plugins/libfreqtracker.so: plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtrackersettings.cpp.o
lib/plugins/libfreqtracker.so: plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtrackerwebapiadapter.cpp.o
lib/plugins/libfreqtracker.so: plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtrackerplugin.cpp.o
lib/plugins/libfreqtracker.so: plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/freqtrackergui.cpp.o
lib/plugins/libfreqtracker.so: plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/build.make
lib/plugins/libfreqtracker.so: lib/libsdrgui.so
lib/plugins/libfreqtracker.so: lib/libsdrbase.so
lib/plugins/libfreqtracker.so: /usr/lib/x86_64-linux-gnu/libopus.so
lib/plugins/libfreqtracker.so: /usr/lib/x86_64-linux-gnu/libm.so
lib/plugins/libfreqtracker.so: /usr/lib/x86_64-linux-gnu/libfftw3f.so
lib/plugins/libfreqtracker.so: /opt/install/serialdv/lib/libserialdv.so
lib/plugins/libfreqtracker.so: /usr/lib/x86_64-linux-gnu/libQt5WebSockets.so.5.15.2
lib/plugins/libfreqtracker.so: lib/libhttpserver.so
lib/plugins/libfreqtracker.so: lib/libqrtplib.so
lib/plugins/libfreqtracker.so: lib/libswagger.so
lib/plugins/libfreqtracker.so: /usr/lib/x86_64-linux-gnu/libQt5Multimedia.so.5.15.2
lib/plugins/libfreqtracker.so: lib/liblogging.so
lib/plugins/libfreqtracker.so: /usr/lib/x86_64-linux-gnu/libQt5Network.so.5.15.2
lib/plugins/libfreqtracker.so: /usr/lib/x86_64-linux-gnu/libQt5OpenGL.so.5.15.2
lib/plugins/libfreqtracker.so: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.15.2
lib/plugins/libfreqtracker.so: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.15.2
lib/plugins/libfreqtracker.so: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.15.2
lib/plugins/libfreqtracker.so: /usr/lib/x86_64-linux-gnu/libGL.so
lib/plugins/libfreqtracker.so: /usr/lib/x86_64-linux-gnu/libGLU.so
lib/plugins/libfreqtracker.so: /opt/install/LimeSuite/lib/libLimeSuite.so
lib/plugins/libfreqtracker.so: plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX shared library ../../../lib/plugins/libfreqtracker.so"
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/freqtracker && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/freqtracker.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/build: lib/plugins/libfreqtracker.so
.PHONY : plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/build

plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/clean:
	cd /opt/build/RPX-100-SDR/build/plugins/channelrx/freqtracker && $(CMAKE_COMMAND) -P CMakeFiles/freqtracker.dir/cmake_clean.cmake
.PHONY : plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/clean

plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/depend:
	cd /opt/build/RPX-100-SDR/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /opt/build/RPX-100-SDR /opt/build/RPX-100-SDR/plugins/channelrx/freqtracker /opt/build/RPX-100-SDR/build /opt/build/RPX-100-SDR/build/plugins/channelrx/freqtracker /opt/build/RPX-100-SDR/build/plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : plugins/channelrx/freqtracker/CMakeFiles/freqtracker.dir/depend
