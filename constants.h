#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <utility>
#include <iostream> //debugging purposes

#define INVALID -16
#define MINE -32
#define UNKNOWN -24 // uncovered for player
#define FREE -8 // 0 -> DIRECTION_SIZE
#define ACTIVE -40 // 1 -> DIRECTION_SIZE
#define UNDEFINED_C '?'
#define FOG_C '#'
#define EXPLODE_C '!'
#define FLAG_C 'X'
#define EMPTY_C ' '
const std::pair<int, int> DIRECTION[] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, 
                                            {1, 1}, {1, 0}, {1, -1}, {0, -1}};
const size_t DIRECTION_SIZE = sizeof(DIRECTION) / sizeof(DIRECTION[0]);
const std::pair<int, int> INVALID_PAIR = {INVALID, INVALID};

#endif