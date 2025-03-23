#include <vector>
#include <algorithm>
#include <iostream>
using std::vector, std::sort;

// Runtime: 75 ms (Beats 98.82 %), Memory: 68.72 MB (Beats 97.24 %).

// magic 1
static auto _sync = std::ios_base::sync_with_stdio(0);
static auto _cin = std::cin.tie(0);
static auto _cout = std::cout.tie(0);

class Solution
{
public:
    int minIncrementForUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        int ans = 0, n = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] <= n)
            {
                ans += (++n) - nums[i];
            }
            else
            {
                n = nums[i];
            }
        }

        return ans;
    }
};
