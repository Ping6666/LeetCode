// Runtime: 0 ms (Beats 100.00 %), Memory: 7.70 MB (Beats 99.69 %).

class Solution
{
public:
    long long coloredCells(int n)
    {
        // do / 2 * 4
        return (long long)(n - 1) * (long long)(n) * 2 + 1;
    }
};
