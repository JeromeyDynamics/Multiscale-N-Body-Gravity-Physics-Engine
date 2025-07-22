#pragma once
#include <SFML/Graphics.hpp>

namespace config::render {
    //window dimensions
    inline constexpr unsigned int windowWidth  = 800;
    inline constexpr unsigned int windowHeight = 600;

    //frame rate cap
    inline constexpr unsigned int frameRateLimit = 60;

    //colors
    inline const sf::Color backgroundColor = sf::Color::Black;
    inline const sf::Color centerMassColor = sf::Color::Yellow;
    inline const sf::Color orbitersColor = sf::Color::Blue;
}
