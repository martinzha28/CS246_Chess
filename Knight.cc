#include <vector>
#include <iostream>
#include <string>
#include "Board.h"
#include "Piece.h"
#include "Knight.h"

// Absolute Value
int abs(int a, int b) {
    if (a - b > 0) {
        return a - b;
    } else {
        return b - a;
    }
}

Knight::Knight(int row, int col, bool color, char letter) : row{row}, col{col}, color{color}, letter{letter} {}

Knight::~Knight() {}

char Knight::getLetter() {
    return this->letter;
}

int Knight::getRow()
{
    return this->row;
}

int Knight::getCol() {
    return this->col;
}

bool Knight::getColor(){
    return this->color;
}

bool Knight::underThreat(std::vector< std::vector<Piece *>> piecePosition, Board theBoard) {
    for (auto it = piecePosition.begin(); it != piecePosition.end(); ++it)
    {
        for (auto it2 = it->begin(); it2 != it->end(); ++it2)
        {
            if ((*it2)->moveable(this->getCol(), this->getRow(), theBoard))
            {
                return true;
            }
        }
    }
}

bool Knight::moveable(int inCol, int inRow, Board theBoard) {

    // std::cout << "inRow: " << inRow << std::endl;

    // Checks if input coords are on the board
    if (inCol < 0 || inCol > 8 || inRow < 0 || inRow > 8) {
        // std::cout << "1 out of bounds" << std::endl;
        return false;
    }
    
    // Checks if input cell is in an L-shape from current cell
    if (!(abs(col - inCol) == 2 && abs(row - inRow) == 1)) {
        // std::cout << "inRow second time: " << inRow << std::endl;

        if (!(abs(col - inCol) == 1 && abs(row - inRow) == 2)) { 
            // std::cout << "2 not L" << std::endl;
            // std::cout << "col - inCol : " << abs(col - inCol) << " row - inRow: " << abs(row - inRow) << " Row: " << row << " inRow: " << inRow << std::endl;
            return false;
        }
    } 
    else if ((abs(col - inCol) == 2 && abs(row - inRow) == 1) || (abs(col - inCol) == 1 && abs(row - inRow) == 2)) {
        if (theBoard.getPiece(inCol, inRow)->getLetter() != ' ') 
        {
            if (theBoard.getPiece(inCol, inRow)->getColor() == this->getColor()) 
            {
                // std::cout << "3 " << std::endl;
                return false;
            }
        }
    }

    // Checks to see if moving the Piece produces check
    /*Board testBoard;
    testBoard.copyBoard(theBoard);
    testBoard.move(this->getRow(), this->getCol(), inRow, inCol);

    testBoard.tempPrint();
    if (testBoard.inCheck(this->getColor()))
    {
        delete &testBoard;
        std::cout << "4 " << std::endl;
        return false;
    }
    delete &testBoard;
    */
    return true;
}
