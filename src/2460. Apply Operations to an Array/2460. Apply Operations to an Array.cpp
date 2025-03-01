#include <vector>
using std::vector;

// Runtime: 0 ms (Beats 100.00 %), Memory: 12.94 MB (Beats 99.53 %).

class Solution
{
public:
    vector<int> applyOperations(vector<int> &nums)
    {
        const int n = nums.size();
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                nums[i] *= 2;
                nums[i + 1] = 0;
                i++;
            }
        }

        vector<int> ans(n, 0);
        int idx = 0;
        for (const auto &n : nums)
        {
            if (n != 0)
            {
                ans[idx] = n;
                idx++;
            }
        }
        return ans;
    }
};
