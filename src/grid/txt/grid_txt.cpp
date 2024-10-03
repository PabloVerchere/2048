#include <iostream>

#include "grid_txt.h"


Grid_txt::Grid_txt(int size): Grid(size) {};
Grid_txt::~Grid_txt() {};


void Grid_txt::display() const {






    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
};
