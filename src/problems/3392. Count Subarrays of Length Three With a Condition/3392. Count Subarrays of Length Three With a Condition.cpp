#include <vector>
using std::vector;

// Runtime: 0 ms (Beats 100.00 %), Memory: 48.22 MB (Beats 95.92 %).

class Solution
{
public:
    int countSubarrays(vector<int> &nums)
    {
        const int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n - 2; i++)
        {
            if (2 * (nums[i] + nums[i + 2]) == nums[i + 1])
            {
                ans++;
            }
        }
        return ans;
    }
};
