#include <vector>
using std::vector;

// Runtime: 110 ms (Beats 97.66 %), Memory: 70.60 MB (Beats 98.95 %).

class Solution
{
public:
    int findCenter(vector<vector<int>> &edges)
    {
        if (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1])
        {
            return edges[0][0];
        }

        return edges[0][1];
    }
};
