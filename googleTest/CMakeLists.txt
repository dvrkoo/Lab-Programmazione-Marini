cmake_minimum_required(VERSION 3.19)
project(LaboratorioProgrammazione)
add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES runAllTests.cpp Tests.cpp)
add_executable(GoogleTests ${TEST_SOURCE_FILES})
target_link_libraries(GoogleTests gtest gtest_main core)

target_link_libraries (GoogleTests core)
