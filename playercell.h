#ifndef PLAYERCELL_H
#define PLAYERCELL_H

#include "cell.h"

class PlayerCell : public Cell
{
public:
    bool isUnknown();
    bool isFree();
    bool isActive();
    int neighborsType(char type);
};

#endif