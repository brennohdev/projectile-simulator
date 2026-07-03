cmake_minimum_required(VERSION 3.20)
project(Projectile-Sim CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Fetch raylib automatically for reproducibility
include(FetchContent)
FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 5.5
    GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(raylib)

# Executable 1: CSV output
add_executable(app
    src/main.cpp
    src/domain/projectile.cpp
    src/domain/forces.cpp
    src/infrastructure/csv_exporter.cpp
    src/application/simulation.cpp
)
target_include_directories(app PRIVATE src)

# Executable 2: real-time visualization
add_executable(sim_visual
    src/main_visual.cpp
    src/domain/projectile.cpp
    src/domain/forces.cpp
)
target_include_directories(sim_visual PRIVATE src)
target_link_libraries(sim_visual raylib)
