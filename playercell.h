#ifndef PLAYERCELL_H
#define PLAYERCELL_H

#include "cell.h"
#include <list>
#include <map>
#include <algorithm>



class PlayerCell : public Cell
{
public:
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
            used = 0;
        }
    };
    
public:
    std::list<PlayerCell*> partial;
    char weight;
public:
    int neighborsType(char type);
    static bool checkPermutation(std::list<PlayerCell::Influence> *influence, std::map<PlayerCell*, bool> *occupied, int *occupied_val);
    static int permutation(std::list<PlayerCell::Influence> *influence, int *step);
    bool applyPermutation(std::list<Influence> *inf, int *occ_max);
    std::list<Influence> getCommonInfluence();
    std::list<Influence> getCommonMines();
    void setPartial();
};

#endif