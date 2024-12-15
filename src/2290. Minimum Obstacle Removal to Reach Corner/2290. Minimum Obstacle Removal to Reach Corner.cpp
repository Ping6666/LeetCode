#include <limits.h>
#include <vector>
#include <queue>
using std::vector, std::deque;

// Runtime: 623 ms (Beats 33.34 %), Memory: 276.35 MB (Beats 16.70 %).

class Solution
{
public:
    int minimumObstacles(vector<vector<int>> &grid)
    {
        int dir[4][2] = {
            {0, 1},
            {0, -1},
            {1, 0},
            {-1, 0},
        };

        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> table(m, vector<int>(n, INT_MAX));
        table[0][0] = 0;

        deque<vector<int>> d;
        d.push_back({0, 0, 0});

        while (!d.empty())
        {
            auto f = d.front();
            d.pop_front();

            int o = f[0], i = f[1], j = f[2];

            for (const auto &_dir : dir)
            {
                int ii = i + _dir[0], jj = j + _dir[1];

                if (0 <= ii && ii < m && 0 <= jj && jj < n && table[ii][jj] == INT_MAX)
                {
                    if (grid[ii][jj] == 1)
                    {
                        // obs
                        table[ii][jj] = o + 1;
                        d.push_back({o + 1, ii, jj});
                    }
                    else
                    {
                        table[ii][jj] = o;
                        d.push_front({o, ii, jj});
                    }
                }
            }
        }

        return table[m - 1][n - 1];
    }
};
