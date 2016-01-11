find_package(Boost COMPONENTS unit_test_framework REQUIRED)

include_directories (${ROOT_DIR}/src
                     ${Boost_INCLUDE_DIRS})

#ADD_DEFINITIONS(-DBOOST_TEST_DYN_LINK)

set(MAIN_SOURCES_TEST test.cpp)
set(HEADERS_TEST)
set(SOURCES_TEST)

set(HEADERS_TEST
   ${HEADERS_TEST}
   "${CMAKE_CURRENT_SOURCE_DIR}/algorithms/ctci/ltest-1-1-str_unique_char.hpp"
   PARENT_SCOPE
)

message("Headers in test: "${HEADERS_TEST})

add_executable(cppnotestest ${MAIN_SOURCES_TEST} ${SOURCES_TEST} ${HEADERS_TEST})

target_link_libraries(cppnotestest
                      cppnotestypes
                      cppnotesclasses
                      cppnotesalgorithms
                      ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
