#ifndef PLAYER_H
#define PLAYER_H

#include "board.h"
#include "playercell.h"
#include "solution.h"
#include <list>
#include "influence.h"

class Player: public Board<PlayerCell>
{
private:
    std::list<PlayerCell*> work;
public:
    Player(size_t N, size_t M);
    Solution getSol();
    void getInfo(Solution info);

public:
    Solution solve(Solution(Player::*algorithm)(PlayerCell*));
    Solution solveTrivial(PlayerCell *cell);

    Solution solvePartial(PlayerCell *cell);
};


#endif