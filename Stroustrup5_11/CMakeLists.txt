cmake_minimum_required(VERSION 2.8.12)

project(Stroustrup5_11)

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
Stroustrup5_11
${SRC_FILES}
)
