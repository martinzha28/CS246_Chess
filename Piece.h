#ifndef __PIECE_H__
#define __PIECE_H__

#include <vector>
#include <iostream>
#include <string>
#include "Board.h"

class Board;

class Piece {
    protected:
        
    public:
        int row;
        int col;
        bool color;
        char letter;
        int getRow();
        int getCol();
        // virtual std::vector<std::string> squaresWatching();
        bool underThreat(std::vector< std::vector<Piece *>>, Board theBoard);
        bool getColor();
        virtual char getLetter() = 0;
        virtual ~Piece();
        virtual void move(int col, int row) = 0;
        virtual bool moveable(int col, int row, Board theBoard) = 0;
};

#endif
