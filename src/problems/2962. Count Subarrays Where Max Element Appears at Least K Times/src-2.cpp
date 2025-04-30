#include <vector>
using std::vector, std::max;

// Runtime: 1071 ms (Beats 5.05 %), Memory: 308.34 MB (Beats 5.36 %).

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

        vector<int> num_freq(1e6 + 1, 0);

        long long ans = 0;
        while (l < n)
        {
            while (r < n && num_freq[_max] < k)
            {
                num_freq[nums[r]]++;
                r++;
            }

            if (l != r && num_freq[_max] >= k)
            {
                ans += n - r + 1;
            }

            num_freq[nums[l]]--;
            l++;
        }
        return ans;
    }
};
