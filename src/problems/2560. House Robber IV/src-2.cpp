#include <vector>
using std::vector;

// Runtime: 21 ms (Beats 70.94 %), Memory: 60.82 MB (Beats 67.69 %).

class Solution
{
public:
    int minCapability(vector<int> &nums, int k)
    {
        const int n = nums.size();
        int l = 0, r = 1e9 + 1;
        int ans = -1, m, c;
        while (l < r)
        {
            m = l + (r - l) / 2;
            c = 0;

            for (int i = 0; i < n; i++)
            {
                if (nums[i] <= m)
                {
                    c++;
                    i++;
                }
            }

            if (c >= k)
            {
                r = m;
                ans = m;
            }
            else
            {
                l = m + 1;
            }
        }
        return ans;
    }
};
