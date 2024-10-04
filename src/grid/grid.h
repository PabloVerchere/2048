#ifndef GRID_H
#define GRID_H


#include <vector>

#include "../tile/tile.h"


class Grid {
    protected:
        bool win;
        int score;
        int size;
        std::vector<std::vector<Tile>> grid;


    public:
        Grid(int);
        ~Grid();

        bool is_loose() const;

        int getScore() const;

        const std::vector<std::vector<Tile>>& getGrid() const;

        void move(int);

        void merge(int[2], int); // take a list of two coordinates and a direction


        virtual void display() const = 0; // abstract method
};

#endif // GRID_H