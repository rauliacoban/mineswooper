#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <utility>

#define UNDEFINED '?'
#define FOG '#'
#define EXPLODE '!'
#define MINE 'X'
#define EMPTY ' '
const std::pair<int, int> directions[] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, 
                                            {0, 1}, {1, -1}, {1, 0}, {1, 1}};

#endif