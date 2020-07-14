#include "Grid.hpp"

Grid::Grid(unsigned int cells) {
    std::vector <std::vector <int>> tmp(cells);
    for(unsigned int i = 0; i < cells; i++) {
        for(unsigned int j = 0; j < cells; j++) {
            grid[i].push_back(0);
        }
    }
}

unsigned int Grid::getCellCount() {return cells;}
