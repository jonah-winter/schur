cmake_minimum_required(VERSION 3.20)
project(SchurLibTest LANGUAGES CXX)

add_subdirectory(.. schur)
add_subdirectory(lib lib)
add_subdirectory(package pkg)
find_package(GTest REQUIRED)
find_package(benchmark REQUIRED)

#find_package(benchmark REQUIRED)

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
