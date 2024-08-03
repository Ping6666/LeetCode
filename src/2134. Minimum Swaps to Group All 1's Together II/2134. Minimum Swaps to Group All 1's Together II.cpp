#include <vector>
using std::vector, std::min;

// Runtime: 55 ms (Beats 96.66 %), Memory: 82.97 MB (Beats 62.08 %).

class Solution
{
public:
    int minSwaps(vector<int> &nums)
    {
        int n = nums.size();

        int num_one = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 1)
            {
                num_one++;
            }
        }

        if (num_one == 0 || num_one == n)
        {
            return 0;
        }

        int min_swap = n;
        int curr_one = 0;

        for (int i = 0; i < num_one; i++)
        {
            if (nums[i] == 1)
            {
                curr_one++;
            }
        }

        min_swap = min(min_swap, num_one - curr_one);

        // int j;
        for (int i = 0; i < n; i++)
        {
            // j = (i + num_one) % n;
            if (nums[i] == 1)
            {
                curr_one--;
            }
            if (nums[(i + num_one) % n] == 1)
            {
                curr_one++;
            }
            min_swap = min(min_swap, num_one - curr_one);
        }

        return min_swap;
    }
};
