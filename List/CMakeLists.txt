cmake_minimum_required(VERSION 2.8.12)

project(List)

set(source_files
main.cpp
)

include_directories(
include
)
 
file (
GLOB
SRC_FILES
src/*.c*
)

add_executable(
List
${SRC_FILES}
)
