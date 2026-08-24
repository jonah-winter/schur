cmake_minimum_required(VERSION 3.20)

project(matrix-lib)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(${PROJECT_NAME} tests/storage_dims_test.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE include)
add_subdirectory(tests)
