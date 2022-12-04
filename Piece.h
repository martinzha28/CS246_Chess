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
        bool color;
    public:
        int getRow();
        int getCol();
        virtual void move(int col, int row);
        virtual bool moveable(int col, int row);
        virtual std::vector<std::string> squaresWatching();
        virtual bool underThreat();
        ~Piece();
};

#endif