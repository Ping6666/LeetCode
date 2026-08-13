#include <vector>

using std::vector;

class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        int s = 0, m;
        for (int i = 0; i < k; i++)
        {
            s += nums[i];
        }
        m = s;
        for (int i = 0; i < nums.size() - k; i++)
        {
            s -= nums[i];
            s += nums[i + k];
            m = std::max(s, m);
        }
        return (double)m / k;
    }
};
