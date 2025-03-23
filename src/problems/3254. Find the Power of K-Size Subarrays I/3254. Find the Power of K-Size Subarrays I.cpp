#include <vector>
using std::vector;

// Runtime: 0 ms (Beats 100.00 %), Memory: 32.91 MB (Beats 77.25 %).

class Solution
{
public:
    vector<int> resultsArray(vector<int> &nums, int k)
    {
        if (k == 1)
        {
            return nums;
        }

        int n = nums.size();
        vector<int> ans(n - k + 1, -1);

        int _consecutive = 1, _p = nums[0], _i = -k + 2;
        for (int i = 1; i < n; i++, _i++)
        {
            if ((nums[i] - _p) == 1)
            {
                // sorted
                _consecutive++;

                if (_i >= 0 && _consecutive >= k)
                {
                    ans[_i] = nums[i];
                }
            }
            else
            {
                _consecutive = 1;
            }

            _p = nums[i];
        }

        return ans;
    }
};
