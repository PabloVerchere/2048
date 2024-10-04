#include <iostream>
#include "grid_txt.h"
#include "../../tile/txt/empty_txt.h"

using namespace std;


Grid_txt::Grid_txt(int s): Grid(s) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; ++j) {
            grid[i][j] = new Empty_txt();
        }
    }
}

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