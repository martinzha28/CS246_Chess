#ifndef __BOARD_H__
#define __BOARD_H__

#include <vector>
#include <iostream>
#include <string>
#include "Piece.h"

class Piece;

class Board
{
protected:
    bool whoseTurn;
    int fiftyMoveDraw;
    /* Player * player1;
    Player * player2; */
    bool stalemate;
    bool checkmate;

public:
    enum columns
    {
        a,
        b,
        c,
        d,
        e,
        f,
        g,
        h
    };
    void blankInit();
    std::vector< std::vector<Piece *>> piecePosition;
    void init();
    ~Board();
    Piece* setupPiece(char piece, int col, int row);
    Piece* setupEmpty(int col, int row);
    void movePiece(std::string startCoord, std::string endCoord);
    void tempPrint();
    Piece* getPiece(int col, int row);
    // bool isCheck(Player chessPlayer);
    // bool isStalemate(Player chessPlayer);
    // bool isCheckmate(Player chessPlayer);
    // void setStalemate(Player chessPlayer);
    // void setCheckmate(Player chessPlayer);
};
#endif
