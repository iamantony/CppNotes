set(MAIN_SOURCES main.cpp)

set (SUBFOLDERS
        algorithms/euler/common
        algorithms/euler
        algorithms
        classes
        types
    )

set (HEADERS)
set (SOURCES)

foreach (folder ${SUBFOLDERS})
    file(GLOB_RECURSE SOURCES ${PROJECT_SOURCE_DIR}/${folder}/*.cpp)
    file(GLOB_RECURSE HEADERS ${PROJECT_SOURCE_DIR}/${folder}/*.hpp)
endforeach ()

add_executable (cppnotes ${MAIN_SOURCES} ${SOURCES} ${HEADERS})
