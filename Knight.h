#ifndef __KNIGHT_H__
#define __KNIGHT_H__

#include <vector>
#include <iostream>
#include <string>
#include "Board.h"
#include "Piece.h"

class Knight: public Piece {
    int row;
    int col;
    bool color;
    char letter;
public:
    Knight(int row, int col, bool color, char letter);
    ~Knight();
    char getLetter();
    void move(int inCol, int inRow);
    bool moveable(int inCol, int inRow, Board theBoard);
};

#endif
