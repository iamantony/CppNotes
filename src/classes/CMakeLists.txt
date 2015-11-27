cmake_minimum_required(VERSION 2.8)

set(PROJECT_CLASSES CppNotesClasses)
project(${PROJECT_CLASSES})

set(HEADERS_CLASSES
   ${CMAKE_CURRENT_SOURCE_DIR}/base_inheritance.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/multy_inheritance.hpp
)

set(SOURCES_CLASSES
   ${CMAKE_CURRENT_SOURCE_DIR}/base_inheritance.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/multy_inheritance.cpp
)

add_library(cppnotesclasses SHARED ${SOURCES_CLASSES} ${HEADERS_CLASSES})
