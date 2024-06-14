#include <vector>
#include <algorithm>
using std::vector, std::sort;

class Solution
{
    // Runtime: 30 ms (Beats 94.31 %), Memory: 31.53 MB (Beats 93.42 %).

public:
    int arrayPairSum(vector<int> &nums)
    {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int ans = 0;
        for (int i = 0; i < n; i += 2)
        {
            ans += nums[i];
        }

        return ans;
    }
};
