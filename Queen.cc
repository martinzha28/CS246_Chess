#include <vector>
#include <iostream>
#include <string>
#include "Board.h"
#include "Piece.h"
#include "Queen.h"

Queen::Queen(int row, int col, bool color, char letter) : row{row}, col{col}, color{color}, letter{letter} {}

Queen::~Queen() {}

char Queen::getLetter() {
    return this->letter;
}

int Queen::getRow()
{
    return this->row;
}

int Queen::getCol() {
    return this->col;
}

bool Queen::getColor(){
    return this->color;
}

bool Queen::underThreat(std::vector< std::vector<Piece *>> piecePosition, Board theBoard) {
    for (auto it = piecePosition.begin(); it != piecePosition.end(); ++it)
    {
        for (auto it2 = it->begin(); it2 != it->end(); ++it2)
        {
            if ((*it2)->moveable(this->getCol(), this->getRow(), theBoard, false))
            {
                return true;
            }
        }
    }
}

bool Queen::moveable(int inCol, int inRow, Board theBoard, bool oneDeep) {

    // Check bounds
    if (inCol < 0 || inCol >= 8 || inRow < 0 || inRow >= 8) {
        return false;
    }

    // Check if moved to own square
    if (inCol == col && inRow == row) {
        return false;
    }

    // Checks if input cell is diagonal or in same row to current cell
    if ((abs(col - inCol) != abs(row - inRow)) && (col != inCol && row != inRow)) {
        return false;
    }

    // Checks if piece is occupied by same color
    if (theBoard.getPiece(inCol, inRow)->getLetter() != ' ') {
        if (theBoard.getPiece(inCol, inRow)->getColor() == this->getColor()) {
            return false;
        }
    }

    // Checks if pathway is blocked

    if (col == inCol) { // rook col path
        int rowDirection = (inRow > row) ? 1 : -1;
        for (int i = this->getRow() + rowDirection; i != inRow; i += rowDirection) {
            if (theBoard.getPiece(col, i)->getLetter() != ' ') {
                return false;
            }
        }
    } else if (row == inRow) { // rook row path
        int colDirection = (inCol > col) ? 1 : -1;
        for (int i = this->getCol() + colDirection; i != inCol; i += colDirection) {
            if (theBoard.getPiece(i, row)->getLetter() != ' ') {
                return false;
            }
        }
    } else { // bishop path

        int colDirection = (inCol > col) ? 1 : -1;
        int rowDirection = (inRow > row) ? 1 : -1;
        int j = this->getRow() + rowDirection;
        for (int i = this->getCol() + colDirection; i != inCol; i += colDirection) {
            if (theBoard.getPiece(i, j)->getLetter() != ' ') {
                return false;
            }
            j += rowDirection;
        }
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
