#ifndef GRID_TXT_H
#define GRID_TXT_H


#include <iostream>

#include "../grid.h"


class Grid_txt: public Grid {
public:
    void display() const override; // abstract method
};

#endif