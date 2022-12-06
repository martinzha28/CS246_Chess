#include <vector>
#include <iostream>
#include <string>
#include "Empty.h"

Empty::Empty(int row, int col) : row{row}, col{col} {}

Empty::~Empty() {}

char Empty::getLetter() {
    return this->letter;
}

bool Empty::moveable(int inCol, int inRow, Board theBoard) {
    return false;
}

void Empty::move(int inCol, int inRow) {
    
}
