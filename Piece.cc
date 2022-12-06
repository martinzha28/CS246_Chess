#include "Piece.h"

Piece::~Piece()
{
    delete this;
}

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