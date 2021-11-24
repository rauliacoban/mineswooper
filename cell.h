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

    bool isEmpty()
    {
        if(val == EMPTY)
            return 1;
        return 0; 
    }

    static char getSymbol(Cell* cell)
    {
        if(cell->isMine())
            return MINE;
        if(cell->isEmpty())
            return EMPTY;
        if(cell->val > 0 && cell->val < DIRECTION_SIZE)
            return '0' + cell->val;
        return UNDEFINED;
    }
};

#endif