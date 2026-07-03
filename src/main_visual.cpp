#include "raylib.h"
#include "domain/vec2.hpp"
#include "domain/projectile.hpp"
#include "domain/forces.hpp"
#include <cmath>

int main() {
    using namespace sim;

    const int screenWidth = 1200;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Projectile Comparison: Drag vs Vacuum");
    SetTargetFPS(60);

    double speed = 50.0;
    double angle_deg = 45.0;
    double angle_rad = angle_deg * M_PI / 180.0;
    double mass = 0.5;

    Vec2 initial_velocity = {speed * cos(angle_rad), speed * sin(angle_rad)};

    Projectile proj_drag({0, 0}, initial_velocity, mass);
    DragParams drag_params = {1.225, 0.47, 0.01};

    Projectile proj_vacuum({0, 0}, initial_velocity, mass);
    DragParams no_drag = {0, 0, 0};

    double dt = 0.01;
    double scale = 5.0;
    int originX = 50;
    int originY = screenHeight - 50;

    const int maxTrail = 5000;
    Vec2 trail_drag[maxTrail];
    int trailCount_drag = 0;
    Vec2 trail_vacuum[maxTrail];
    int trailCount_vacuum = 0;

    while (!WindowShouldClose()) {
        for (int i = 0; i < 5 && proj_drag.is_active(); i++) {
            if (trailCount_drag < maxTrail) {
                trail_drag[trailCount_drag] = proj_drag.position();
                trailCount_drag++;
            }
            proj_drag.apply_force(gravity(proj_drag.mass()));
            proj_drag.apply_force(drag(proj_drag.velocity(), drag_params));
            proj_drag.update(dt);
        }

        for (int i = 0; i < 5 && proj_vacuum.is_active(); i++) {
            if (trailCount_vacuum < maxTrail) {
                trail_vacuum[trailCount_vacuum] = proj_vacuum.position();
                trailCount_vacuum++;
            }
            proj_vacuum.apply_force(gravity(proj_vacuum.mass()));
            proj_vacuum.apply_force(drag(proj_vacuum.velocity(), no_drag));
            proj_vacuum.update(dt);
        }

        BeginDrawing();
        ClearBackground(BLACK);

        for (int i = 1; i < trailCount_vacuum; i++) {
            int x1 = originX + (int)(trail_vacuum[i-1].x * scale);
            int y1 = originY - (int)(trail_vacuum[i-1].y * scale);
            int x2 = originX + (int)(trail_vacuum[i].x * scale);
            int y2 = originY - (int)(trail_vacuum[i].y * scale);
            if (i % 3 != 0) DrawLine(x1, y1, x2, y2, GRAY);
        }

        for (int i = 1; i < trailCount_drag; i++) {
            int x1 = originX + (int)(trail_drag[i-1].x * scale);
            int y1 = originY - (int)(trail_drag[i-1].y * scale);
            int x2 = originX + (int)(trail_drag[i].x * scale);
            int y2 = originY - (int)(trail_drag[i].y * scale);
            DrawLine(x1, y1, x2, y2, BLUE);
        }

        if (proj_drag.is_active()) {
            int px = originX + (int)(proj_drag.position().x * scale);
            int py = originY - (int)(proj_drag.position().y * scale);
            DrawCircle(px, py, 6, RED);
        }

        if (proj_vacuum.is_active()) {
            int px = originX + (int)(proj_vacuum.position().x * scale);
            int py = originY - (int)(proj_vacuum.position().y * scale);
            DrawCircle(px, py, 6, GREEN);
        }

        DrawText("Projectile Comparison", 10, 10, 20, WHITE);
        DrawCircle(20, 50, 5, RED);
        DrawText("With drag (air)", 35, 43, 16, WHITE);
        DrawCircle(20, 75, 5, GREEN);
        DrawText("No drag (vacuum)", 35, 68, 16, WHITE);
        DrawText("Press ESC to close", 10, screenHeight - 25, 16, GRAY);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
