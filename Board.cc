#include "Board.h"

void Board::init() {
    for (int i = 0; i < 8; i++) {
        vector<*Piece> vect;
        theBoard.emplace_back(vect);
        for (int j = 0; j < 8; j++) {
            
        }
    }
}

Board::~Board() {
}

void Board::setupPiece(char piece, std::string coord) {

}

void Board::movePiece(std::string startCoord, std::string endCoord) {

}

bool Board::isStalemate() {
    return 1;
}

bool Board::isCheckmate() {
    return 1;
}

void Board::setStalemate() {
}

void Board::setCheckmate() {
}
