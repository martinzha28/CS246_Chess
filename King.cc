#include <vector>
#include <iostream>
#include <string>
#include "Board.h"
#include "Piece.h"
#include "King.h"

King::King(int row, int col, bool color, char letter) : row{row}, col{col}, color{color}, letter{letter} {}

King::~King() {}

char King::getLetter() {
    return this->letter;
}

int King::getRow()
{
    return this->row;
}

int King::getCol() {
    return this->col;
}

bool King::getColor(){
    return this->color;
}

bool King::underThreat(std::vector< std::vector<Piece *>> piecePosition, Board theBoard) {
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

bool King::moveable(int inCol, int inRow, Board theBoard, bool oneDeep) {
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

    // Checks if moved in direct one move

    if (inCol - col > 1 || inRow - row > 1 || col - inCol > 1 || row - inRow > 1) {
        return false;
    } else if (false) { // castling conditions NOT FINISHED
        // check casling conditions
        return false;
    }

    // Checks to see if moving the Piece produces check
    // has a bool argument called oneDeep (defaults false)
    // when false, it checks for if moveable to inRow inCol and doesn't put themself in check
    // when true, it only checks for if moveable to inRow inCol, doesn't care if putting itself in check
    if (!oneDeep) {
        Board testBoard;
        testBoard.copyBoard(theBoard);
        testBoard.move(this->getRow(), this->getCol(), inRow, inCol);
        
        if (testBoard.inCheck(this->getColor(), true))
        {
            return false;
        }
    }
    return true;
}
