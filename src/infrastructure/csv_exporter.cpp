#include "csv_exporter.hpp"

CsvExporter::CsvExporter(const std::string& path)
    : file_(path)
    {
        file_ << "time,x,y" << "\n";
    }

void CsvExporter::write(double time, const Vec2& position)
{
    file_ << time << "," << position.x << "," << position.y << "\n";
}

void CsvExporter::close()
{
    file_.close();
}