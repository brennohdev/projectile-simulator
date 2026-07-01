#include "simulation.hpp"
#include "../domain/forces.hpp"

Simulation::Simulation(const SimulationConfig& config)
    : config_(config) {}

void Simulation::run(Projectile& projectile) {
    double time = 0;

    while (projectile.is_active() && time < config_.max_time) {
        projectile.apply_force(gravity(projectile.mass()));
        projectile.apply_force(drag(projectile.velocity(), config_.drag));

        projectile.update(config_.dt);
        time += config_.dt;
    }
}
