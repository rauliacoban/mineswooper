#ifndef BOARD_H
#define BOARD_H

#include "cell.h"
#include <cstdlib>
#include <iostream>

template<class CellType> class Board
{
protected:
    size_t N, M, size;
    CellType *board;
public:
    Board(size_t N, size_t M):
        N(N),
        M(M)
    {
        size = N * M;
        std::cout << sizeof(CellType) << "\n";
        board = (CellType*) calloc(size, sizeof(CellType));
        if(board == NULL)
        {
            std::cout << "ERROR while allocating memory. Exiting.\n";
            exit(1);
        }
        
        for(int i = 0; i < size; i++)// NEEDS TESTING!
        {
            Cell *cell = (Cell*) board + i;
            cell->id = i;
            cell->symbol = UNDEFINED;
            buildNeighbors(i);
        }
    }

protected:
    bool isValid(int x, int y)
    {
        if(x < 0 || y < 0 || x >= M || y >= N)
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

private:
    int goDirection(int id, int dir)
    {
        std::pair<int, int> neighbor = getCoords(id);
        if(neighbor == INVALID_PAIR)
            return INVALID;

        neighbor.first += DIRECTION[dir].first;
        neighbor.second += DIRECTION[dir].second;

        if(isValid(neighbor))
            return getId(neighbor);
        return INVALID;
    }

    void buildNeighbors(int id)
    {
        size_t dir_size = sizeof(DIRECTION) / sizeof(DIRECTION[0]);
        for(int dir  = 0; dir < dir_size; dir++)
        {
            int neighbor = goDirection(id, dir);
            if(isValid(neighbor))
                board[id].neighbors.push_back(board + neighbor);
        }
    }
};


#endif