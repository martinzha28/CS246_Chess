#include <vector>
#include <iostream>
#include <string>
#include "Empty.h"

Empty::Empty(int row, int col) : row{row}, col{col} {}

Empty::~Empty() {}

char Empty::getLetter() {
    return this->letter;
}

int Empty::getRow()
{
    return this->row;
}

int Empty::getCol() {
    return this->col;
}

bool Empty::getColor(){
    return this->color;
}

bool Empty::underThreat(std::vector< std::vector<Piece *>> piecePosition, Board theBoard) {
    for (auto it = piecePosition.begin(); it != piecePosition.end(); ++it)
    {
        for (auto it2 = it->begin(); it2 != it->end(); ++it2)
        {
            if ((*it2)->moveable(this->getCol(), this->getRow(), theBoard))
            {
                return true;
            }
        }
    }
}

bool Empty::moveable(int inCol, int inRow, Board theBoard) {
    return false;
}
