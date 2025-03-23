#include <vector>
#include <queue>
using std::vector, std::queue, std::pair, std::max;

// Runtime: 10 ms (Beats 52.71 %), Memory: 108.01 MB (Beats 23.29 %).

class Solution
{
private:
    int bfs(const int &m, const int &n,
            vector<vector<int>> &grid,
            const int &i, const int &j)
    {
        if (grid[i][j] == 0)
        {
            return 0;
        }

        int ans = 0;
        queue<pair<int, int>> q;
        q.push({i, j});

        while (!q.empty())
        {
            auto [ii, jj] = q.front();
            q.pop();

            if (0 <= ii && ii < m && 0 <= jj && jj < n && grid[ii][jj] != 0)
            {
                ans += grid[ii][jj];
                grid[ii][jj] = 0;

                q.push({ii, jj + 1});
                q.push({ii, jj - 1});
                q.push({ii + 1, jj});
                q.push({ii - 1, jj});
            }
        }

        return ans;
    }

public:
    int findMaxFish(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();

        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    continue;
                }

                ans = max(ans, bfs(m, n, grid, i, j));
            }
        }
        return ans;
    }
};
