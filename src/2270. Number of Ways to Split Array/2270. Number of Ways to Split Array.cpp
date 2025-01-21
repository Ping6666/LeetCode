#include <vector>
using std::vector;

// Runtime: 0 ms (Beats 100.00 %), Memory: 89.20 MB (Beats 87.28 %).

class Solution
{
public:
    int waysToSplitArray(vector<int> &nums)
    {
        int n = nums.size();

        long sum_r = 0;
        long sum_l = 0;

        for (int i = 0; i < n; i++)
        {
            sum_r += nums[i];
        }

        int ans = 0;
        for (int i = 0; i < n - 1; i++)
        {
            sum_r -= nums[i];
            sum_l += nums[i];

            if (sum_l >= sum_r)
            {
                ans++;
            }
        }
        return ans;
    }
};
