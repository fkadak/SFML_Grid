#include "Button.hpp"

class Application{
private:
    sf::RenderWindow window;
    AppState currentState;
    std::vector <Button> buttons;
public:
    Application();

    void run();
};
