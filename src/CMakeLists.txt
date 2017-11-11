project(cppnotes)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/externals/sanitizers-cmake/cmake" ${CMAKE_MODULE_PATH})
find_package(Sanitizers REQUIRED)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

file(GLOB_RECURSE SOURCE_FILES *.cpp *.h *.hpp)

add_executable (${PROJECT_NAME} ${SOURCE_FILES})
add_sanitizers(${PROJECT_NAME})

if (CMAKE_COMPILER_IS_GNUCXX)
    target_compile_options(${PROJECT_NAME}
        PRIVATE
            -Wall -Wextra -Werror -Wpedantic
            -pedantic-errors -Wold-style-cast -Woverloaded-virtual -Wsign-promo
            -Wdouble-promotion -Wformat=2 -Wmissing-include-dirs -Wswitch-default
            -Wswitch-enum -Wunknown-pragmas -Wswitch-enum
            -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wcast-qual
            -Wcast-align -Wconversion -Wsign-conversion
            -Wzero-as-null-pointer-constant -Wuseless-cast -Wlogical-op
            -Wno-aggressive-loop-optimizations -Wredundant-decls -Winline
            -Winvalid-pch -Wdisabled-optimization -fno-inline
            -fstack-protector-all -Wstack-protector
            -Wno-overloaded-virtual
    )
endif()

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        Threads::Threads
        ubsan
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)
