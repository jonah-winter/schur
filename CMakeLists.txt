cmake_minimum_required(VERSION 3.24)

project(Schur LANGUAGES CXX) 

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) 

#find_program(IWYU_PATH NAMES include-what-you-use iwyu)
#if(IWYU_PATH)
  #set(CMAKE_CXX_INCLUDE_WHAT_YOU_USE "${IWYU_PATH}")
#endif()

add_subdirectory(tests)
