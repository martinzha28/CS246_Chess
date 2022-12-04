#include "Piece.h"

class Empty : public Piece
{
protected:
    int row;
    int col;

public:
    Empty(int row, int col);
    bool underThreat();
};