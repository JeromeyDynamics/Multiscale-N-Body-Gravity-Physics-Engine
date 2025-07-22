#include "central_mass.hpp"

//the ": mass(m)" initializes the mass private variable with the m value
CentralMass::CentralMass(float x, float y, float radius, float m, sf::Color color) : mass(m) {
    shape.setRadius(radius);
    shape.setOrigin(radius, radius);
    shape.setPosition(x, y);
    shape.setFillColor(color);
}

void CentralMass::update(float) {
    //no physics yet
}

void CentralMass::render(sf::RenderWindow& window) const {
    window.draw(shape);
}