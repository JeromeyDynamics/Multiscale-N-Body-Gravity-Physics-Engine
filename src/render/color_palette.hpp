#pragma once
#include <SFML/Graphics.hpp>
#include "../config/render_constants.hpp"

namespace RenderColors {
    inline const sf::Color background = config::render::backgroundColor;
    inline const sf::Color centralMass  = config::render::centerMassColor;
    inline const sf::Color orbiters    = config::render::orbitersColor;
}