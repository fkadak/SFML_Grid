#ifndef UTILITIES_HPP
#define UTILITIES_HPP
#endif

#include <SFML/Graphics.hpp>
#include <vector>

enum AppState {
    MAIN_MENU = 0,
    MAP_GEN = 1
};

std::vector<std::pair <std::string, sf::Color>> colors;
