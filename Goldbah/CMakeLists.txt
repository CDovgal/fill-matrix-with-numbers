cmake_minimum_required(VERSION 2.8.12)

project(Goldbah)

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
INCLUDE_FILES
include/*.h
)

add_executable(
Goldbah
${SRC_FILES}
)
