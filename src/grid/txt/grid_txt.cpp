#include "grid_txt.h"


void Grid_txt::display() const {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            (*grid[i][j]).display();
        }
        std::cout << std::endl;
    }
}