#ifndef __KING_H__
#define __KING_H__

#include <vector>
#include <iostream>
#include <string>
#include "Piece.h"

class King: public Piece {
    protected:
        bool canCastle;
        bool inCheck;
    public:
        void move(string coords);
        bool moveable(string coords);
        std::vector<std::string> squaresWatching();
        bool underThreat();
}

#endif