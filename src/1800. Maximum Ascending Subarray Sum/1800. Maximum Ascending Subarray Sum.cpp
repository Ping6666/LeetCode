#include <vector>
using std::vector, std::max;

// Runtime: 0 ms (Beats 100.00 %), Memory: 11.05 MB (Beats 77.09 %).

class Solution
{
public:
    int maxAscendingSum(vector<int> &nums)
    {
        int p = nums[0];
        int ans = p;
        int sum = p;

        for (const auto &n : nums)
        {
            if (p < n)
            {
                sum += n;
            }
            else
            {
                sum = n;
            }
            p = n;
            ans = max(ans, sum);
        }
        return ans;
    }
};
