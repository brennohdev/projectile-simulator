#pragma once
#include "vec2.hpp"

class Projectile {
public:
    Projectile(Vector2 position, Vector2 velocity, double mass);

    void apply_force(const Vector2& force);
    void update(double dt);

    Vector2 position() const;
    Vector2 velocity() const;
    double mass() const;
    bool is_active() const;

private:
    Vector2 position_;
    Vector2 velocity_;
    Vector2 accumulated_force_;
    double mass_;
};
