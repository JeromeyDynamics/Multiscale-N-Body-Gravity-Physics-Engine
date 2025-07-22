#include "orbit_object.hpp"

OrbitObject::OrbitObject(float x, float y, float radius, float m, sf::Color color) : mass(m) {
    shape.setRadius(radius);
    shape.setOrigin(radius, radius);
    shape.setPosition(x, y);
    shape.setFillColor(color);
}

void OrbitObject::update(float) {
    //no physics yet
}

void OrbitObject::render(sf::RenderWindow& window) const {
    window.draw(shape);
}