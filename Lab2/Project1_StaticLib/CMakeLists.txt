cmake_minimum_required(VERSION 3.10)
project(Project1_StaticLib)

add_library(MathLib STATIC
    src/MathUtils.cpp
)

target_include_directories(MathLib PUBLIC include)
