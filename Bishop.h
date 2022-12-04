#ifndef __BISHOP_H__
#define __BISHOP_H__

#include <vector>
#include <iostream>
#include <string>
#include "Piece.h"

class Bishop: public Piece {
    int row;
    int col;
    bool color;
    char letter;
public:
    Bishop(row, col, color, letter);
    void move(int inCol, int inRow);
    bool moveable(int inCol, int inRow);
    std::vector<std::string> squaresWatching();
    bool underThreat();
};

#endif