#ifndef __MOVE_H__
#define __MOVE_H__

#include <vector>
#include <iostream>
#include <string>
#include "Board.h"
#include "Piece.h"

class Move {
    public:
    int startRow;
    int startCol;
    int endRow;
    int endCol;
    Move(int startCol, int startRow, int endCol, int endRow);

    int getStartRow();
    int getStartCol();
    int getEndRow();
    int getEndCol();
};

#endif
