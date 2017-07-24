project(cppnotes)

#file(GLOB FILES_SRC *.cpp)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SUB_SOURCES)

set(FILES_SRC
  ${FILES_SRC}
  ${SUB_SOURCES}
  PARENT_SCOPE
)

add_executable (${PROJECT_NAME} ${FILES_SRC})

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/types
)

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

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        ubsan
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)
