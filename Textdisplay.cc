#include "Textdisplay.h"
#include <iostream>

void textDisplay::notify()
{
    for (int row = 7; row >= 0; --row)
    {
        for (int col = 0; col < 8; ++col)
        {
            if (col == 0)
            {
                std::cout << row + 1 << " ";
            }

            if (subject->getPiece(col, row)->getLetter() == ' ' && (row + col) % 2 == 0)
            {
                std::cout << '_';
            }
            else
            {
                std::cout << subject->getPiece(col, row)->getLetter();
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl
              << "  abcdefgh" << std::endl;
}

textDisplay::textDisplay(Board* theBoard) : subject{theBoard} {
    subject->attach(this);
}

textDisplay::~textDisplay() {
    subject->detach(this);
}
