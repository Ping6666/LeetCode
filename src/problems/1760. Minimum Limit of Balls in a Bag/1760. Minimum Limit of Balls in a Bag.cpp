#include <vector>
using std::vector;

// Runtime: 31 ms (Beats 74.00 %), Memory: 59.67 MB (Beats 28.46 %).

class Solution
{
private:
    bool fit(vector<int> &nums, const int &_max, int _step)
    {
        int _curr = 0, t;
        for (const auto &n : nums)
        {
            t = n / _step;
            if (t * _step < n)
            {
                t++;
            }

            // minus one: no need to count self
            _curr += (t - 1);

            if (_curr > _max)
            {
                return false;
            }
        }

        return _curr <= _max;
    }

public:
    int minimumSize(vector<int> &nums, int maxOperations)
    {
        int l = 1, r = 1e9;
        int ans, m;

        while (l <= r)
        {
            m = l + (r - l) / 2;
            if (fit(nums, maxOperations, m))
            {
                ans = m;
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }

        return ans;
    }
};
