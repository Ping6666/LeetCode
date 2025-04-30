#include <vector>
#include <unordered_map>
using std::vector, std::unordered_map, std::max;

// Runtime: 143 ms (Beats 5.05 %), Memory: 150.29 MB (Beats 5.36 %).

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

        unordered_map<int, int> m;

        long long ans = 0;
        while (l < n)
        {
            while (r < n && (l == r || m[_max] < k))
            {
                m[nums[r]]++;
                r++;
            }

            if (l != r && m[_max] >= k)
            {
                ans += n - r + 1;
            }

            m[nums[l]]--;
            l++;
        }
        return ans;
    }
};
