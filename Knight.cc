#include <vector>
#include <iostream>
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

void Knight::move(int inCol, int inRow) {

}

bool Knight::moveable(int inCol, int inRow) {
    bool moveable = false;
    // Checks if input cell is diagonal to current cell
    if (col - inCol == abs(row - inRow)) { // col > inCol, bishop moves left
        for (int i = col; i <= inCol; i--) {
            if ()
        }
    } else if (col - inCol == abs(row - inRow)) { // inCol > col, bishop moves right
        for (int i = col; i <= inCol; i++) { 

        }
    } 

    return moveable;
}

std::vector<std::string> Knight::squaresWatching() {

}

bool Knight::underThreat() {

}