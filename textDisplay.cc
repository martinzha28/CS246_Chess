#include "textDisplay.h"
#include <iostream>

void textDisplay::notify()
{
    int row = 1;
    for (auto it = subject->piecePosition.begin(); it != subject->piecePosition.end(); ++it)
    {
        int col = 1;
        std::cout << row << " ";
        ++row;
        for (auto it2 = it->begin(); it2 != it->end(); ++it2)
        {
            if ((*it2)->getLetter() == ' ' && (row + col) % 2 == 0)
            {
                std::cout << '_';
            }
            else
            {
                std::cout << (*it2)->getLetter();
            }

            ++col;
        }
        std::cout << std::endl;
    }
}

textDisplay::textDisplay(Board *theBoard) : subject{theBoard}
{
    subject->attach(this);
}

textDisplay::~textDisplay()
{
    subject->detach(this);
}
