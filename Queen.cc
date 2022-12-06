#include <vector>
#include <iostream>
#include <string>
#include "Board.h"
#include "Piece.h"
#include "Queen.h"

// Absolute Value
int abs(int a, int b) {
    if (a - b > 0) {
        return a - b;
    } else {
        return b - a;
    }
}


Queen::Queen(int row, int col, bool color, char letter) : row{row}, col{col}, color{color}, letter{letter} {}

void Queen::move(int inCol, int inRow) {

}

bool Queen::moveable(int inCol, int inRow) {

    // Check bounds
    if (inCol <= 0 || inCol > 8 || inRow <= 0 || inRow > 8) {
        return false;
    }

    // Check if moved to own square
    if (inCol == col && inRow == row) {
        return false;
    }

    // Checks if input cell is diagonal or in same row to current cell
    if ((abs(col - inCol) != abs(row - inRow)) or (col != inCol && row != inRow)) {
        return false;
    }

    // Checks if piece is occupied by same color
    if (theBoard.getPiece(inCol, inRow).getColor() == this.getColor()) {
        return false;
    }

    // Checks if pathway is blocked

    if (col == inCol) { // rook col path
        int rowDirection = (inRow > row) ? 1 : -1;
        for (int i = inRow + rowDirection; i != inRow; i += rowDirection) {
            if (theBoard.getPiece(col, i).getLetter() != '0') {
                return false;
            }
        }
    } else if (row == inRow) { // rook row path
        int colDirection = (inCol > col) ? 1 : -1;
        for (int i = inCol + colDirection; i != inCol; i += colDirection) {
            if (theBoard.getPiece(i, row).getLetter() != '0') {
                return false;
            }
        }
    } else { // bishop path

        int colDirection = (inCol > col) ? 1 : -1;
        int rowDirection = (inRow > row) ? 1 : -1;
        for (int i = inCol + colDirection, int j = inRow + rowDirection; i != inCol; i += colDirection, j += rowDirection) {
            if (theBoard.getPiece(i, j).getLetter() != 0) {
                return false;
            }
        }
    }

    // Check to see if move blocks check

    // Checks to see if moving the Piece produces check

    return true;
}

bool Queen::underThreat() {
    for (auto it = piecePosition.begin(); it != piecePosition.end(); ++it)
    {
        for (auto it2 = it->begin(); it2 != it->end(); ++it2)
        {
            if ((*it2)->moveable(this->col, this->row))
            {
                return *it2;
            }
        }
    }
}