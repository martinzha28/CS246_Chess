#ifndef __KING_H__
#define __KING_H__

#include <vector>
#include <iostream>
#include <string>
#include "Piece.h"

class King : public Piece
{
protected:
    bool canCastle;
    bool inCheck;
    int row;
    int col;
    bool color;
    char letter;

public:
    King(int row, int col, bool color, char letter);
    void move(int col, int row);
    bool moveable(int col, int row);
    std::vector<std::string> squaresWatching();
    bool underThreat();
};

#endif