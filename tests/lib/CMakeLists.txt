add_executable(lib_test Operations_Test.cpp)

target_include_directories(lib_test PRIVATE
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR})
target_link_libraries(lib_test PRIVATE Schur::Schur)
