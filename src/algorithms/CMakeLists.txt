cmake_minimum_required(VERSION 2.8)

set(PROJECT_ALGORITHMS CppNotesAlgorithms)
project(${PROJECT_ALGORITHMS})

set(HEADERS_ALGORITHMS
   ${CMAKE_CURRENT_SOURCE_DIR}/factorial.hpp
)

set(SOURCES_ALGORITHMS
   ${CMAKE_CURRENT_SOURCE_DIR}/factorial.cpp
)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/euler")

add_library(cppnotesalgorithms SHARED ${SOURCES_ALGORITHMS} ${HEADERS_ALGORITHMS})
