#include <vector>
using std::vector, std::max, std::min;

// Runtime: 0 ms (Beats 100.00 %), Memory: 93.88 MB (Beats 62.97 %).

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        const int n = nums.size();

        long long ans = 0;
        int start_idx = -1, minK_idx = -1, maxK_idx = -1;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] < minK || nums[i] > maxK)
            {
                start_idx = i;
            }
            if (nums[i] == minK)
            {
                minK_idx = i;
            }
            if (nums[i] == maxK)
            {
                maxK_idx = i;
            }

            ans += max(0, min(minK_idx, maxK_idx) - start_idx);
        }
        return ans;
    }
};
