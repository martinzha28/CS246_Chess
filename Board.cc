#include "Board.h"

void Board::init() {
    for (int i = 0; i < 8; i++) {
        vector<Piece *> vect;
        for (int j = 0; j < 8; j++) {
            if (i == 0) {
                if (j == 0) {
                    this.setupPiece('R', "a1");
                } else if (j == 1) {
                    this.setupPiece('N', "b1");
                } else if (j == 2) {
                    this.setupPiece('B', "c1");
                } else if (j == 3) {
                    this.setupPiece('Q', "d1");
                } else if (j == 4) {
                    this.setupPiece('K', "e1");
                } else if (j == 5) {
                    this.setupPiece('B', "f1");
                } else if (j == 6) {
                    this.setupPiece('N', "g1");
                } else if (j == 7) {
                    this.setupPiece('R', "h1");
                } 
            } else if (i == 7) {
                if (j == 0) {
                    this.setupPiece('r', "a8");
                } else if (j == 1) {
                    this.setupPiece('n', "b8");
                } else if (j == 2) {
                    this.setupPiece('b', "c8");
                } else if (j == 3) {
                    this.setupPiece('q', "d8");
                } else if (j == 4) {
                    this.setupPiece('k', "e8");
                } else if (j == 5) {
                    this.setupPiece('b', "f8");
                } else if (j == 6) {
                    this.setupPiece('n', "g8");
                } else if (j == 7) {
                    this.setupPiece('r', "h8");
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
