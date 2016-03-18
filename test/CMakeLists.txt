find_package(Boost COMPONENTS unit_test_framework REQUIRED)

include_directories (${ROOT_DIR}/src
                     ${Boost_INCLUDE_DIRS})

ADD_DEFINITIONS(-DBOOST_TEST_DYN_LINK) 

set(MAIN_SOURCES_TEST test.cpp)
set(HEADERS_TEST)
set(SOURCES_TEST)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/types")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/algorithms")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/ctci5")

#message("Headers in test: " ${HEADERS_TEST})
#message("Sources in test: " ${SOURCES_TEST})

add_executable(cppnotestest ${MAIN_SOURCES_TEST} ${SOURCES_TEST} ${HEADERS_TEST})

target_link_libraries(cppnotestest
                      ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
