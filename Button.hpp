#include "Utilities.hpp"

class Button {
private:
    sf::Vector2f coords;
    int height;
    int width;
    sf::Text buttonText;
    std::vector <sf::Shape*> design;
private:
    Button() = default;
    Button(sf::Vector2f, int, int);

    bool isInside(sf::Vector2f);
    std::string getText();
};
