#ifndef GRID_TXT_H
#define GRID_TXT_H


#include "../grid.h"


class Grid_txt: public Grid {
public:
    Grid_txt(int);
    
    void display() const override; // abstract method
};

#endif