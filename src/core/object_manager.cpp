#include "object_manager.hpp"

//std::shared_ptr<SimObject> is a pointer to an object in the simulation
void ObjectManager::addObject(std::shared_ptr<SimObject> obj) {
    //std::move(obj) gives access to the object pointer to the objects vector
    //appends a new pointer to a new object to the objects vector
    objects.push_back(std::move(obj));
}

void ObjectManager::updateAll(float dt) {
    //goes through the objects vector
    for (auto& obj : objects) {
        //uses the virtual update function of the current object in the simulation
        obj->update(dt);
    }
}

void ObjectManager::renderAll(sf::RenderWindow& window) const {
    //goes through the objects vector
    for (const auto& obj : objects) {
        //uses the virtual render function of the current object in the simulation
        obj->render(window);
    }
}

const std::vector<std::shared_ptr<SimObject>>& ObjectManager::getObjects() const {
    return objects;
}