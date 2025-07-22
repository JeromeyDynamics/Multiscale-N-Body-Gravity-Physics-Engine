#include <memory>
#include "core/object_manager.hpp"
#include "entities/central_mass.hpp"
#include "render/renderer.hpp"

int main() {
    ObjectManager manager;
    Renderer renderer(800, 600, "THE SUN!!!");

    //defines and creates the central mass object
    auto center = std::make_shared<CentralMass>(
        400.f, // x
        300.f, // y
        50.f, // radius
        1e12f, // mass
        sf::Color::Yellow // color
    );
    manager.addObject(center);

    sf::Clock clock;
    while (renderer.isOpen()) {
        renderer.processEvents();

        float dt = clock.restart().asSeconds();
        manager.updateAll(dt);

        renderer.clear();
        renderer.renderAll(manager);
        renderer.display();
    }

    return 0;
}
