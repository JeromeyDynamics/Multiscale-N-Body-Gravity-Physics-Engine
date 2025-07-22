#include "renderer.hpp"

Renderer::Renderer(unsigned int w, unsigned int h, const std::string& title) : window(w, h, title) {

}

bool Renderer::isOpen() const {
    return window.isOpen();
}

void Renderer::processEvents() {
    sf::Event e;
    while (window.pollEvent(e)) {
        if (e.type == sf::Event::Closed)
            window.handle().close();
    }
}

void Renderer::clear() {
    window.clear();
}

void Renderer::renderAll(const ObjectManager& mgr) {
    for (const auto& obj : mgr.getObjects()) {
        obj->render(window.handle());
    }
}

void Renderer::display() {
    window.display();
}
