#ifndef BOARD_H
#define BOARD_H

#include "cell.h"
#include "playercell.h"
#include "gamecell.h"
#include <cstdlib>
#include <iostream>

template<class CellType> class Board
{
protected:
    size_t N, M, size;
    CellType *board;

public:
    Board(size_t N, size_t M);
    void printDebug();
    
private:
    int goDirection(int id, int dir);
    void buildNeighbors(int id);

protected:
    bool isValid(int x, int y)
    {
        if(x < 0 || y < 0 || x >= N || y >= M)
            return 0;
        return 1;
    }

    bool isValid(std::pair<int, int> coords)
    {
        return isValid(coords.first, coords.second);
    }

    bool isValid(int id)
    {
        if(id < 0 || id >= size)
            return 0;
        return 1;
    }

    int getId(int x, int y)
    {
        if(!isValid(x, y))
            return INVALID;
        return x * M + y;
    }

    int getId(std::pair<int, int> coords)
    {
        return getId(coords.first, coords.second);
    }

    std::pair<int, int> getCoords(int id)
    {
        if(!isValid(id))
            return INVALID_PAIR;
        int x = id / M;
        int y = id % M;
        return std::make_pair(x, y);
    }
};


#endif