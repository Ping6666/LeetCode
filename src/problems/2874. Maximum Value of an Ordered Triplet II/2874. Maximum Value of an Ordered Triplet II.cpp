#include <vector>
using std::vector, std::max;

// Runtime: 0 ms (Beats 100.00 %), Memory: 90.68 MB (Beats 100.00 %).

class Solution
{
public:
    long long maximumTripletValue(vector<int> &nums)
    {
        const int n = nums.size();
        int _max = 0, _dmax = 0;
        long long ans = 0;
        for (int k = 0; k < n; k++)
        {
            ans = max(ans, (long long)_dmax * nums[k]);
            _max = max(_max, nums[k]);
            _dmax = max(_dmax, _max - nums[k]);
        }
        return ans;
    }
};
