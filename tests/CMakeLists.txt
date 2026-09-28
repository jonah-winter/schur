cmake_minimum_required(VERSION 3.24)
project(SchurLibTest LANGUAGES CXX)

#add_subdirectory(.. schur)
add_subdirectory(lib lib)
add_subdirectory(package pkg)

set(gtest_build_tests OFF)
set(INSTALL_GTEST OFF)
set(BENCHMARK_ENABLE_TESTING OFF)
set(BENCHMARK_ENABLE_INSTALL OFF)

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

#add_executable(bench test_funcs.cpp)

#target_include_directories(bench PRIVATE
#        ${CMAKE_SOURCE_DIR}/include
#        ${CMAKE_SOURCE_DIR})

#target_link_libraries(bench PRIVATE benchmark::benchmark schur)
#target_include_directories(bench PRIVATE ${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/src)

#target_include_directories(bench PRIVATE ${CMAKE_SOURCE_DIR}/tests ${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/src)

#target_link_libraries(internals PRIVATE GTest::gtest_main)

#target_include_directories(internals PRIVATE
#                           ${CMAKE_SOURCE_DIR}/include)
#include(GoogleTest)
