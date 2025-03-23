#include <vector>
using std::vector;

// Runtime: 435 ms (Beats 5.00 %), Memory: 71.93 MB (Beats 29.86 %).

class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();

        int ans = 0;
        vector<int> table(k + 1, 0);

        for (int i = 0; i < n; i++)
        {
            if (nums[i] % 2 == 0)
            {
                // even
                // prev. stay all the same (do nothing)

                // curr. 0 odd will + 1
                table[0]++;
            }
            else
            {
                // odd
                // prev. stay all the same but shift one pos.
                table.insert(table.begin(), 0);
                table.pop_back();

                // curr. 1 odd will + 1
                table[1]++;
            }

            ans += table[k];
        }

        return ans;
    }
};
