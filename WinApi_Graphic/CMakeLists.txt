cmake_minimum_required(VERSION 2.8.12)

project(WinApi_Graphic)

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
resource/*.*
)

add_executable(
WinApi_Graphic
${SRC_FILES}
)
