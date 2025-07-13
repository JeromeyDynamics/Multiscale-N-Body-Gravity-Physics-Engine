#include <SFML/Graphics.hpp>
#include "src/entities/central_mass.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Central Mass Demo");
    window.setFramerateLimit(60);

    // center at (400,300), radius 40, red color
    CentralMass center(400.f, 300.f, 40.f, sf::Color::Red);

    while (window.isOpen()) {
        sf::Event ev;
        while (window.pollEvent(ev))
            if (ev.type == sf::Event::Closed)
                window.close();

        window.clear(sf::Color::Black);
        window.draw(center.getShape());
        window.display();
    }

    return 0;
}
