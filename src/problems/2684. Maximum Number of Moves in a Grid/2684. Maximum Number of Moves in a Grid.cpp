#include <vector>
using std::vector;

// Runtime: 8 ms (Beats 86.96 %), Memory: 69.76 MB (Beats 87.70 %).

class Solution
{
public:
    int maxMoves(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();

        vector<vector<bool>> dp(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++)
        {
            dp[i][0] = true;
        }

        int ans = 0;
        bool step = false;
        for (int j = 0; j < m - 1; j++)
        {
            step = false;
            for (int i = 0; i < n; i++)
            {
                if (dp[i][j])
                {
                    if ((i > 0) && (!dp[i - 1][j + 1]) &&
                        (grid[i][j] < grid[i - 1][j + 1]))
                    {
                        dp[i - 1][j + 1] = true;
                        step = true;
                    }
                    if ((!dp[i][j + 1]) &&
                        (grid[i][j] < grid[i][j + 1]))
                    {
                        dp[i][j + 1] = true;
                        step = true;
                    }
                    if ((i < n - 1) && (!dp[i + 1][j + 1]) &&
                        (grid[i][j] < grid[i + 1][j + 1]))
                    {
                        dp[i + 1][j + 1] = true;
                        step = true;
                    }
                }
            }

            if (!step)
            {
                break;
            }
            ans++;
        }

        return ans;
    }
};
