#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>

struct Body {
    sf::CircleShape shape;
    sf::Vector2f velocity;
};

void createBody(std::vector<Body> &bodies, float x, float y) {
    Body b;
    b.shape = sf::CircleShape(10.f);
    b.shape.setOrigin(10.f, 10.f);
    b.shape.setPosition({x, y});
    b.shape.setFillColor(sf::Color::Cyan);
    b.velocity = {0.f, 0.f};
    bodies.push_back(b);
}

int main() {
    sf::RenderWindow window({800, 600}, "Attraction Demo");
    window.setFramerateLimit(200);

    std::vector<Body> bodies;
    sf::Clock clock;
    const sf::Vector2f center{400.f, 300.f};
    const float strength = 300.f;

    //making bodies
    createBody(bodies, 200, 500);
    createBody(bodies, 100, 400);
    createBody(bodies, 500, 700);
    createBody(bodies, 700, 100);

    while (window.isOpen()) {
        sf::Event e;
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed)
                window.close();
        }

        float dt = clock.restart().asSeconds();
        for (auto& b : bodies) {
            sf::Vector2f diff = center - b.shape.getPosition();
            float dist = std::sqrt(diff.x*diff.x + diff.y*diff.y);
            if (dist > 1.f) {
                sf::Vector2f dir = diff / dist;
                b.velocity += dir * strength * dt;
                b.shape.move(b.velocity * dt);
            }
        }

        window.clear(sf::Color::Black);
        for (auto& b : bodies)
            window.draw(b.shape);
        window.display();
    }
    return 0;
}