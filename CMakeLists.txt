cmake_minimum_required(VERSION 3.2)

# Set project name
project(CppNotesMain)

option(BUILD_TESTS "build tests" ON)

set(CMAKE_VERBOSE_MAKEFILE ON)

message("Build: " ${CMAKE_BUILD_TYPE})

add_subdirectory(src)

if(BUILD_TESTS)
    add_subdirectory(test)
    enable_testing()
    add_test(NAME cntest COMMAND cppnotestest)
endif(BUILD_TESTS)
