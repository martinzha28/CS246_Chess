#ifndef __PIECE_H__
#define __PIECE_H__

#include <vector>
#include <iostream>
#include <string>
#include "Board.h"

class Piece {
    protected:
        int row;
        int col;
        bool color; // false for black, true for white
        char letter;
    public:
        virtual void move(int inCol, int inRow); // think this is useless
        virtual bool moveable(int inCol, int inRow);
        virtual std::vector<std::string> squaresWatching(); // so is this
        virtual bool underThreat();
        ~Piece();
}

#endif