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
#include "Textdisplay.h"

void Board::blankInit() {
    for (int i = 0; i < 8; i++)
    {
        std::vector<Piece *> vect;
        for (int j = 0; j < 8; j++)
        {
            Piece *newPiece = this->setupEmpty(i, j);
            vect.emplace_back(&*newPiece);
        }
        piecePosition.emplace_back(vect);
    }
}

void Board::update(int inCol, int inRow, Piece *updatePiece)
{
    for (auto it = piecePosition.begin(); it != piecePosition.end(); ++it)
    {
        int index = 0;
        for (auto it2 = it->begin(); it2 != it->end(); ++it2)
        {
            if ((*it2)->getCol() == inCol && (*it2)->getRow() == inRow)
            {
                delete *it2;
                it->erase(it->begin() + index);
                it->emplace(it->begin() + index, updatePiece);
            }
            index++;
        }
    }
}

void Board::init() // Initial Setup for Board
{
    for (int i = 0; i < 8; i++)
    {
        std::vector<Piece *> vect;
        for (int j = 0; j < 8; j++)
        {
            if (i == 7)
            {
                if (j == 0)
                {
                    Piece *tempPiece = this->setupPiece('r', a, i);
                    vect.emplace_back(&*tempPiece);
                }
                else if (j == 1)
                {
                    Piece *tempPiece = this->setupPiece('n', b, i);
                    vect.emplace_back(&*tempPiece);
                }
                else if (j == 2)
                {
                    Piece *tempPiece = this->setupPiece('b', c, i);
                    vect.emplace_back(&*tempPiece);
                }
                else if (j == 3)
                {
                    Piece *tempPiece = this->setupPiece('q', d, i);
                    vect.emplace_back(&*tempPiece);
                }
                else if (j == 4)
                {
                    Piece *tempPiece = this->setupPiece('k', e, i);
                    vect.emplace_back(&*tempPiece);
                }
                else if (j == 5)
                {
                    Piece *tempPiece = this->setupPiece('b', f, i);
                    vect.emplace_back(&*tempPiece);
                }
                else if (j == 6)
                {
                    Piece *tempPiece = this->setupPiece('n', g, i);
                    vect.emplace_back(&*tempPiece);
                }
                else if (j == 7)
                {
                    Piece *tempPiece = this->setupPiece('r', h, i);
                    vect.emplace_back(&*tempPiece);
                }
            }
            else if (i == 6)
            {
                if (j == 0)
                {
                    Piece *tempPiece = this->setupPiece('p', a, i);
                    vect.emplace_back(&*tempPiece);
                }
                else if (j == 1)
                {
                    Piece *tempPiece = this->setupPiece('p', b, i);
                    vect.emplace_back(&*tempPiece);
                }
                else if (j == 2)
                {
                    Piece *tempPiece = this->setupPiece('p', c, i);
                    vect.emplace_back(&*tempPiece);
                }
                else if (j == 3)
                {
                    Piece *tempPiece = this->setupPiece('p', d, i);
                    vect.emplace_back(&*tempPiece);
                }
                else if (j == 4)
                {
                    Piece *tempPiece = this->setupPiece('p', e, i);
                    vect.emplace_back(&*tempPiece);
                }
                else if (j == 5)
                {
                    Piece *tempPiece = this->setupPiece('p', f, i);
                    vect.emplace_back(&*tempPiece);
                }
                else if (j == 6)
                {
                    Piece *tempPiece = this->setupPiece('p', g, i);
                    vect.emplace_back(&*tempPiece);
                }
                else if (j == 7)
                {
                    Piece *tempPiece = this->setupPiece('p', h, i);
                    vect.emplace_back(&*tempPiece);
                }
            }
            else if (i == 1)
            {
                if (j == 0)
                {
                    Piece *tempPiece = this->setupPiece('P', a, i);
                    vect.emplace_back(&*tempPiece);
                }
                else if (j == 1)
                {
                    Piece *tempPiece = this->setupPiece('P', b, i);
                    vect.emplace_back(&*tempPiece);
                }
                else if (j == 2)
                {
                    Piece *tempPiece = this->setupPiece('P', c, i);
                    vect.emplace_back(&*tempPiece);
                }
                else if (j == 3)
                {
                    Piece *tempPiece = this->setupPiece('P', d, i);
                    vect.emplace_back(&*tempPiece);
                }
                else if (j == 4)
                {
                    Piece *tempPiece = this->setupPiece('P', e, i);
                    vect.emplace_back(&*tempPiece);
                }
                else if (j == 5)
                {
                    Piece *tempPiece = this->setupPiece('P', f, i);
                    vect.emplace_back(&*tempPiece);
                }
                else if (j == 6)
                {
                    Piece *tempPiece = this->setupPiece('P', g, i);
                    vect.emplace_back(&*tempPiece);
                }
                else if (j == 7)
                {
                    Piece *tempPiece = this->setupPiece('P', h, i);
                    vect.emplace_back(&*tempPiece);
                }
            }
            else if (i == 0)
            {
                if (j == 0)
                {
                    Piece *tempPiece = this->setupPiece('R', a, i);
                    vect.emplace_back(&*tempPiece);
                }
                else if (j == 1)
                {
                    Piece *tempPiece = this->setupPiece('N', b, i);
                    vect.emplace_back(&*tempPiece);
                }
                else if (j == 2)
                {
                    Piece *tempPiece = this->setupPiece('B', c, i);
                    vect.emplace_back(&*tempPiece);
                }
                else if (j == 3)
                {
                    Piece *tempPiece = this->setupPiece('Q', d, i);
                    vect.emplace_back(&*tempPiece);
                }
                else if (j == 4)
                {
                    Piece *tempPiece = this->setupPiece('K', e, i);
                    vect.emplace_back(&*tempPiece);
                }
                else if (j == 5)
                {
                    Piece *tempPiece = this->setupPiece('B', f, i);
                    vect.emplace_back(&*tempPiece);
                }
                else if (j == 6)
                {
                    Piece *tempPiece = this->setupPiece('N', g, i);
                    vect.emplace_back(&*tempPiece);
                }
                else if (j == 7)
                {
                    Piece *tempPiece = this->setupPiece('R', h, i);
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

void Board::copyBoard(Board theBoard)
{
    // loops through each cell in theBoard
    int row = 0;
    for (auto it = theBoard.piecePosition.begin(); it != theBoard.piecePosition.end(); ++it)
    {
        int col = 0;
        std::vector<Piece *> vect;
        for (auto it2 = it->begin(); it2 != it->end(); ++it2)
        {
            // if empty, setupEmpty with row and col
            // else, setupPiece with theBoard.letter, row and col
            if ((*it2)->getLetter() == ' ')
            {
                Piece *tempPiece = this->setupEmpty(col, row);
                vect.emplace_back(&*tempPiece);
            }
            else
            {
                Piece *tempPiece = this->setupPiece((*it2)->getLetter(), col, row);
                vect.emplace_back(&*tempPiece);
            }
            col++;
        }
        this->piecePosition.emplace_back(vect);
        row++;
    }
}

Board::~Board()
{
    // for (auto it = piecePosition.begin(); it != piecePosition.end(); ++it)
    // {
    //     for (auto it2 = it->begin(); it2 != it->end(); ++it2)
    //     {
    //         delete *it2; //<- is this necessary?
    //         it->erase(it2);
    //     }
    //     piecePosition.erase(it);
    // } 
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
    return newPiece;
}

Piece *Board::setupEmpty(int col, int row)
{
    Piece *newPiece = new Empty{row, col};
    return newPiece;
}

void Board::move(int startRow, int startCol, int endRow, int endCol) 
{
    Piece *newPiece = this->setupPiece(this->getPiece(startCol, startRow)->getLetter(), endCol, endRow);
    this->update(endCol, endRow, newPiece);

    Piece *newEmpty = this->setupEmpty(startCol, startRow);
    this->update(startCol, startRow, newEmpty);
}

// void Board::printBoard() {
//     int row = 8;
//     for (auto it = this->piecePosition.begin(); it != this->piecePosition.end(); ++it)
//     {
//         for (auto it2 = it->begin(); it2 != it->end(); ++it2)
//         {
//             if (it2 == it->begin()) {
//                 std::cout << row << " ";
//             }
//             std::cout << (*it2)->getLetter() << "|";
//         }
//         std::cout << std::endl;
//         for (int i = 0; i < 8; i++) {
//             std::cout << "--";
//         }
//         std::cout << std::endl;
//     }
// }

void Board::printBoard() {
    notifyObservers();
}

// void Board::printBoard() {
//     for (int i = 7; i >= 0; i--) {
//         std::cout << (i + 1) << "|";
//         for (int j = 0; j < 8; j++) {
//             std::cout << this->getPiece(j, i)->getLetter() << "|";
//         }
//         std::cout << std::endl;
//         std::cout << " ----------------" << std::endl;
//     }
//     std::cout << "  a b c d e f g h" << std::endl;
// }

// void Board::printBoard()
// {
//     int row = 8;
//     for (auto it = piecePosition.begin(); it != piecePosition.end(); ++it)
//     {
//         int col = 1;
//         for (auto it2 = it->begin(); it2 != it->end(); ++it2)
//         {
//             if (it2 == it->begin())
//             {
//                 std::cout << row << " ";
//                 --row;
//             }

//             if ((*it2)->getLetter() == ' ' && (row + col) % 2 == 0)
//             {
//                 std::cout << '_';
//             }
//             else
//             {
//                 std::cout << (*it2)->getLetter();
//             }

//             ++col;
//         }
//         std::cout << std::endl;
//     }
//     std::cout << std::endl
//               << "  abcdefgh" << std::endl;
// }

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

// Finding if the passed color is in check

bool Board::inCheck(bool color, bool oneDeep)
{
    int kingRow;
    int kingCol;
    for (auto it = piecePosition.begin(); it != piecePosition.end(); ++it) // finding same colored King
    {
        for (auto it2 = it->begin(); it2 != it->end(); ++it2)
        {
            if (((*it2)->getLetter() == 'K' && color) || ((*it2)->getLetter() == 'k' && !color))
            {
                kingRow = (*it2)->getRow();
                kingCol = (*it2)->getCol();
            }
        }
    }

    // std::cout << "Kings Position : " << kingRow << " " << kingCol << std::endl;

    for (auto it = piecePosition.begin(); it != piecePosition.end(); ++it) // finding opposite pieces that attack king
    {
        for (auto it2 = it->begin(); it2 != it->end(); ++it2)
        {
            if ((*it2)->getLetter() != ' ')
            {
                if ((*it2)->getColor() == !color && (*it2)->moveable(kingCol, kingRow, *this, oneDeep))
                {
                    if (!oneDeep) {
                        std::string s = (color) ? "White" : "Black";
                        std::cout << s << " is in check." << std::endl;
                    }
                    return true;
                }
            }
        }
    }

    return false;
}

bool Board::inStalemate(bool color)
{
    // Ensures that color is not in check
    if (inCheck(color, false))
    {
        return false;
    }
    // loop through each cell on the board
    for (auto it = piecePosition.begin(); it != piecePosition.end(); ++it)
    {
        for (auto it2 = it->begin(); it2 != it->end(); ++it2)
        {
            // if it's not empty and the piece is the color we're analyzing
            // std::cout << "Letter: "<< (*it2)->getLetter() << " ";
            // std::cout << "Row | Col: " << (*it2)->getRow() << " " << (*it2)->getCol() << std::endl;
            if ((*it2)->getLetter() != ' ' && (*it2)->getColor() == color)
            {
                // see if the piece can move anywhere on the board
                for (int row = 0; row < 8; row++)
                {
                    for (int col = 0; col < 8; col++)
                    {
                        if ((*it2)->moveable(col, row, *this, false))
                        {
                            return false;
                        }
                    }
                }
            }
        }
    }
    std::cout << "Stalemate!" << std::endl;
    return true;
}

bool Board::inCheckmate(bool color)
{
    // Ensures that color is in Check
    if (!inCheck(color, false))
    {
        return false;
    }

    // loop through each cell on the board
    for (auto it = piecePosition.begin(); it != piecePosition.end(); ++it)
    {
        for (auto it2 = it->begin(); it2 != it->end(); ++it2)
        {
            // if it's not empty and the piece is the color we're analyzing
            if ((*it2)->getLetter() != ' ' && (*it2)->getColor() == color)
            {
                // see if the piece can move anywhere on the board
                for (int row = 0; row < 8; row++)
                {
                    for (int col = 0; col < 8; col++)
                    {
                        if ((*it2)->moveable(col, row, *this, false))
                        {
                            return false;
                        }
                    }
                }
            }
        }
    }
    std::string s = (color) ? "White" : "Black";
    std::cout << "Checkmate! " << s << "wins!" << std::endl;
    return true;
}

void Board::setPlayerOne(Player *player)  {
    this->player1 = player;
}

void Board::setPlayerTwo(Player *player)  {
    this->player2 = player;
}

