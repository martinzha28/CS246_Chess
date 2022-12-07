#ifndef __ROOK_H__
#define __ROOK_H__

#include <vector>
#include <iostream>
#include <string>
#include "Board.h"
#include "Piece.h"

class Rook: public Piece {
protected:
    int row;
    int col;
    bool color;
    char letter;
    bool canCastle = true;
public:
    Rook(int row, int col, bool color, char letter);
    ~Rook();
    char getLetter() override;
    int getRow() override;
    int getCol() override;
    bool getColor() override;
    bool underThreat(std::vector< std::vector<Piece *>> piecePosition, Board theBoard) override;
    bool moveable(int inCol, int inRow, Board theBoard, bool oneDeep) override;
};

#endif
