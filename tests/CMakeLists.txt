#cmake_minimum_required(VERSION 3.24)
#project(SchurLibTest LANGUAGES CXX)

#set(gtest_build_tests OFF)
#set(INSTALL_GTEST OFF)
#set(BENCHMARK_ENABLE_TESTING OFF)
#set(BENCHMARK_ENABLE_INSTALL OFF)

set(gtest_build_tests OFF CACHE BOOL "" FORCE)
set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)

set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "" FORCE)
set(BENCHMARK_ENABLE_INSTALL OFF CACHE BOOL "" FORCE)

include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.tar.gz
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

FetchContent_MakeAvailable(googletest)

FetchContent_Declare(
  benchmark
  URL https://github.com/google/benchmark/archive/refs/tags/v1.9.5.tar.gz
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

FetchContent_MakeAvailable(benchmark)

add_subdirectory(lib lib)
add_subdirectory(package pkg)
