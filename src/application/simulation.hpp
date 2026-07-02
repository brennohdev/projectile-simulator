#pragma once
#include "../domain/forces.hpp"
#include "../domain/projectile.hpp"
#include "i_exporter.hpp"

struct SimulationConfig
{
    double dt;
    double max_time;
    DragParams drag_params;
};

class Simulation
{
    public:
        Simulation(const SimulationConfig& config);
        void run(Projectile& projectile, IExporter& exporter);

        private:
        SimulationConfig config_;
};