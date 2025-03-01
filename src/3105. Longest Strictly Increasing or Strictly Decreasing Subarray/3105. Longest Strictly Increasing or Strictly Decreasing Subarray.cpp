#include <vector>
using std::vector, std::max;

// Runtime: 0 ms (Beats 100.00 %), Memory: 27.72 MB (Beats 89.71 %).

class Solution
{
public:
    int longestMonotonicSubarray(vector<int> &nums)
    {
        int ans = 1;

        int p = nums[0];
        int si = 1, sd = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            sd = p > nums[i] ? sd + 1 : 1;
            si = p < nums[i] ? si + 1 : 1;

            p = nums[i];
            ans = max(ans, max(si, sd));
        }
        return ans;
    }
};
