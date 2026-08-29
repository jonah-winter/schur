add_executable(internals storage_dims_test.cpp
        ../include/schur/dimensions/dim_safe_funcs.hpp
        ../include/schur/storage/storage_decl_internal.hpp
        ../include/schur/storage/storage_constructors_impl.cpp
        ../include/schur/storage/storage_safe_funcs.cpp
        ../include/schur/storage/storage_incl.hpp
        ../include/schur/dimensions/dimensions_incl.hpp
        ../include/schur/dimensions/generic_dim_funcs.hpp
        ../src/dim_dynamic_safe_funcs.cpp)

find_package(GTest)

target_link_libraries(internals PRIVATE GTest::gtest_main)

target_include_directories(internals PRIVATE
                           ${CMAKE_SOURCE_DIR}/include)
include(GoogleTest)
