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
include fcdhid/CMakeFiles/fcdhid.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include fcdhid/CMakeFiles/fcdhid.dir/compiler_depend.make

# Include the progress variables for this target.
include fcdhid/CMakeFiles/fcdhid.dir/progress.make

# Include the compile flags for this target's objects.
include fcdhid/CMakeFiles/fcdhid.dir/flags.make

fcdhid/CMakeFiles/fcdhid.dir/fcdhid_autogen/mocs_compilation.cpp.o: fcdhid/CMakeFiles/fcdhid.dir/flags.make
fcdhid/CMakeFiles/fcdhid.dir/fcdhid_autogen/mocs_compilation.cpp.o: fcdhid/fcdhid_autogen/mocs_compilation.cpp
fcdhid/CMakeFiles/fcdhid.dir/fcdhid_autogen/mocs_compilation.cpp.o: fcdhid/CMakeFiles/fcdhid.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object fcdhid/CMakeFiles/fcdhid.dir/fcdhid_autogen/mocs_compilation.cpp.o"
	cd /opt/build/RPX-100-SDR/build/fcdhid && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT fcdhid/CMakeFiles/fcdhid.dir/fcdhid_autogen/mocs_compilation.cpp.o -MF CMakeFiles/fcdhid.dir/fcdhid_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/fcdhid.dir/fcdhid_autogen/mocs_compilation.cpp.o -c /opt/build/RPX-100-SDR/build/fcdhid/fcdhid_autogen/mocs_compilation.cpp

fcdhid/CMakeFiles/fcdhid.dir/fcdhid_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fcdhid.dir/fcdhid_autogen/mocs_compilation.cpp.i"
	cd /opt/build/RPX-100-SDR/build/fcdhid && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/build/fcdhid/fcdhid_autogen/mocs_compilation.cpp > CMakeFiles/fcdhid.dir/fcdhid_autogen/mocs_compilation.cpp.i

fcdhid/CMakeFiles/fcdhid.dir/fcdhid_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fcdhid.dir/fcdhid_autogen/mocs_compilation.cpp.s"
	cd /opt/build/RPX-100-SDR/build/fcdhid && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/build/fcdhid/fcdhid_autogen/mocs_compilation.cpp -o CMakeFiles/fcdhid.dir/fcdhid_autogen/mocs_compilation.cpp.s

fcdhid/CMakeFiles/fcdhid.dir/__/custom/apple/apple_compat.c.o: fcdhid/CMakeFiles/fcdhid.dir/flags.make
fcdhid/CMakeFiles/fcdhid.dir/__/custom/apple/apple_compat.c.o: ../custom/apple/apple_compat.c
fcdhid/CMakeFiles/fcdhid.dir/__/custom/apple/apple_compat.c.o: fcdhid/CMakeFiles/fcdhid.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object fcdhid/CMakeFiles/fcdhid.dir/__/custom/apple/apple_compat.c.o"
	cd /opt/build/RPX-100-SDR/build/fcdhid && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT fcdhid/CMakeFiles/fcdhid.dir/__/custom/apple/apple_compat.c.o -MF CMakeFiles/fcdhid.dir/__/custom/apple/apple_compat.c.o.d -o CMakeFiles/fcdhid.dir/__/custom/apple/apple_compat.c.o -c /opt/build/RPX-100-SDR/custom/apple/apple_compat.c

fcdhid/CMakeFiles/fcdhid.dir/__/custom/apple/apple_compat.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/fcdhid.dir/__/custom/apple/apple_compat.c.i"
	cd /opt/build/RPX-100-SDR/build/fcdhid && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /opt/build/RPX-100-SDR/custom/apple/apple_compat.c > CMakeFiles/fcdhid.dir/__/custom/apple/apple_compat.c.i

fcdhid/CMakeFiles/fcdhid.dir/__/custom/apple/apple_compat.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/fcdhid.dir/__/custom/apple/apple_compat.c.s"
	cd /opt/build/RPX-100-SDR/build/fcdhid && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /opt/build/RPX-100-SDR/custom/apple/apple_compat.c -o CMakeFiles/fcdhid.dir/__/custom/apple/apple_compat.c.s

fcdhid/CMakeFiles/fcdhid.dir/hid-libusb.c.o: fcdhid/CMakeFiles/fcdhid.dir/flags.make
fcdhid/CMakeFiles/fcdhid.dir/hid-libusb.c.o: ../fcdhid/hid-libusb.c
fcdhid/CMakeFiles/fcdhid.dir/hid-libusb.c.o: fcdhid/CMakeFiles/fcdhid.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object fcdhid/CMakeFiles/fcdhid.dir/hid-libusb.c.o"
	cd /opt/build/RPX-100-SDR/build/fcdhid && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT fcdhid/CMakeFiles/fcdhid.dir/hid-libusb.c.o -MF CMakeFiles/fcdhid.dir/hid-libusb.c.o.d -o CMakeFiles/fcdhid.dir/hid-libusb.c.o -c /opt/build/RPX-100-SDR/fcdhid/hid-libusb.c

fcdhid/CMakeFiles/fcdhid.dir/hid-libusb.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/fcdhid.dir/hid-libusb.c.i"
	cd /opt/build/RPX-100-SDR/build/fcdhid && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /opt/build/RPX-100-SDR/fcdhid/hid-libusb.c > CMakeFiles/fcdhid.dir/hid-libusb.c.i

fcdhid/CMakeFiles/fcdhid.dir/hid-libusb.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/fcdhid.dir/hid-libusb.c.s"
	cd /opt/build/RPX-100-SDR/build/fcdhid && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /opt/build/RPX-100-SDR/fcdhid/hid-libusb.c -o CMakeFiles/fcdhid.dir/hid-libusb.c.s

fcdhid/CMakeFiles/fcdhid.dir/fcdhid.c.o: fcdhid/CMakeFiles/fcdhid.dir/flags.make
fcdhid/CMakeFiles/fcdhid.dir/fcdhid.c.o: ../fcdhid/fcdhid.c
fcdhid/CMakeFiles/fcdhid.dir/fcdhid.c.o: fcdhid/CMakeFiles/fcdhid.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object fcdhid/CMakeFiles/fcdhid.dir/fcdhid.c.o"
	cd /opt/build/RPX-100-SDR/build/fcdhid && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT fcdhid/CMakeFiles/fcdhid.dir/fcdhid.c.o -MF CMakeFiles/fcdhid.dir/fcdhid.c.o.d -o CMakeFiles/fcdhid.dir/fcdhid.c.o -c /opt/build/RPX-100-SDR/fcdhid/fcdhid.c

fcdhid/CMakeFiles/fcdhid.dir/fcdhid.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/fcdhid.dir/fcdhid.c.i"
	cd /opt/build/RPX-100-SDR/build/fcdhid && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /opt/build/RPX-100-SDR/fcdhid/fcdhid.c > CMakeFiles/fcdhid.dir/fcdhid.c.i

fcdhid/CMakeFiles/fcdhid.dir/fcdhid.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/fcdhid.dir/fcdhid.c.s"
	cd /opt/build/RPX-100-SDR/build/fcdhid && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /opt/build/RPX-100-SDR/fcdhid/fcdhid.c -o CMakeFiles/fcdhid.dir/fcdhid.c.s

# Object files for target fcdhid
fcdhid_OBJECTS = \
"CMakeFiles/fcdhid.dir/fcdhid_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/fcdhid.dir/__/custom/apple/apple_compat.c.o" \
"CMakeFiles/fcdhid.dir/hid-libusb.c.o" \
"CMakeFiles/fcdhid.dir/fcdhid.c.o"

# External object files for target fcdhid
fcdhid_EXTERNAL_OBJECTS =

lib/libfcdhid.so: fcdhid/CMakeFiles/fcdhid.dir/fcdhid_autogen/mocs_compilation.cpp.o
lib/libfcdhid.so: fcdhid/CMakeFiles/fcdhid.dir/__/custom/apple/apple_compat.c.o
lib/libfcdhid.so: fcdhid/CMakeFiles/fcdhid.dir/hid-libusb.c.o
lib/libfcdhid.so: fcdhid/CMakeFiles/fcdhid.dir/fcdhid.c.o
lib/libfcdhid.so: fcdhid/CMakeFiles/fcdhid.dir/build.make
lib/libfcdhid.so: /usr/lib/x86_64-linux-gnu/libusb-1.0.so
lib/libfcdhid.so: fcdhid/CMakeFiles/fcdhid.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX shared library ../lib/libfcdhid.so"
	cd /opt/build/RPX-100-SDR/build/fcdhid && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fcdhid.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
fcdhid/CMakeFiles/fcdhid.dir/build: lib/libfcdhid.so
.PHONY : fcdhid/CMakeFiles/fcdhid.dir/build

fcdhid/CMakeFiles/fcdhid.dir/clean:
	cd /opt/build/RPX-100-SDR/build/fcdhid && $(CMAKE_COMMAND) -P CMakeFiles/fcdhid.dir/cmake_clean.cmake
.PHONY : fcdhid/CMakeFiles/fcdhid.dir/clean

fcdhid/CMakeFiles/fcdhid.dir/depend:
	cd /opt/build/RPX-100-SDR/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /opt/build/RPX-100-SDR /opt/build/RPX-100-SDR/fcdhid /opt/build/RPX-100-SDR/build /opt/build/RPX-100-SDR/build/fcdhid /opt/build/RPX-100-SDR/build/fcdhid/CMakeFiles/fcdhid.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : fcdhid/CMakeFiles/fcdhid.dir/depend

