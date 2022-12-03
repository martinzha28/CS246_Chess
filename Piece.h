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
        char letter;
    public:
        virtual void move(string coords);
        virtual bool moveable(string coords);
        virtual std::vector<std::string> squaresWatching();
        virtual bool underThreat();
}

#endif