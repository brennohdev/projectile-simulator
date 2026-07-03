# Projectile Simulation with Aerodynamic Drag

A projectile simulator in C++17 that compares trajectories with and without air resistance. Built from scratch as my first C++ project — part of a self-directed path toward robotics.

---

## Demo

https://github.com/user-attachments/assets/fe406f09-74dd-45a2-9c49-09eb126e5d05

---

## Results

![Comparison Plot](docs/comparison.png)

| Metric | With Drag | Without Drag | Difference |
|--------|-----------|--------------|------------|
| Max Height | ~42 m | ~63.7 m | -34% |
| Range | ~109 m | ~163 m | -33% |
| Flight Time | ~4.6 s | ~7.2 s | -36% |
| Peak Time | ~2.69 s | ~3.6 s | -25% |

The drag case is noticeably asymmetric — the projectile climbs slower and falls steeper because drag is proportional to v², so it hits hardest at the beginning when speed is highest.

---

## Physics

Gravity pulls down, drag opposes velocity:

$$\vec{F}_{gravity} = -m \cdot g \cdot \hat{j}$$

$$\vec{F}_{drag} = -\frac{1}{2} \, \rho \, C_d \, A \, |\vec{v}|^2 \, \hat{v}$$

Parameters used: $\rho = 1.225$ kg/m³, $C_d = 0.47$ (sphere), $A = 0.01$ m².

Integration is forward Euler with $\Delta t = 0.001$s.

---

## Project Structure

```
src/
├── domain/              # Vec2, Projectile, forces (gravity + drag)
├── application/         # Simulation loop, IExporter interface
├── infrastructure/      # CSV file writer
├── main.cpp             # Runs simulation → CSV
└── main_visual.cpp      # Runs simulation → Raylib window
```

The domain layer has no dependencies on I/O. The simulation talks to an abstract `IExporter`, and the concrete CSV writer lives in infrastructure. This separation made it easy to add the Raylib visualizer without touching physics code.

---

## Building

Requires a C++17 compiler and CMake 3.20+. Raylib is fetched automatically.

```bash
cmake -B build
cmake --build build

mkdir -p output
./build/app           # outputs CSV
./build/sim_visual    # opens visualization window
```

For the plot: `python scripts/plot_trajectory.py` (needs pandas + matplotlib).

---

## What I Learned

This was my first time writing C++. I came from TypeScript/Python.

Things that tripped me up: the compilation model (headers vs source files, why you get linker errors), name shadowing between variables and functions (had `drag` as both a variable and a function — compiler was not happy), and figuring out CMake.

Things I liked: operator overloading makes physics code read like math (`velocity + acceleration * dt`), and the compiler catches bugs that would be runtime errors in Python.

---

## Roadmap

This is checkpoint 1 in a robotics learning path. Next up: A* pathfinding, then PID control for a differential robot.

---

## Disclosure

README written with AI assistance. Code is mine — written while studying physics simulation and C++ fundamentals through courses and documentation.

---

License: MIT
