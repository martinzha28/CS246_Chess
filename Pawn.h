#ifndef __PAWN_H__
#define __PAWN_H__

#include <vector>
#include <iostream>
#include <string>
#include "Piece.h"

class Pawn: public Piece {
    int row;
    int col;
    bool color;
    char letter;
    bool twoStep;
    bool enPassent;
public:
    Pawn(int row, int col, bool color, char letter);
    void move(int inCol, int inRow);
    bool moveable(int inCol, int inRow);
    std::vector<std::string> squaresWatching();
    bool underThreat();
};

#endif