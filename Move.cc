#include <vector>
#include <iostream>
#include <string>
#include "Board.h"
#include "Piece.h"
#include "Move.h"

Move::Move(int startCol, int startRow, int endCol, int endRow) : startCol{startCol}, startRow{startRow}, endCol{endCol}, endRow{endRow} {}

int Move::getStartRow() {
    return this->startRow;
}

int Move::getStartCol() {
    return this->startRow;
}

int Move::getEndRow() {
    return this->endRow;
}

int Move::getEndCol() {
    return this->endCol;
}
