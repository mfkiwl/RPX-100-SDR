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
include httpserver/CMakeFiles/httpserver.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include httpserver/CMakeFiles/httpserver.dir/compiler_depend.make

# Include the progress variables for this target.
include httpserver/CMakeFiles/httpserver.dir/progress.make

# Include the compile flags for this target's objects.
include httpserver/CMakeFiles/httpserver.dir/flags.make

httpserver/CMakeFiles/httpserver.dir/httpserver_autogen/mocs_compilation.cpp.o: httpserver/CMakeFiles/httpserver.dir/flags.make
httpserver/CMakeFiles/httpserver.dir/httpserver_autogen/mocs_compilation.cpp.o: httpserver/httpserver_autogen/mocs_compilation.cpp
httpserver/CMakeFiles/httpserver.dir/httpserver_autogen/mocs_compilation.cpp.o: httpserver/CMakeFiles/httpserver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object httpserver/CMakeFiles/httpserver.dir/httpserver_autogen/mocs_compilation.cpp.o"
	cd /opt/build/RPX-100-SDR/build/httpserver && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT httpserver/CMakeFiles/httpserver.dir/httpserver_autogen/mocs_compilation.cpp.o -MF CMakeFiles/httpserver.dir/httpserver_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/httpserver.dir/httpserver_autogen/mocs_compilation.cpp.o -c /opt/build/RPX-100-SDR/build/httpserver/httpserver_autogen/mocs_compilation.cpp

httpserver/CMakeFiles/httpserver.dir/httpserver_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/httpserver.dir/httpserver_autogen/mocs_compilation.cpp.i"
	cd /opt/build/RPX-100-SDR/build/httpserver && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/build/httpserver/httpserver_autogen/mocs_compilation.cpp > CMakeFiles/httpserver.dir/httpserver_autogen/mocs_compilation.cpp.i

httpserver/CMakeFiles/httpserver.dir/httpserver_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/httpserver.dir/httpserver_autogen/mocs_compilation.cpp.s"
	cd /opt/build/RPX-100-SDR/build/httpserver && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/build/httpserver/httpserver_autogen/mocs_compilation.cpp -o CMakeFiles/httpserver.dir/httpserver_autogen/mocs_compilation.cpp.s

httpserver/CMakeFiles/httpserver.dir/httpglobal.cpp.o: httpserver/CMakeFiles/httpserver.dir/flags.make
httpserver/CMakeFiles/httpserver.dir/httpglobal.cpp.o: ../httpserver/httpglobal.cpp
httpserver/CMakeFiles/httpserver.dir/httpglobal.cpp.o: httpserver/CMakeFiles/httpserver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object httpserver/CMakeFiles/httpserver.dir/httpglobal.cpp.o"
	cd /opt/build/RPX-100-SDR/build/httpserver && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT httpserver/CMakeFiles/httpserver.dir/httpglobal.cpp.o -MF CMakeFiles/httpserver.dir/httpglobal.cpp.o.d -o CMakeFiles/httpserver.dir/httpglobal.cpp.o -c /opt/build/RPX-100-SDR/httpserver/httpglobal.cpp

httpserver/CMakeFiles/httpserver.dir/httpglobal.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/httpserver.dir/httpglobal.cpp.i"
	cd /opt/build/RPX-100-SDR/build/httpserver && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/httpserver/httpglobal.cpp > CMakeFiles/httpserver.dir/httpglobal.cpp.i

httpserver/CMakeFiles/httpserver.dir/httpglobal.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/httpserver.dir/httpglobal.cpp.s"
	cd /opt/build/RPX-100-SDR/build/httpserver && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/httpserver/httpglobal.cpp -o CMakeFiles/httpserver.dir/httpglobal.cpp.s

httpserver/CMakeFiles/httpserver.dir/httplistener.cpp.o: httpserver/CMakeFiles/httpserver.dir/flags.make
httpserver/CMakeFiles/httpserver.dir/httplistener.cpp.o: ../httpserver/httplistener.cpp
httpserver/CMakeFiles/httpserver.dir/httplistener.cpp.o: httpserver/CMakeFiles/httpserver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object httpserver/CMakeFiles/httpserver.dir/httplistener.cpp.o"
	cd /opt/build/RPX-100-SDR/build/httpserver && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT httpserver/CMakeFiles/httpserver.dir/httplistener.cpp.o -MF CMakeFiles/httpserver.dir/httplistener.cpp.o.d -o CMakeFiles/httpserver.dir/httplistener.cpp.o -c /opt/build/RPX-100-SDR/httpserver/httplistener.cpp

httpserver/CMakeFiles/httpserver.dir/httplistener.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/httpserver.dir/httplistener.cpp.i"
	cd /opt/build/RPX-100-SDR/build/httpserver && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/httpserver/httplistener.cpp > CMakeFiles/httpserver.dir/httplistener.cpp.i

httpserver/CMakeFiles/httpserver.dir/httplistener.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/httpserver.dir/httplistener.cpp.s"
	cd /opt/build/RPX-100-SDR/build/httpserver && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/httpserver/httplistener.cpp -o CMakeFiles/httpserver.dir/httplistener.cpp.s

httpserver/CMakeFiles/httpserver.dir/httpconnectionhandler.cpp.o: httpserver/CMakeFiles/httpserver.dir/flags.make
httpserver/CMakeFiles/httpserver.dir/httpconnectionhandler.cpp.o: ../httpserver/httpconnectionhandler.cpp
httpserver/CMakeFiles/httpserver.dir/httpconnectionhandler.cpp.o: httpserver/CMakeFiles/httpserver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object httpserver/CMakeFiles/httpserver.dir/httpconnectionhandler.cpp.o"
	cd /opt/build/RPX-100-SDR/build/httpserver && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT httpserver/CMakeFiles/httpserver.dir/httpconnectionhandler.cpp.o -MF CMakeFiles/httpserver.dir/httpconnectionhandler.cpp.o.d -o CMakeFiles/httpserver.dir/httpconnectionhandler.cpp.o -c /opt/build/RPX-100-SDR/httpserver/httpconnectionhandler.cpp

httpserver/CMakeFiles/httpserver.dir/httpconnectionhandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/httpserver.dir/httpconnectionhandler.cpp.i"
	cd /opt/build/RPX-100-SDR/build/httpserver && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/httpserver/httpconnectionhandler.cpp > CMakeFiles/httpserver.dir/httpconnectionhandler.cpp.i

httpserver/CMakeFiles/httpserver.dir/httpconnectionhandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/httpserver.dir/httpconnectionhandler.cpp.s"
	cd /opt/build/RPX-100-SDR/build/httpserver && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/httpserver/httpconnectionhandler.cpp -o CMakeFiles/httpserver.dir/httpconnectionhandler.cpp.s

httpserver/CMakeFiles/httpserver.dir/httpconnectionhandlerpool.cpp.o: httpserver/CMakeFiles/httpserver.dir/flags.make
httpserver/CMakeFiles/httpserver.dir/httpconnectionhandlerpool.cpp.o: ../httpserver/httpconnectionhandlerpool.cpp
httpserver/CMakeFiles/httpserver.dir/httpconnectionhandlerpool.cpp.o: httpserver/CMakeFiles/httpserver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object httpserver/CMakeFiles/httpserver.dir/httpconnectionhandlerpool.cpp.o"
	cd /opt/build/RPX-100-SDR/build/httpserver && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT httpserver/CMakeFiles/httpserver.dir/httpconnectionhandlerpool.cpp.o -MF CMakeFiles/httpserver.dir/httpconnectionhandlerpool.cpp.o.d -o CMakeFiles/httpserver.dir/httpconnectionhandlerpool.cpp.o -c /opt/build/RPX-100-SDR/httpserver/httpconnectionhandlerpool.cpp

httpserver/CMakeFiles/httpserver.dir/httpconnectionhandlerpool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/httpserver.dir/httpconnectionhandlerpool.cpp.i"
	cd /opt/build/RPX-100-SDR/build/httpserver && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/httpserver/httpconnectionhandlerpool.cpp > CMakeFiles/httpserver.dir/httpconnectionhandlerpool.cpp.i

httpserver/CMakeFiles/httpserver.dir/httpconnectionhandlerpool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/httpserver.dir/httpconnectionhandlerpool.cpp.s"
	cd /opt/build/RPX-100-SDR/build/httpserver && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/httpserver/httpconnectionhandlerpool.cpp -o CMakeFiles/httpserver.dir/httpconnectionhandlerpool.cpp.s

httpserver/CMakeFiles/httpserver.dir/httprequest.cpp.o: httpserver/CMakeFiles/httpserver.dir/flags.make
httpserver/CMakeFiles/httpserver.dir/httprequest.cpp.o: ../httpserver/httprequest.cpp
httpserver/CMakeFiles/httpserver.dir/httprequest.cpp.o: httpserver/CMakeFiles/httpserver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object httpserver/CMakeFiles/httpserver.dir/httprequest.cpp.o"
	cd /opt/build/RPX-100-SDR/build/httpserver && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT httpserver/CMakeFiles/httpserver.dir/httprequest.cpp.o -MF CMakeFiles/httpserver.dir/httprequest.cpp.o.d -o CMakeFiles/httpserver.dir/httprequest.cpp.o -c /opt/build/RPX-100-SDR/httpserver/httprequest.cpp

httpserver/CMakeFiles/httpserver.dir/httprequest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/httpserver.dir/httprequest.cpp.i"
	cd /opt/build/RPX-100-SDR/build/httpserver && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/httpserver/httprequest.cpp > CMakeFiles/httpserver.dir/httprequest.cpp.i

httpserver/CMakeFiles/httpserver.dir/httprequest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/httpserver.dir/httprequest.cpp.s"
	cd /opt/build/RPX-100-SDR/build/httpserver && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/httpserver/httprequest.cpp -o CMakeFiles/httpserver.dir/httprequest.cpp.s

httpserver/CMakeFiles/httpserver.dir/httpresponse.cpp.o: httpserver/CMakeFiles/httpserver.dir/flags.make
httpserver/CMakeFiles/httpserver.dir/httpresponse.cpp.o: ../httpserver/httpresponse.cpp
httpserver/CMakeFiles/httpserver.dir/httpresponse.cpp.o: httpserver/CMakeFiles/httpserver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object httpserver/CMakeFiles/httpserver.dir/httpresponse.cpp.o"
	cd /opt/build/RPX-100-SDR/build/httpserver && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT httpserver/CMakeFiles/httpserver.dir/httpresponse.cpp.o -MF CMakeFiles/httpserver.dir/httpresponse.cpp.o.d -o CMakeFiles/httpserver.dir/httpresponse.cpp.o -c /opt/build/RPX-100-SDR/httpserver/httpresponse.cpp

httpserver/CMakeFiles/httpserver.dir/httpresponse.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/httpserver.dir/httpresponse.cpp.i"
	cd /opt/build/RPX-100-SDR/build/httpserver && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/httpserver/httpresponse.cpp > CMakeFiles/httpserver.dir/httpresponse.cpp.i

httpserver/CMakeFiles/httpserver.dir/httpresponse.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/httpserver.dir/httpresponse.cpp.s"
	cd /opt/build/RPX-100-SDR/build/httpserver && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/httpserver/httpresponse.cpp -o CMakeFiles/httpserver.dir/httpresponse.cpp.s

httpserver/CMakeFiles/httpserver.dir/httpcookie.cpp.o: httpserver/CMakeFiles/httpserver.dir/flags.make
httpserver/CMakeFiles/httpserver.dir/httpcookie.cpp.o: ../httpserver/httpcookie.cpp
httpserver/CMakeFiles/httpserver.dir/httpcookie.cpp.o: httpserver/CMakeFiles/httpserver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object httpserver/CMakeFiles/httpserver.dir/httpcookie.cpp.o"
	cd /opt/build/RPX-100-SDR/build/httpserver && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT httpserver/CMakeFiles/httpserver.dir/httpcookie.cpp.o -MF CMakeFiles/httpserver.dir/httpcookie.cpp.o.d -o CMakeFiles/httpserver.dir/httpcookie.cpp.o -c /opt/build/RPX-100-SDR/httpserver/httpcookie.cpp

httpserver/CMakeFiles/httpserver.dir/httpcookie.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/httpserver.dir/httpcookie.cpp.i"
	cd /opt/build/RPX-100-SDR/build/httpserver && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/httpserver/httpcookie.cpp > CMakeFiles/httpserver.dir/httpcookie.cpp.i

httpserver/CMakeFiles/httpserver.dir/httpcookie.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/httpserver.dir/httpcookie.cpp.s"
	cd /opt/build/RPX-100-SDR/build/httpserver && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/httpserver/httpcookie.cpp -o CMakeFiles/httpserver.dir/httpcookie.cpp.s

httpserver/CMakeFiles/httpserver.dir/httprequesthandler.cpp.o: httpserver/CMakeFiles/httpserver.dir/flags.make
httpserver/CMakeFiles/httpserver.dir/httprequesthandler.cpp.o: ../httpserver/httprequesthandler.cpp
httpserver/CMakeFiles/httpserver.dir/httprequesthandler.cpp.o: httpserver/CMakeFiles/httpserver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object httpserver/CMakeFiles/httpserver.dir/httprequesthandler.cpp.o"
	cd /opt/build/RPX-100-SDR/build/httpserver && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT httpserver/CMakeFiles/httpserver.dir/httprequesthandler.cpp.o -MF CMakeFiles/httpserver.dir/httprequesthandler.cpp.o.d -o CMakeFiles/httpserver.dir/httprequesthandler.cpp.o -c /opt/build/RPX-100-SDR/httpserver/httprequesthandler.cpp

httpserver/CMakeFiles/httpserver.dir/httprequesthandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/httpserver.dir/httprequesthandler.cpp.i"
	cd /opt/build/RPX-100-SDR/build/httpserver && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/httpserver/httprequesthandler.cpp > CMakeFiles/httpserver.dir/httprequesthandler.cpp.i

httpserver/CMakeFiles/httpserver.dir/httprequesthandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/httpserver.dir/httprequesthandler.cpp.s"
	cd /opt/build/RPX-100-SDR/build/httpserver && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/httpserver/httprequesthandler.cpp -o CMakeFiles/httpserver.dir/httprequesthandler.cpp.s

httpserver/CMakeFiles/httpserver.dir/httpsession.cpp.o: httpserver/CMakeFiles/httpserver.dir/flags.make
httpserver/CMakeFiles/httpserver.dir/httpsession.cpp.o: ../httpserver/httpsession.cpp
httpserver/CMakeFiles/httpserver.dir/httpsession.cpp.o: httpserver/CMakeFiles/httpserver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object httpserver/CMakeFiles/httpserver.dir/httpsession.cpp.o"
	cd /opt/build/RPX-100-SDR/build/httpserver && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT httpserver/CMakeFiles/httpserver.dir/httpsession.cpp.o -MF CMakeFiles/httpserver.dir/httpsession.cpp.o.d -o CMakeFiles/httpserver.dir/httpsession.cpp.o -c /opt/build/RPX-100-SDR/httpserver/httpsession.cpp

httpserver/CMakeFiles/httpserver.dir/httpsession.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/httpserver.dir/httpsession.cpp.i"
	cd /opt/build/RPX-100-SDR/build/httpserver && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/httpserver/httpsession.cpp > CMakeFiles/httpserver.dir/httpsession.cpp.i

httpserver/CMakeFiles/httpserver.dir/httpsession.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/httpserver.dir/httpsession.cpp.s"
	cd /opt/build/RPX-100-SDR/build/httpserver && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/httpserver/httpsession.cpp -o CMakeFiles/httpserver.dir/httpsession.cpp.s

httpserver/CMakeFiles/httpserver.dir/httpsessionstore.cpp.o: httpserver/CMakeFiles/httpserver.dir/flags.make
httpserver/CMakeFiles/httpserver.dir/httpsessionstore.cpp.o: ../httpserver/httpsessionstore.cpp
httpserver/CMakeFiles/httpserver.dir/httpsessionstore.cpp.o: httpserver/CMakeFiles/httpserver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object httpserver/CMakeFiles/httpserver.dir/httpsessionstore.cpp.o"
	cd /opt/build/RPX-100-SDR/build/httpserver && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT httpserver/CMakeFiles/httpserver.dir/httpsessionstore.cpp.o -MF CMakeFiles/httpserver.dir/httpsessionstore.cpp.o.d -o CMakeFiles/httpserver.dir/httpsessionstore.cpp.o -c /opt/build/RPX-100-SDR/httpserver/httpsessionstore.cpp

httpserver/CMakeFiles/httpserver.dir/httpsessionstore.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/httpserver.dir/httpsessionstore.cpp.i"
	cd /opt/build/RPX-100-SDR/build/httpserver && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/httpserver/httpsessionstore.cpp > CMakeFiles/httpserver.dir/httpsessionstore.cpp.i

httpserver/CMakeFiles/httpserver.dir/httpsessionstore.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/httpserver.dir/httpsessionstore.cpp.s"
	cd /opt/build/RPX-100-SDR/build/httpserver && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/httpserver/httpsessionstore.cpp -o CMakeFiles/httpserver.dir/httpsessionstore.cpp.s

httpserver/CMakeFiles/httpserver.dir/staticfilecontroller.cpp.o: httpserver/CMakeFiles/httpserver.dir/flags.make
httpserver/CMakeFiles/httpserver.dir/staticfilecontroller.cpp.o: ../httpserver/staticfilecontroller.cpp
httpserver/CMakeFiles/httpserver.dir/staticfilecontroller.cpp.o: httpserver/CMakeFiles/httpserver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object httpserver/CMakeFiles/httpserver.dir/staticfilecontroller.cpp.o"
	cd /opt/build/RPX-100-SDR/build/httpserver && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT httpserver/CMakeFiles/httpserver.dir/staticfilecontroller.cpp.o -MF CMakeFiles/httpserver.dir/staticfilecontroller.cpp.o.d -o CMakeFiles/httpserver.dir/staticfilecontroller.cpp.o -c /opt/build/RPX-100-SDR/httpserver/staticfilecontroller.cpp

httpserver/CMakeFiles/httpserver.dir/staticfilecontroller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/httpserver.dir/staticfilecontroller.cpp.i"
	cd /opt/build/RPX-100-SDR/build/httpserver && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/build/RPX-100-SDR/httpserver/staticfilecontroller.cpp > CMakeFiles/httpserver.dir/staticfilecontroller.cpp.i

httpserver/CMakeFiles/httpserver.dir/staticfilecontroller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/httpserver.dir/staticfilecontroller.cpp.s"
	cd /opt/build/RPX-100-SDR/build/httpserver && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/build/RPX-100-SDR/httpserver/staticfilecontroller.cpp -o CMakeFiles/httpserver.dir/staticfilecontroller.cpp.s

# Object files for target httpserver
httpserver_OBJECTS = \
"CMakeFiles/httpserver.dir/httpserver_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/httpserver.dir/httpglobal.cpp.o" \
"CMakeFiles/httpserver.dir/httplistener.cpp.o" \
"CMakeFiles/httpserver.dir/httpconnectionhandler.cpp.o" \
"CMakeFiles/httpserver.dir/httpconnectionhandlerpool.cpp.o" \
"CMakeFiles/httpserver.dir/httprequest.cpp.o" \
"CMakeFiles/httpserver.dir/httpresponse.cpp.o" \
"CMakeFiles/httpserver.dir/httpcookie.cpp.o" \
"CMakeFiles/httpserver.dir/httprequesthandler.cpp.o" \
"CMakeFiles/httpserver.dir/httpsession.cpp.o" \
"CMakeFiles/httpserver.dir/httpsessionstore.cpp.o" \
"CMakeFiles/httpserver.dir/staticfilecontroller.cpp.o"

# External object files for target httpserver
httpserver_EXTERNAL_OBJECTS =

lib/libhttpserver.so: httpserver/CMakeFiles/httpserver.dir/httpserver_autogen/mocs_compilation.cpp.o
lib/libhttpserver.so: httpserver/CMakeFiles/httpserver.dir/httpglobal.cpp.o
lib/libhttpserver.so: httpserver/CMakeFiles/httpserver.dir/httplistener.cpp.o
lib/libhttpserver.so: httpserver/CMakeFiles/httpserver.dir/httpconnectionhandler.cpp.o
lib/libhttpserver.so: httpserver/CMakeFiles/httpserver.dir/httpconnectionhandlerpool.cpp.o
lib/libhttpserver.so: httpserver/CMakeFiles/httpserver.dir/httprequest.cpp.o
lib/libhttpserver.so: httpserver/CMakeFiles/httpserver.dir/httpresponse.cpp.o
lib/libhttpserver.so: httpserver/CMakeFiles/httpserver.dir/httpcookie.cpp.o
lib/libhttpserver.so: httpserver/CMakeFiles/httpserver.dir/httprequesthandler.cpp.o
lib/libhttpserver.so: httpserver/CMakeFiles/httpserver.dir/httpsession.cpp.o
lib/libhttpserver.so: httpserver/CMakeFiles/httpserver.dir/httpsessionstore.cpp.o
lib/libhttpserver.so: httpserver/CMakeFiles/httpserver.dir/staticfilecontroller.cpp.o
lib/libhttpserver.so: httpserver/CMakeFiles/httpserver.dir/build.make
lib/libhttpserver.so: /usr/lib/x86_64-linux-gnu/libQt5Network.so.5.15.2
lib/libhttpserver.so: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.15.2
lib/libhttpserver.so: httpserver/CMakeFiles/httpserver.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/opt/build/RPX-100-SDR/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX shared library ../lib/libhttpserver.so"
	cd /opt/build/RPX-100-SDR/build/httpserver && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/httpserver.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
httpserver/CMakeFiles/httpserver.dir/build: lib/libhttpserver.so
.PHONY : httpserver/CMakeFiles/httpserver.dir/build

httpserver/CMakeFiles/httpserver.dir/clean:
	cd /opt/build/RPX-100-SDR/build/httpserver && $(CMAKE_COMMAND) -P CMakeFiles/httpserver.dir/cmake_clean.cmake
.PHONY : httpserver/CMakeFiles/httpserver.dir/clean

httpserver/CMakeFiles/httpserver.dir/depend:
	cd /opt/build/RPX-100-SDR/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /opt/build/RPX-100-SDR /opt/build/RPX-100-SDR/httpserver /opt/build/RPX-100-SDR/build /opt/build/RPX-100-SDR/build/httpserver /opt/build/RPX-100-SDR/build/httpserver/CMakeFiles/httpserver.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : httpserver/CMakeFiles/httpserver.dir/depend
