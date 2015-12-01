cmake_minimum_required(VERSION 2.8)

set(PROJECT_TYPES CppNotesTypes)
project(${PROJECT_TYPES})

set(HEADERS_TYPES
   ${CMAKE_CURRENT_SOURCE_DIR}/basics.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/boolean.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/chartype.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/inttype.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/linkedlist.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/stack.hpp
)

set(SOURCES_TYPES
   ${CMAKE_CURRENT_SOURCE_DIR}/linkedlist.cpp
)

add_library(cppnotestypes SHARED ${SOURCES_TYPES} ${HEADERS_TYPES})
