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

    bool isFree()
    {
        if(val >= 0 && val <= DIRECTION_SIZE)
            return 1;
        return 0;
    }

    int neighborsType(char type)
    {
        int res = 0;
        for(auto it = neighbors.begin(); it < neighbors.end(); it++)
        {
            PlayerCell *cell = (PlayerCell*) *it;
            if(cell->val == type)
                res++;
        }
        return res;
    }
};

#endif