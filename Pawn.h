#ifndef __PAWN_H__
#define __PAWN_H__

#include <vector>
#include <iostream>
#include <string>
#include "Board.h"
#include "Piece.h"

class Pawn: public Piece {
    int row;
    int col;
    bool color;
    char letter;
    bool twoStep  = true;
    bool enPassent = false;
public:
    Pawn(int row, int col, bool color, char letter);
    ~Pawn();
    char getLetter() override;
    int getRow() override;
    int getCol() override;
    bool getColor() override;
    bool underThreat(std::vector< std::vector<Piece *>> piecePosition, Board theBoard) override;
    bool moveable(int inCol, int inRow, Board theBoard) override;
};

#endif
