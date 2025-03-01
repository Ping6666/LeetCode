#include <vector>
using std::vector, std::max, std::min;

// Runtime: 0 ms (Beats 100.00 %), Memory: 45.03 MB (Beats 78.26 %).
// Kadane's algorithm

class Solution
{
public:
    int maxAbsoluteSum(vector<int> &nums)
    {
        const int n = nums.size();

        int ans = 0, curr_max = 0, curr_min = 0;
        for (int i = 0; i < n; i++)
        {
            curr_max = max(0, curr_max + nums[i]);
            curr_min = min(0, curr_min + nums[i]);

            ans = max(ans, max(curr_max, -curr_min));
        }
        return ans;
    }
};
