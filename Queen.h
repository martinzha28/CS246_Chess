#ifndef __QUEEN_H__
#define __QUEEN_H__

#include <vector>
#include <iostream>
#include <string>
#include "Piece.h"

class Queen: public Piece {
    int row;
    int col;
    bool color;
    char letter;
public:
    Queen(int row, int col, bool color, char letter);
    void move(int inCol, int inRow);
    bool moveable(int inCol, int inRow);
    std::vector<std::string> squaresWatching();
    bool underThreat();
};

#endif