#ifndef __BISHOP_H__
#define __BISHOP_H__

#include <vector>
#include <iostream>
#include <string>
#include "Piece.h"

class Bishop: public Piece {
    public:
        void move(std::string coords);
        bool moveable(std::string coords);
        std::vector<std::string> squaresWatching();
        bool underThreat();
};

#endif