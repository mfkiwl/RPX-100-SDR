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
include plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/compiler_depend.make

# Include the progress variables for this target.
include plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/progress.make

# Include the compile flags for this target's objects.
include plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/flags.make

plugins/feature/vorlocalizer/vorlocalizer_autogen/EWIEGA46WW/qrc_map.cpp: ../plugins/feature/vorlocalizer/map.qrc
plugins/feature/vorlocalizer/vorlocalizer_autogen/EWIEGA46WW/qrc_map.cpp: plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer_autogen.dir/AutoRcc_map_EWIEGA46WW_Info.json
plugins/feature/vorlocalizer/vorlocalizer_autogen/EWIEGA46WW/qrc_map.cpp: ../plugins/feature/vorlocalizer/map/VORTAC.png
plugins/feature/vorlocalizer/vorlocalizer_autogen/EWIEGA46WW/qrc_map.cpp: ../plugins/feature/vorlocalizer/map/VOR.png
plugins/feature/vorlocalizer/vorlocalizer_autogen/EWIEGA46WW/qrc_map.cpp: ../plugins/feature/vorlocalizer/map/VOR-DME.png
plugins/feature/vorlocalizer/vorlocalizer_autogen/EWIEGA46WW/qrc_map.cpp: ../plugins/feature/vorlocalizer/map/MapStation.qml
plugins/feature/vorlocalizer/vorlocalizer_autogen/EWIEGA46WW/qrc_map.cpp: ../plugins/feature/vorlocalizer/map/map.qml
plugins/feature/vorlocalizer/vorlocalizer_autogen/EWIEGA46WW/qrc_map.cpp: ../plugins/feature/vorlocalizer/map/antenna.png
plugins/feature/vorlocalizer/vorlocalizer_autogen/EWIEGA46WW/qrc_map.cpp: /usr/lib/qt5/bin/rcc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic RCC for map.qrc"
	cd /opt/build/RPX-100-SDR/build/plugins/feature/vorlocalizer && /home/bernhard/Qt/Tools/CMake/bin/cmake -E cmake_autorcc /opt/build/RPX-100-SDR/build/plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer_autogen.dir/AutoRcc_map_EWIEGA46WW_Info.json RelWithDebInfo

plugins/feature/vorlocalizer/vorlocalizer_autogen/EWIEGA46WW/qrc_icons.cpp: ../plugins/feature/vorlocalizer/icons.qrc
plugins/feature/vorlocalizer/vorlocalizer_autogen/EWIEGA46WW/qrc_icons.cpp: plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer_autogen.dir/AutoRcc_icons_EWIEGA46WW_Info.json
plugins/feature/vorlocalizer/vorlocalizer_autogen/EWIEGA46WW/qrc_icons.cpp: ../plugins/feature/vorlocalizer/icons/vor.png
plugins/feature/vorlocalizer/vorlocalizer_autogen/EWIEGA46WW/qrc_icons.cpp: ../plugins/feature/vorlocalizer/icons/compass.png
plugins/feature/vorlocalizer/vorlocalizer_autogen/EWIEGA46WW/qrc_icons.cpp: /usr/lib/qt5/bin/rcc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Automatic RCC for icons.qrc"
	cd /opt/build/RPX-100-SDR/build/plugins/feature/vorlocalizer && /home/bernhard/Qt/Tools/CMake/bin/cmake -E cmake_autorcc /opt/build/RPX-100-SDR/build/plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer_autogen.dir/AutoRcc_icons_EWIEGA46WW_Info.json RelWithDebInfo

plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizer_autogen/mocs_compilation.cpp.o: plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/flags.make
plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizer_autogen/mocs_compilation.cpp.o: plugins/feature/vorlocalizer/vorlocalizer_autogen/mocs_compilation.cpp
plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizer_autogen/mocs_compilation.cpp.o: plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizer_autogen/mocs_compilation.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/feature/vorlocalizer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizer_autogen/mocs_compilation.cpp.o -MF CMakeFiles/vorlocalizer.dir/vorlocalizer_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/vorlocalizer.dir/vorlocalizer_autogen/mocs_compilation.cpp.o -c /opt/build/RPX-100-SDR/build/plugins/feature/vorlocalizer/vorlocalizer_autogen/mocs_compilation.cpp

plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizer_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vorlocalizer.dir/vorlocalizer_autogen/mocs_compilation.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/feature/vorlocalizer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/build/plugins/feature/vorlocalizer/vorlocalizer_autogen/mocs_compilation.cpp > CMakeFiles/vorlocalizer.dir/vorlocalizer_autogen/mocs_compilation.cpp.i

plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizer_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vorlocalizer.dir/vorlocalizer_autogen/mocs_compilation.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/feature/vorlocalizer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/build/plugins/feature/vorlocalizer/vorlocalizer_autogen/mocs_compilation.cpp -o CMakeFiles/vorlocalizer.dir/vorlocalizer_autogen/mocs_compilation.cpp.s

plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizer.cpp.o: plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/flags.make
plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizer.cpp.o: ../plugins/feature/vorlocalizer/vorlocalizer.cpp
plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizer.cpp.o: plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizer.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/feature/vorlocalizer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizer.cpp.o -MF CMakeFiles/vorlocalizer.dir/vorlocalizer.cpp.o.d -o CMakeFiles/vorlocalizer.dir/vorlocalizer.cpp.o -c /opt/build/RPX-100-SDR/plugins/feature/vorlocalizer/vorlocalizer.cpp

plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vorlocalizer.dir/vorlocalizer.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/feature/vorlocalizer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/feature/vorlocalizer/vorlocalizer.cpp > CMakeFiles/vorlocalizer.dir/vorlocalizer.cpp.i

plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vorlocalizer.dir/vorlocalizer.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/feature/vorlocalizer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/feature/vorlocalizer/vorlocalizer.cpp -o CMakeFiles/vorlocalizer.dir/vorlocalizer.cpp.s

plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizersettings.cpp.o: plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/flags.make
plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizersettings.cpp.o: ../plugins/feature/vorlocalizer/vorlocalizersettings.cpp
plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizersettings.cpp.o: plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizersettings.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/feature/vorlocalizer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizersettings.cpp.o -MF CMakeFiles/vorlocalizer.dir/vorlocalizersettings.cpp.o.d -o CMakeFiles/vorlocalizer.dir/vorlocalizersettings.cpp.o -c /opt/build/RPX-100-SDR/plugins/feature/vorlocalizer/vorlocalizersettings.cpp

plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizersettings.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vorlocalizer.dir/vorlocalizersettings.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/feature/vorlocalizer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/feature/vorlocalizer/vorlocalizersettings.cpp > CMakeFiles/vorlocalizer.dir/vorlocalizersettings.cpp.i

plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizersettings.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vorlocalizer.dir/vorlocalizersettings.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/feature/vorlocalizer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/feature/vorlocalizer/vorlocalizersettings.cpp -o CMakeFiles/vorlocalizer.dir/vorlocalizersettings.cpp.s

plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizerworker.cpp.o: plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/flags.make
plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizerworker.cpp.o: ../plugins/feature/vorlocalizer/vorlocalizerworker.cpp
plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizerworker.cpp.o: plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizerworker.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/feature/vorlocalizer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizerworker.cpp.o -MF CMakeFiles/vorlocalizer.dir/vorlocalizerworker.cpp.o.d -o CMakeFiles/vorlocalizer.dir/vorlocalizerworker.cpp.o -c /opt/build/RPX-100-SDR/plugins/feature/vorlocalizer/vorlocalizerworker.cpp

plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizerworker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vorlocalizer.dir/vorlocalizerworker.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/feature/vorlocalizer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/feature/vorlocalizer/vorlocalizerworker.cpp > CMakeFiles/vorlocalizer.dir/vorlocalizerworker.cpp.i

plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizerworker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vorlocalizer.dir/vorlocalizerworker.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/feature/vorlocalizer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/feature/vorlocalizer/vorlocalizerworker.cpp -o CMakeFiles/vorlocalizer.dir/vorlocalizerworker.cpp.s

plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizerplugin.cpp.o: plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/flags.make
plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizerplugin.cpp.o: ../plugins/feature/vorlocalizer/vorlocalizerplugin.cpp
plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizerplugin.cpp.o: plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizerplugin.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/feature/vorlocalizer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizerplugin.cpp.o -MF CMakeFiles/vorlocalizer.dir/vorlocalizerplugin.cpp.o.d -o CMakeFiles/vorlocalizer.dir/vorlocalizerplugin.cpp.o -c /opt/build/RPX-100-SDR/plugins/feature/vorlocalizer/vorlocalizerplugin.cpp

plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizerplugin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vorlocalizer.dir/vorlocalizerplugin.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/feature/vorlocalizer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/feature/vorlocalizer/vorlocalizerplugin.cpp > CMakeFiles/vorlocalizer.dir/vorlocalizerplugin.cpp.i

plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizerplugin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vorlocalizer.dir/vorlocalizerplugin.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/feature/vorlocalizer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/feature/vorlocalizer/vorlocalizerplugin.cpp -o CMakeFiles/vorlocalizer.dir/vorlocalizerplugin.cpp.s

plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizerwebapiadapter.cpp.o: plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/flags.make
plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizerwebapiadapter.cpp.o: ../plugins/feature/vorlocalizer/vorlocalizerwebapiadapter.cpp
plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizerwebapiadapter.cpp.o: plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizerwebapiadapter.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/feature/vorlocalizer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizerwebapiadapter.cpp.o -MF CMakeFiles/vorlocalizer.dir/vorlocalizerwebapiadapter.cpp.o.d -o CMakeFiles/vorlocalizer.dir/vorlocalizerwebapiadapter.cpp.o -c /opt/build/RPX-100-SDR/plugins/feature/vorlocalizer/vorlocalizerwebapiadapter.cpp

plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizerwebapiadapter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vorlocalizer.dir/vorlocalizerwebapiadapter.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/feature/vorlocalizer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/feature/vorlocalizer/vorlocalizerwebapiadapter.cpp > CMakeFiles/vorlocalizer.dir/vorlocalizerwebapiadapter.cpp.i

plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizerwebapiadapter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vorlocalizer.dir/vorlocalizerwebapiadapter.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/feature/vorlocalizer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/feature/vorlocalizer/vorlocalizerwebapiadapter.cpp -o CMakeFiles/vorlocalizer.dir/vorlocalizerwebapiadapter.cpp.s

plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizerreport.cpp.o: plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/flags.make
plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizerreport.cpp.o: ../plugins/feature/vorlocalizer/vorlocalizerreport.cpp
plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizerreport.cpp.o: plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizerreport.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/feature/vorlocalizer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizerreport.cpp.o -MF CMakeFiles/vorlocalizer.dir/vorlocalizerreport.cpp.o.d -o CMakeFiles/vorlocalizer.dir/vorlocalizerreport.cpp.o -c /opt/build/RPX-100-SDR/plugins/feature/vorlocalizer/vorlocalizerreport.cpp

plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizerreport.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vorlocalizer.dir/vorlocalizerreport.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/feature/vorlocalizer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/feature/vorlocalizer/vorlocalizerreport.cpp > CMakeFiles/vorlocalizer.dir/vorlocalizerreport.cpp.i

plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizerreport.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vorlocalizer.dir/vorlocalizerreport.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/feature/vorlocalizer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/feature/vorlocalizer/vorlocalizerreport.cpp -o CMakeFiles/vorlocalizer.dir/vorlocalizerreport.cpp.s

plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizergui.cpp.o: plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/flags.make
plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizergui.cpp.o: ../plugins/feature/vorlocalizer/vorlocalizergui.cpp
plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizergui.cpp.o: plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizergui.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/feature/vorlocalizer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizergui.cpp.o -MF CMakeFiles/vorlocalizer.dir/vorlocalizergui.cpp.o.d -o CMakeFiles/vorlocalizer.dir/vorlocalizergui.cpp.o -c /opt/build/RPX-100-SDR/plugins/feature/vorlocalizer/vorlocalizergui.cpp

plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizergui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vorlocalizer.dir/vorlocalizergui.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/feature/vorlocalizer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/plugins/feature/vorlocalizer/vorlocalizergui.cpp > CMakeFiles/vorlocalizer.dir/vorlocalizergui.cpp.i

plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizergui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vorlocalizer.dir/vorlocalizergui.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/feature/vorlocalizer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/plugins/feature/vorlocalizer/vorlocalizergui.cpp -o CMakeFiles/vorlocalizer.dir/vorlocalizergui.cpp.s

plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizer_autogen/EWIEGA46WW/qrc_map.cpp.o: plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/flags.make
plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizer_autogen/EWIEGA46WW/qrc_map.cpp.o: plugins/feature/vorlocalizer/vorlocalizer_autogen/EWIEGA46WW/qrc_map.cpp
plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizer_autogen/EWIEGA46WW/qrc_map.cpp.o: plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizer_autogen/EWIEGA46WW/qrc_map.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/feature/vorlocalizer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizer_autogen/EWIEGA46WW/qrc_map.cpp.o -MF CMakeFiles/vorlocalizer.dir/vorlocalizer_autogen/EWIEGA46WW/qrc_map.cpp.o.d -o CMakeFiles/vorlocalizer.dir/vorlocalizer_autogen/EWIEGA46WW/qrc_map.cpp.o -c /opt/build/RPX-100-SDR/build/plugins/feature/vorlocalizer/vorlocalizer_autogen/EWIEGA46WW/qrc_map.cpp

plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizer_autogen/EWIEGA46WW/qrc_map.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vorlocalizer.dir/vorlocalizer_autogen/EWIEGA46WW/qrc_map.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/feature/vorlocalizer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/build/plugins/feature/vorlocalizer/vorlocalizer_autogen/EWIEGA46WW/qrc_map.cpp > CMakeFiles/vorlocalizer.dir/vorlocalizer_autogen/EWIEGA46WW/qrc_map.cpp.i

plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizer_autogen/EWIEGA46WW/qrc_map.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vorlocalizer.dir/vorlocalizer_autogen/EWIEGA46WW/qrc_map.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/feature/vorlocalizer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/build/plugins/feature/vorlocalizer/vorlocalizer_autogen/EWIEGA46WW/qrc_map.cpp -o CMakeFiles/vorlocalizer.dir/vorlocalizer_autogen/EWIEGA46WW/qrc_map.cpp.s

plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizer_autogen/EWIEGA46WW/qrc_icons.cpp.o: plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/flags.make
plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizer_autogen/EWIEGA46WW/qrc_icons.cpp.o: plugins/feature/vorlocalizer/vorlocalizer_autogen/EWIEGA46WW/qrc_icons.cpp
plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizer_autogen/EWIEGA46WW/qrc_icons.cpp.o: plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizer_autogen/EWIEGA46WW/qrc_icons.cpp.o"
	cd /opt/build/RPX-100-SDR/build/plugins/feature/vorlocalizer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizer_autogen/EWIEGA46WW/qrc_icons.cpp.o -MF CMakeFiles/vorlocalizer.dir/vorlocalizer_autogen/EWIEGA46WW/qrc_icons.cpp.o.d -o CMakeFiles/vorlocalizer.dir/vorlocalizer_autogen/EWIEGA46WW/qrc_icons.cpp.o -c /opt/build/RPX-100-SDR/build/plugins/feature/vorlocalizer/vorlocalizer_autogen/EWIEGA46WW/qrc_icons.cpp

plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizer_autogen/EWIEGA46WW/qrc_icons.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vorlocalizer.dir/vorlocalizer_autogen/EWIEGA46WW/qrc_icons.cpp.i"
	cd /opt/build/RPX-100-SDR/build/plugins/feature/vorlocalizer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/build/plugins/feature/vorlocalizer/vorlocalizer_autogen/EWIEGA46WW/qrc_icons.cpp > CMakeFiles/vorlocalizer.dir/vorlocalizer_autogen/EWIEGA46WW/qrc_icons.cpp.i

plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizer_autogen/EWIEGA46WW/qrc_icons.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vorlocalizer.dir/vorlocalizer_autogen/EWIEGA46WW/qrc_icons.cpp.s"
	cd /opt/build/RPX-100-SDR/build/plugins/feature/vorlocalizer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/build/plugins/feature/vorlocalizer/vorlocalizer_autogen/EWIEGA46WW/qrc_icons.cpp -o CMakeFiles/vorlocalizer.dir/vorlocalizer_autogen/EWIEGA46WW/qrc_icons.cpp.s

# Object files for target vorlocalizer
vorlocalizer_OBJECTS = \
"CMakeFiles/vorlocalizer.dir/vorlocalizer_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/vorlocalizer.dir/vorlocalizer.cpp.o" \
"CMakeFiles/vorlocalizer.dir/vorlocalizersettings.cpp.o" \
"CMakeFiles/vorlocalizer.dir/vorlocalizerworker.cpp.o" \
"CMakeFiles/vorlocalizer.dir/vorlocalizerplugin.cpp.o" \
"CMakeFiles/vorlocalizer.dir/vorlocalizerwebapiadapter.cpp.o" \
"CMakeFiles/vorlocalizer.dir/vorlocalizerreport.cpp.o" \
"CMakeFiles/vorlocalizer.dir/vorlocalizergui.cpp.o" \
"CMakeFiles/vorlocalizer.dir/vorlocalizer_autogen/EWIEGA46WW/qrc_map.cpp.o" \
"CMakeFiles/vorlocalizer.dir/vorlocalizer_autogen/EWIEGA46WW/qrc_icons.cpp.o"

# External object files for target vorlocalizer
vorlocalizer_EXTERNAL_OBJECTS =

lib/plugins/libvorlocalizer.so: plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizer_autogen/mocs_compilation.cpp.o
lib/plugins/libvorlocalizer.so: plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizer.cpp.o
lib/plugins/libvorlocalizer.so: plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizersettings.cpp.o
lib/plugins/libvorlocalizer.so: plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizerworker.cpp.o
lib/plugins/libvorlocalizer.so: plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizerplugin.cpp.o
lib/plugins/libvorlocalizer.so: plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizerwebapiadapter.cpp.o
lib/plugins/libvorlocalizer.so: plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizerreport.cpp.o
lib/plugins/libvorlocalizer.so: plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizergui.cpp.o
lib/plugins/libvorlocalizer.so: plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizer_autogen/EWIEGA46WW/qrc_map.cpp.o
lib/plugins/libvorlocalizer.so: plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/vorlocalizer_autogen/EWIEGA46WW/qrc_icons.cpp.o
lib/plugins/libvorlocalizer.so: plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/build.make
lib/plugins/libvorlocalizer.so: /usr/lib/x86_64-linux-gnu/libQt5QuickWidgets.so.5.15.2
lib/plugins/libvorlocalizer.so: /usr/lib/x86_64-linux-gnu/libQt5Positioning.so.5.15.2
lib/plugins/libvorlocalizer.so: lib/libsdrgui.so
lib/plugins/libvorlocalizer.so: /usr/lib/x86_64-linux-gnu/libQt5Quick.so.5.15.2
lib/plugins/libvorlocalizer.so: /usr/lib/x86_64-linux-gnu/libQt5QmlModels.so.5.15.2
lib/plugins/libvorlocalizer.so: /usr/lib/x86_64-linux-gnu/libQt5Qml.so.5.15.2
lib/plugins/libvorlocalizer.so: lib/libsdrbase.so
lib/plugins/libvorlocalizer.so: /usr/lib/x86_64-linux-gnu/libopus.so
lib/plugins/libvorlocalizer.so: /usr/lib/x86_64-linux-gnu/libm.so
lib/plugins/libvorlocalizer.so: /usr/lib/x86_64-linux-gnu/libfftw3f.so
lib/plugins/libvorlocalizer.so: /opt/install/serialdv/lib/libserialdv.so
lib/plugins/libvorlocalizer.so: /usr/lib/x86_64-linux-gnu/libQt5WebSockets.so.5.15.2
lib/plugins/libvorlocalizer.so: lib/libhttpserver.so
lib/plugins/libvorlocalizer.so: lib/libqrtplib.so
lib/plugins/libvorlocalizer.so: lib/libswagger.so
lib/plugins/libvorlocalizer.so: /usr/lib/x86_64-linux-gnu/libQt5Multimedia.so.5.15.2
lib/plugins/libvorlocalizer.so: lib/liblogging.so
lib/plugins/libvorlocalizer.so: /usr/lib/x86_64-linux-gnu/libQt5Network.so.5.15.2
lib/plugins/libvorlocalizer.so: /usr/lib/x86_64-linux-gnu/libQt5OpenGL.so.5.15.2
lib/plugins/libvorlocalizer.so: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.15.2
lib/plugins/libvorlocalizer.so: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.15.2
lib/plugins/libvorlocalizer.so: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.15.2
lib/plugins/libvorlocalizer.so: /usr/lib/x86_64-linux-gnu/libGL.so
lib/plugins/libvorlocalizer.so: /usr/lib/x86_64-linux-gnu/libGLU.so
lib/plugins/libvorlocalizer.so: /opt/install/LimeSuite/lib/libLimeSuite.so
lib/plugins/libvorlocalizer.so: plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX shared library ../../../lib/plugins/libvorlocalizer.so"
	cd /opt/build/RPX-100-SDR/build/plugins/feature/vorlocalizer && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/vorlocalizer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/build: lib/plugins/libvorlocalizer.so
.PHONY : plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/build

plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/clean:
	cd /opt/build/RPX-100-SDR/build/plugins/feature/vorlocalizer && $(CMAKE_COMMAND) -P CMakeFiles/vorlocalizer.dir/cmake_clean.cmake
.PHONY : plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/clean

plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/depend: plugins/feature/vorlocalizer/vorlocalizer_autogen/EWIEGA46WW/qrc_icons.cpp
plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/depend: plugins/feature/vorlocalizer/vorlocalizer_autogen/EWIEGA46WW/qrc_map.cpp
	cd /opt/build/RPX-100-SDR/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /opt/build/RPX-100-SDR /opt/build/RPX-100-SDR/plugins/feature/vorlocalizer /opt/build/RPX-100-SDR/build /opt/build/RPX-100-SDR/build/plugins/feature/vorlocalizer /opt/build/RPX-100-SDR/build/plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : plugins/feature/vorlocalizer/CMakeFiles/vorlocalizer.dir/depend
