#include "Board.h"
#include "Piece.h"
#include <vector>

void Board::init()
{
    for (int i = 0; i < 8; i++)
    {
        std::vector<Piece*> vect;
        for (int j = 0; j < 8; j++)
        {
            if (i == 0)
            {
                if (j == 0)
                {
                    Piece tempPiece = setupPiece('R', a, 1);
                    vect.emplace_back(&tempPiece);
                }
                else if (j == 1)
                {
                    Piece tempPiece = setupPiece('N', b, 1);
                    vect.emplace_back(&tempPiece);
                }
                else if (j == 2)
                {
                    Piece tempPiece = setupPiece('B', c, 1);
                    vect.emplace_back(&tempPiece);
                }
                else if (j == 3)
                {
                    Piece tempPiece = setupPiece('Q', d, 1);
                    vect.emplace_back(&tempPiece);
                }
                else if (j == 4)
                {
                    Piece tempPiece = setupPiece('K', e, 1);
                    vect.emplace_back(&tempPiece);
                }
                else if (j == 5)
                {
                    Piece tempPiece = setupPiece('B', f, 1);
                    vect.emplace_back(&tempPiece);
                }
                else if (j == 6)
                {
                    Piece tempPiece = setupPiece('N', g, 1);
                    vect.emplace_back(&tempPiece);
                }
                else if (j == 7)
                {
                    Piece tempPiece = setupPiece('R', h, 1);
                    vect.emplace_back(&tempPiece);
                }
            }
            else if (i == 7)
            {
                if (j == 0)
                {
                    Piece tempPiece = setupPiece('r', a, 8);
                    vect.emplace_back(&tempPiece);
                }
                else if (j == 1)
                {
                    Piece tempPiece = setupPiece('n', b, 8);
                    vect.emplace_back(&tempPiece);
                }
                else if (j == 2)
                {
                    Piece tempPiece = setupPiece('b', c, 8);
                    vect.emplace_back(&tempPiece);
                }
                else if (j == 3)
                {
                    Piece tempPiece = setupPiece('q', d, 8);
                    vect.emplace_back(&tempPiece);
                }
                else if (j == 4)
                {
                    Piece tempPiece = setupPiece('k', e, 8);
                    vect.emplace_back(&tempPiece);
                }
                else if (j == 5)
                {
                    Piece tempPiece = setupPiece('b', f, 8);
                    vect.emplace_back(&tempPiece);
                }
                else if (j == 6)
                {
                    Piece tempPiece = setupPiece('n', g, 8);
                    vect.emplace_back(&tempPiece);
                }
                else if (j == 7)
                {
                    Piece tempPiece = setupPiece('r', h, 8);
                    vect.emplace_back(&tempPiece);
                }
            }
        }
        piecePosition.emplace_back(vect);
    }
}

Board::~Board()
{
}

Piece Board::setupPiece(char piece, int col, int row)
{
}

void Board::movePiece(std::string startCoord, std::string endCoord)
{
}

bool Board::isStalemate()
{
    return 1;
}

bool Board::isCheckmate()
{
    return 1;
}

void Board::setStalemate()
{
}

void Board::setCheckmate()
{
}
