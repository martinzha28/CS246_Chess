#include <vector>
#include <iostream>
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

void Bishop::move(int inCol, int inRow) {

}

bool Bishop::moveable(int inCol, int inRow) {
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

std::vector<std::string> Bishop::squaresWatching() {

}

bool Bishop::underThreat() {

}