#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <utility>
#include <iostream> //debugging purposes

#define INVALID -1
#define UNDEFINED '?'
#define FOG '#'
#define EXPLODE '!'
#define MINE 'X'
#define EMPTY ' '
const std::pair<int, int> DIRECTION[] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, 
                                            {0, 1}, {1, -1}, {1, 0}, {1, 1}};
const std::pair<int, int> INVALID_PAIR = {-1, -1};

#endif