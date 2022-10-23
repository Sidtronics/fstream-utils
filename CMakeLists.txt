cmake_minimum_required(VERSION 3.23.3)

project(txtblocks VERSION 1.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(INCLUDE_DIR "include/TB")
set(SRC_DIR "src")

if (CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    set(TXTB_STANDALONE TRUE)
endif()

option(TXTB_BUILD_TESTS "Build the test programs" ${TXTB_STANDALONE})

add_library(txtblocks
    ${SRC_DIR}/blkfile.cpp
    ${SRC_DIR}/block.cpp)

target_include_directories(txtblocks PUBLIC 
    ${INCLUDE_DIR}
    ${SRC_DIR})

if (TXTB_BUILD_TESTS)
    add_subdirectory(tests)
endif()
