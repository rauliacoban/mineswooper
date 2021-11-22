#ifndef GAMECELL_H
#define GAMECELL_H

#include "cell.h"

class GameCell : public Cell
{
private:
    bool cover = 1;

public:
    bool isCovered()
    {
        return cover;
    }
};

#endif