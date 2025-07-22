#include <memory>
#include "core/simulation.hpp"
#include "entities/central_mass.hpp"
#include <SFML/Graphics.hpp>

int main() {
    Simulation sim;

    //defines and creates the central mass object
    auto sun = std::make_shared<CentralMass>(
        400.f, // x
        300.f, // y
        50.f, // radius
        1e12f, // mass
        sf::Color::Yellow // color
    );

    sim.addObject(sun);

    sim.run();

    return 0;
}
