#include <vector>
using std::vector, std::max;

class Solution
{
public:
    long long minTime(vector<int> &skill, vector<int> &mana)
    {
        const int n = skill.size(), m = mana.size();

        vector<vector<long long>> dp(m, vector<long long>(n + 1, 0));
        for (int i = 0; i < m; i++)
        {
            // for each Potion

            bool re_compute = false;

            if (i != 0)
            {
                dp[i][0] = dp[i - 1][1];
            }
            for (int j = 1; j <= n; j++)
            {
                // for each Wizard

                // if no-sync
                dp[i][j] = dp[i][j - 1] + skill[j - 1] * mana[i];

                if (i > 0 && j != n)
                {
                    // check sync
                    if (dp[i][j] < dp[i - 1][j + 1])
                    {
                        dp[i][j] = dp[i - 1][j + 1];
                        re_compute = true;
                    }
                }

                // printf("%lld ", dp[i][j]);
            }

            if (re_compute)
            {
                for (int j = n; j >= 1; j--)
                {
                    dp[i][j - 1] = dp[i][j] - skill[j - 1] * mana[i];
                    // printf("%lld ", dp[i][j - 1]);
                }
            }
            // printf("\n");
        }
        return dp[m - 1][n];
    }
};
