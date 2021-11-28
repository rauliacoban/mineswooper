#ifndef PLAYER_H
#define PLAYER_H

#include "board.h"
#include "playercell.h"
#include "solution.h"
#include <list>

class Player: public Board<PlayerCell>
{
private:
    std::list<PlayerCell*> work;
public:
    Player(size_t N, size_t M, int start);
    Solution getSol();
    void getInfo(Solution info);

private:
};


#endif