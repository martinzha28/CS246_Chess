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
    char getLetter();
    int getRow() override;
    int getCol() override;
    bool getColor() override;
    bool underThreat(std::vector< std::vector<Piece *>> piecePosition, Board theBoard) override;
    bool moveable(int inCol, int inRow, Board theBoard, bool oneDeep) override;
};

#endif
