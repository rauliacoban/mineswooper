#ifndef CELL_H
#define CELL_H

#include <vector>
#include "constants.h"

class Cell
{
public:
    int id;
    char val;
    char symbol;
    std::vector<Cell*> neighbors;

    bool isMine()
    {
        if(val == MINE)
            return 1;
        return 0;
    }

    
};

#endif