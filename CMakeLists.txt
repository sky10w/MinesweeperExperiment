cmake_minimum_required(VERSION 3.20)

project(
    Minesweeper
    LANGUAGES CXX
    DESCRIPTION "A tiny experiment"
    VERSION 1.0
)

set(CMAKE_GENERATOR "MinGW Makefiles")

file(GLOB SRC "*.cpp")

add_executable(main ${SRC})
target_compile_features(main PRIVATE cxx_std_14)