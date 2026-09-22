add_executable(mat matrix_base_test.cpp
)

#target_include_directories(mat PRIVATE
#        ${CMAKE_SOURCE_DIR}/include
#        ${CMAKE_SOURCE_DIR}/src
#        ${CMAKE_SOURCE_DIR})

target_link_libraries(mat PRIVATE schur)
target_include_directories(mat PRIVATE ${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/src)

target_sources(mat PRIVATE
#        ${CMAKE_SOURCE_DIR}/include/schur/dimensions/Dimensions_Validate.hpp
#        ${CMAKE_SOURCE_DIR}/src/Dimensions_DynamicSafeFuncs.hpp
#        ${CMAKE_SOURCE_DIR}/include/schur/storage/Storage_ConstructorsImpl.hpp
#        ${CMAKE_SOURCE_DIR}/include/schur/storage/Storage_SafeFuncs.hpp
#        ${CMAKE_SOURCE_DIR}/include/schur/storage/Storage_UnsafeFuncs.hpp
#        ${CMAKE_SOURCE_DIR}/include/schur/matrix/Matrix_MainConstructors.hpp
        )
#find_package(benchmark REQUIRED)

#add_executable(bench test_funcs.cpp)

#target_include_directories(bench PRIVATE
#        ${CMAKE_SOURCE_DIR}/include
#        ${CMAKE_SOURCE_DIR})

#target_link_libraries(bench PRIVATE benchmark::benchmark schur)
#target_include_directories(bench PRIVATE ${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/src)

#target_include_directories(bench PRIVATE ${CMAKE_SOURCE_DIR}/tests ${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/src)

#target_link_libraries(internals PRIVATE GTest::gtest_main)

#target_include_directories(internals PRIVATE
#                           ${CMAKE_SOURCE_DIR}/include)
#include(GoogleTest)
