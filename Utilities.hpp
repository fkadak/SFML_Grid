#ifndef UTILITIES_HPP
#define UTILITIES_HPP
#endif

#include <SFML/Graphics.hpp>
#include <vector>

enum AppState {
    MAIN_MENU = 0,
    MAP_GEN = 1
};

struct Point {
    int x;
    int y;
};
