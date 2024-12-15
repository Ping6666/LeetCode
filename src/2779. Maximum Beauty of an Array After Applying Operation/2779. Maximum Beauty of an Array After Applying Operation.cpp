#include <vector>
#include <algorithm>
using std::vector, std::sort;

// Runtime: 39 ms (Beats 87.31 %), Memory: 104.95 MB (Beats 84.24 %).

class Solution
{
public:
    int maximumBeauty(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int l = 0, r = 0;

        int ans = 0;

        for (l = 0; l < n; l++)
        {
            while (r < n && nums[r] - nums[l] <= 2 * k)
            {
                r++;
            }

            ans = max(ans, r - l);
        }

        return ans;
    }
};
