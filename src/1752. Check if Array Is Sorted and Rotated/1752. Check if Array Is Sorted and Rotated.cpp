#include <vector>
using std::vector;

// Runtime: 0 ms (Beats 100.00 %), Memory: 11.01 MB (Beats 85.59 %).

class Solution
{
public:
    bool check(vector<int> &nums)
    {
        int s = nums[0], p;

        int fail_times = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (p != -1)
            {
                if (p > nums[i])
                {
                    fail_times++;

                    if (fail_times >= 2)
                    {
                        return false;
                    }
                }
            }
            p = nums[i];
        }

        if (fail_times == 1 && s < p)
        {
            return false;
        }
        return true;
    }
};
