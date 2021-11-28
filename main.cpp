#include "board.h"
#include "game.h"
#include "player.h"
#include <iostream>

int main()
{
    Game game(4, 7, 5, 777);
    //game.print(GameCell::symbolWithCover);
    //board.printDebug();

    Player player(4, 7);
    



    Solution x = Solution(game.getStart(), FREE);
    while(x.isValid())
    {
        std::cout << x.id << " " << (int)x.val << "\n";
        x = game.evaluate(x);
        player.getInfo(x);
        player.print(Cell::getSymbol);
        x = player.getSol();
    }
    

    

    return 0;
}