#include <vector>
#include <iostream>
#include <string>
#include "Board.h"
#include "Piece.h"
#include "Knight.h"

Knight::Knight(int row, int col, bool color, char letter) : row{row}, col{col}, color{color}, letter{letter} {}

Knight::~Knight() {}

void Knight::move(int inCol, int inRow) {

}

bool Knight::moveable(int inCol, int inRow, Board theBoard) {

    bool moveable = false;

    // Checks if input coords are on the board
    if (inCol <= 0 || inCol > 8 || inRow <= 0 || inRow > 8) {
        return false;
    }
    
    // Checks if input cell is in an L-shape from current cell
    if (abs(col - inCol) == 2 && abs(row - inRow) == 1) { 
        if (theBoard.getPiece(inCol, inRow)->getLetter() == ' ') {
            moveable = true;
        }
        else if (theBoard.getPiece(inCol, inRow)->getColor() != this->getColor()) {
            moveable = true;
        }
    } else if (abs(col - inCol) == 1 && abs(row - inRow) == 2) {
        if (theBoard.getPiece(inCol, inRow)->getLetter() == ' ') {
            moveable = true;
         }
        else if (theBoard.getPiece(inCol, inRow)->getColor() != this->getColor()) {
            moveable = true;
        }
    }

    // need to check if moving this piece puts king in check
    return moveable;
}
