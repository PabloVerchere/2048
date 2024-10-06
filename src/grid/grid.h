#ifndef GRID_H
#define GRID_H


#include "../tile/tile.h"
#include "../tile/empty.h"



class Grid {
    protected:
        int size;
        int generable[2] = {2, 4}; // temp
        Empty* empty;
        Tile*** grid; // 2D array of pointers to Tile
    

    public:
        Grid(int);
        ~Grid();


        virtual void create_rd() = 0; // abstract method

        virtual void display() const = 0; // abstract method

        virtual void play() = 0; // abstract method


        bool move_total(int); // take a direction and move then merge the tiles while possible

        void exchange(int[2], int[2]); // exchange 2 tiles in the grid

        bool mergeable(int, int[2]) const; // take a direction and a list of two coordinates
        
        bool move(int);
        bool merge(int);

        bool move_H(int);
        bool merge_H(int);

        bool move_V(int);
        bool merge_V(int);

        bool move_H_row(int, int);
        bool merge_H_row(int, int);

        bool move_V_col(int, int);
        bool merge_V_col(int, int);

        int convert_dir(int); // convert a direction to a number

        bool mergeable_all_direction(int[2]) const;

        bool empty_in_grid() const;
        bool mergeable_in_grid() const;

        bool is_loose() const;

        bool coord_in_grid(int[2]) const;
};

#endif // GRID_H