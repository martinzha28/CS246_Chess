#include <iostream>
#include <string>
#include <memory>
#include "Piece.h"
#include "Board.h"
#include "Rook.h"
#include "Bishop.h"
#include "King.h"
#include "Queen.h"
#include "Knight.h"
#include "Pawn.h"
#include "Empty.h"

int main() {
    float whiteScore = 0; // 0.5 for draws
    float blackScore = 0;
    Board theBoard;
    bool manualSetup = false;
    bool turn = true;

    std::string cmd;

    while (!std::cin.eof())
        {
            std::cin >> cmd;
            if (cmd == "game") { // Starts Game
                turn = true;
                std::string playerOne;
                std::string playerTwo;
                std::cin >> playerOne >> playerTwo;
                // NEED TO DETERMINE HUMAN/BOT MATCHUP + PLAYER STUFF
                
                if (!manualSetup) { // Default Initialize if setup was not engaged
                    theBoard.init();
                }
                manualSetup = false; // Sets for next game

                theBoard.tempPrint();
                while (true) {
                    std::string moveCmd;
                    std::cout << "Enter a move: " << std::endl;
                    std::cin >> moveCmd;
                    if (moveCmd == "resign") {
                        if (turn == true) {
                            blackScore++;
                            delete &theBoard;
                            Board theBoard;
                            break;
                        } else if (turn == false) {
                            whiteScore++;
                            delete &theBoard;
                            Board theBoard;
                            break;
                        }
                    } else if (moveCmd == "move") {
                        // Convert String to 
                        std::string startCoord; 
                        std::string endCoord;
                        std::cin >> startCoord;
                        std::cout << "Start Coords: " << startCoord << std::endl;
                        std::cin >> endCoord;
                        std::cout << "End Coords: " << endCoord << std::endl;
                        int startRow = startCoord[1] - '1';
                        int startCol = startCoord[0] - 'a';
                        int endRow = endCoord[1] - '1';
                        int endCol = endCoord[0] - 'a';

                        if (theBoard.getPiece(startCol, startRow)->getColor() != turn) { // If picked piece is opponent color
                            std::cout << "Cannot Pick up Opponent's Piece" << std::endl;
                            continue;
                        }

                        // std::cout << startCol << startRow << endRow << endCol << std::endl;

                        // If Moveable, will Move the Piece                   
                        if (theBoard.getPiece(startCol, startRow)->moveable(endCol, endRow, theBoard)) { 

                            theBoard.move(startRow, startCol, endRow, endCol);

                            theBoard.tempPrint();
                            turn = !turn;
                        } else {
                            std::cout << "Please enter a valid move." << std::endl;
                            continue;
                        }

                        // Checks for End Condition
                        if (theBoard.inCheckmate(turn)) {
                            (turn) ? whiteScore++ : blackScore++; 
                            break;
                            delete &theBoard;
                            Board theBoard;
                        } else if (theBoard.inStalemate(true) || theBoard.inStalemate(false)) {
                            blackScore += 0.5;
                            whiteScore += 0.5;
                            delete &theBoard;
                            Board theBoard;
                            break;
                        }
                        
                    }
                    
                }


            } else if (cmd =="setup") {
                theBoard.blankInit();
                bool whiteKing = false;
                bool blackKing = false;
                manualSetup = true;
                std::cout << "Entering setup:" << std::endl;
                while (true) {
                    std::string setupCmd;
                    std::cin >> setupCmd;
                        if (setupCmd == "+") {
                            char piece;
                            std::string coords;
                            std::cin >> piece >> coords;

                            int inRow = coords[1] - '1';
                            int inCol = coords[0] - 'a';

                            // std::cout << "inRow: " << inRow << "inCol: " << inCol << std::endl;

                            if (piece == 'k' && !blackKing) {
                                blackKing = true;
                                Piece *newPiece = theBoard.setupPiece('k', 7 - inRow, inCol);
                                theBoard.update(7 - inRow, inCol, newPiece);
                                theBoard.tempPrint();
                            } else if (piece == 'K' && !whiteKing) {
                                whiteKing = true;
                                Piece *newPiece = theBoard.setupPiece('K', 7 - inRow, inCol);
                                theBoard.update(7 - inRow, inCol, newPiece);
                                theBoard.tempPrint();
                            } else if (piece != 'k' && piece != 'K'){
                                Piece *newPiece = theBoard.setupPiece(piece, 7 - inRow, inCol);
                                theBoard.update(7 - inRow, inCol, newPiece);
                                theBoard.tempPrint();
                            } else {
                                std::cout << "Only one King is allowed per color." << std::endl;
                            }

                        } else if (setupCmd == "-") {
                            std::string coords;
                            std::cin >> coords;

                            int inRow = coords[1] - '1';
                            int inCol = coords[0] - 'a';

                            char piece = theBoard.getPiece(7 - inRow, inCol)->getLetter();

                            if (piece == 'k') {
                                blackKing = false;
                                Piece *emptyPiece = theBoard.setupEmpty(7 - inRow, inCol);
                                theBoard.update(7 - inRow, inCol, emptyPiece);
                                theBoard.tempPrint();
                            } else if (piece == 'K') {
                                whiteKing = false;
                                Piece *emptyPiece = theBoard.setupEmpty(7 - inRow, inCol);
                                theBoard.update(7 - inRow, inCol, emptyPiece);
                                theBoard.tempPrint();
                            } else {
                                Piece *emptyPiece = theBoard.setupEmpty(7 - inRow, inCol);
                                theBoard.update(7 - inRow, inCol, emptyPiece);
                                theBoard.tempPrint();
                            }
                        } else if (setupCmd == "=") {
                            std::string color;
                            std::cin >> color;
                            if (color == "white") {
                                turn = true;
                            } else if (color == "black") {
                                turn = false;
                            } else {
                                std::cout << "Enter a valid color." << std::endl;
                            }
                        } else if (setupCmd == "done") {

                            if (!whiteKing || !blackKing) { // White/Black King is not placed
                                std::cout << "Both Kings are Not Placed." << std::endl;
                                continue;
                            } 
                            if (theBoard.inCheck(true) || theBoard.inCheck(false)) { // White/Black King is in Check
                                std::cout << "A King is in Check!" << std::endl;
                                continue;
                            }
                            for (int i = 0; i <= 8; i += 8) { // Pawns on the Back Ranks
                                for (int j = 0; j <= 8; j++) {
                                    char backRanks = theBoard.getPiece(j, i)->getLetter();
                                    if (backRanks == 'p' || backRanks == 'P') {
                                        std::cout << "There is a Pawn on the first/last row." << std::endl;
                                        continue;
                                    }
                                }
                            }

                            break;
                        } else {
                            std::cout << "Please enter a valid setup command." << std::endl;
                        }
                }
            } else {
                std::cout << "Please enter a valid command." << std::endl;
            }
        }

        delete &theBoard;
        std::cout << "Final Score:" << std::endl;
        std::cout << "White: " << whiteScore << std::endl;
        std::cout << "Black: " << blackScore << std::endl;
   

}
