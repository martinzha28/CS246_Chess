#include <vector>
#include <iostream>
#include <string>
#include "Board.h"
#include "Piece.h"
#include "King.h"

// Absolute Value
int abs(int a, int b) {
    if (a - b > 0) {
        return a - b;
    } else {
        return b - a;
    }
}

King::King(int row, int col, bool color, char letter) : row{row}, col{col}, color{color}, letter{letter} {}

King::~King() {}

char King::getLetter() {
    return this->letter;
}

void King::move(int inCol, int inRow) {

}

bool King::moveable(int inCol, int inRow, Board theBoard) {
    // Check bounds
    if (inCol <= 0 || inCol > 8 || inRow <= 0 || inRow > 8) {
        return false;
    }

    // Check if moved to own square
    if (inCol == col && inRow == row) {
        return false;
    }

    // Checks if piece is occupied by same color
    if (theBoard.getPiece(inCol, inRow)->getColor() == this->getColor()) {
        return false;
    }

    // Checks if moved in direct one move

    if (inCol - col > 1 || inRow - row > 1 || col - inCol > 1 || row - inRow > 1) {
        return false;
    } else if (true) { // castling conditions NOT FINISHED
        // check casling conditions
        return false;
    }

    // check conditions for moving creates a check

    return true;

}
