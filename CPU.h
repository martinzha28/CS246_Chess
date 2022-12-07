#ifndef __CPU_H__
#define __CPU_H__

#include <vector>
#include <iostream>
#include <string>
#include "Board.h"
#include "Piece.h"
#include "Move.h"
#include "Player.h"

class CPU : public Player {
    public:
    int level;
    bool color;
    CPU(int level, bool color);
    ~CPU();
    void getMove(int *startCol, int *startRow, int *endCol, int *endRow, Board theBoard) override;
};

#endif
