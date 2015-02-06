cmake_minimum_required(VERSION 2.8.12)

project(WinApi_Graphic)

include_directories(
include
)

file (
GLOB
SRC_FILES
src/*.cpp
INCLUDE_FILES
include/*.h
RESOURCE_FILES
rc/*.*
#rc/*.ico
)

# resources
SET(RESOURCE_FILES rc/WinApi_Graphic.rc)
SET(RESOURCE_FILES_ICON_MAIN rc/WinApi_Graphic.ico)
SET(RESOURCE_FILES_ICON_SMALL rc/small.ico)


# group in filters
source_group("Resources" FILES ${RESOURCE_FILES_ICON_MAIN} ${RESOURCE_FILES_ICON_SMALL} ${RESOURCE_FILES})

add_executable(
WinApi_Graphic
${SRC_FILES}
)
