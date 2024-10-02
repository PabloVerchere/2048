#ifndef NUMBER_H
#define NUMBER_H


#include "tile.h"


class Number: public Tile {
private:
    int value;

public:
    Number() {}
    ~Number() {}
    

    int getValue() const {}

    void setValue(int) {}
};

#endif