#ifndef CELL_H
#define CELL_H

#include <vector>
#include "constants.h"

class Cell
{
public:
    int id;
    char val;
    std::vector<Cell*> neighbors;

    bool isMine()
    {
        if(val == MINE)
            return 1;
        return 0;
    }

    char getSymbol()
    {
        if(isMine())
            return MINE;
        if(val == 0)
            return EMPTY;
        if(val > 0 && val < DIRECTION_SIZE)
            return '0' + val;
        return UNDEFINED;
    }
};

#endif