#include <vector>
using std::vector, std::max;

// Runtime: 57 ms (Beats 37.48 %), Memory: 12.27 MB (Beats 66.14 %).

class Solution
{
public:
    int stoneGameII(vector<int> &piles)
    {
        int n = piles.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        vector<int> suffix_sum(n + 1, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            dp[i][n] = suffix_sum[i] = suffix_sum[i + 1] + piles[i];
        }

        // curr pos.
        for (int i = n - 1; i >= 0; i--)
        {
            // max. m
            for (int j = n - 1; j >= 1; j--)
            {
                for (int m = 1; m <= 2 * j && m + i <= n; m++)
                {
                    // minus the op.
                    dp[i][j] = max(dp[i][j], suffix_sum[i] - dp[i + m][max(j, m)]);
                }
            }
        }

        return dp[0][1];
    }
};
