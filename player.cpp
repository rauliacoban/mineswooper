#include "player.h"

Player::Player(size_t N, size_t M):
    Board(N, M)
{
    for(int i = 0; i < size; i++)
        board[i].val = UNKNOWN;
}

void Player::getInfo(Solution info)
{
    PlayerCell *cell = board + info.id;
    cell->val = info.val;
    if(!cell->isMine())
    {
        work.push_back(cell);
    }

    for(auto it = cell->neighbors.begin(); it != cell->neighbors.end(); it++)
    {
        PlayerCell *nbr = (PlayerCell*)*it;
        if(nbr->unknownNeighbors() == 0)
            work.remove(nbr);
    }
}

Solution Player::getSol()
{
    std::cout << "work: ";
    for(auto it = work.begin(); it != work.end(); it++)
    {
        PlayerCell *cell = *it;
        std::cout << cell->id << " ";
    }
    std::cout << "\n";

    return solveTrivial();
}

Solution Player::solveTrivial()
{
    for(auto it = work.begin(); it != work.end(); it++)
    {
        
        PlayerCell *cell = *it;
        if(cell->unknownNeighbors() == cell->val)
        {
            for(auto i = cell->neighbors.begin(); i != cell->neighbors.end(); i++)
            {
                PlayerCell *nbr = (PlayerCell*)*i;
                if(nbr->isUnknown())
                {
                    return Solution(nbr->id, MINE);
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
    }

    return Solution(INVALID);
}