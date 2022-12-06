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

bool Bishop::moveable(int inCol, int inRow, Board theBoard) {

    // Check bounds
    if (inCol <= 0 || inCol > 8 || inRow <= 0 || inRow > 8) {
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
    if (theBoard.getPiece(inCol, inRow)->getColor() == this->getColor()) {
        return false;
    }

    // Checks if pathway is blocked
    int colDirection = (inCol > col) ? 1 : -1;
    int rowDirection = (inRow > row) ? 1 : -1;
    int j = inRow + rowDirection;
    for (int i = inCol + colDirection; i != inCol; i += colDirection) {
        if (theBoard.getPiece(i, j)->getLetter() != ' ') {
            return false;
        }
        j += rowDirection;
    }

    // Check to see if move is able to block check

    

    // Checks to see if moving the Piece produces check
    
    

    return true;
}

void Bishop::move(int inCol, int inRow) {

}
