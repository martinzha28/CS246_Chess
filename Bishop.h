#ifndef __BISHOP_H__
#define __BISHOP_H__

#include <vector>
#include <iostream>
#include <string>
#include "Board.h"
#include "Piece.h"

class Bishop: public Piece {
protected:
    int row;
    int col;
    bool color;
    char letter;
public:
    Bishop(int row, int col, bool color, char letter);
    ~Bishop();
    char getLetter();
    void move(int inCol, int inRow);
    bool moveable(int inCol, int inRow, Board theBoard);
};

#endif
