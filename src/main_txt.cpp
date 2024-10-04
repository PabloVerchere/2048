#include <iostream>

#include "./grid/txt/grid_txt.h"



using namespace std;


int main() {
    cout  << "Hello, World!" << endl;

    Grid_txt g(5);
    g.display();

    return 0;
}