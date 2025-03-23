#include <vector>
using std::vector;

// Runtime: 0 ms (Beats 100.00 %), Memory: 139.88 MB (Beats 93.66 %).

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        const int n = nums.size();

        int ans = 0;
        for (int i = 0; i < n - 2; i++)
        {
            if (nums[i] == 1)
            {
                // good
                continue;
            }
            else
            {
                // do flip
                ans++;
                nums[i + 1] = (nums[i + 1] + 1) % 2;
                nums[i + 2] = (nums[i + 2] + 1) % 2;
            }
        }

        if (nums[n - 1] == 1 && nums[n - 2] == 1)
        {
            // good
            return ans;
        }
        return -1;
    }
};
