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

int Game::getStart()
{
    while(true)
    {
        int id = rand() % size;
        if(board[id].isEmpty())
            return id;
    }
}

Solution Game::evaluate(Solution sol)
{
    GameCell *cell = board + sol.id;
    cell->setCover(0);

    if(cell->isMine())
    {
        if(sol.val != MINE)
            gameOver(sol);
    }
    else
    {
        if(sol.val != FREE)
            gameOver(sol);
    }

    return Solution(sol.id, cell->val);
}

void Game::gameOver(Solution sol)
{
    std::cout << "MISTAKE at cell(" << getCoords(sol.id).first << ", " << getCoords(sol.id).second << ")\n";
    exit(0);
}