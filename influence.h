#ifndef INFLUENCE_H
#define INFLUENCE_H

#include "playercell.h"

class Influence
{
public:
    PlayerCell *origin;
    std::vector<PlayerCell*> target;
    bool used;

    Influence(PlayerCell *src, PlayerCell *tgt)
    {
        origin = src;
        target.push_back(tgt);
    }
};

#endif