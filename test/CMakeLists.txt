find_package(Boost COMPONENTS unit_test_framework system filesystem REQUIRED)

project(cppnotestest)

file(GLOB FILES_SRC *.cpp)

add_executable (${PROJECT_NAME} ${FILES_SRC})

include_directories (${CMAKE_CURRENT_SOURCE_DIR}/../src
                     ${Boost_INCLUDE_DIRS})

ADD_DEFINITIONS(-DBOOST_TEST_DYN_LINK)

target_link_libraries(${PROJECT_NAME}
                      ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
                      ${Boost_SYSTEM_LIBRARY}
                      ${Boost_FILESYSTEM_LIBRARY})

if (CMAKE_COMPILER_IS_GNUCXX)
    target_compile_options(${PROJECT_NAME}
        PRIVATE
            -std=c++14 -lpthread -Wall -Wextra -Werror -Wpedantic
            -pedantic-errors -Wold-style-cast -Woverloaded-virtual -Wsign-promo
            -Wdouble-promotion -Wformat=2 -Wmissing-include-dirs -Wswitch-default
            -Wswitch-enum -Wunknown-pragmas -Wswitch-enum -Wunknown-pragmas
            -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wcast-qual
            -Wcast-align -Wconversion -Wsign-conversion
            -Wzero-as-null-pointer-constant -Wuseless-cast -Wlogical-op
            -Wno-aggressive-loop-optimizations -Wredundant-decls -Winline
            -Winvalid-pch -Wdisabled-optimization -fno-inline
            -fsanitize=undefined -fstack-protector-all -Wstack-protector
            -Wno-overloaded-virtual
    )
endif()

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)
