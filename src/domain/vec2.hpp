#pragma once
#include <cmath>

namespace sim {

/**
*@brief: Represents a 2D vector for physics calculations.
*/
struct Vec2 {
    double x;
    double y;

    Vec2 operator*(double scalar) const
    {
        return {x * scalar, y*scalar};
    };

    Vec2 operator+(const Vec2& other) const
    {
        return {x + other.x, y + other.y};
    };

    Vec2 operator-(const Vec2& other) const
    {
        return {x - other.x, y - other.y};
    };

    /**
     * @brief Returns the magnitude (length) of the vector.
     * @return The Euclidean norm: sqrt(x² + y²)
     */
    double magnitude() const
    {
        return sqrt(x * x + y * y);
    }

    Vec2 normalize() const
    {
        double mag = magnitude();
        if (mag==0) return {0,0};
        return {x/mag, y/mag};
    }
};

}
