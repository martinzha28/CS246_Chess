#include <vector>
#include <iostream>
#include <string>
#include "Board.h"
#include "Piece.h"
#include "Pawn.h"


Pawn::Pawn(int row, int col, bool color, char letter) : row{row}, col{col}, color{color}, letter{letter} {}

Pawn::~Pawn() {}

char Pawn::getLetter() {
    return this->letter;
}

int Pawn::getRow()
{
    return this->row;
}

int Pawn::getCol() {
    return this->col;
}

bool Pawn::getColor(){
    return this->color;
}

bool Pawn::underThreat(std::vector< std::vector<Piece *>> piecePosition, Board theBoard) {
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

bool Pawn::moveable(int inCol, int inRow, Board theBoard, bool oneDeep) {
     // Check bounds
    if (inCol < 0 || inCol >= 8 || inRow < 0 || inRow >= 8) {
        return false;
    }

    // Check if moved to own square
    if (inCol == col && inRow == row) {
        return false;
    }

    // Checks if piece is occupied by same color
    if (theBoard.getPiece(inCol, inRow)->getLetter() != ' ') {
        if (theBoard.getPiece(inCol, inRow)->getColor() == this->getColor()) {
            return false;
        }
    }

    int direction = (this->getColor() == 1) ? 1 : -1; // direction of pawn
    int initialRow = (this->getColor() == 1) ? 1 : 6; // initial row of pawn
    
    if (col == inCol && row + direction == inRow) { // condition for moving forward 1
        if (theBoard.getPiece(inCol, inRow)->getLetter() == ' ') {
            return true;
        }
    } else if (col == inCol && row + direction + direction == inRow) { // condition for moving forward 2
        if (this->getRow() == initialRow) { //checks if you're in the starting row
            if (theBoard.getPiece(inCol, inRow)->getLetter() == ' ' && theBoard.getPiece(inCol, inRow - direction)->getLetter() == ' ') {
                return true;
            }
        }

    } else if (row + direction == inRow && (col + 1 == inCol || col - 1 == inCol)) { // condition for taking diagonally 
        if (theBoard.getPiece(inCol, inRow)->getLetter() != ' ') {
            if (theBoard.getPiece(inCol, inRow)->getColor() != this->getColor()) {
                return true;
            }
        }
    } else {
        return false;
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
