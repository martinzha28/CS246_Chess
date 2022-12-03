#include "Board.h"

void Board::init() {
    for (int i = 0; i < 8; i++) {
        vector<Piece *> vect;
        for (int j = 0; j < 8; j++) {
            if (i == 0) {
                if (j == 0) {
                    this.setupPiece('R', "a1");
                } else if (j == 1) {
                    this.setupPiece('N', "a2");
                } else if (j == 2) {
                    this.setupPiece('B', "a3");
                } else if (j == 3) {
                    this.setupPiece('Q', "a4");
                } else if (j == 4) {
                    this.setupPiece('K', "a5");
                } else if (j == 5) {
                    this.setupPiece('B', "a6");
                } else if (j == 6) {
                    this.setupPiece('N', "a7");
                } else if (j == 7) {
                    this.setupPiece('R', "a8");
                } 
            }
        }
        piecePosition.emplace_back(vect);
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
