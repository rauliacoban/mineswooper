#include "board.h"
#include "game.h"
#include "player.h"
#include <iostream>

int main()
{
    const size_t N = 15;
    const size_t M = 31;
    const size_t MINES = 99;
    const size_t SEED = 675;

    Game game(N, M, MINES, SEED);
    //game.print(GameCell::symbolWithCover);
    //board.printDebug();

    Player player(N, M);
    



    Solution x = Solution(game.getStart(), FREE);
    while(x.isValid())
    {
        std::cout << x.id << " " << (int)x.val << "\n";
        x = game.evaluate(x);
        player.getInfo(x);
        //player.print(Cell::getSymbol);
        game.print(GameCell::symbolWithCover);
        x = player.getSol();
    }
    

    

    return 0;
}