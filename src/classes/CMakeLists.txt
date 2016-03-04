set(HEADERS
   ${HEADERS}
   ${CMAKE_CURRENT_SOURCE_DIR}/base_inheritance.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/construction.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/multy_inheritance.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/virtualfunctions.hpp
   PARENT_SCOPE
)

set(SOURCES
   ${SOURCES}
   ${CMAKE_CURRENT_SOURCE_DIR}/base_inheritance.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/multy_inheritance.cpp
   PARENT_SCOPE
)
