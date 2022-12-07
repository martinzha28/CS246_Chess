#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <vector>
#include <iostream>
#include <string>
#include "Move.h"
#include "Board.h"
#include "Piece.h"

class Move;
class Board;

class Player {
    public: 
    virtual ~Player();
    virtual void getMove(int *startCol, int *startRow, int *endCol, int *endRow, Board theBoard) = 0;
};

#endif
