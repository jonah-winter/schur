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
#        ../include/schur/matrix/Matrix_MainConstructors.hpp)
add_executable(mat matrix_base_test.cpp ../include/schur/matrix/Matrix
        ../include/schur/matrix/Matrix_Operations.hpp
        util/Operations_Benchmarking.hpp
        #        ../include/schur/matrix/Matrix_MainClass.hpp
#        ../include/schur/matrix/Matrix_MainFuncs.hpp
#        ../include/schur/matrix/Matrix_Block.hpp
#        ../include/schur/matrix/lazy/Matrix_LazyStructs.hpp
#        ../include/schur/core/Concepts.hpp
#        ../include/schur/core/Types.hpp
#        ../include/schur/core/Traits.hpp
#        ../include/schur/core/Forward_Lazy.hpp
)

target_include_directories(mat PRIVATE
        ${CMAKE_SOURCE_DIR}/include)

target_sources(mat PRIVATE
#        ${CMAKE_SOURCE_DIR}/include/schur/dimensions/Dimensions_Validate.hpp
#        ${CMAKE_SOURCE_DIR}/src/Dimensions_DynamicSafeFuncs.hpp
#        ${CMAKE_SOURCE_DIR}/include/schur/storage/Storage_ConstructorsImpl.hpp
#        ${CMAKE_SOURCE_DIR}/include/schur/storage/Storage_SafeFuncs.hpp
#        ${CMAKE_SOURCE_DIR}/include/schur/storage/Storage_UnsafeFuncs.hpp
#        ${CMAKE_SOURCE_DIR}/include/schur/matrix/Matrix_MainConstructors.hpp
        )
find_package(benchmark REQUIRED)

add_executable(bench test_funcs.cpp)

target_link_libraries(bench PRIVATE benchmark::benchmark)

target_include_directories(bench PRIVATE ${CMAKE_SOURCE_DIR}/tests ${CMAKE_SOURCE_DIR}/include)

#target_link_libraries(internals PRIVATE GTest::gtest_main)

#target_include_directories(internals PRIVATE
#                           ${CMAKE_SOURCE_DIR}/include)
#include(GoogleTest)
