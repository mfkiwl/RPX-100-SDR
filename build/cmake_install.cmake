# Install script for directory: /opt/build/RPX-100-SDR

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/opt/install/RPX-100-SDR ..")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "RelWithDebInfo")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/RPX100bench" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/RPX100bench")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/RPX100bench"
         RPATH "/opt/install/RPX-100-SDR ../lib/RPX100:/opt/install/serialdv/lib:/opt/install/LimeSuite/lib")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/opt/build/RPX-100-SDR/build/RPX100bench")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/RPX100bench" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/RPX100bench")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/RPX100bench"
         OLD_RPATH "/opt/build/RPX-100-SDR/build/lib:/opt/install/serialdv/lib:/opt/install/LimeSuite/lib::::::"
         NEW_RPATH "/opt/install/RPX-100-SDR ../lib/RPX100:/opt/install/serialdv/lib:/opt/install/LimeSuite/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/RPX100bench")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/RPX100" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/RPX100")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/RPX100"
         RPATH "/opt/install/RPX-100-SDR ../lib/RPX100:/opt/install/serialdv/lib:/opt/install/LimeSuite/lib")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/opt/build/RPX-100-SDR/build/RPX100")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/RPX100" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/RPX100")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/RPX100"
         OLD_RPATH "/opt/build/RPX-100-SDR/build/lib:/opt/install/serialdv/lib:/opt/install/LimeSuite/lib::::::"
         NEW_RPATH "/opt/install/RPX-100-SDR ../lib/RPX100:/opt/install/serialdv/lib:/opt/install/LimeSuite/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/RPX100")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/RPX100srv" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/RPX100srv")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/RPX100srv"
         RPATH "/opt/install/RPX-100-SDR ../lib/RPX100:/opt/install/serialdv/lib:/opt/install/LimeSuite/lib")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/opt/build/RPX-100-SDR/build/RPX100srv")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/RPX100srv" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/RPX100srv")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/RPX100srv"
         OLD_RPATH "/opt/build/RPX-100-SDR/build/lib:/opt/install/serialdv/lib:/opt/install/LimeSuite/lib::::::"
         NEW_RPATH "/opt/install/RPX-100-SDR ../lib/RPX100:/opt/install/serialdv/lib:/opt/install/LimeSuite/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/RPX100srv")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/RPX100" TYPE FILE FILES "/opt/build/RPX-100-SDR/Readme.md")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/applications" TYPE FILE FILES "/opt/build/RPX-100-SDR/build/RPX100.desktop")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/icons/hicolor/scalable/apps" TYPE FILE FILES "/opt/build/RPX-100-SDR/cmake/cpack/RPX100_icon.svg")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/opt/build/RPX-100-SDR/build/fcdlib/cmake_install.cmake")
  include("/opt/build/RPX-100-SDR/build/fcdhid/cmake_install.cmake")
  include("/opt/build/RPX-100-SDR/build/sdrbase/cmake_install.cmake")
  include("/opt/build/RPX-100-SDR/build/httpserver/cmake_install.cmake")
  include("/opt/build/RPX-100-SDR/build/logging/cmake_install.cmake")
  include("/opt/build/RPX-100-SDR/build/qrtplib/cmake_install.cmake")
  include("/opt/build/RPX-100-SDR/build/swagger/cmake_install.cmake")
  include("/opt/build/RPX-100-SDR/build/devices/cmake_install.cmake")
  include("/opt/build/RPX-100-SDR/build/sdrbench/cmake_install.cmake")
  include("/opt/build/RPX-100-SDR/build/sdrgui/cmake_install.cmake")
  include("/opt/build/RPX-100-SDR/build/plugins/cmake_install.cmake")
  include("/opt/build/RPX-100-SDR/build/sdrsrv/cmake_install.cmake")
  include("/opt/build/RPX-100-SDR/build/pluginssrv/cmake_install.cmake")
  include("/opt/build/RPX-100-SDR/build/cmake/cpack/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/opt/build/RPX-100-SDR/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
