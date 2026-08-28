add_executable(internals storage_dims_test.cpp
        ../include/matrix/dim_safe_funcs.hpp
        ../include/matrix/storage_decl_internal.hpp
        ../include/matrix/storage_constructors_impl.cpp
        ../include/matrix/storage_safe_funcs.cpp
        ../include/matrix/storage_incl.hpp
        ../include/matrix/dimensions_incl.hpp
        ../include/matrix/generic_dim_funcs.hpp
        ../src/dim_dynamic_safe_funcs.cpp)

find_package(GTest)

target_link_libraries(internals PRIVATE GTest::gtest_main)

target_include_directories(internals PRIVATE
                           ${CMAKE_SOURCE_DIR}/include)
include(GoogleTest)
