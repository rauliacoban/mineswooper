#ifndef SOLUTION_H
#define SOLUTION_H

class Solution
{
public:
    int id;
    char val;

    Solution(int id, char val):
        id(id),
        val(val)
    {}

    Solution(int id):
        id(id),
        val(INVALID)
    {}

    Solution():
        id(INVALID),
        val(INVALID)
    {}

    bool isValid()
    {
        return id != INVALID;
    }
};

#endif