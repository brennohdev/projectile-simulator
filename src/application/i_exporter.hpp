#pragma once
#include "../domain/vec2.hpp"

namespace sim {

class IExporter
{
public:
    virtual ~IExporter() = default;
    virtual void write(double time, const Vec2& position) = 0;
    virtual void close() = 0;
};

}
