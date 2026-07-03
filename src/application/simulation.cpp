#include "i_exporter.hpp"
#include "simulation.hpp"
#include "../domain/forces.hpp"

namespace sim {

Simulation::Simulation(const SimulationConfig& config)
    : config_(config) {}

void Simulation::run(Projectile& projectile, IExporter& exporter) {
    double time = 0;

    while (projectile.is_active() && time < config_.max_time) {
        exporter.write(time, projectile.position());
        projectile.apply_force(gravity(projectile.mass()));
        projectile.apply_force(drag(projectile.velocity(), config_.drag_params));

        projectile.update(config_.dt);
        time += config_.dt;
    }
    exporter.close();
}

} 
