#include "projectile.hpp"
#include "vec2.hpp"

Projectile::Projectile(Vector2 position, Vector2 velocity, double mass)
    : position_(position), velocity_(velocity), accumulated_force_({0, 0}), mass_(mass) {}


    Vector2 Projectile::position() const 
    {
        return position_;
    }

    Vector2 Projectile::velocity() const 
    {
        return velocity_;
    }

    bool Projectile::is_active() const
    {
        return position_.y >= 0;
    }

    double Projectile::mass() const 
    {
    return mass_;
    }

    void Projectile::apply_force(const Vector2& force) 
    {
    accumulated_force_ = accumulated_force_ + force;
    }

    void Projectile::update(double dt)
    {
        // a = F / m
        Vector2 acceleration = accumulated_force_ * (1.0 / mass_);

        // v = v + a * dt
        velocity_ = velocity_ + (acceleration * dt);

        // pos = pos + v * dt
        position_ = position_ + (velocity_ * dt);

        accumulated_force_ = {0,0};
    }
