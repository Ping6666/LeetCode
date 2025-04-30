#include <vector>
using std::vector;

// Runtime: 0 ms (Beats 100.00 %), Memory: 15.40 MB (Beats 91.08 %).

class Solution
{
public:
    int countPairs(vector<int> &nums, int k)
    {
        const int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] != nums[j])
                {
                    continue;
                }

                if ((i * j) % k == 0)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};
