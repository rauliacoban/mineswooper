#ifndef SOLUTION_H
#define SOLUTION_H


class Solution
{
public:
    int id;
    int origin_id;
    char val;

    Solution(int id, char val, int origin_id):
        id(id),
        val(val),
        origin_id(origin_id)
    {}

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