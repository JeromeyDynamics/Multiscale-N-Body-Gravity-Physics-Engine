#pragma once
#include <memory>
#include <vector>
#include "sim_object.hpp"

class ObjectManager {
public:
    //adds a pointer to a SimObject to the objects vector
    void addObject(std::shared_ptr<SimObject> obj);

    //moves every object by dt
    void updateAll(float dt);

    //draws every object into the given window
    void renderAll(sf::RenderWindow& window) const;

    //returns the objects vector
    const std::vector<std::shared_ptr<SimObject>>& getObjects() const;

private:
    std::vector<std::shared_ptr<SimObject>> objects;
};