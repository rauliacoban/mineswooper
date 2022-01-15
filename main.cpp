#include "board.h"
#include "game.h"
#include "player.h"
#include <iostream>
#include <string>

#include <windows.h>

int main(int argc, char **argv)
{
    size_t N, M, MINES, SEED;
    if(argc == 1)
    {
        N = 15;
        M = 31;
        MINES = 99;
        SEED = 0;
    }
    else if(argc == 2)
    {
        SEED = atoi(argv[1]);
    }
    else if(argc == 5)
    {
        SEED = atoi(argv[1]);
        N = atoi(argv[2]);
        M = atoi(argv[3]);
        MINES = atoi(argv[4]);
    }
    else
    {
        std::cout << "Provide in the command line when launching the program:\n";
        std::cout << "a seed for generating a game with standard settings OR\n";
        std::cout << "a seed, height of board, width of board and number of mines OR\n";
        std::cout << "leave empty for standard settings\n";
        exit(1);
    }
    
    Game game(N, M, MINES, SEED);
    //game.print(GameCell::symbolWithCover);
    //board.printDebug();

    Player player(N, M);

    Solution x = Solution(game.getStart(), FREE);
    Solution sol;
    bool is_over = 0;
    int skip = 0;

    while(x.isValid())
    {
        sol = x;
        x = game.evaluate(x);
        player.getInfo(x);;
        x = player.getSol();
        
        if(skip == 0)
        {
            game.print(GameCell::symbolWithCover);
            std::cout << "Press enter to advance 1 move or enter the number of moves to advance by\n";
            std::string str = "";
            std::getline(std::cin, str);
            if(str.empty())
            {
                skip = 1;
            }
            else
            {
                skip = stoi(str);
            }
        }
        skip--;
    }
    game.print(GameCell::symbolWithCover);

    std::cout << "I can't make any more moves\n seed: " << SEED << "\n";


    return 0;
}