add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/ctci")

set(HEADERS_TEST
   ${HEADERS_TEST}
   ${CMAKE_CURRENT_SOURCE_DIR}/testbubblesort.hpp
   PARENT_SCOPE
)
