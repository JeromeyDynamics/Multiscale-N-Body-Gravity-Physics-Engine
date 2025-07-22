#include "window.hpp"

Window::Window(unsigned int w, unsigned int h, const std::string& title) : window(sf::VideoMode(w, h), title) {
    window.setFramerateLimit(60);
}

bool Window::isOpen() const {
    return window.isOpen();
}

bool Window::pollEvent(sf::Event& e) {
    return window.pollEvent(e);
}

void Window::clear() {
    window.clear(sf::Color::Black);
}

void Window::display() {
    window.display();
}

sf::RenderWindow& Window::handle() {
    return window;
}
