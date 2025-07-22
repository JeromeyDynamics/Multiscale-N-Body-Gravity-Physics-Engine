#pragma once
#include "window.hpp"
#include "../core/object_manager.hpp"

class Renderer {
public:
    Renderer(unsigned int w, unsigned int h, const std::string& title);

    bool isOpen() const;
    void processEvents();
    void clear();
    void renderAll(const ObjectManager& mgr);
    void display();

private:
    Window window;
};
