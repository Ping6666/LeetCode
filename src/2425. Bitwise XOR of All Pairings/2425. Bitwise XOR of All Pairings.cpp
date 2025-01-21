#include <vector>
using std::vector;

// Runtime: 0 ms (Beats 100.00 %), Memory: 64.13 MB (Beats 82.93 %).

class Solution
{
public:
    int xorAllNums(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();

        int ans = 0;
        if (n1 % 2 == 1)
        {
            // odd
            for (const auto &n : nums2)
            {
                ans ^= n;
            }
        }
        if (n2 % 2 == 1)
        {
            // odd
            for (const auto &n : nums1)
            {
                ans ^= n;
            }
        }
        return ans;
    }
};
