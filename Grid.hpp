#include "Utilities.hpp"

class Grid{
private:
    unsigned int cells;
    float cellSize;
    std::vector <std::vector <int>> grid;
public:
    Grid() = default;
    Grid(unsigned int cells);
    
    unsigned int getCellCount();

};
