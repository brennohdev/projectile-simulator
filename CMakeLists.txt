cmake_minimum_required(VERSION 3.20)
project(Projectile-Sim CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_executable(app src/main.cpp
    src/domain/projectile.hpp
    src/domain/projectile.cpp
    src/domain/forces.cpp
    src/application/simulation.hpp
    src/application/simulatio.cpp)