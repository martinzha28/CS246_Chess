#ifndef __KING_H__
#define __KING_H__

#include <vector>
#include <iostream>
#include <string>
#include "Board.h"
#include "Piece.h"

class King : public Piece {
protected:
    bool canCastle = true;
    bool inCheck = false;
    int row;
    int col;
    bool color;
    char letter;

public:
    King(int row, int col, bool color, char letter);
    ~King();
    void move(int col, int row);
    bool moveable(int col, int row, Board theBoard);
    bool underThreat(std::vector< std::vector<Piece *>>, Board theBoard);
};

#endif
