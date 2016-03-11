add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/ctci")

set(HEADERS_TEST
   ${HEADERS_TEST}
   ${CMAKE_CURRENT_SOURCE_DIR}/testbubblesort.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/testgnomesort.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/testselectionsort.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/testinsertionsort.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/testmergesort.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/testquicksort.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/testbinarysearch.hpp
   PARENT_SCOPE
)
