#include <vector>
#include <unordered_set>
using std::vector, std::unordered_set;

// Runtime: 6 ms (Beats 71.70 %), Memory: 29.38 MB (Beats 69.22 %).

class Solution
{
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
    {
        unordered_set<int> s;

        const int n = grid.size();
        int sum = (n * n) * ((n * n) + 1) / 2;

        int a = -1;
        for (const auto &_grid : grid)
        {
            for (const auto &g : _grid)
            {
                if (a == -1)
                {
                    if (s.find(g) == s.end())
                    {
                        s.insert(g);
                    }
                    else
                    {
                        a = g;
                    }
                }

                sum -= g;
            }
        }

        return {a, a + sum};
    }
};
