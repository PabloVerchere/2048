#include "grid.h"
#include "empty.h"


Grid::Grid(int s) {
    size = s;

    grid = new Tile**[size];
    for (int i = 0; i < size; i++) {
        grid[i] = new Tile*[size];

        for (int j = 0; j < size; ++j) {
            grid[i][j] = new Empty(); // 2 solve
        }
    }
};

Grid::~Grid() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; ++j) {
            delete grid[i][j];
        }
        delete[] grid[i];
    }
    delete[] grid;
};