#include "player.h"

Player::Player(size_t N, size_t M):
    Board(N, M)
{
    for(int i = 0; i < size; i++)
        board[i].val = UNKNOWN;
}

void Player::getInfo(Solution info)
{
    PlayerCell *cell = &board[info.id];
    cell->val = info.val;

    for(auto it = cell->neighbors.begin(); it != cell->neighbors.end(); it++)
    {
        PlayerCell *nbr = (PlayerCell*)*it;
        if(nbr->neighborsType(UNKNOWN) == 0)
            work.remove(nbr);

        if(cell->isMine())
        {
            if(nbr->isFree())
                nbr->val--;
            if(nbr->isUnknown())
                nbr->partial.remove(cell);
        }
        else
        {
            if(nbr->isMine())
                cell->val--;
        }
    }

    cell->weight = cell->val;
    if(cell->isMine())
        cell->partial.clear();
    if(cell->isFree())
    {
        if(cell->isActive())
            cell->setPartial();
        else
            cell->partial.clear();
    
        if(cell->neighborsType(UNKNOWN))
            work.push_back(cell);
    }
}

Solution Player::getSol()
{
    Solution sol;
    sol = solve(solveTrivial);
    if(sol.isValid())
        return sol;

    sol = solve(solvePartial);
    if(sol.isValid())
        return sol;

    return Solution(INVALID);
}

Solution Player::solve(Solution(Player::*algorithm)(PlayerCell*))
{
    for(auto it = work.begin(); it != work.end(); it++)
    {
        PlayerCell *cell = (PlayerCell*) *it;
        Solution sol = (this->*algorithm)(cell);
        
        if(sol.isValid())
            return sol;
    }

    return Solution(INVALID);
}

Solution Player::solveTrivial(PlayerCell *cell)
{
    if(cell->neighborsType(UNKNOWN) == cell->val)
    {
        for(auto i = cell->neighbors.begin(); i != cell->neighbors.end(); i++)
        {
            PlayerCell *nbr = (PlayerCell*)*i;
            if(nbr->isUnknown())
            {
                return Solution(nbr->id, MINE, cell->id);
            }
        }
    }
    if(cell->isEmpty())
    {
        for(auto i = cell->neighbors.begin(); i != cell->neighbors.end(); i++)
        {
            PlayerCell *nbr = (PlayerCell*)*i;
            if(nbr->isUnknown())
            {
                return Solution(nbr->id, FREE);
            }
        }
    } 
    return Solution(INVALID);
}

Solution Player::solvePartial(PlayerCell *cell)
{
    cell->setPartial();
    if(!cell->partial.empty())
    {
        if(cell->weight == 0)
            return Solution((*(cell->partial.begin()))->id, FREE, cell->id);
        if(cell->weight == cell->partial.size())
            return Solution((*(cell->partial.begin()))->id, MINE, cell->id);
    }
    

    return Solution(INVALID);
}