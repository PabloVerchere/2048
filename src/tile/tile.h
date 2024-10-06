#ifndef TILE_H
#define TILE_H



class Tile {
    public:
        Tile();
        virtual ~Tile();

        virtual void display() const = 0; // abstract method
};

#endif