#include <vector>
using std::vector, std::max;

// Runtime: 0 ms (Beats 100.00 %), Memory: 23.70 MB (Beats 78.44 %).

// in-place

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        const int n = nums.size();

        int prev_zero_idx = 0, prev_non_zero_idx = 0;
        int zero_idx, non_zero_idx;
        while (true)
        {
            zero_idx = prev_zero_idx;
            while (zero_idx < n && nums[zero_idx] != 0)
            {
                zero_idx++;
            }

            if (zero_idx == n)
            {
                // no more zero after non-zero
                return;
            }

            non_zero_idx = max(zero_idx + 1, prev_non_zero_idx);
            while (non_zero_idx < n && nums[non_zero_idx] == 0)
            {
                non_zero_idx++;
            }

            if (non_zero_idx == n)
            {
                // no more non-zero after zero
                return;
            }

            // swap
            nums[zero_idx] = nums[non_zero_idx];
            nums[non_zero_idx] = 0;

            // move to next
            prev_zero_idx = zero_idx + 1;
            prev_non_zero_idx = non_zero_idx + 1;
        }
    }
};
