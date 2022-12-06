#ifndef __QUEEN_H__
#define __QUEEN_H__

#include <vector>
#include <iostream>
#include <string>
#include "Board.h"
#include "Piece.h"

class Queen: public Piece {
    int row;
    int col;
    bool color;
    char letter;
public:
    Queen(int row, int col, bool color, char letter);
    ~Queen();
    char getLetter();
    void move(int inCol, int inRow);
    bool moveable(int inCol, int inRow, Board theBoard);
};

#endif
