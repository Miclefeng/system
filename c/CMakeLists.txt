cmake_minimum_required(VERSION 3.14)
project(c)

set(CMAKE_CXX_STANDARD 14)

include_directories(makefile/cacu/add)
include_directories(makefile/cacu/sub)

add_executable(pointerVariable base/Pointer/pointerVariable.c)

add_executable(variableAddress base/Pointer/variableAddress.c)

