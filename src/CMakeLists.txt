set(MAIN_SOURCES main.cpp)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/types")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/classes")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/algorithms")

set (ADDITIONAL_LIBRARIES
    cppnotestypes
    cppnotesclasses
    cppnotesalgorithms
    )

add_executable(cppnotes ${MAIN_SOURCES} ${SOURCES} ${HEADERS})

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/types")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/classes")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/algorithms")

target_link_libraries(cppnotes ${ADDITIONAL_LIBRARIES})
