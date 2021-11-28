#include "board.h"
#include "solution.h"

class Game: public Board<GameCell>
{
private:
    size_t n_bombs;
    int seed;

public:
    Game(size_t N, size_t M, size_t n_bombs, int seed);
    int getStart();
    Solution evaluate(Solution sol);

private:
    void populate();
    void gameOver(Solution sol);
};