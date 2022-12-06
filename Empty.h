#ifndef __EMPTY_H__
#define __EMPTY_H__

#include <vector>
#include <iostream>
#include <string>
#include "Piece.h"

class Empty: public Piece {
    int row;
    int col;
    char letter = ' ';
public:
    Empty(int row, int col);
    ~Empty();
};

#endif
