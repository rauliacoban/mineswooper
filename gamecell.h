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
    
    void setCover(bool state)
    {
        cover = state;
    }

    static char symbolWithCover(Cell* cell_)
    {
        GameCell *cell = (GameCell*) cell_;

        if(cell->isCovered())
            return FOG;
        return getSymbol(cell);
    }
};

#endif