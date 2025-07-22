#pragma once
#include <SFML/Graphics.hpp>

class Window {
public:
    Window(unsigned int w, unsigned int h, const std::string& title);
    bool isOpen() const;
    bool pollEvent(sf::Event& e);
    void clear();
    void display();
    sf::RenderWindow& handle();

private:
    sf::RenderWindow window;
};
