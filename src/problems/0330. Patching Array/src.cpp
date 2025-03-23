#include <vector>
using std::vector;

// Runtime: 0 ms (Beats 100.00 %), Memory: 13.58 MB (Beats 97.87 %).

class Solution
{
public:
    int minPatches(vector<int> &nums, int n)
    {
        long long curr_check = 0;
        int add_count = 0, nums_idx = 0, l = nums.size();

        while (curr_check < n)
        {
            if (nums_idx < l && nums[nums_idx] <= curr_check + 1)
            {
                curr_check += nums[nums_idx];
                nums_idx++;
            }
            else
            {
                // has no curr val. or remain part
                add_count++;
                curr_check += curr_check + 1;
            }
        }

        return add_count;
    }
};
