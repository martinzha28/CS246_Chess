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

    theBoard.setupPiece('q', 3, 4);

    theBoard.tempInit();
    theBoard.tempPrint();


}
