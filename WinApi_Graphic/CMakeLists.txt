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
)

# resources
SET(client_resources rc/WinApi_Graphic.rc)
SET(client_icon rc/WinApi_Graphic.ico)
SET(client_icon rc/small.ico)

# group in filters
source_group("Resources" FILES ${client_resources} ${client_icon})

add_executable(
WinApi_Graphic
${SRC_FILES}
)
