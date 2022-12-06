#ifndef __EMPTY_H__
#define __EMPTY_H__

#include <vector>
#include <iostream>
#include <string>
#include "Piece.h"

class Empty: public Piece {
    int row;
    int col;
    char letter = ' ';
public:
    Empty(int row, int col);
    ~Empty();
    char getLetter() override;
    int getRow() override;
    int getCol() override;
    bool getColor() override;
    bool underThreat(std::vector< std::vector<Piece *>> piecePosition, Board theBoard) override;
    bool moveable(int inCol, int inRow, Board theBoard) override;
};

#endif
