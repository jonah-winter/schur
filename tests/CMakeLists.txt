project(tests)

add_executable(${PROJECT_NAME} storage_dims_test.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE
                           ${CMAKE_SOURCE_DIR}/include)