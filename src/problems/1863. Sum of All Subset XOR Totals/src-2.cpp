#include <vector>
using std::vector;

// Runtime: 0 ms (Beats 100.00 %), Memory: 9.06 MB (Beats 90.00 %).

class Solution
{
public:
    int subsetXORSum(vector<int> &nums)
    {
        int ans = 0;
        for (const auto n : nums)
        {
            ans |= n;
        }
        return ans << (nums.size() - 1);
    }
};
