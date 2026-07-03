#pragma once
#include "../application/i_exporter.hpp"
#include <fstream>
#include <string>

namespace sim {

class CsvExporter : public IExporter
{
public:
    explicit CsvExporter(const std::string& path);
    void write(double time, const Vec2& position) override;
    void close() override;

private:
    std::ofstream file_;
};

}
