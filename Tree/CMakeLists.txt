cmake_minimum_required(VERSION 2.8.12)

project(Tree)

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
)

# resources



# group in filters


add_executable(
Tree
${SRC_FILES}
)
