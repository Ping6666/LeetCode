#include <vector>
#include <queue>
using std::vector, std::priority_queue, std::queue, std::pair;

// same as q.1765

// Runtime: 7 ms (Beats 93.93 %), Memory: 34.73 MB (Beats 76.00 %).

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
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int m = mat.size(), n = mat[0].size();
        queue<pair<int, int>> q;

        vector<vector<int>> ans(m, vector<int>(n, -1));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 0)
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
