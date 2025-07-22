#pragma once
#include "../core/sim_object.hpp"
#include <SFML/Graphics.hpp>

class OrbitObject : public SimObject {
public:
    OrbitObject(float x, float y, float radius, float mass, sf::Color color);

    void update(float /*dt*/) override;
    void render(sf::RenderWindow& window) const override;

private:
    sf::CircleShape shape;
    float mass;
};