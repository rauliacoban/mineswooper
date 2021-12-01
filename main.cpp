#include "board.h"
#include "game.h"
#include "player.h"
#include <iostream>

int main()
{
    const size_t N = 4;
    const size_t M = 12;
    const size_t MINES = 7;
    const size_t SEED = 2623;

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

    PlayerCell *cell = &player.board[1];
    std::cout << (int)cell->weight << " partial " << cell->id << ": ";
    for(auto it = cell->partial.begin(); it != cell->partial.end(); it++)
    {
        PlayerCell *c = *it;
        player.printCoords(c);
    }
    std::cout << "\n";

    cell = &player.board[13];
    std::cout << (int)cell->weight << " partial " << cell->id << ": ";
    for(auto it = cell->partial.begin(); it != cell->partial.end(); it++)
    {
        PlayerCell *c = *it;
        player.printCoords(c);
    }
    std::cout << "\n";

    cell = &player.board[25];
    std::cout << (int)cell->weight << " partial " << cell->id << ": ";
    for(auto it = cell->partial.begin(); it != cell->partial.end(); it++)
    {
        PlayerCell *c = *it;
        player.printCoords(c);
    }
    std::cout << "\n";

    cell = &player.board[37];
    std::cout << (int)cell->weight << " partial " << cell->id << ": ";
    for(auto it = cell->partial.begin(); it != cell->partial.end(); it++)
    {
        PlayerCell *c = *it;
        player.printCoords(c);
    }
    std::cout << "\n";

/*
    player.board[0].val = INVALID;

    player.board[2].val = UNKNOWN;
    player.board[4].val = UNKNOWN;
    player.board[8].val = UNKNOWN;
    player.board[10].val = UNKNOWN;
    player.board[6].val = INVALID;
    player.board[7].val = INVALID;
    player.board[9].val = INVALID;
    player.board[11].val = INVALID;
    player.board[1].val = 1;
    player.board[3].val = 2;
    player.board[5].val = 1;

    player.print(PlayerCell::getSymbol);

    player.board[1].setPartial();
    //player.board[3].setPartial();
    player.board[5].setPartial();
    player.board[3].setPartial();
    //player.board[1].setPartial();

    PlayerCell *cell = &player.board[5];
    std::cout << (int)cell->weight << " partial 5: ";
    for(auto it = cell->partial.begin(); it != cell->partial.end(); it++)
    {
        PlayerCell *c = *it;
        player.printCoords(c);
    }
    std::cout << "\n";

    cell = &player.board[3];
    std::cout << (int)cell->weight << " partial 3: ";
    for(auto it = cell->partial.begin(); it != cell->partial.end(); it++)
    {
        PlayerCell *c = *it;
        player.printCoords(c);
    }
    std::cout << "\n";

    cell = &player.board[1];
    std::cout << (int)cell->weight << " partial 1: ";
    for(auto it = cell->partial.begin(); it != cell->partial.end(); it++)
    {
        PlayerCell *c = *it;
        player.printCoords(c);
    }
    std::cout << "\n";
*/
    return 0;
}