#include "renderer.hpp"

Renderer::Renderer(unsigned int width, unsigned int height, const std::string& title) : window(sf::VideoMode(width, height), title) {
    window.setFramerateLimit(60);
}

bool Renderer::isOpen() const {
    return window.isOpen();
}

void Renderer::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void Renderer::clear() {
    window.clear(sf::Color::Black);
}

void Renderer::renderAll(const ObjectManager& mgr) {
    for (const auto& obj : mgr.getObjects()) {
        obj->render(window);
    }
}

void Renderer::display() {
    window.display();
}