cmake_minimum_required(VERSION 3.24)

project(Schur LANGUAGES CXX) 

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) 

#find_program(IWYU_PATH NAMES include-what-you-use iwyu)
#if(IWYU_PATH)
  #set(CMAKE_CXX_INCLUDE_WHAT_YOU_USE "${IWYU_PATH}")
#endif()

add_library(schur INTERFACE
        include/schur/matrix/lazy/Matrix_SubtView.hpp
        include/schur/matrix/lazy/Matrix_Transpose.hpp
        include/schur/matrix/mult/Matrix_MultMain.hpp)

target_include_directories(schur INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR})

add_subdirectory(tests)
