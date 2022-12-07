#include <vector>
#include <iostream>
#include <string>
#include "Board.h"
#include "Piece.h"
#include "Move.h"
#include "Player.h"
#include "CPU.h"

CPU::CPU(int level, bool color): level{level}, color{color} {}

CPU::~CPU() {}

void CPU::getMove(int *startCol, int *startRow, int *endCol, int *endRow, Board theBoard) {
    if (this->level == 1) {
        std::vector<int> scv;
        std::vector<int> srv;
        std::vector<int> ecv;
        std::vector<int> erv;

        for (int i = 0; i < 8; i++) { // Looks at *any* possible moves and randomly picks one
            for (int j = 0; j < 8; j++) {
                for (int k = 0; k < 8; k++) {
                    for (int l = 0; l < 8; l++) {
                        if (theBoard.getPiece(i,j)->getLetter() != ' ' && theBoard.getPiece(i,j)->getColor() == this->color) {
                            if (theBoard.getPiece(i,j)->moveable(k,l, theBoard, false)) {
                                std::cout << theBoard.getPiece(i,j)->getLetter() << i << j << k << l << std::endl;
                                scv.emplace_back(i);
                                srv.emplace_back(j);
                                ecv.emplace_back(k);
                                erv.emplace_back(l);
                            }
                        }
                    }
                }
            }
        }


        int pickedMove = rand() % scv.size();

        *startCol = scv.at(pickedMove);
        *startRow = srv.at(pickedMove);
        *endCol = srv.at(pickedMove);
        *endRow = erv.at(pickedMove);

        
    } else if (this->level == 2) {


        // first prioritizes giving a check

        int kingRow;
        int kingCol;
        for (auto it = theBoard.piecePosition.begin(); it != theBoard.piecePosition.end(); ++it) // finding Opposite colored King
        {
            for (auto it2 = it->begin(); it2 != it->end(); ++it2)
            {
                if (((*it2)->getLetter() == 'k' && this->color) || ((*it2)->getLetter() == 'K' && !this->color))
                {
                    kingRow = (*it2)->getRow();
                    kingCol = (*it2)->getCol();
                }
            }
        }

        for (int i = 0; i < 8; i++) { // Looks at *any* possible moves and randomly picks one
            for (int j = 0; j < 8; j++) {
                for (int k = 0; k < 8; k++) {
                    for (int l = 0; l < 8; l++) {
                        // for every pair of coords in the board
                        // if the current (i,j) position is not empty:
                        // if the current (i,j) position is your color:
                        // create testBoard and move piece at (i,j) to (k,l), test if in check (oneDeep = true)
                        Board testBoard;
                        testBoard.copyBoard(theBoard);
                        if (testBoard.getPiece(i, j)->getLetter() != ' ' && testBoard.getPiece(i, j)->getColor() == this->color) {
                            testBoard.move(i,j,k,l); // moves to all (k,l)
                            if (testBoard.inCheck(!this->color, true)) { // if piece (i,j) moving to (k,l) produces check
                                delete &testBoard;
                                // Move *newMove = new Move(i,j,k,l);
                                // return newMove;
                            }
                        }
                    }   
                }
            }
        } 


        // next tries to find a piece to take


        // resorts to lower level bot

    } 
    else if (this->level == 3) {

    }
    else if (this->level == 4) {
        // Priotizes middle + higher value squares
    } 
}
