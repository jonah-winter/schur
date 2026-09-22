cmake_minimum_required(VERSION 3.24)

project(Schur LANGUAGES CXX) 

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(schur INTERFACE
        include/schur/core/Numbers.hpp
        include/schur/core/Range.hpp)

target_include_directories(schur INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR})

add_subdirectory(tests)