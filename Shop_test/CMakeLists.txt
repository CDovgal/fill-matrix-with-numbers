cmake_minimum_required(VERSION 2.8.12)

project(Shop_test)

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

add_executable(
Shop_test
${SRC_FILES}
)
