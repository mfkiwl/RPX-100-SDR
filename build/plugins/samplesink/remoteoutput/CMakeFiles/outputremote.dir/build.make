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
include plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/compiler_depend.make

# Include the progress variables for this target.
include plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/progress.make

# Include the compile flags for this target's objects.
include plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/flags.make

plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/outputremote_autogen/mocs_compilation.cpp.o: plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/flags.make
plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/outputremote_autogen/mocs_compilation.cpp.o: plugins/samplesink/remoteoutput/outputremote_autogen/mocs_compilation.cpp
plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/outputremote_autogen/mocs_compilation.cpp.o: plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/outputremote_autogen/mocs_compilation.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/samplesink/remoteoutput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/outputremote_autogen/mocs_compilation.cpp.o -MF CMakeFiles/outputremote.dir/outputremote_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/outputremote.dir/outputremote_autogen/mocs_compilation.cpp.o -c /opt/build/RPX-100-SDR/build/plugins/samplesink/remoteoutput/outputremote_autogen/mocs_compilation.cpp

plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/outputremote_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/outputremote.dir/outputremote_autogen/mocs_compilation.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/samplesink/remoteoutput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/build/plugins/samplesink/remoteoutput/outputremote_autogen/mocs_compilation.cpp > CMakeFiles/outputremote.dir/outputremote_autogen/mocs_compilation.cpp.i

plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/outputremote_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/outputremote.dir/outputremote_autogen/mocs_compilation.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/samplesink/remoteoutput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/build/plugins/samplesink/remoteoutput/outputremote_autogen/mocs_compilation.cpp -o CMakeFiles/outputremote.dir/outputremote_autogen/mocs_compilation.cpp.s

plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/remoteoutput.cpp.o: plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/flags.make
plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/remoteoutput.cpp.o: ../plugins/samplesink/remoteoutput/remoteoutput.cpp
plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/remoteoutput.cpp.o: plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/remoteoutput.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/samplesink/remoteoutput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/remoteoutput.cpp.o -MF CMakeFiles/outputremote.dir/remoteoutput.cpp.o.d -o CMakeFiles/outputremote.dir/remoteoutput.cpp.o -c /opt/build/RPX-100-SDR/plugins/samplesink/remoteoutput/remoteoutput.cpp

plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/remoteoutput.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/outputremote.dir/remoteoutput.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/samplesink/remoteoutput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/samplesink/remoteoutput/remoteoutput.cpp > CMakeFiles/outputremote.dir/remoteoutput.cpp.i

plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/remoteoutput.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/outputremote.dir/remoteoutput.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/samplesink/remoteoutput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/samplesink/remoteoutput/remoteoutput.cpp -o CMakeFiles/outputremote.dir/remoteoutput.cpp.s

plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/remoteoutputplugin.cpp.o: plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/flags.make
plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/remoteoutputplugin.cpp.o: ../plugins/samplesink/remoteoutput/remoteoutputplugin.cpp
plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/remoteoutputplugin.cpp.o: plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/remoteoutputplugin.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/samplesink/remoteoutput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/remoteoutputplugin.cpp.o -MF CMakeFiles/outputremote.dir/remoteoutputplugin.cpp.o.d -o CMakeFiles/outputremote.dir/remoteoutputplugin.cpp.o -c /opt/build/RPX-100-SDR/plugins/samplesink/remoteoutput/remoteoutputplugin.cpp

plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/remoteoutputplugin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/outputremote.dir/remoteoutputplugin.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/samplesink/remoteoutput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/samplesink/remoteoutput/remoteoutputplugin.cpp > CMakeFiles/outputremote.dir/remoteoutputplugin.cpp.i

plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/remoteoutputplugin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/outputremote.dir/remoteoutputplugin.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/samplesink/remoteoutput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/samplesink/remoteoutput/remoteoutputplugin.cpp -o CMakeFiles/outputremote.dir/remoteoutputplugin.cpp.s

plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/remoteoutputsettings.cpp.o: plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/flags.make
plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/remoteoutputsettings.cpp.o: ../plugins/samplesink/remoteoutput/remoteoutputsettings.cpp
plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/remoteoutputsettings.cpp.o: plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/remoteoutputsettings.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/samplesink/remoteoutput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/remoteoutputsettings.cpp.o -MF CMakeFiles/outputremote.dir/remoteoutputsettings.cpp.o.d -o CMakeFiles/outputremote.dir/remoteoutputsettings.cpp.o -c /opt/build/RPX-100-SDR/plugins/samplesink/remoteoutput/remoteoutputsettings.cpp

plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/remoteoutputsettings.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/outputremote.dir/remoteoutputsettings.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/samplesink/remoteoutput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/samplesink/remoteoutput/remoteoutputsettings.cpp > CMakeFiles/outputremote.dir/remoteoutputsettings.cpp.i

plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/remoteoutputsettings.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/outputremote.dir/remoteoutputsettings.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/samplesink/remoteoutput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/samplesink/remoteoutput/remoteoutputsettings.cpp -o CMakeFiles/outputremote.dir/remoteoutputsettings.cpp.s

plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/remoteoutputwebapiadapter.cpp.o: plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/flags.make
plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/remoteoutputwebapiadapter.cpp.o: ../plugins/samplesink/remoteoutput/remoteoutputwebapiadapter.cpp
plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/remoteoutputwebapiadapter.cpp.o: plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/remoteoutputwebapiadapter.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/samplesink/remoteoutput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/remoteoutputwebapiadapter.cpp.o -MF CMakeFiles/outputremote.dir/remoteoutputwebapiadapter.cpp.o.d -o CMakeFiles/outputremote.dir/remoteoutputwebapiadapter.cpp.o -c /opt/build/RPX-100-SDR/plugins/samplesink/remoteoutput/remoteoutputwebapiadapter.cpp

plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/remoteoutputwebapiadapter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/outputremote.dir/remoteoutputwebapiadapter.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/samplesink/remoteoutput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/samplesink/remoteoutput/remoteoutputwebapiadapter.cpp > CMakeFiles/outputremote.dir/remoteoutputwebapiadapter.cpp.i

plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/remoteoutputwebapiadapter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/outputremote.dir/remoteoutputwebapiadapter.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/samplesink/remoteoutput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/samplesink/remoteoutput/remoteoutputwebapiadapter.cpp -o CMakeFiles/outputremote.dir/remoteoutputwebapiadapter.cpp.s

plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/remoteoutputworker.cpp.o: plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/flags.make
plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/remoteoutputworker.cpp.o: ../plugins/samplesink/remoteoutput/remoteoutputworker.cpp
plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/remoteoutputworker.cpp.o: plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/remoteoutputworker.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/samplesink/remoteoutput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/remoteoutputworker.cpp.o -MF CMakeFiles/outputremote.dir/remoteoutputworker.cpp.o.d -o CMakeFiles/outputremote.dir/remoteoutputworker.cpp.o -c /opt/build/RPX-100-SDR/plugins/samplesink/remoteoutput/remoteoutputworker.cpp

plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/remoteoutputworker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/outputremote.dir/remoteoutputworker.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/samplesink/remoteoutput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/samplesink/remoteoutput/remoteoutputworker.cpp > CMakeFiles/outputremote.dir/remoteoutputworker.cpp.i

plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/remoteoutputworker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/outputremote.dir/remoteoutputworker.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/samplesink/remoteoutput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/samplesink/remoteoutput/remoteoutputworker.cpp -o CMakeFiles/outputremote.dir/remoteoutputworker.cpp.s

plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/udpsinkfec.cpp.o: plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/flags.make
plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/udpsinkfec.cpp.o: ../plugins/samplesink/remoteoutput/udpsinkfec.cpp
plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/udpsinkfec.cpp.o: plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/udpsinkfec.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/samplesink/remoteoutput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/udpsinkfec.cpp.o -MF CMakeFiles/outputremote.dir/udpsinkfec.cpp.o.d -o CMakeFiles/outputremote.dir/udpsinkfec.cpp.o -c /opt/build/RPX-100-SDR/plugins/samplesink/remoteoutput/udpsinkfec.cpp

plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/udpsinkfec.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/outputremote.dir/udpsinkfec.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/samplesink/remoteoutput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/samplesink/remoteoutput/udpsinkfec.cpp > CMakeFiles/outputremote.dir/udpsinkfec.cpp.i

plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/udpsinkfec.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/outputremote.dir/udpsinkfec.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/samplesink/remoteoutput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/samplesink/remoteoutput/udpsinkfec.cpp -o CMakeFiles/outputremote.dir/udpsinkfec.cpp.s

plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/remoteoutputsender.cpp.o: plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/flags.make
plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/remoteoutputsender.cpp.o: ../plugins/samplesink/remoteoutput/remoteoutputsender.cpp
plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/remoteoutputsender.cpp.o: plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/remoteoutputsender.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/samplesink/remoteoutput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/remoteoutputsender.cpp.o -MF CMakeFiles/outputremote.dir/remoteoutputsender.cpp.o.d -o CMakeFiles/outputremote.dir/remoteoutputsender.cpp.o -c /opt/build/RPX-100-SDR/plugins/samplesink/remoteoutput/remoteoutputsender.cpp

plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/remoteoutputsender.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/outputremote.dir/remoteoutputsender.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/samplesink/remoteoutput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/samplesink/remoteoutput/remoteoutputsender.cpp > CMakeFiles/outputremote.dir/remoteoutputsender.cpp.i

plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/remoteoutputsender.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/outputremote.dir/remoteoutputsender.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/samplesink/remoteoutput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/samplesink/remoteoutput/remoteoutputsender.cpp -o CMakeFiles/outputremote.dir/remoteoutputsender.cpp.s

plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/remoteoutputfifo.cpp.o: plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/flags.make
plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/remoteoutputfifo.cpp.o: ../plugins/samplesink/remoteoutput/remoteoutputfifo.cpp
plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/remoteoutputfifo.cpp.o: plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/remoteoutputfifo.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/samplesink/remoteoutput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/remoteoutputfifo.cpp.o -MF CMakeFiles/outputremote.dir/remoteoutputfifo.cpp.o.d -o CMakeFiles/outputremote.dir/remoteoutputfifo.cpp.o -c /opt/build/RPX-100-SDR/plugins/samplesink/remoteoutput/remoteoutputfifo.cpp

plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/remoteoutputfifo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/outputremote.dir/remoteoutputfifo.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/samplesink/remoteoutput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/samplesink/remoteoutput/remoteoutputfifo.cpp > CMakeFiles/outputremote.dir/remoteoutputfifo.cpp.i

plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/remoteoutputfifo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/outputremote.dir/remoteoutputfifo.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/samplesink/remoteoutput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/samplesink/remoteoutput/remoteoutputfifo.cpp -o CMakeFiles/outputremote.dir/remoteoutputfifo.cpp.s

plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/remoteoutputgui.cpp.o: plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/flags.make
plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/remoteoutputgui.cpp.o: ../plugins/samplesink/remoteoutput/remoteoutputgui.cpp
plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/remoteoutputgui.cpp.o: plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/remoteoutputgui.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/samplesink/remoteoutput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/remoteoutputgui.cpp.o -MF CMakeFiles/outputremote.dir/remoteoutputgui.cpp.o.d -o CMakeFiles/outputremote.dir/remoteoutputgui.cpp.o -c /opt/build/RPX-100-SDR/plugins/samplesink/remoteoutput/remoteoutputgui.cpp

plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/remoteoutputgui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/outputremote.dir/remoteoutputgui.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/samplesink/remoteoutput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/samplesink/remoteoutput/remoteoutputgui.cpp > CMakeFiles/outputremote.dir/remoteoutputgui.cpp.i

plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/remoteoutputgui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/outputremote.dir/remoteoutputgui.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/samplesink/remoteoutput && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/samplesink/remoteoutput/remoteoutputgui.cpp -o CMakeFiles/outputremote.dir/remoteoutputgui.cpp.s

# Object files for target outputremote
outputremote_OBJECTS = \
"CMakeFiles/outputremote.dir/outputremote_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/outputremote.dir/remoteoutput.cpp.o" \
"CMakeFiles/outputremote.dir/remoteoutputplugin.cpp.o" \
"CMakeFiles/outputremote.dir/remoteoutputsettings.cpp.o" \
"CMakeFiles/outputremote.dir/remoteoutputwebapiadapter.cpp.o" \
"CMakeFiles/outputremote.dir/remoteoutputworker.cpp.o" \
"CMakeFiles/outputremote.dir/udpsinkfec.cpp.o" \
"CMakeFiles/outputremote.dir/remoteoutputsender.cpp.o" \
"CMakeFiles/outputremote.dir/remoteoutputfifo.cpp.o" \
"CMakeFiles/outputremote.dir/remoteoutputgui.cpp.o"

# External object files for target outputremote
outputremote_EXTERNAL_OBJECTS =

lib/plugins/liboutputremote.so: plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/outputremote_autogen/mocs_compilation.cpp.o
lib/plugins/liboutputremote.so: plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/remoteoutput.cpp.o
lib/plugins/liboutputremote.so: plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/remoteoutputplugin.cpp.o
lib/plugins/liboutputremote.so: plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/remoteoutputsettings.cpp.o
lib/plugins/liboutputremote.so: plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/remoteoutputwebapiadapter.cpp.o
lib/plugins/liboutputremote.so: plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/remoteoutputworker.cpp.o
lib/plugins/liboutputremote.so: plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/udpsinkfec.cpp.o
lib/plugins/liboutputremote.so: plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/remoteoutputsender.cpp.o
lib/plugins/liboutputremote.so: plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/remoteoutputfifo.cpp.o
lib/plugins/liboutputremote.so: plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/remoteoutputgui.cpp.o
lib/plugins/liboutputremote.so: plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/build.make
lib/plugins/liboutputremote.so: lib/libsdrgui.so
lib/plugins/liboutputremote.so: /opt/install/cm256cc/lib/libcm256cc.so
lib/plugins/liboutputremote.so: lib/libsdrbase.so
lib/plugins/liboutputremote.so: lib/libswagger.so
lib/plugins/liboutputremote.so: /usr/lib/x86_64-linux-gnu/libopus.so
lib/plugins/liboutputremote.so: /usr/lib/x86_64-linux-gnu/libm.so
lib/plugins/liboutputremote.so: /usr/lib/x86_64-linux-gnu/libfftw3f.so
lib/plugins/liboutputremote.so: /opt/install/serialdv/lib/libserialdv.so
lib/plugins/liboutputremote.so: /usr/lib/x86_64-linux-gnu/libQt5WebSockets.so.5.15.2
lib/plugins/liboutputremote.so: lib/libhttpserver.so
lib/plugins/liboutputremote.so: lib/libqrtplib.so
lib/plugins/liboutputremote.so: /usr/lib/x86_64-linux-gnu/libQt5Multimedia.so.5.15.2
lib/plugins/liboutputremote.so: lib/liblogging.so
lib/plugins/liboutputremote.so: /usr/lib/x86_64-linux-gnu/libQt5Network.so.5.15.2
lib/plugins/liboutputremote.so: /usr/lib/x86_64-linux-gnu/libQt5OpenGL.so.5.15.2
lib/plugins/liboutputremote.so: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.15.2
lib/plugins/liboutputremote.so: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.15.2
lib/plugins/liboutputremote.so: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.15.2
lib/plugins/liboutputremote.so: /usr/lib/x86_64-linux-gnu/libGL.so
lib/plugins/liboutputremote.so: /usr/lib/x86_64-linux-gnu/libGLU.so
lib/plugins/liboutputremote.so: /opt/install/LimeSuite/lib/libLimeSuite.so
lib/plugins/liboutputremote.so: plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX shared library ../../../lib/plugins/liboutputremote.so"
	cd /opt/build/RPX-100-SDR/build/plugins/samplesink/remoteoutput && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/outputremote.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/build: lib/plugins/liboutputremote.so
.PHONY : plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/build

plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/clean:
	cd /opt/build/RPX-100-SDR/build/plugins/samplesink/remoteoutput && $(CMAKE_COMMAND) -P CMakeFiles/outputremote.dir/cmake_clean.cmake
.PHONY : plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/clean

plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/depend:
	cd /opt/build/RPX-100-SDR/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /opt/build/RPX-100-SDR /opt/build/RPX-100-SDR/plugins/samplesink/remoteoutput /opt/build/RPX-100-SDR/build /opt/build/RPX-100-SDR/build/plugins/samplesink/remoteoutput /opt/build/RPX-100-SDR/build/plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : plugins/samplesink/remoteoutput/CMakeFiles/outputremote.dir/depend

