#ifndef __BOARD_H__
#define __BOARD_H__

#include <vector>
#include <iostream>
#include <string>
#include "Piece.h"
#include "Player.h"
#include "Subject.h"

class Piece;

class Board : public Subject
{
protected:
    bool whoseTurn;
    int fiftyMoveDraw;
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
    Player *player1;
    Player *player2;
    void blankInit();
    std::vector< std::vector<Piece *>> piecePosition;
    void init();
    void copyBoard(Board theBoard);
    ~Board();
    Piece* setupPiece(char piece, int col, int row);
    Piece* setupEmpty(int col, int row);
    void update(int inCol, int inRow, Piece *updatePiece);
    void move(int startRow, int startCol, int endRow, int endCol);
    void printBoard();
    Piece* getPiece(int col, int row);
    bool inCheck(bool color, bool oneDeep);
    bool inStalemate(bool color);
    bool inCheckmate(bool color);

    void setPlayerOne(Player *player);
    void setPlayerTwo(Player *player);
};
#endif
