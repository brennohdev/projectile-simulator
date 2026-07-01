#pragma once
#include "../domain/forces.hpp"
#include "../domain/projectile.hpp"

struct SimulationConfig
{
    double dt;
    double max_time;
    DragParams drag;
};

class Simulation
{
    public:
        Simulation(const SimulationConfig& config);
        void run(Projectile& projectile /* ,exporter */);

        private:
        SimulationConfig config_;
};