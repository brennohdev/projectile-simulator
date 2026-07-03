#pragma once
#include "vec2.hpp"

namespace sim {

class Projectile {
public:
    Projectile(Vec2 position, Vec2 velocity, double mass);

    void apply_force(const Vec2& force);
    void update(double dt);

    Vec2 position() const;
    Vec2 velocity() const;
    double mass() const;
    bool is_active() const;

private:
    Vec2 position_;
    Vec2 velocity_;
    Vec2 accumulated_force_;
    double mass_;
};

} 
