#include "playercell.h"

bool PlayerCell::isUnknown()
{
    if(val == UNKNOWN)
        return 1;
    return 0;
}

bool PlayerCell::isFree()
{
    if(val >= 0 && val <= DIRECTION_SIZE)
        return 1;
    return 0;
}

bool PlayerCell::isActive()
{
    if(val > 0 && val <= DIRECTION_SIZE)
        return 1;
    return 0;
}

int PlayerCell::neighborsType(char type)
{
    int res = 0;
    
    for(auto it = neighbors.begin(); it < neighbors.end(); it++)
    {
        PlayerCell *nbr = (PlayerCell*) *it;

        if(type == ACTIVE)
        {
            if(nbr->val > 0 && nbr->val < DIRECTION_SIZE)
                res++;
        }
        else if(nbr->val == type)
            res++;
    }
    return res;
}