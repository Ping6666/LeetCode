#include <vector>
using std::vector;

// Runtime: 47 ms (Beats 93.02 %), Memory: 13.11 MB (Beats 98.87 %).

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int _sum = 0;
        for (const int n : nums)
        {
            _sum += n;
        }
        if (_sum % 2 != 0)
        {
            return false;
        }
        _sum /= 2;

        vector<bool> dp(_sum + 1, false);
        dp[0] = true;
        for (const int n : nums)
        {
            for (int i = _sum; i - n >= 0; i--)
            {
                dp[i] = dp[i] || dp[i - n];
                if (dp[_sum])
                {
                    return true;
                }
            }
        }
        return dp[_sum];
    }
};
