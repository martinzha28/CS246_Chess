#include <vector>
#include <iostream>
#include <string>
#include "Board.h"
#include "Piece.h"
#include "Move.h"
#include "Player.h"
#include "Human.h"

Human::Human() {}

Human::~Human() {}


void Human::getMove(int *startCol, int *startRow, int *endCol, int *endRow, Board theBoard) {

    std::string startCoord; 
    std::string endCoord;
    std::cin >> startCoord;
    std::cin >> endCoord;
    *startRow = startCoord[1] - '1';
    *startCol = startCoord[0] - 'a';
    *endRow = endCoord[1] - '1';
    *endCol = endCoord[0] - 'a';

}
