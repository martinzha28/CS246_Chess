#ifndef __HUMAN_H__
#define __HUMAN_H__

#include <vector>
#include <iostream>
#include <string>
#include "Board.h"
#include "Piece.h"
#include "Move.h"
#include "Player.h"

class Human : public Player {
    public:
        Human();
        ~Human();
        void getMove(int *startCol, int *startRow, int *endCol, int *endRow, Board theBoard) override;
};

#endif
