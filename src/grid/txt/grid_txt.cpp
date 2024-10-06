#include <iostream>
#include <random>
#include <conio.h>

#include "grid_txt.h"
#include "../../tile/txt/empty_txt.h"
#include "../../tile/txt/number_txt.h"

using namespace std;





void Grid_txt::create(int co[2]) {
    grid[co[0]][co[1]] = new Number_txt(2);
}

Grid_txt::Grid_txt(int s): Grid(s) {
    // Initialize random seed
    srand(time(0));

    empty = new Empty_txt();

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; ++j) {
            grid[i][j] = new Empty_txt();
        }
    }
}



// init a number tile at a random empty position
void Grid_txt::create_rd() {
    int x, y;

    do {
        x = rand() % size;
        y = rand() % size;
    } while (!dynamic_cast<Empty*>(grid[x][y])); // check if the tile is empty


    grid[x][y] = new Number_txt(generable[rand() % 2]);
};


void Grid_txt::display() const {
    for (int i = 0; i < size; i++) {
        cout << string(8 * size, '#') << "#" << endl;

        cout << "#";
        for (int j = 0; j < size; j++) {
            cout << " ";
            (*grid[i][j]).display();
            cout << '\t';
            cout << "#";
        }
        cout << endl;
    }
    cout << string(8 * size, '#') << "#" << endl;
}


void Grid_txt::play() {
    char arrow;
    int dir;

    cout << "\033c"; // Clear screen

    create_rd();  // Create the initial random cell
    display(); // Display the grid
  
    while (!is_loose()) {
        if (kbhit()) { // Wait for a key to be pressed
            arrow = fgetc(stdin);
            dir = convert_dir(arrow);

            if(dir != -1) { // If the key is an arrow key
                move_total(dir); 
                create_rd(); 
                cout << "\033c";
                display();
            }
        }
    }
}