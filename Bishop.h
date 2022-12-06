#ifndef __BISHOP_H__
#define __BISHOP_H__

#include <vector>
#include <iostream>
#include <string>
#include "Board.h"
#include "Piece.h"

class Bishop: public Piece {
    int row;
    int col;
    bool color;
    char letter;
public:
    Bishop(int row, int col, bool color, char letter);
    void move(int inCol, int inRow);
    bool moveable(int inCol, int inRow);
    bool underThreat();
};

#endif