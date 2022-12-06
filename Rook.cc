#include <vector>
#include <iostream>
#include <string>
#include "Board.h"
#include "Piece.h"
#include "Rook.h"

// Absolute Value
int abs(int a, int b) {
    if (a - b > 0) {
        return a - b;
    } else {
        return b - a;
    }
}


Rook::Rook(int row, int col, bool color, char letter) : row{row}, col{col}, color{color}, letter{letter} {}

void Rook::move(int inCol, int inRow) {

}

bool Rook::moveable(int inCol, int inRow) {
    // Check bounds
    if (inCol <= 0 || inCol > 8 || inRow <= 0 || inRow > 8) {
        return false;
    }

    // Check if moved to own square
    if (inCol == col && inRow == row) {
        return false;
    }

    // Checks if piece is occupied by same color
    if (theBoard.getPiece(inCol, inRow).getColor() == this.getColor()) {
        return false;
    }

    // Checks if input cell is in a straight line to the current cell
    if (col != inCol && row != inRow) {
        return false;
    }

    // Checks if pathway is blocked
    if (col == inCol) {
        int rowDirection = (inRow > row) ? 1 : -1;
        for (int i = inRow + rowDirection; i != inRow; i += rowDirection) {
            if (theBoard.getPiece(col, i).getLetter() != '0') {
                return false;
            }
        }
    } else if (row == inRow) {
        int colDirection = (inCol > col) ? 1 : -1;
        for (int i = inCol + colDirection; i != inCol; i += colDirection) {
            if (theBoard.getPiece(i, row).getLetter() != '0') {
                return false;
            }
        }
    }
    // Check to see if move blocks check

    

    // Checks to see if moving the Piece produces check
    


    return true;
}

bool Rook::underThreat() {
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