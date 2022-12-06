#include <vector>
#include <iostream>
#include <string>
#include "Board.h"
#include "Piece.h"
#include "Pawn.h"

// Absolute Value
int abs(int a, int b) {
    if (a - b > 0) {
        return a - b;
    } else {
        return b - a;
    }
}


Pawn::Pawn(int row, int col, bool color, char letter) : row{row}, col{col}, color{color}, letter{letter} {}

void Pawn::move(int inCol, int inRow) {

}

bool Pawn::moveable(int inCol, int inRow) {
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

    int direction = (this->color == 1) ? 1 : -1; // direction of pawn
    
    if (col == inCol && row + direction == inRow) { // condition for moving forward 1

    } else if (col == inCol && row + direction + direction == inRow) { // condition for moving forward 2

    } else if (row + direction == inRow && (col + 1 == inCol || col - 1 == inCol)) { // condition for taking diagonally 

    }


    // condition for moving piece creates check
    
    return true;
}

bool Pawn::underThreat() {
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