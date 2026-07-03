#include <cmath>
#include "domain/projectile.hpp"
#include "domain/forces.hpp"
#include "application/simulation.hpp"
#include "infrastructure/csv_exporter.hpp"

int main() {
    using namespace sim;

    double speed = 50.0;        // m/s
    double angle_deg = 45.0;    // degrees
    double mass = 0.5;          // kg

    double angle_rad = angle_deg * M_PI / 180.0;
    Vec2 initial_velocity = {
        speed * cos(angle_rad),
        speed * sin(angle_rad)
    };

    Projectile projectile({0, 0}, initial_velocity, mass);

    DragParams drag_params = {1.225, 0.47, 0.01};
    SimulationConfig config = {0.001, 20.0, drag_params};

    CsvExporter exporter("output/with_drag.csv");

    Simulation simulation(config);
    simulation.run(projectile, exporter);

    return 0;
}
