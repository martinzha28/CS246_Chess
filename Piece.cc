#include "Piece.h"

Piece::~Piece()
{
    delete this;
}

int Piece::getRow()
{
    return this->row;
}

int Piece::getCol(){
    return this->col;
}
