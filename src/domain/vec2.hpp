#pragma once
#include <cmath>

/**
*@brief: Represents a 2D vector for physics calculations.
*/
struct Vector2 {
    double x;
    double y;

    Vector2 operator*(double scalar) const
    {
        return {x * scalar, y*scalar};
    };

    Vector2 operator+(const Vector2& other) const
    {
        return {x + other.x, y + other.y};
    };

    Vector2 operator-(const Vector2& other) const
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

    Vector2 normalize() const
    {
        double mag = magnitude();
        if (mag==0) return {0,0};
        return {x/mag, y/mag};
    }
};
