#include "player.h"

Player::Player(size_t N, size_t M, int start):
    Board(N, M)
{
    for(int i = 0; i < size; i++)
        board[i].val = INVALID;
    getInfo(Solution::makeSol(start, 0));
}

void Player::getInfo(Solution info)
{
    PlayerCell *cell = board + info.id;
    cell->val = info.val;
    if(!cell->isMine())
    {
        work.push_back(cell);
    }
}