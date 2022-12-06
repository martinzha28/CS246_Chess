#include "Empty.h"

Empty::Empty(int row, int col) : row{row}, col{col} {}

Empty::moveable(int inCol, int inRow) {
    return false;
}

Empty::underThreat() {
    return false;
}