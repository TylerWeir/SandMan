cmake_minimum_required(VERSION 3.25)

Project(SandMan CXX)
set(CMAKE_CXX_STANDARD 17)


# Test Support
find_package(doctest)
include(CTest)

add_subdirectory(src)
add_subdirectory(examples)


# Development Candy
set(CMAKE_COLOR_DIAGNOSTICS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
