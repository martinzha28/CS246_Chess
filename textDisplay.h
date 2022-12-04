#include "Observer.h"

class textDisplay : public Observer
{
public:
    textDisplay();
    ~textDisplay();
    void notify() override;
};
