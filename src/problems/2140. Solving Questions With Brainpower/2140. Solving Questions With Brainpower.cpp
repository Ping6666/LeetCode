#include <vector>
using std::vector, std::max;

// Runtime: 0 ms (Beats 100.00 %), Memory: 119.62 MB (Beats 86.16 %).

class Solution
{
public:
    long long mostPoints(vector<vector<int>> &questions)
    {
        const int n = questions.size();

        long long ans = 0;
        vector<long long> dp(n, 0);
        for (int i = 0; i < n; i++)
        {
            // solve
            int ii = i + questions[i][1] + 1;
            long long _curr = dp[i] + (long long)questions[i][0];

            if (ii < n)
            {
                dp[ii] = max(dp[ii], _curr);
            }
            else
            {
                ans = max(ans, _curr);
            }

            // skip
            if (i + 1 < n)
            {
                dp[i + 1] = max(dp[i + 1], dp[i]);
            }
            else
            {
                ans = max(ans, dp[i]);
            }

            // printf("%d | ", ans);
            // for (int j = 0; j < n; j++)
            // {
            //     printf("%d ", dp[j]);
            // }
            // printf("\n");
        }
        return max(ans, dp[n - 1]);
    }
};
