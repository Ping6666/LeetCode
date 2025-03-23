#include <limits.h>
#include <vector>
#include <queue>
using std::vector, std::deque, std::pair;

// Runtime: 6 ms (Beats 97.75 %), Memory: 18.81 MB (Beats 72.86 %).

class Solution
{
    vector<vector<int>> dirs = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0},
    };

public:
    int minCost(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> min_cost(m, vector<int>(n, INT_MAX));
        min_cost[0][0] = 0;

        deque<pair<int, int>> dq;
        dq.push_back({0, 0});

        while (!dq.empty())
        {
            auto [i, j] = dq.front();
            dq.pop_front();

            for (int dir = 1; dir <= 4; dir++)
            {
                int _i = i + dirs[dir - 1][0];
                int _j = j + dirs[dir - 1][1];
                int cost = (grid[i][j] == dir) ? 0 : 1;

                if ((0 <= _i && _i < m) && (0 <= _j && _j < n) &&
                    (min_cost[i][j] + cost < min_cost[_i][_j]))
                {
                    min_cost[_i][_j] = min_cost[i][j] + cost;

                    if (cost == 1)
                    {
                        dq.push_back({_i, _j});
                    }
                    else
                    {
                        dq.push_front({_i, _j});
                    }
                }
            }
        }
        return min_cost[m - 1][n - 1];
    }
};
