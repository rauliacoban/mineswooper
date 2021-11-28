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

    static Solution makeSol(int id, char val)
    {
        return Solution(id, val);
    }
};

#endif