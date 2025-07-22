#pragma once
#include <SFML/Graphics.hpp>

namespace config::colors {
    //basic colors
    //rainbow
    inline const sf::Color red = sf::Color(255,   0,   0);
    inline const sf::Color orange = sf::Color(255, 127,   0);
    inline const sf::Color yellow = sf::Color(255, 255,   0);
    inline const sf::Color green = sf::Color(  0, 255,   0);
    inline const sf::Color blue = sf::Color(  0,   0, 255);
    inline const sf::Color indigo = sf::Color( 75,   0, 130);
    inline const sf::Color violet = sf::Color(148,   0, 211);

    //neutrals
    inline const sf::Color black = sf::Color(  0,   0,   0);
    inline const sf::Color white = sf::Color(255, 255, 255);
    inline const sf::Color gray = sf::Color(128, 128, 128);
    inline const sf::Color lightGray = sf::Color(192, 192, 192);

    //other common colors
    inline const sf::Color brown = sf::Color(165,  42,  42);
    inline const sf::Color cyan = sf::Color(  0, 255, 255);
    inline const sf::Color magenta = sf::Color(255,   0, 255);
    inline const sf::Color pink = sf::Color(255, 192, 203);
    inline const sf::Color teal = sf::Color(  0, 128, 128);
}