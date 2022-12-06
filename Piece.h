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
        virtual ~Piece();
        virtual char getLetter() = 0;
        virtual int getRow() = 0;
        virtual int getCol() = 0;
        virtual bool getColor() = 0;
        virtual bool underThreat(std::vector< std::vector<Piece *>> piecePosition, Board theBoard) = 0;
        virtual bool moveable(int col, int row, Board theBoard) = 0;
};

#endif
