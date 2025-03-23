#include <vector>
using std::vector, std::max;

// Runtime: 35 ms (Beats 72.68 %), Memory: 47.13 MB (Beats 19.42 %).

class Solution
{
public:
    int maxWidthRamp(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> right_max(n, 0);
        right_max[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--)
        {
            right_max[i] = max(right_max[i + 1], nums[i]);
        }

        int l = 0, r = 0;
        int max_ramp = 0;

        while (r < n)
        {
            while (l < r && nums[l] > right_max[r])
            {
                l++;
            }
            max_ramp = max(max_ramp, r - l);
            r++;
        }

        return max_ramp;
    }
};
