# Install script for directory: /opt/build/RPX-100-SDR/plugins/channelrx

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
  include("/opt/build/RPX-100-SDR/build/plugins/channelrx/demodadsb/cmake_install.cmake")
  include("/opt/build/RPX-100-SDR/build/plugins/channelrx/demodvor/cmake_install.cmake")
  include("/opt/build/RPX-100-SDR/build/plugins/channelrx/demodam/cmake_install.cmake")
  include("/opt/build/RPX-100-SDR/build/plugins/channelrx/demodbfm/cmake_install.cmake")
  include("/opt/build/RPX-100-SDR/build/plugins/channelrx/demodnfm/cmake_install.cmake")
  include("/opt/build/RPX-100-SDR/build/plugins/channelrx/demodssb/cmake_install.cmake")
  include("/opt/build/RPX-100-SDR/build/plugins/channelrx/udpsink/cmake_install.cmake")
  include("/opt/build/RPX-100-SDR/build/plugins/channelrx/demodwfm/cmake_install.cmake")
  include("/opt/build/RPX-100-SDR/build/plugins/channelrx/localsink/cmake_install.cmake")
  include("/opt/build/RPX-100-SDR/build/plugins/channelrx/filesink/cmake_install.cmake")
  include("/opt/build/RPX-100-SDR/build/plugins/channelrx/freqtracker/cmake_install.cmake")
  include("/opt/build/RPX-100-SDR/build/plugins/channelrx/demodchirpchat/cmake_install.cmake")
  include("/opt/build/RPX-100-SDR/build/plugins/channelrx/demodvorsc/cmake_install.cmake")
  include("/opt/build/RPX-100-SDR/build/plugins/channelrx/demodpacket/cmake_install.cmake")
  include("/opt/build/RPX-100-SDR/build/plugins/channelrx/demodais/cmake_install.cmake")
  include("/opt/build/RPX-100-SDR/build/plugins/channelrx/demodpager/cmake_install.cmake")
  include("/opt/build/RPX-100-SDR/build/plugins/channelrx/radioclock/cmake_install.cmake")
  include("/opt/build/RPX-100-SDR/build/plugins/channelrx/demoddab/cmake_install.cmake")
  include("/opt/build/RPX-100-SDR/build/plugins/channelrx/demodapt/cmake_install.cmake")
  include("/opt/build/RPX-100-SDR/build/plugins/channelrx/demoddsd/cmake_install.cmake")
  include("/opt/build/RPX-100-SDR/build/plugins/channelrx/remotesink/cmake_install.cmake")
  include("/opt/build/RPX-100-SDR/build/plugins/channelrx/demodfreedv/cmake_install.cmake")
  include("/opt/build/RPX-100-SDR/build/plugins/channelrx/noisefigure/cmake_install.cmake")
  include("/opt/build/RPX-100-SDR/build/plugins/channelrx/chanalyzer/cmake_install.cmake")
  include("/opt/build/RPX-100-SDR/build/plugins/channelrx/demodatv/cmake_install.cmake")
  include("/opt/build/RPX-100-SDR/build/plugins/channelrx/demoddatv/cmake_install.cmake")

endif()

