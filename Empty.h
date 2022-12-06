#ifndef __EMPTY_H__
#define __EMPTY_H__

#include <vector>
#include <iostream>
#include <string>
#include "Piece.h"

class Empty: public Piece {
    int row;
    int col;
    char letter = 0;
public:
    Empty(row, col);
    void move(int inCol, int inRow);
    bool moveable(int inCol, int inRow);
    std::vector<std::string> squaresWatching();
    bool underThreat();
};

#endif