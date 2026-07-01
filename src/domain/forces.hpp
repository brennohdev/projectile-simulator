#pragma once
#include "vec2.hpp"

struct DragParams
{
    double air_density;
    double drag_coef;
    double cross_section;
};

Vector2 gravity(double mass);
Vector2 drag(const Vector2& velocity, const DragParams& params);