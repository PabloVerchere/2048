#ifndef EMPTY_H
#define EMPTY_H

#include "tile.h"



class Empty: public Tile {
    public:
        virtual Empty* clone() const = 0;
};

#endif