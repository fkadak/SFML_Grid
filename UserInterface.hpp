#include "Button.hpp"

class UserInterface{
private:
    std::vector <Button> buttons;
public:
    UserInterface() = default;
    
    void addButton();
};
