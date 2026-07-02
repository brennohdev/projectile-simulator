cmake_minimum_required(VERSION 3.20)
project(Projectile-Sim CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(raylib REQUIRED)

# Executável 1: gera CSV
add_executable(app
    src/main.cpp
    src/domain/projectile.cpp
    src/domain/forces.cpp
    src/infrastructure/csv_exporter.cpp
    src/application/simulation.cpp
)
target_include_directories(app PRIVATE src)

# Executável 2: visualização em tempo real
add_executable(sim_visual
    src/main_visual.cpp
    src/domain/projectile.cpp
    src/domain/forces.cpp
)
target_include_directories(sim_visual PRIVATE src)
target_link_libraries(sim_visual raylib)
