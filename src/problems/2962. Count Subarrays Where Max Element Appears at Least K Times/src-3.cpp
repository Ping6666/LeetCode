#include <vector>
using std::vector, std::max;

// Runtime: 0 ms (Beats 100.00 %), Memory: 121.59 MB (Beats 95.79 %).

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        const int n = nums.size();
        int l = 0, r = 0;

        int _max = 0;
        for (const auto num : nums)
        {
            _max = max(_max, num);
        }

        int num_freq = 0;

        long long ans = 0;
        while (l < n)
        {
            while (r < n && num_freq < k)
            {
                if (nums[r] == _max)
                {
                    num_freq++;
                }
                r++;
            }

            if (l != r && num_freq >= k)
            {
                ans += n - r + 1;
            }

            if (nums[l] == _max)
            {
                num_freq--;
            }
            l++;
        }
        return ans;
    }
};
