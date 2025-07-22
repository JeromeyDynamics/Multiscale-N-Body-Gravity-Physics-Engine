#pragma once
#include <SFML/Graphics.hpp>
#include "../core/object_manager.hpp"

class Renderer {
public:
    //specifies the window dimensions and title
    Renderer(unsigned int width = 800, unsigned int height = 600, const std::string& title = "N-Body Gravity Sim");

    //checks if the window is still open
    bool isOpen() const;

    //handles window events
    void processEvents();

    //clears the window with a black background
    void clear();

    //renders all objects managed by the ObjectManager
    void renderAll(const ObjectManager& mgr);

    //displays the rendered frame
    void display();

private:
    sf::RenderWindow window;
};