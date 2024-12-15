#include <vector>
#include <queue>
using std::vector, std::priority_queue;

// Runtime: 1504 ms (Beats 5.15 %), Memory: 240.53 MB (Beats 5.66 %).

class Solution
{
public:
    int minimumTime(vector<vector<int>> &grid)
    {
        if (grid[0][1] > 1 && grid[1][0] > 1)
        {
            return -1;
        }

        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> dir = {
            {0, 1},
            {0, -1},
            {1, 0},
            {-1, 0},
        };

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<vector<int>, vector<vector<int>>, std::greater<>> pq;
        pq.push({grid[0][0], 0, 0});

        while (!pq.empty())
        {
            auto t = pq.top();
            pq.pop();

            int time = t[0], i = t[1], j = t[2];

            if (i == m - 1 && j == n - 1)
            {
                return time;
            }

            if (visited[i][j])
            {
                continue;
            }
            visited[i][j] = true;

            for (const auto &d : dir)
            {
                int ii = i + d[0], jj = j + d[1];
                if (!(0 <= ii && ii < m && 0 <= jj && jj < n))
                {
                    continue;
                }

                // stand for move toward & backward
                int wait_time = ((grid[ii][jj] - time) % 2 ? 0 : 1);

                int next_time = max(grid[ii][jj] + wait_time, time + 1);

                pq.push({next_time, ii, jj});
            }
        }

        return -1;
    }
};
