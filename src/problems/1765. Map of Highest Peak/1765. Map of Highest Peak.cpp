#include <vector>
#include <queue>
using std::vector, std::priority_queue, std::queue, std::pair;

// same as q.0542

// BFS + queue
//   Runtime: 75 ms (Beats 74.51 %), Memory: 112.76 MB (Beats 85.31 %).

// BFS + priority_queue
//   Runtime: 721 ms (Beats 6.67 %), Memory: 108.75 MB (Beats 93.93 %).

class Solution
{
private:
    vector<vector<int>> dirs = {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0},
    };

public:
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater)
    {
        int m = isWater.size(), n = isWater[0].size();
        queue<pair<int, int>> q;

        vector<vector<int>> ans(m, vector<int>(n, -1));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isWater[i][j] == 1)
                {
                    q.push({i, j});
                    ans[i][j] = 0;
                }
            }
        }

        int h = 1, c;
        while (!q.empty())
        {
            c = q.size();
            for (int i = 0; i < c; i++)
            {
                auto f = q.front();
                q.pop();

                for (const auto &d : dirs)
                {
                    int _row = f.first + d[0];
                    int _col = f.second + d[1];

                    if (0 <= _row && _row < m && 0 <= _col && _col < n && ans[_row][_col] == -1)
                    {
                        q.push({_row, _col});
                        ans[_row][_col] = h;
                    }
                }
            }
            h++;
        }
        return ans;
    }
};
