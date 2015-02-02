cmake_minimum_required(VERSION 2.8.12)

project(WinApi2)

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
RESOURCE_FILES
rc/*.rc, *.ico
)

add_executable(
WinApi2
${SRC_FILES}
)
