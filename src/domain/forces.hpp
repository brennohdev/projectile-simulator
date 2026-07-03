#pragma once
#include "vec2.hpp"

namespace sim {

struct DragParams
{
    double air_density;
    double drag_coef;
    double cross_section;
};

Vec2 gravity(double mass);
Vec2 drag(const Vec2& velocity, const DragParams& params);

}
