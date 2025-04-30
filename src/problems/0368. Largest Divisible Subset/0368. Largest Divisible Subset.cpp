#include <vector>
#include <algorithm>
using std::vector, std::sort, std::reverse;

// Runtime: 8 ms (Beats 85.49 %), Memory: 12.42 MB (Beats 91.73 %).

class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        const int n = nums.size();

        vector<int> dp(n, 1); // LIS
        vector<int> prev(n, -1);

        int last_idx = 0;
        for (int j = 1; j < n; j++)
        {
            for (int i = 0; i < j; i++)
            {
                if (nums[j] % nums[i] == 0 && dp[i] + 1 > dp[j])
                {
                    dp[j] = dp[i] + 1;
                    prev[j] = i;
                }
            }
            if (dp[j] > dp[last_idx])
            {
                last_idx = j;
            }
        }

        vector<int> ans;
        while (last_idx >= 0)
        {
            ans.push_back(nums[last_idx]);
            last_idx = prev[last_idx];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
