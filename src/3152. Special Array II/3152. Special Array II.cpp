#include <vector>
using std::vector;

// Runtime: 0 ms (Beats 100.00 %), Memory: 126.37 MB (Beats 71.06 %).

class Solution
{
public:
    vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size(), m = queries.size();
        vector<bool> ans(m, false);
        vector<int> prefix(n, 0);

        for (int i = 1; i < n; i++)
        {
            if (nums[i - 1] % 2 == nums[i] % 2)
            {
                // same
                prefix[i] = prefix[i - 1] + 1;
            }
            else
            {
                // else
                prefix[i] = prefix[i - 1];
            }
        }

        for (int i = 0; i < m; i++)
        {
            ans[i] = prefix[queries[i][0]] == prefix[queries[i][1]];
        }

        return ans;
    }
};
