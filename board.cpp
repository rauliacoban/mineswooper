#include "board.h"

template<class CellType> 
Board<CellType>::Board(size_t N, size_t M):
    N(N),
    M(M)
{
    size = N * M;
    board = (CellType*) calloc(size, sizeof(CellType));
    if(board == NULL)
    {
        std::cout << "ERROR while allocating memory. Exiting.\n";
        exit(1);
    }
    
    for(int i = 0; i < size; i++)
    {
        Cell *cell = (Cell*) board + i;
        cell->id = i;
        cell->symbol = UNDEFINED;
        buildNeighbors(i);
    }
}

template<class CellType> 
void Board<CellType>::printDebug()
{
    for(int i = 0; i < size; i++)
    {
        Cell *cell = board + i;
        std::cout << "(" << getCoords(i).first << ", " << getCoords(i).second << "):   ";
        for(int j = 0; j < cell->neighbors.size(); j++)
        {
            Cell *neighbor = cell->neighbors[j];
            std::cout << "(" << getCoords(neighbor->id).first << ", " << getCoords(neighbor->id).second << ")";
        }
        std::cout << "\n";
    }
}

template<class CellType> 
int Board<CellType>::goDirection(int id, int dir)
{
    std::pair<int, int> neighbor = getCoords(id);
    if(neighbor == INVALID_PAIR)
        return INVALID;

    neighbor.first += DIRECTION[dir].first;
    neighbor.second += DIRECTION[dir].second;

    return getId(neighbor);
}

template<class CellType> 
void Board<CellType>::buildNeighbors(int id)
{
    size_t dir_size = sizeof(DIRECTION) / sizeof(DIRECTION[0]);
    for(int dir  = 0; dir < dir_size; dir++)
    {
        int neighbor = goDirection(id, dir);
        if(isValid(neighbor))
            board[id].neighbors.push_back(board + neighbor);
    }
}

template class Board<Cell>;