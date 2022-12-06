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
    void copyBoard(Board theBoard);
    ~Board();
    Piece* setupPiece(char piece, int col, int row);
    Piece* setupEmpty(int col, int row);
    void update(int inCol, int inRow, Piece *updatePiece);
    void move(int startRow, int startCol, int endRow, int endCol);
    void tempPrint();
    Piece* getPiece(int col, int row);
    bool inCheck(bool color);
    bool inStalemate(bool color);
    bool inCheckmate(bool color);
    // void setStalemate(Player chessPlayer);
    // void setCheckmate(Player chessPlayer);
};
#endif
