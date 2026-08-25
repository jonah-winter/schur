add_executable(internals storage_dims_test.cpp
        ../include/matrix/dim_funcs.h)

find_package(GTest)

target_link_libraries(internals PRIVATE GTest::gtest_main)

target_include_directories(internals PRIVATE
                           ${CMAKE_SOURCE_DIR}/include)
include(GoogleTest)
