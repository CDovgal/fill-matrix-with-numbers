cmake_minimum_required(VERSION 2.8.12)

project(Ticket)

set(source_files
main.cpp
)

###################GTEST###################

set(GTEST_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../../gtest-1.7.0/include")
set(GTEST_BINARY_DIR  "${CMAKE_CURRENT_SOURCE_DIR}/../../gtest-1.7.0/bin")

set(GTEST_STATIC_LIB_NAME "gtest")

###########################################

include_directories(
include
)
 
file (
GLOB
SRC_FILES
src/*.c*
)

add_executable(
Ticket
${SRC_FILES}
)
