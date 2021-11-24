#include "game.h"

Game::Game(size_t N, size_t M, size_t n_bombs, int seed):
    Board(N, M),
    n_bombs(n_bombs),
    seed(seed)
{
    for(int i = 0; i < size; i++)
        board[i].setCover(1);
    populate();
}

void Game::populate()
{
    srand(seed);
    size_t count = n_bombs;

    while(count)
    {
        int idx = rand() % size;
        std::cout << idx << "\n";
        GameCell *cell = board + idx;
        if(!cell->isMine())
        {
            cell->val = MINE;
            count--;

            for(int i = 0; i < cell->neighbors.size(); i++)
            {
                GameCell *neighbor = (GameCell*) cell->neighbors[i];
                if(!neighbor->isMine())
                    neighbor->val++;
            }
        }
    }   
}

