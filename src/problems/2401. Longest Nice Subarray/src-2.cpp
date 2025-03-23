#include <vector>
using std::vector, std::max;

// Runtime: 0 ms (Beats 100.00 %), Memory: 60.80 MB (Beats 99.56 %).

class Solution
{
public:
    int longestNiceSubarray(vector<int> &nums)
    {
        const int n = nums.size();
        int l = 0, r = 0;

        int use_bits = 0;
        int ans = 1;
        while (r < n)
        {
            while ((use_bits & nums[r]) != 0)
            {
                // remove l
                use_bits ^= nums[l];
                l++;
            }

            use_bits |= nums[r];
            r++;

            ans = max(ans, r - l);
        }
        return ans;
    }
};
