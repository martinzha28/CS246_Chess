#ifndef __KNIGHT_H__
#define __KNIGHT_H__

#include <vector>
#include <iostream>
#include <string>
#include "Piece.h"

class Knight: public Piece {
    int row;
    int col;
    bool color;
    char letter;
public:
    Knight(row, col, color, letter);
    void move(int inCol, int inRow);
    bool moveable(int inCol, int inRow);
    std::vector<std::string> squaresWatching();
    bool underThreat();
};

#endif