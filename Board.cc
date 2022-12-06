#include "Board.h"
#include "Piece.h"
#include <vector>

void Board::init() // Initial Setup for Board
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
                    Piece::Piece tempPiece = setupPiece('R', a, 0);
                    vect.emplace_back(&tempPiece);
                }
                else if (j == 1)
                {
                    Piece::Piece tempPiece = setupPiece('N', b, 0);
                    vect.emplace_back(&tempPiece);
                }
                else if (j == 2)
                {
                    Piece::Piece tempPiece = setupPiece('B', c, 0);
                    vect.emplace_back(&tempPiece);
                }
                else if (j == 3)
                {
                    Piece::Piece tempPiece = setupPiece('Q', d, 0);
                    vect.emplace_back(&tempPiece);
                }
                else if (j == 4)
                {
                    Piece::Piece tempPiece = setupPiece('K', e, 0);
                    vect.emplace_back(&tempPiece);
                }
                else if (j == 5)
                {
                    Piece::Piece tempPiece = setupPiece('B', f, 0);
                    vect.emplace_back(&tempPiece);
                }
                else if (j == 6)
                {
                    Piece::Piece tempPiece = setupPiece('N', g, 0);
                    vect.emplace_back(&tempPiece);
                }
                else if (j == 7)
                {
                    Piece::Piece tempPiece = setupPiece('R', h, 0);
                    vect.emplace_back(&tempPiece);
                }
            } else if (i == 1) {
                if (j == 0)
                {
                    Piece::Piece tempPiece = setupPiece('P', a, 1);
                    vect.emplace_back(&tempPiece);
                }
                else if (j == 1)
                {
                    Piece::Piece tempPiece = setupPiece('P', b, 1);
                    vect.emplace_back(&tempPiece);
                }
                else if (j == 2)
                {
                    Piece::Piece tempPiece = setupPiece('P', c, 1);
                    vect.emplace_back(&tempPiece);
                }
                else if (j == 3)
                {
                    Piece::Piece tempPiece = setupPiece('P', d, 1);
                    vect.emplace_back(&tempPiece);
                }
                else if (j == 4)
                {
                    Piece::Piece tempPiece = setupPiece('P', e, 1);
                    vect.emplace_back(&tempPiece);
                }
                else if (j == 5)
                {
                    Piece::Piece tempPiece = setupPiece('P', f, 1);
                    vect.emplace_back(&tempPiece);
                }
                else if (j == 6)
                {
                    Piece::Piece tempPiece = setupPiece('P', g, 1);
                    vect.emplace_back(&tempPiece);
                }
                else if (j == 7)
                {
                    Piece::Piece tempPiece = setupPiece('P', h, 1);
                    vect.emplace_back(&tempPiece);
                }
            } else if (i == 6) {
                if (j == 0)
                {
                    Piece::Piece tempPiece = setupPiece('p', a, 6);
                    vect.emplace_back(&tempPiece);
                }
                else if (j == 1)
                {
                    Piece::Piece tempPiece = setupPiece('p', b, 6);
                    vect.emplace_back(&tempPiece);
                }
                else if (j == 2)
                {
                    Piece::Piece tempPiece = setupPiece('p', c, 6);
                    vect.emplace_back(&tempPiece);
                }
                else if (j == 3)
                {
                    Piece::Piece tempPiece = setupPiece('p', d, 6);
                    vect.emplace_back(&tempPiece);
                }
                else if (j == 4)
                {
                    Piece::Piece tempPiece = setupPiece('p', e, 6);
                    vect.emplace_back(&tempPiece);
                }
                else if (j == 5)
                {
                    Piece::Piece tempPiece = setupPiece('p', f, 6);
                    vect.emplace_back(&tempPiece);
                }
                else if (j == 6)
                {
                    Piece::Piece tempPiece = setupPiece('p', g, 6);
                    vect.emplace_back(&tempPiece);
                7
                else if (j == 7)
                {
                    Piece::Piece tempPiece = setupPiece('p', h, 6);
                    vect.emplace_back(&tempPiece);
                }
            }
            else if (i == 7)
            {
                if (j == 0)
                {
                    Piece::Piece tempPiece = setupPiece('r', a, 7);
                    vect.emplace_back(&tempPiece);
                }
                else if (j == 1)
                {
                    Piece::Piece tempPiece = setupPiece('n', b, 7);
                    vect.emplace_back(&tempPiece);
                }
                else if (j == 2)
                {
                    Piece::Piece tempPiece = setupPiece('b', c, 7);
                    vect.emplace_back(&tempPiece);
                }
                else if (j == 3)
                {
                    Piece::Piece tempPiece = setupPiece('q', d, 7);
                    vect.emplace_back(&tempPiece);
                }
                else if (j == 4)
                {
                    Piece::Piece tempPiece = setupPiece('k', e, 7);
                    vect.emplace_back(&tempPiece);
                }
                else if (j == 5)
                {
                    Piece::Piece tempPiece = setupPiece('b', f, 7);
                    vect.emplace_back(&tempPiece);
                }
                else if (j == 6)
                {
                    Piece::Piece tempPiece = setupPiece('n', g, 7);
                    vect.emplace_back(&tempPiece);
                }
                else if (j == 7)
                {
                    Piece::Piece tempPiece = setupPiece('r', h, 7);
                    vect.emplace_back(&tempPiece);
                }
            }
        }
        piecePosition.emplace_back(vect);
    }
}

Board::~Board()
{
    for (auto it = piecePosition.begin(); it != piecePosition.end(); ++it) {
        for (auto it2 = it->begin(); it2 != it->end(); ++it2) {
            //delete it2? <- is this necessary?
            it->erase(it2);
        }
        piecePosition.erase(it);
    }
}

Piece::Piece Board::setupPiece(char piece, int col, int row)
{
    Piece::Piece newPiece;
    if (piece == 'p' || piece == 'P') {

    } else if (piece == 'r') {
        
    } else if (piece == 'R') {
        newPiece = new ;
    } else if (piece == 'n') {
        
    } else if (piece == 'N') {
        newPiece = new ;
    } else if (piece == 'b') {
        newPiece = new Bishop{row, col, false, 'b'};
    } else if (piece == 'B') {
        newPiece = new Bishop{row, col, true, 'B'};
    } else if (piece == 'q') {
        
    } else if (piece == 'Q') {
        newPiece = new ;
    } else if (piece == 'k') {
        
    } else if (piece == 'K') {
        newPiece = new ;
    }
    return newPiece;
}

void Board::movePiece(std::string startCoord, std::string endCoord)
{
    // not finished
}

Piece Board::getPiece(int inCol, int inRow) {
    for (PiecePosition) {
        if (Piece.row == inRow && Piece.col == inCol) {
            return Piece;
        }
    }
}

bool Board::isCheck(Player chessPlayer) {
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
