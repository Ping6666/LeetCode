#include <vector>
using std::vector;

// Runtime: 0 ms (Beats 100.00 %), Memory: 127.63 MB (Beats 87.50 %).

class Solution
{
public:
    vector<int> pivotArray(vector<int> &nums, int pivot)
    {
        const int n = nums.size();
        vector<int> ans(n, pivot);
        for (int i = 0, idx = 0; i < n; i++)
        {
            if (nums[i] < pivot)
            {
                ans[idx] = nums[i];
                idx++;
            }
        }
        for (int i = n - 1, idx = n - 1; i >= 0; i--)
        {
            if (nums[i] > pivot)
            {
                ans[idx] = nums[i];
                idx--;
            }
        }
        return ans;
    }
};
