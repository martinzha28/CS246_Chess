#include "Board.h"
#include "Piece.h"
#include "Bishop.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Queen.h"
#include "King.h"
#include "Empty.h"
#include <iostream>
#include <vector>
#include <memory>
#include <string>


void Board::tempInit() {
    for (int i = 0; i < 8; i++)
    {
        std::vector<Piece *> vect;
        for (int j = 0; j < 8; j++)
        {
            Piece *newPiece = this->setupPiece('R', i, j);
            vect.emplace_back(&*newPiece);
        }
        piecePosition.emplace_back(vect);
    }
}

void Board::init() // Initial Setup for Board
{
    for (int i = 0; i < 8; i++)
    {
        std::vector<Piece *> vect;
        for (int j = 0; j < 8; j++)
        {
            if (i == 0)
            {
                if (j == 0)
                {
                    Piece *tempPiece = this->setupPiece('R', a, 0);
                    vect.emplace_back(&*tempPiece);
                }
                else if (j == 1)
                {
                    Piece *tempPiece = this->setupPiece('N', b, 0);
                    vect.emplace_back(&*tempPiece);
                }
                else if (j == 2)
                {
                    Piece *tempPiece = this->setupPiece('B', c, 0);
                    vect.emplace_back(&*tempPiece);
                }
                else if (j == 3)
                {
                    Piece *tempPiece = this->setupPiece('Q', d, 0);
                    vect.emplace_back(&*tempPiece);
                }
                else if (j == 4)
                {
                    Piece *tempPiece = this->setupPiece('K', e, 0);
                    vect.emplace_back(&*tempPiece);
                }
                else if (j == 5)
                {
                    Piece *tempPiece = this->setupPiece('B', f, 0);
                    vect.emplace_back(&*tempPiece);
                }
                else if (j == 6)
                {
                    Piece *tempPiece = this->setupPiece('N', g, 0);
                    vect.emplace_back(&*tempPiece);
                }
                else if (j == 7)
                {
                    Piece *tempPiece = this->setupPiece('R', h, 0);
                    vect.emplace_back(&*tempPiece);
                }
            }
            else if (i == 1)
            {
                if (j == 0)
                {
                    Piece *tempPiece = this->setupPiece('P', a, 1);
                    vect.emplace_back(&*tempPiece);
                }
                else if (j == 1)
                {
                    Piece *tempPiece = this->setupPiece('P', b, 1);
                    vect.emplace_back(&*tempPiece);
                }
                else if (j == 2)
                {
                    Piece *tempPiece = this->setupPiece('P', c, 1);
                    vect.emplace_back(&*tempPiece);
                }
                else if (j == 3)
                {
                    Piece *tempPiece = this->setupPiece('P', d, 1);
                    vect.emplace_back(&*tempPiece);
                }
                else if (j == 4)
                {
                    Piece *tempPiece = this->setupPiece('P', e, 1);
                    vect.emplace_back(&*tempPiece);
                }
                else if (j == 5)
                {
                    Piece *tempPiece = this->setupPiece('P', f, 1);
                    vect.emplace_back(&*tempPiece);
                }
                else if (j == 6)
                {
                    Piece *tempPiece = this->setupPiece('P', g, 1);
                    vect.emplace_back(&*tempPiece);
                }
                else if (j == 7)
                {
                    Piece *tempPiece = this->setupPiece('P', h, 1);
                    vect.emplace_back(&*tempPiece);
                }
            }
            else if (i == 6)
            {
                if (j == 0)
                {
                    Piece *tempPiece = this->setupPiece('p', a, 6);
                    vect.emplace_back(&*tempPiece);
                }
                else if (j == 1)
                {
                    Piece *tempPiece = this->setupPiece('p', b, 6);
                    vect.emplace_back(&*tempPiece);
                }
                else if (j == 2)
                {
                    Piece *tempPiece = this->setupPiece('p', c, 6);
                    vect.emplace_back(&*tempPiece);
                }
                else if (j == 3)
                {
                    Piece *tempPiece = this->setupPiece('p', d, 6);
                    vect.emplace_back(&*tempPiece);
                }
                else if (j == 4)
                {
                    Piece *tempPiece = this->setupPiece('p', e, 6);
                    vect.emplace_back(&*tempPiece);
                }
                else if (j == 5)
                {
                    Piece *tempPiece = this->setupPiece('p', f, 6);
                    vect.emplace_back(&*tempPiece);
                }
                else if (j == 6)
                {
                    Piece *tempPiece = this->setupPiece('p', g, 6);
                    vect.emplace_back(&*tempPiece);
                }
                else if (j == 7)
                {
                    Piece *tempPiece = this->setupPiece('p', h, 6);
                    vect.emplace_back(&*tempPiece);
                }
            }
            else if (i == 7)
            {
                if (j == 0)
                {
                    Piece *tempPiece = this->setupPiece('r', a, 7);
                    vect.emplace_back(&*tempPiece);
                }
                else if (j == 1)
                {
                    Piece *tempPiece = this->setupPiece('n', b, 7);
                    vect.emplace_back(&*tempPiece);
                }
                else if (j == 2)
                {
                    Piece *tempPiece = this->setupPiece('b', c, 7);
                    vect.emplace_back(&*tempPiece);
                }
                else if (j == 3)
                {
                    Piece *tempPiece = this->setupPiece('q', d, 7);
                    vect.emplace_back(&*tempPiece);
                }
                else if (j == 4)
                {
                    Piece *tempPiece = this->setupPiece('k', e, 7);
                    vect.emplace_back(&*tempPiece);
                }
                else if (j == 5)
                {
                    Piece *tempPiece = this->setupPiece('b', f, 7);
                    vect.emplace_back(&*tempPiece);
                }
                else if (j == 6)
                {
                    Piece *tempPiece = this->setupPiece('n', g, 7);
                    vect.emplace_back(&*tempPiece);
                }
                else if (j == 7)
                {
                    Piece *tempPiece = this->setupPiece('r', h, 7);
                    vect.emplace_back(&*tempPiece);
                }
            }
            else
            {
                Piece *tempPiece = setupEmpty(j, i);
                vect.emplace_back(&*tempPiece);
            }
        }
        piecePosition.emplace_back(vect);
    }
}

Board::~Board()
{
    for (auto it = piecePosition.begin(); it != piecePosition.end(); ++it)
    {
        for (auto it2 = it->begin(); it2 != it->end(); ++it2)
        {
            // delete it2? <- is this necessary?
            it->erase(it2);
        }
        piecePosition.erase(it);
    }
}

Piece *Board::setupPiece(char piece, int col, int row)
{
    Piece *newPiece;
    if (piece == 'p')
    {
        newPiece = new Pawn{row, col, false, 'p'};
    }
    else if (piece == 'P')
    {
        newPiece = new Pawn{row, col, true, 'P'};
    }
    else if (piece == 'r')
    {
        newPiece = new Rook{row, col, false, 'r'};
    }
    else if (piece == 'R')
    {
        newPiece = new Rook{row, col, true, 'R'};
    }
    else if (piece == 'n')
    {
        newPiece = new Knight{row, col, false, 'n'};
    }
    else if (piece == 'N')
    {
        newPiece = new Knight{row, col, true, 'N'};
    }
    else if (piece == 'b')
    {
        newPiece = new Bishop{row, col, false, 'b'};
    }
    else if (piece == 'B')
    {
        newPiece = new Bishop{row, col, true, 'B'};
    }
    else if (piece == 'q')
    {
        newPiece = new Queen{row, col, false, 'q'};
    }
    else if (piece == 'Q')
    {
        newPiece = new Queen{row, col, true, 'Q'};
    }
    else if (piece == 'k')
    {
        newPiece = new King{row, col, false, 'k'};
    }
    else if (piece == 'K')
    {
        newPiece = new King{row, col, true, 'K'};
    }
    std::cout << "Piece Letter : " << newPiece->letter << "Actual Piece: " << piece <<std::endl;
    return newPiece;
}

Piece * Board::setupEmpty(int col, int row)
{
    Piece *newPiece = new Empty{row, col};
    return newPiece;
}
/*
void Board::movePiece(std::string startCoord, std::string endCoord)
{
    // not finished
} */

void Board::tempPrint() {
    for (auto it = piecePosition.begin(); it != piecePosition.end(); ++it)
    {
        for (auto it2 = it->begin(); it2 != it->end(); ++it2)
        {
            // something wrong with getLetter()
            // only printing in 6th col
            std::string s(1, (*it2)->letter); // convert char to string
            std::cout << s << "|";
        }
        std::cout << std::endl;
        for (int i = 0; i < 8; i++) {
            std::cout << "--";
        }
        std::cout << std::endl;
    }
}

Piece *Board::getPiece(int inCol, int inRow)
{
    for (auto it = piecePosition.begin(); it != piecePosition.end(); ++it)
    {
        for (auto it2 = it->begin(); it2 != it->end(); ++it2)
        {
            if ((*it2)->getRow() == inRow && (*it2)->getCol() == inCol)
            {
                return *it2;
            }
        }
    }
}
/*
bool Board::isCheck(Player chessPlayer)
{
    // not finished
}

bool Board::isStalemate(Player chessPlayer)
{
    return 1; // not finished
}

bool Board::isCheckmate(Player chessPlayer)
{
    return 1; // not finished
}

void Board::setStalemate(Player chessPlayer)
{
    // not finished
}

void Board::setCheckmate(Player chessPlayer)
{
    // not finished
}
*/
