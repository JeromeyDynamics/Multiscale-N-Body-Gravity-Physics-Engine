#include "simulation.hpp"

Simulation::Simulation() : dt(0.f), manager(), renderer(800, 600, "N-Body Simulation"), clock() {

}

void Simulation::addObject(std::shared_ptr<SimObject> obj) {
    manager.addObject(std::move(obj));
}

void Simulation::run() {
    //uses clock to measure dt each frame
    while (renderer.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Simulation::processEvents() {
    renderer.processEvents();
}

void Simulation::update() {
    //computes the dt since last frame
    float elapsed = clock.restart().asSeconds();
    manager.updateAll(elapsed);
}

void Simulation::render() {
    renderer.clear();
    renderer.renderAll(manager);
    renderer.display();
}