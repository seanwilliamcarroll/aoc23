cmake_minimum_required(VERSION 3.15)

project(
        AoC_d01
        LANGUAGES
        CXX
        )

include(cppcheck.cmake)
include(clang-format.cmake)

add_executable(p1 p1.cpp)
add_executable(p2 p2.cpp)
