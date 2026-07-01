#include "forces.hpp"
#include "vec2.hpp"

constexpr double G = 9.81;

/**
@brief: Simple function that implements the Gravitacional Force calculation
@return: Resultant Vector 2D
*/
Vector2 gravity(double mass) {
    return {0, -mass * G};
}

Vector2 drag(const Vector2& velocity, const DragParams& params)
{
    double speed = velocity.magnitude();

    if (speed == 0) return {0,0};

    double force_magnitude = 0.5
        * params.air_density
        * params.drag_coef
        * params.cross_section
        * speed * speed;

    Vector2 direction = velocity.normalize();

    return direction * (-force_magnitude);
}