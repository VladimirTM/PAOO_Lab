cmake_minimum_required(VERSION 3.10)
project(Lab3 LANGUAGES CXX)

include_directories(inc)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME}
    inc/Thermometer.hpp
    src/Thermometer.cpp
    src/main.cpp
)
