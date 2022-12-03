#ifndef __BOARD_H__
#define __BOARD_H__

#include <vector>
#include <iostream>
#include <string>

class Board
{
protected:
    std::vector<std::vector<Piece *>> piecePosition;
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
    void init();
    Piece setupPiece(char piece, int col, int row);
    void movePiece(std::string startCoord, std::string endCoord);
    bool isStalemate();
    bool isCheckmate();
    void setStalemate();
    void setCheckmate();
};
#endif
