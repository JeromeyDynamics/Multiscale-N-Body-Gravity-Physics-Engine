#pragma once
#include <SFML/Graphics.hpp>

//this is the base interface for all objects in the simulation
struct SimObject {
    //virtual means that the object here can be overridden in derived classes
    virtual ~SimObject() = default;
    virtual void update(float dt) = 0;
    virtual void render(sf::RenderWindow& window) const = 0;
};
