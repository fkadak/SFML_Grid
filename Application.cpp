#include "Applicaiton.hpp"
#include "Utilities.hpp"

void Application::initialize(){
    window.create(sf::VideoMode(1200, 1000), "test");

    sf::Color DarkGray(44, 47, 51);
    sf::Color LightGray(153, 170, 181);
    
    currentState = AppState::MAIN_MENU;

    UserInterface mainMenu;
    UserInterface mapScreen;    
};
