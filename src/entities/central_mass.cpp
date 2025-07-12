#include "central_mass.h++"

CentralMass::CentralMass(float x, float y, float radius, sf::Color color)
{
    shape.setRadius(radius);
    shape.setOrigin(radius, radius);
    shape.setPosition(x, y);
    shape.setFillColor(color);
}

const sf::CircleShape& CentralMass::getShape() const
{
    return shape;
}