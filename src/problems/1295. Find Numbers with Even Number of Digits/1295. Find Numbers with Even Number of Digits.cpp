#include <vector>
using std::vector;

// Runtime: 0 ms (Beats 100.00 %), Memory: 13.15 MB (Beats 99.22 %).

// Constraints
//   1 <= nums[i] <= 1e5

class Solution
{
public:
    int findNumbers(vector<int> &nums)
    {
        int ans = 0;
        for (const int num : nums)
        {
            if ((10 <= num && num < 100) || (1000 <= num && num < 10000) || (100000 == num))
            {
                ans++;
            }
        }
        return ans;
    }
};
