#include <SFML/Graphics.hpp>
#include <memory>
#include "core/simulation.hpp"
#include "entities/central_mass.hpp"
#include "entities/orbit_object.hpp"
#include "config/color_constants.hpp"

int main() {
    Simulation sim;

    //Objects:
    const auto Sun = std::make_shared<CentralMass>(
        400.f, // x
        300.f, // y
        139.f, // radius
        4.385e30f, // mass
        config::colors::yellow // color
    );

    sim.addObject(Sun);

    const auto Jupiter = std::make_shared<OrbitObject>(
        600.f, // x
        200.f, // y
        5.02f, // radius
        4.18e27f, // mass
        config::colors::brown // color
    );

    sim.addObject(Jupiter);

    sim.run();

    return 0;
}
