#include <vector>

using std::vector;

class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        int len = nums.size();
        if (len <= 2)
        {
            return false;
        }
        if (len == 3)
        {
            return nums[0] < nums[1] && nums[1] < nums[2];
        }

        vector<int> right_max = vector<int>(len);
        right_max[len - 1] = nums[len - 1];
        for (int i = len - 2; i >= 0; i--)
        {
            right_max[i] = std::max(right_max[i + 1], nums[i]);
        }

        int _min = nums[0];
        for (int i = 1; i < len; i++)
        {
            if (_min < nums[i] && nums[i] < right_max[i])
            {
                return true;
            }
            _min = std::min(_min, nums[i]);
        }

        return false;
    }
};
