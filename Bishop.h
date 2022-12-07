#ifndef __BISHOP_H__
#define __BISHOP_H__

#include <vector>
#include <iostream>
#include <string>
#include "Board.h"
#include "Piece.h"

class Bishop: public Piece {
protected:
    int row;
    int col;
    bool color;
    char letter;
public:
    Bishop(int row, int col, bool color, char letter);
    ~Bishop();
    char getLetter() override;
    int getRow() override;
    int getCol() override;
    bool getColor() override;
    bool underThreat(std::vector< std::vector<Piece *>> piecePosition, Board theBoard) override;
    bool moveable(int inCol, int inRow, Board theBoard, bool oneDeep) override;
};

#endif


