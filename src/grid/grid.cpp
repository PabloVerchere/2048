#include "grid.h"
#include "../tile/empty.h"
#include "../tile/number.h"

#include <iostream>


// temp
#include "../tile/txt/number_txt.h"
#include "../tile/txt/empty_txt.h"

Grid::Grid(int s) {
    size = s;

    grid = new Tile**[size];
    for (int i = 0; i < size; i++) {
        grid[i] = new Tile*[size];
    }
}

Grid::~Grid() {
    delete empty;

    for (int i = 0; i < size; i++) {
        delete[] grid[i];
    }
    delete[] grid;
}


bool Grid::move_total(int dir) {
    bool change = false;
    bool init = false;

    change = move(dir);
    change = merge(dir) || change;
    init = change || init; // if change is true 1 time, init stay true

    do {
        change = false;
        change = move(dir);
        
        init = change || init; // if change is true 1 time, init stay true
    } while(change);

    return init;
}


void Grid::exchange(int coord1[2], int coord2[2]) {
    Tile* temp = grid[coord1[0]][coord1[1]];
    grid[coord1[0]][coord1[1]] = grid[coord2[0]][coord2[1]];
    grid[coord2[0]][coord2[1]] = temp;
}


bool Grid::mergeable(int dir, int coord[2]) const { // 0 is up, 1 is right, 2 is down, 3 is left
    int dirH = 0;
    int dirV = 0;

    if(dir == 0) {
        dirV = 1;
    } else if(dir == 1) {
        dirH = -1;
    } else if(dir == 2) {
        dirV = -1;
    } else if(dir == 3) {
        dirH = 1;
    }




    if(!coord_in_grid(coord) || !coord_in_grid(new int[2]{coord[0] + dirV, coord[1] + dirH})) {
        return false;
    }

    // Check if both tiles are instances of Number
    Number* firstNumber = dynamic_cast<Number*>(grid[coord[0]][coord[1]]);
    Number* secondNumber = dynamic_cast<Number*>(grid[coord[0] + dirV][coord[1] + dirH]);


    if (firstNumber && secondNumber) { // Both are Numbers, so we can compare their values
        return firstNumber->getValue() == secondNumber->getValue();
    }

    return false;
}


bool Grid::move(int dir) { // 0 is up, 1 is right, 2 is down, 3 is left
    switch (dir) {
    case 0:
        return move_V(1);
        break;
    
    case 1:
        return move_H(0);
        break;
    
    case 2:
        return move_V(0);
        break;

    case 3:
        return move_H(1);
        break;
    
    default:
        return false;
        break;
    }
}


bool Grid::merge(int dir) { // 0 is up, 1 is right, 2 is down, 3 is left
    switch (dir) {
    case 0:
        return merge_V(1);
        break;
    
    case 1:
        return merge_H(0);
        break;
    
    case 2:
        return merge_V(0);
        break;

    case 3:
        return merge_H(1);
        break;
    
    default:
    return false;
        break;
    }
}


bool Grid::move_H(int dir) { // 0 is right, 1 is left
    bool change = false;

    for(int i = 0; i < size; i++) {
        if(move_H_row(dir, i)) {
            change = true;
        }
    }
    return change;
}


bool Grid::merge_H(int dir) { // 0 is right, 1 is left
    bool change = false;

    for(int i = 0; i < size; i++) {
        if(merge_H_row(dir, i)) {
            change = true;
        }
    }
    return change;
}


bool Grid::move_V(int dir) { // 0 is down, 1 is up
    bool change = false;
    for(int j = 0; j < size; j++) {
        if(move_V_col(dir, j)) {
            change = true;
        }
    }
    return change;
}


bool Grid::merge_V(int dir) { // 0 is down, 1 is up
    bool change = false;
    for(int j = 0; j < size; j++) {
        if(merge_V_col(dir, j)) {
            change = true;
        }
    }
    return change;
}


bool Grid::move_H_row(int dir, int i) { // 0 is right, 1 is left
    bool change = false;

    int j = 0;
    int step = 1;
    if(dir == 1) {
        j = size - 1;
        step = -1;
    }
    
    for(int _ = 0; _ < size; _++) {
        if(j + step >= 0 && j + step < size && dynamic_cast<Number*>(grid[i][j])) {
            int coord[2] = {i, j};

            // while the next tile is in the grid and is empty
            while(j + step >= 0 && j + step < size && dynamic_cast<Empty*>(grid[i][j + step])) {
                change = true;
                exchange(coord, new int[2]{i, j + step});
                coord[0] = i;
                coord[1] = j + step;

                
                j += step;
            }
        }
        j += step;
    }

    return change;
}


bool Grid::merge_H_row(int dir, int i) { // 0 is right, 1 is left
    bool change = false;
    int dir4;

    if(dir) {
        dir4 = 3;
    } else {
        dir4 = 1;
    }


    int j = 0;
    int step = 1;
    if(dir == 0) {
        j = size - 1;
        step = -1;
    }

    for(int _ = 0; _ < size; _++) {
        if(mergeable(dir4, new int[2]{i, j})) {
            change = true;
            int coord[2] = {i, j};

            // increase the value of the first tile
            Number* firstNumber = dynamic_cast<Number*>(grid[i][j]);
            firstNumber->setValue(firstNumber->getValue() * 2);


            // remove the second tile (ie set it to empty)
            grid[i][j + step] = empty->clone();
        }
        j += step;
    }
    return change;
}


bool Grid::move_V_col(int dir, int j) { // 0 is down, 1 is up
    bool change = false;

    int i = 0;
    int step = 1;
    if(dir == 1) {
        i = size - 1;
        step = -1;
    }

    for(int k = 0; k < size; k++) {
        if(i + step >= 0 && i + step < size && dynamic_cast<Number*>(grid[i][j])) {
            int coord[2] = {i, j};

            // while the next tile is in the grid and is empty
            while(i + step >= 0 && i + step < size && dynamic_cast<Empty*>(grid[i + step][j])) {
                change = true;
                exchange(coord, new int[2]{i + step, j});
                coord[0] = i + step;
                coord[1] = j;

                i += step;
            }
        }
        i += step;
    }

    return change;
}


bool Grid::merge_V_col(int dir, int j) { // 0 is down, 1 is up
    bool change = false;
    int dir4;

    if(dir) {
        dir4 = 0;
    } else {
        dir4 = 2;
    }

    int i = 0;
    int step = 1;
    if(dir == 0) {
        i = size - 1;
        step = -1;
    }

    for(int k = 0; k < size; k++) {
        if(mergeable(dir4, new int[2]{i, j})) {
            change = true;

            int coord[2] = {i, j};

            // increase the value of the first tile
            Number* firstNumber = dynamic_cast<Number*>(grid[i][j]);
            firstNumber->setValue(firstNumber->getValue() * 2);

            // remove the second tile (ie set it to empty)
            grid[i + step][j] = empty->clone();
        }
        i += step;
    }
    return change;
}


int Grid::convert_dir(int dir) {
    switch (dir) {
        case 65: // up arrow
            return 0;
            break;
        case 66: // down arrow
            return 2;
            break;
        case 68: // left arrow
            return 3;
            break;
        case 67: // right arrow
            return 1;
            break;
        default:
            return -1;
            break;
    }
}


bool Grid::mergeable_all_direction(int coord[2]) const {
    return (mergeable(0, coord) || mergeable(1, coord) || mergeable(2, coord) || mergeable(3, coord));
}


bool Grid::empty_in_grid() const {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if(dynamic_cast<Empty*>(grid[i][j])) {
                return true;
            }
        }
    }
    return false;
}


bool Grid::mergeable_in_grid() const {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            // Check for all tile if its mergeable
            if(mergeable_all_direction(new int[2]{i, j})) {
                return true;
            }
        }
    }
    return false;
}


bool Grid::is_loose() const {
    // Check if there is an empty tile or a mergeable tile
    return !empty_in_grid() && !mergeable_in_grid();
}

bool Grid::coord_in_grid(int coord[2]) const {
    return coord[0] >= 0 && coord[0] < size && coord[1] >= 0 && coord[1] < size;
}