cmake_minimum_required(VERSION 3.10)
project(Lab4 LANGUAGES CXX)

include_directories(inc)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME}
    inc/FileSystem.hpp
    inc/NamedObject.hpp
    inc/HomeForSale.hpp
    src/FileSystem.cpp
    src/NamedObject.cpp
    src/HomeForSale.cpp
    src/main.cpp
)

