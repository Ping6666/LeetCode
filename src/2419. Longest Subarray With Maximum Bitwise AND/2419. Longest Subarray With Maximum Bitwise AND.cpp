#include <vector>
using std::vector;

// Runtime: 96 ms (Beats 82.68 %), Memory: 84.76 MB (Beats 90.79 %).

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int max_num = nums[0];
        for (const auto &n : nums)
        {
            if (n > max_num)
            {
                max_num = n;
            }
        }

        int ans = 0, tmp = 0;
        for (const auto &n : nums)
        {
            if (n == max_num)
            {
                tmp++;

                if (tmp > ans)
                {
                    ans = tmp;
                }
            }
            else
            {
                tmp = 0;
            }
        }

        return ans;
    }
};
