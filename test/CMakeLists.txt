project(cppnotestest)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/externals/sanitizers-cmake/cmake" ${CMAKE_MODULE_PATH})
find_package(Sanitizers REQUIRED)

find_package(Boost COMPONENTS unit_test_framework system filesystem REQUIRED)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

file(GLOB_RECURSE SOURCE_FILES *.cpp *.h *.hpp)

add_executable (${PROJECT_NAME} ${SOURCE_FILES})
add_sanitizers(${PROJECT_NAME})

include_directories (${CMAKE_CURRENT_SOURCE_DIR}/../src
                     ${Boost_INCLUDE_DIRS})

target_compile_definitions(${PROJECT_NAME} PUBLIC -DBOOST_TEST_DYN_LINK)

if (CMAKE_COMPILER_IS_GNUCXX)
    target_compile_options(${PROJECT_NAME}
        PUBLIC
            -Wall -Wextra -Werror -Wpedantic
            -pedantic-errors -Wold-style-cast -Woverloaded-virtual -Wsign-promo
            -Wdouble-promotion -Wformat=2 -Wmissing-include-dirs -Wswitch-default
            -Wswitch-enum -Wunknown-pragmas -Wswitch-enum -Wunknown-pragmas
            -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wcast-qual
            -Wcast-align -Wconversion -Wsign-conversion
            -Wzero-as-null-pointer-constant -Wuseless-cast -Wlogical-op
            -Wno-aggressive-loop-optimizations -Wredundant-decls -Winline
            -Winvalid-pch -Wdisabled-optimization
            -fstack-protector-all -Wstack-protector
            -Wno-overloaded-virtual
    )
endif()

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        ${Boost_SYSTEM_LIBRARY}
        ${Boost_FILESYSTEM_LIBRARY}
        Threads::Threads
        ubsan
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                   ${CMAKE_CURRENT_SOURCE_DIR}/data ${CMAKE_CURRENT_BINARY_DIR}/data)
