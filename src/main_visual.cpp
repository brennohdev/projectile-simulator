#include "raylib.h"
#include "domain/vec2.hpp"
#include "domain/projectile.hpp"
#include "domain/forces.hpp"
#include <cmath>

int main() {
    const int screenWidth = 1200;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Projectile Simulation");
    SetTargetFPS(60);

    double speed = 50.0;
    double angle_deg = 45.0;
    double angle_rad = angle_deg * M_PI / 180.0;
    double mass = 0.5;

    Vec2 initial_velocity = {speed * cos(angle_rad), speed * sin(angle_rad)};
    Projectile projectile({0, 0}, initial_velocity, mass);

    DragParams drag_params = {1.225, 0.47, 0.01};
    double dt = 0.01;

    double scale = 8.0;
    int originX = 50;
    int originY = screenHeight - 50;

    const int maxTrail = 5000;
    Vec2 trail[maxTrail];
    int trailCount = 0;

    while (!WindowShouldClose()) {
        for (int i = 0; i < 5 && projectile.is_active(); i++) {
            if (trailCount < maxTrail) {
                trail[trailCount] = {projectile.position().x, projectile.position().y};
                trailCount++;
            }

            projectile.apply_force(gravity(projectile.mass()));
            projectile.apply_force(drag(projectile.velocity(), drag_params));
            projectile.update(dt);
        }

        BeginDrawing();
        ClearBackground(BLACK);

        for (int i = 1; i < trailCount; i++) {
            int x1 = originX + (int)(trail[i-1].x * scale);
            int y1 = originY - (int)(trail[i-1].y * scale);
            int x2 = originX + (int)(trail[i].x * scale);
            int y2 = originY - (int)(trail[i].y * scale);
            DrawLine(x1, y1, x2, y2, BLUE);
        }

        if (projectile.is_active()) {
            int px = originX + (int)(projectile.position().x * scale);
            int py = originY - (int)(projectile.position().y * scale);
            DrawCircle(px, py, 6, RED);
        }

        DrawText("Projectile with Aerodynamic Drag", 10, 10, 20, WHITE);
        DrawText("Press ESC to close", 10, 35, 16, GRAY);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
