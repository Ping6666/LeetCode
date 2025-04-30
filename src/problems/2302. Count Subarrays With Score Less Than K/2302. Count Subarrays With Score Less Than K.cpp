#include <vector>
using std::vector;

// Runtime: 0 ms (Beats 100.00 %), Memory: 98.87 MB (Beats 97.61 %).

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, long long k)
    {
        long long prefix_sum = 0;

        const int n = nums.size();
        int l = 0, r = 0;

        long long ans = 0;
        while (l < n)
        {
            while (r < n && ((prefix_sum + nums[r]) * (r - l + 1)) < k)
            {
                prefix_sum += nums[r];
                r++;
            }

            // remove the check can speed up a bit
            // if ((prefix_sum * (r - l)) < k)
            {
                ans += (r - l);
            }

            prefix_sum -= nums[l];
            l++;
        }
        return ans;
    }
};
