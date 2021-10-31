# This file will be configured to contain variables for CPack. These variables
# should be set in the CMake list file of the project before CPack module is
# included. The list of available CPACK_xxx variables and their associated
# documentation may be obtained using
#  cpack --help-variable-list
#
# Some variables are common to all generators (e.g. CPACK_PACKAGE_NAME)
# and some are specific to a generator
# (e.g. CPACK_NSIS_EXTRA_INSTALL_COMMANDS). The generator specific variables
# usually begin with CPACK_<GENNAME>_xxxx.


set(CPACK_BINARY_DEB "OFF")
set(CPACK_BINARY_FREEBSD "OFF")
set(CPACK_BINARY_IFW "OFF")
set(CPACK_BINARY_NSIS "OFF")
set(CPACK_BINARY_RPM "OFF")
set(CPACK_BINARY_STGZ "ON")
set(CPACK_BINARY_TBZ2 "OFF")
set(CPACK_BINARY_TGZ "ON")
set(CPACK_BINARY_TXZ "OFF")
set(CPACK_BINARY_TZ "ON")
set(CPACK_BUILD_SOURCE_DIRS "/opt/build/RPX-100-SDR;/opt/build/RPX-100-SDR/build")
set(CPACK_CMAKE_GENERATOR "Unix Makefiles")
set(CPACK_COMPONENT_UNSPECIFIED_HIDDEN "TRUE")
set(CPACK_COMPONENT_UNSPECIFIED_REQUIRED "TRUE")
set(CPACK_DEFAULT_PACKAGE_DESCRIPTION_FILE "/home/bernhard/Qt/Tools/CMake/share/cmake-3.21/Templates/CPack.GenericDescription.txt")
set(CPACK_DEFAULT_PACKAGE_DESCRIPTION_SUMMARY "RPX100 built using CMake")
set(CPACK_GENERATOR "ZIP;TGZ")
set(CPACK_IGNORE_FILES "/opt/build/RPX-100-SDR/build;/.git/;.gitignore;menu.yml;.travis.yml;.appveyor.yml;default.nix;.envrc;TODOs.org;/.scripts/")
set(CPACK_INSTALLED_DIRECTORIES "/opt/build/RPX-100-SDR;/")
set(CPACK_INSTALL_CMAKE_PROJECTS "")
set(CPACK_INSTALL_PREFIX "/opt/install/RPX-100-SDR ..")
set(CPACK_MODULE_PATH "/opt/build/RPX-100-SDR/cmake/Modules")
set(CPACK_NSIS_DISPLAY_NAME "RPX100 6.16.5")
set(CPACK_NSIS_INSTALLER_ICON_CODE "")
set(CPACK_NSIS_INSTALLER_MUI_ICON_CODE "")
set(CPACK_NSIS_INSTALL_ROOT "$PROGRAMFILES")
set(CPACK_NSIS_PACKAGE_NAME "RPX100 6.16.5")
set(CPACK_NSIS_UNINSTALL_NAME "Uninstall")
set(CPACK_OUTPUT_CONFIG_FILE "/opt/build/RPX-100-SDR/build/CPackConfig.cmake")
set(CPACK_PACKAGE_CONTACT "https://github.com/isemann/RPX100-SDR")
set(CPACK_PACKAGE_DEFAULT_LOCATION "/")
set(CPACK_PACKAGE_DESCRIPTION_FILE "/opt/build/RPX-100-SDR/Readme.md")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "SDR Rx/Tx software for Airspy, Airspy HF+, BladeRF, HackRF, LimeSDR, PlutoSDR, RTL-SDR, SDRplay, USRP and FunCube")
set(CPACK_PACKAGE_FILE_NAME "RPX100-6.16.5-Source")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "RPX100 6.16.5")
set(CPACK_PACKAGE_INSTALL_REGISTRY_KEY "RPX100 6.16.5")
set(CPACK_PACKAGE_NAME "RPX100")
set(CPACK_PACKAGE_RELOCATABLE "true")
set(CPACK_PACKAGE_VENDOR "oe3bia")
set(CPACK_PACKAGE_VERSION "6.16.5")
set(CPACK_PACKAGE_VERSION_MAJOR "6")
set(CPACK_PACKAGE_VERSION_MINOR "16")
set(CPACK_PACKAGE_VERSION_PATCH "5")
set(CPACK_RESOURCE_FILE_LICENSE "/opt/build/RPX-100-SDR/LICENSE")
set(CPACK_RESOURCE_FILE_README "/opt/build/RPX-100-SDR/Readme.md")
set(CPACK_RESOURCE_FILE_WELCOME "/home/bernhard/Qt/Tools/CMake/share/cmake-3.21/Templates/CPack.GenericWelcome.txt")
set(CPACK_RPM_PACKAGE_SOURCES "ON")
set(CPACK_SET_DESTDIR "OFF")
set(CPACK_SOURCE_GENERATOR "ZIP;TGZ")
set(CPACK_SOURCE_IGNORE_FILES "/opt/build/RPX-100-SDR/build;/.git/;.gitignore;menu.yml;.travis.yml;.appveyor.yml;default.nix;.envrc;TODOs.org;/.scripts/")
set(CPACK_SOURCE_INSTALLED_DIRECTORIES "/opt/build/RPX-100-SDR;/")
set(CPACK_SOURCE_OUTPUT_CONFIG_FILE "/opt/build/RPX-100-SDR/build/CPackSourceConfig.cmake")
set(CPACK_SOURCE_PACKAGE_FILE_NAME "RPX100-6.16.5-Source")
set(CPACK_SOURCE_STRIP_FILES "true")
set(CPACK_SOURCE_TOPLEVEL_TAG "Linux-Source")
set(CPACK_STRIP_FILES "true")
set(CPACK_SYSTEM_NAME "Linux")
set(CPACK_THREADS "1")
set(CPACK_TOPLEVEL_TAG "Linux-Source")
set(CPACK_WIX_SIZEOF_VOID_P "8")

if(NOT CPACK_PROPERTIES_FILE)
  set(CPACK_PROPERTIES_FILE "/opt/build/RPX-100-SDR/build/CPackProperties.cmake")
endif()

if(EXISTS ${CPACK_PROPERTIES_FILE})
  include(${CPACK_PROPERTIES_FILE})
endif()
