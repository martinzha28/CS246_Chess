#ifndef __ROOK_H__
#define __ROOK_H__

#include <vector>
#include <iostream>
#include <string>
#include "Piece.h"

class Rook: public Piece {
    int row;
    int col;
    bool color;
    char letter;
public:
    Rook(int row, int col, bool color, char letter);
    void move(int inCol, int inRow);
    bool moveable(int inCol, int inRow);
    std::vector<std::string> squaresWatching();
    bool underThreat();
};

#endif