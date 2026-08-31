#add_executable(internals storage_dims_test.cpp
#        ../include/schur/dimensions/dim_safe_funcs.cpp
#        ../include/schur/storage/storage_decl_internal.hpp
#        ../include/schur/storage/storage_constructors_impl.cpp
#        ../include/schur/storage/storage_safe_funcs.cpp
#        ../include/schur/storage/storage_incl.hpp
#        ../include/schur/dimensions/dimensions_incl.hpp
#        ../include/schur/dimensions/generic_dim_funcs.hpp
#        ../src/dim_dynamic_safe_funcs.cpp
#        ../include/schur/matrix/matrix_base_class.hpp
#        ../include/schur/matrix/matrix_constants.hpp
#        ../include/schur/matrix/matrix_base_funcs.cpp
#        ../include/schur/matrix/Matrix_BaseConstructors.hpp)
add_executable(mat matrix_base_test.cpp
)

target_include_directories(mat PRIVATE
        ${CMAKE_SOURCE_DIR}/include)

target_sources(mat PRIVATE
        ${CMAKE_SOURCE_DIR}/include/schur/dimensions/Dimensions_SafeFuncs.hpp
        ${CMAKE_SOURCE_DIR}/src/Dimensions_DynamicSafeFuncs.hpp
        ${CMAKE_SOURCE_DIR}/include/schur/storage/Storage_ConstructorsImpl.hpp
        ${CMAKE_SOURCE_DIR}/include/schur/storage/Storage_SafeFuncs.hpp
        ${CMAKE_SOURCE_DIR}/include/schur/storage/Storage_UnsafeFuncs.hpp
        ${CMAKE_SOURCE_DIR}/include/schur/matrix/Matrix_BaseConstructors.hpp
        )
#find_package(GTest)

#target_link_libraries(internals PRIVATE GTest::gtest_main)

#target_include_directories(internals PRIVATE
#                           ${CMAKE_SOURCE_DIR}/include)
#include(GoogleTest)
