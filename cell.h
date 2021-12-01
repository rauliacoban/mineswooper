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
        if(val == 0)
            return 1;
        return 0; 
    }

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

    bool isActive()
    {
        if(val > 0 && val <= DIRECTION_SIZE)
            return 1;
        return 0;
    }

    static char getSymbol(Cell* cell)
    {
        if(cell->isMine())
            return FLAG_C;
        if(cell->isEmpty())
            return EMPTY_C;
        if(cell->isUnknown())
            return FOG_C;
        if(cell->val > 0 && cell->val < DIRECTION_SIZE)
            return '0' + cell->val;
        return UNDEFINED_C;
    }

    bool isValid()
    {
        char res = Cell::getSymbol(this);
        if(res == UNDEFINED_C)
            return 0;
        return 1;
    }
};

#endif