set(MAIN_SOURCES main.cpp)
set(HEADERS)
set(SOURCES)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/types")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/classes")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/algorithms")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/templates")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/ctci5")

#message("Headers: " ${HEADERS})
#message("Sources: " ${SOURCES})

add_executable (cppnotes ${MAIN_SOURCES} ${SOURCES} ${HEADERS})
