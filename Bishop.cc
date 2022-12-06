#include <vector>
#include <iostream>
#include <string>
#include "Board.h"
#include "Piece.h"
#include "Bishop.h"

// Absolute Value
int abs(int a, int b) {
    if (a - b > 0) {
        return a - b;
    } else {
        return b - a;
    }
}

Bishop::Bishop(int row, int col, bool color, char letter) : row{row}, col{col}, color{color}, letter{letter} {}

bool Bishop::moveable(int inCol, int inRow) {

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
    if (theBoard.getPiece(inCol, inRow).getColor() == this.getColor()) {
        return false;
    }

    // Checks if pathway is blocked
    int colDirection = (inCol > col) ? 1 : -1;
    int rowDirection = (inRow > row) ? 1 : -1;
    for (int i = inCol + colDirection, int j = inRow + rowDirection; i != inCol; i += colDirection, j += rowDirection) {
        if (theBoard.getPiece(i, j).getLetter() != 0) {
            return false;
        }
    }

    // Check to see if move is able to block check

    

    // Checks to see if moving the Piece produces check
    
    

    return true;
}

bool Bishop::underThreat() {
    for (PiecePosition) {
        if (Piece.moveable(this->col, this->row)) {
            return true;
        }
    }
    return false;
}