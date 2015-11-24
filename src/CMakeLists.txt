set(MAIN_SOURCES main.cpp)
set(HEADERS)
set(SOURCES)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/types")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/classes")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/algorithms")

#message("Headers: " ${HEADERS})
#message("Sources: " ${SOURCES})

add_executable (cppnotes ${MAIN_SOURCES} ${SOURCES} ${HEADERS})
