#pragma once
#include <memory>
#include <SFML/System/Clock.hpp>
#include "object_manager.hpp"
#include "../render/renderer.hpp"

class Simulation {
public:
    Simulation();    

    //adds any SimObject to the simulation through a pointer
    void addObject(std::shared_ptr<SimObject> obj);

    //runs the main loop
    void run();

private:
    void processEvents();
    void update();
    void render();

    const float dt;      //time step fetched each frame
    ObjectManager manager;
    Renderer renderer;
    sf::Clock clock;
};