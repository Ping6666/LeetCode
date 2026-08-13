#include <vector>

using std::vector;

// Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int num_zero = 0;
        int last_zero_idx = -1;
        long long int p = 1;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                num_zero++;
                last_zero_idx = i;
            }
            else
            {
                p *= nums[i];
            }
        }

        vector<int> ans = vector<int>(nums.size(), 0);
        if (num_zero >= 2)
        {
            return ans;
        }
        else if (num_zero == 1)
        {
            ans[last_zero_idx] = p;
            return ans;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            ans[i] = (int)(p / nums[i]);
        }

        return ans;
    }
};
