//used instead of having the guards
#pragma once
#include <SFML/Graphics.hpp>

class CentralMass {
public:
    CentralMass(float x, float y, float radius, sf::Color color = sf::Color::Yellow);
    const sf::CircleShape& getShape() const;

private:
    sf::CircleShape shape;
};