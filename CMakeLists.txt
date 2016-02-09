cmake_minimum_required(VERSION 2.8)

message("Starting cmake")

# Set project name
set(PROJECT CppNotesPrj)
project(${PROJECT})

# Set paths
set(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set("${PROJECT}_BINARY_DIR" bin)
set("${PROJECT}_SOURCE_DIR" src)
#set("${PROJECT}_LIB_DIR" lib)

set(CMAKE_INCLUDE_PATH ${${PROJECT}_SOURCE_DIR})
#set(CMAKE_LIBRARY_PATH ${${PROJECT}_LIB_DIR})
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/${${PROJECT}_BINARY_DIR})
set(CMAKE_VERBOSE_MAKEFILE ON)

if(NOT CMAKE_COMPILER_IS_GNUCXX)
  message(FATAL_ERROR "Can build only with GNU g++ compiler")
endif()

# Set compiler flags
set(CFLAGS)
string(TOLOWER "${CMAKE_BUILD_TYPE}" build)
if(build MATCHES release)
  set(CMAKE_BUILD_TYPE Release)
  set(CFLAGS "-O3 -NDEBUG -std=c++14 -fsanitize=undefined -fstack-protector-strong")
elseif(build MATCHES debug)
  set(CMAKE_BUILD_TYPE Debug)
  set(CFLAGS "${CFLAGS} -g -std=c++14 -Wall -Wextra -Werror -Wpedantic")
  set(CFLAGS "${CFLAGS} -pedantic-errors -Wold-style-cast")
  set(CFLAGS "${CFLAGS} -Woverloaded-virtual -Wsign-promo -Wdouble-promotion")
  set(CFLAGS "${CFLAGS} -Wformat=2 -Wmissing-include-dirs -Wswitch-default")
  set(CFLAGS "${CFLAGS} -Wswitch-enum -Wunknown-pragmas")
  set(CFLAGS "${CFLAGS} -Wfloat-equal -Wundef -Wshadow")
  set(CFLAGS "${CFLAGS} -Wpointer-arith -Wcast-qual -Wcast-align -Wconversion")
  set(CFLAGS "${CFLAGS} -Wsign-conversion -Wzero-as-null-pointer-constant")
  set(CFLAGS "${CFLAGS} -Wuseless-cast -Wlogical-op -Wno-aggressive-loop-optimizations")
  set(CFLAGS "${CFLAGS} -Wredundant-decls -Winline -Winvalid-pch -Wdisabled-optimization")
  set(CFLAGS "${CFLAGS} -fno-inline -fsanitize=undefined -fstack-protector-strong")
else()
  message(FATAL_ERROR "Build " ${CMAKE_BUILD_TYPE} " is not supported!")
endif()

set(CMAKE_CXX_FLAGS ${CFLAGS})
message("Build: " ${CMAKE_BUILD_TYPE})
message("Compiler flags: " ${CMAKE_CXX_FLAGS})

add_subdirectory(src)
add_subdirectory(test)

enable_testing()
add_test(NAME cntest COMMAND cppnotestest)
