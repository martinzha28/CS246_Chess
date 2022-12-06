#include <vector>
#include <iostream>
#include <string>
#include "Board.h"
#include "Piece.h"
#include "Bishop.h"

Bishop::Bishop(int row, int col, bool color, char letter) : row{row}, col{col}, color{color}, letter{letter} {}

Bishop::~Bishop() {}

char Bishop::getLetter() {
    return this->letter;
}

int Bishop::getRow()
{
    return this->row;
}

int Bishop::getCol() {
    return this->col;
}

bool Bishop::getColor(){
    return this->color;
}

bool Bishop::underThreat(std::vector< std::vector<Piece *>> piecePosition, Board theBoard) {
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


bool Bishop::moveable(int inCol, int inRow, Board theBoard) {

    // Check bounds
    if (inCol < 0 || inCol >= 8 || inRow < 0 || inRow >= 8) {
        return false;
    }

    // Check if moved to own square
    if (inCol == col && inRow == row) {
        return false;
    }

    // Checks if input cell is diagonal to current cell
    if (abs(col - inCol) != abs(row - inRow)) {
        return false;
    }

    // Checks if piece is occupied by same color
    if (theBoard.getPiece(inCol, inRow)->getLetter() != ' ') {
        if (theBoard.getPiece(inCol, inRow)->getColor() == this->getColor()) {
            return false;
        }
    }

    // Checks if pathway is blocked
    int colDirection = (inCol > col) ? 1 : -1;
    int rowDirection = (inRow > row) ? 1 : -1;
    int j = this->getRow() + rowDirection;
    for (int i = this->getCol() + colDirection; i != inCol; i += colDirection) {
        if (theBoard.getPiece(i, j)->getLetter() != ' ') {
            return false;
        }
        j += rowDirection;
    }

    // Checks to see if moving the Piece produces check
    // Board testBoard;
    // testBoard.copyBoard(theBoard);
    // testBoard.move(this->getRow(), this->getCol(), inRow, inCol);

    // if (testBoard.inCheck(this->getColor()))
    // {
    //     delete &testBoard;
    //     return false;
    // }
    // delete &testBoard;
    return true;
}
