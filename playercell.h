#ifndef PLAYERCELL_H
#define PLAYERCELL_H

#include "cell.h"

class PlayerCell : public Cell
{
public:
    bool isUnknown()
    {
        if(val == UNKNOWN)
            return 1;
        return 0;
    }

    int unknownNeighbors()
    {
        int res = 0;
        for(auto it = neighbors.begin(); it < neighbors.end(); it++)
        {
            PlayerCell *cell = (PlayerCell*) *it;
            if(cell->isUnknown())
                res++;
        }
        return res;
    }
};

#endif