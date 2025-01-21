#include <cmath>
#include <numeric>
#include <vector>
using std::vector, std::accumulate, std::abs;

// Runtime: 7 ms (Beats 71.87 %), Memory: 24.28 MB (Beats 33.24 %).

class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int total_sum = accumulate(nums.begin(), nums.end(), 0);

        if (abs(target) > total_sum)
        {
            return 0;
        }

        vector<int> dp(2 * total_sum + 1, 0);
        dp[total_sum + nums[0]] += 1;
        dp[total_sum - nums[0]] += 1;

        int n = nums.size();
        for (int i = 1; i < n; i++)
        {
            vector<int> next_dp(2 * total_sum + 1, 0);
            for (int j = -total_sum; j <= total_sum; j++)
            {
                if (dp[j + total_sum] > 0)
                {
                    next_dp[j + total_sum + nums[i]] += dp[j + total_sum];
                    next_dp[j + total_sum - nums[i]] += dp[j + total_sum];
                }
            }
            dp = next_dp;
        }

        return dp[target + total_sum];
    }
};
