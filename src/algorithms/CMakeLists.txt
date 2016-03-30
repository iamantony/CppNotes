add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/euler")

set(HEADERS
   ${HEADERS}
   ${CMAKE_CURRENT_SOURCE_DIR}/factorial.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/bitsmanipulation.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/bubblesort.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/gnomesort.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/selectionsort.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/insertionsort.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/mergesort.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/searchelementindex.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/quicksort.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/binarysearch.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/strpermutations.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/find_two_elements.hpp
   PARENT_SCOPE
)

set(SOURCES
   ${SOURCES}
   ${CMAKE_CURRENT_SOURCE_DIR}/factorial.cpp
   PARENT_SCOPE
)
