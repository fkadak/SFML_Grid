#include "UserInterface.hpp"

class Application{
private:
    sf::RenderWindow window;
    AppState currentState;
    
    std::vector <UserInterface> UI;
public:
    Application() = default;

    void run();
    void initialize();
};
