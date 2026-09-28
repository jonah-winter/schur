cmake_minimum_required(VERSION 3.24)

project(schur_
        VERSION 0.2.0
        LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
option(SCHUR_TEST_EXE "Build Schur tests" ON)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

add_library(schur_ INTERFACE)
add_library(Schur::Schur ALIAS schur_)

target_compile_features(schur_ INTERFACE cxx_std_23)

target_include_directories(schur_ INTERFACE
  # build_interface is for developer use when editing from project dir
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>

  # from GNU install dirs, makes sure that package is being 
  # installed on the right path relative to user home dir
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

# installs files into {home_dir}/include/schur
install(
  DIRECTORY include/
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
install(
  TARGETS schur_
  EXPORT  SchurTargets
)
install(
  EXPORT SchurTargets
  FILE   SchurTargets.cmake
  NAMESPACE Schur::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Schur
)
# creates config from .cmake.in file
configure_package_config_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/cmake/SchurConfig.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/SchurConfig.cmake
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Schur
)
write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/SchurConfigVersion.cmake
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY SameMajorVersion
)
install(
  FILES 
    ${CMAKE_CURRENT_BINARY_DIR}/SchurConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/SchurConfigVersion.cmake
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Schur
)

if(${SCHUR_TEST_EXE})
  add_subdirectory(tests)
endif()
