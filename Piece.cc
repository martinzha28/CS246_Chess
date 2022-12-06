#include <vector>
#include <iostream>
#include <string>
#include "Board.h"
#include "Piece.h"

/* Piece::~Piece()
{
    delete this;
} */

Piece::~Piece() {}

int Piece::getRow()
{
    return this->row;
}

int Piece::getCol() {
    return this->col;
}

bool Piece::getColor(){
    return this->color;
}

char Piece::getLetter() {
    return this->letter;
}

bool Piece::underThreat(std::vector< std::vector<Piece *>> piecePosition, Board theBoard) {
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
