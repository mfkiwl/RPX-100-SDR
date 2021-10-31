# Install script for directory: /opt/build/RPX-100-SDR/plugins/channeltx

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

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/opt/build/RPX-100-SDR/build/pluginssrv/channeltx/modais/cmake_install.cmake")
  include("/opt/build/RPX-100-SDR/build/pluginssrv/channeltx/modam/cmake_install.cmake")
  include("/opt/build/RPX-100-SDR/build/pluginssrv/channeltx/modchirpchat/cmake_install.cmake")
  include("/opt/build/RPX-100-SDR/build/pluginssrv/channeltx/modnfm/cmake_install.cmake")
  include("/opt/build/RPX-100-SDR/build/pluginssrv/channeltx/modssb/cmake_install.cmake")
  include("/opt/build/RPX-100-SDR/build/pluginssrv/channeltx/modwfm/cmake_install.cmake")
  include("/opt/build/RPX-100-SDR/build/pluginssrv/channeltx/modpacket/cmake_install.cmake")
  include("/opt/build/RPX-100-SDR/build/pluginssrv/channeltx/mod802.15.4/cmake_install.cmake")
  include("/opt/build/RPX-100-SDR/build/pluginssrv/channeltx/udpsource/cmake_install.cmake")
  include("/opt/build/RPX-100-SDR/build/pluginssrv/channeltx/localsource/cmake_install.cmake")
  include("/opt/build/RPX-100-SDR/build/pluginssrv/channeltx/filesource/cmake_install.cmake")
  include("/opt/build/RPX-100-SDR/build/pluginssrv/channeltx/remotesource/cmake_install.cmake")
  include("/opt/build/RPX-100-SDR/build/pluginssrv/channeltx/modatv/cmake_install.cmake")
  include("/opt/build/RPX-100-SDR/build/pluginssrv/channeltx/moddatv/cmake_install.cmake")
  include("/opt/build/RPX-100-SDR/build/pluginssrv/channeltx/modfreedv/cmake_install.cmake")

endif()

