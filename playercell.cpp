#include "playercell.h"
#include <map>

std::list<PlayerCell::Influence> PlayerCell::getCommonInfluence()
{
    std::list<Influence> influence;
    for(auto it = neighbors.begin(); it != neighbors.end(); it++)
    {
        PlayerCell *nbr = (PlayerCell*) *it;
        if(!nbr->isUnknown()) 
            continue;
        
        for(auto i = nbr->partial.begin(); i != nbr->partial.end(); i++)
        {
            PlayerCell *src = *i;
            if(src == this || !src->isFree())
                continue;

            bool is_in = 0;
            for(auto j = influence.begin(); j != influence.end() && !is_in; j++)
            {
                Influence *inf = &*j;
                if(inf->origin == src)
                {
                    inf->target.push_back(nbr);
                    is_in = 1;
                }
            }
            if(!is_in)
                influence.push_back(Influence(src, nbr));
        }
    }

    return influence;
}

std::list<PlayerCell::Influence> PlayerCell::getCommonMines()
{
    std::list<Influence> inf = getCommonInfluence();
    std::list<Influence> sol;
    for(auto it = inf.begin(); it != inf.end(); it++)
    {
        Influence *elem = &*it;
        if(elem->target.size() == elem->origin->partial.size())
        {
            sol.push_back(*elem);
        }
    }

    return sol;
}

int PlayerCell::permutation(std::list<PlayerCell::Influence> *influence, int *step_ret)
{
    int step = *step_ret;
    int pow = 2;
    for(auto it = influence->begin(); it != influence->end(); it++, pow*=2)
    {
        PlayerCell::Influence *inf = &(*it);
        if(step % pow)
            inf->used = 1;
        else
            inf->used = 0;
        step -= step % pow;
    }

    if(step == pow / 2)
        return 0;
    (*step_ret)++;
    return 1;
}

bool PlayerCell::checkPermutation(std::list<PlayerCell::Influence> *influence, std::map<PlayerCell*, bool> *occupied, int *occupied_val)
{
    for(auto it = influence->begin(); it != influence->end(); it++)
    {
        PlayerCell::Influence *inf = &(*it);
        if(inf->used)
        {
            *occupied_val += inf->origin->weight;
            for(auto i = inf->target.begin(); i != inf->target.end(); i++)
            {
                PlayerCell *cell = *i;
                if(occupied->count(cell))
                    return 0;
                else
                    occupied->emplace(cell, 1);
            }
        }
    }

    return 1;
}

bool PlayerCell::applyPermutation(std::list<Influence> *inf, int *occ_max)
{
    std::map<PlayerCell*, bool> occupied;
    int occupied_val = 0;
    if(!checkPermutation(inf, &occupied, &occupied_val))
        return 0;
    
    if(occupied_val <= *occ_max)
        return 0;
    
    *occ_max = occupied_val;
    weight = val - occupied_val;

    for(auto it = partial.begin(); it != partial.end(); it++)
    {
        PlayerCell *nbr = *it;
        nbr->partial.remove(this);
    }
    partial.clear();
    
    for(auto it = neighbors.begin(); it != neighbors.end(); it++)
    {
        PlayerCell *nbr = (PlayerCell*) *it;
        
        if(nbr->isUnknown() && !occupied.count(nbr))
        {
            bool is_in = std::find(nbr->partial.begin(), nbr->partial.end(), this) != nbr->partial.end();
            if(!is_in)
                nbr->partial.push_back(this);

            is_in = std::find(partial.begin(), partial.end(), this) != partial.end();
            if(!is_in)
            {
                partial.push_back(nbr);
            }
        }
        if(nbr->isActive())
        {
            nbr->partial.remove(this);
        }
    }

    return 1;
}

void PlayerCell::setPartial()
{
    if(!isFree())
        return;
    std::list<PlayerCell::Influence> inf = getCommonMines();

    weight = val;
    int occ_max = -1;
    int step = 0;
    while(permutation(&inf, &step))
    {
        applyPermutation(&inf, &occ_max);
    }
    
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