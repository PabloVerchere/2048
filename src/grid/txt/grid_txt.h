#ifndef GRID_TXT_H
#define GRID_TXT_H


#include "../grid.h"



class Grid_txt: public Grid {
public:
    Grid_txt(int);


    void create_rd() override; // abstract method

    void display() const override; // abstract method

    virtual void play() override; // abstract method


    //temp
    void create(int[2]);
};

#endif