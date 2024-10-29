#include <vector>
using std::vector;

// Runtime: 1 ms (Beats 89.30 %), Memory: 28.95 MB (Beats 68.35 %).

class Solution
{
private:
    int solve(vector<vector<int>> &matrix,
              vector<vector<int>> &dp,
              const int &n, const int &m,
              int i, int j)
    {
        if (i >= n || j >= m)
        {
            return 0;
        }
        if (matrix[i][j] == 0)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int r = solve(matrix, dp, n, m, i, j + 1);
        int d = solve(matrix, dp, n, m, i + 1, j + 1);
        int b = solve(matrix, dp, n, m, i + 1, j);

        dp[i][j] = 1 + min(r, min(d, b));
        return dp[i][j];
    }

public:
    int countSquares(vector<vector<int>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ans += solve(matrix, dp, n, m, i, j);
            }
        }

        return ans;
    }
};
