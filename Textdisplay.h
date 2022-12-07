#ifndef _TEXTDISPLAY_H_
#define _TEXTDISPLAY_H_

#include "Observer.h"
#include "Board.h"

class textDisplay : public Observer
{
    Board* subject;
public:
    textDisplay(Board* theBoard);
    ~textDisplay();
    void notify() override;
};

#endif
