#include <SFML/Graphics.hpp>

int main() {
    // Create a window
    sf::RenderWindow window({640, 480}, "Simple SFML Test");

    // A moving circle
    sf::CircleShape circle(20.f);
    circle.setFillColor(sf::Color::Cyan);
    circle.setPosition(0.f, 240.f);

    sf::Clock clock;
    while (window.isOpen()) {
        sf::Event ev;
        while (window.pollEvent(ev))
            if (ev.type == sf::Event::Closed)
                window.close();

        // Move at 100 pixels/sec, wrap around
        float dt = clock.restart().asSeconds();
        circle.move(100.f * dt, 0.f);
        if (circle.getPosition().x > 640)
            circle.setPosition(-40.f, 240.f);

        window.clear();
        window.draw(circle);
        window.display();
    }
    return 0;
}
