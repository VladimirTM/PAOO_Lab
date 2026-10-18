cmake_minimum_required(VERSION 3.10)
project(Project2_App)

add_executable(App
    src/main.cpp
)

target_link_libraries(App PRIVATE MathLib)
