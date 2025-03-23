#include <vector>
using std::vector, std::max;

// Runtime: 0 ms (Beats 100.00 %), Memory: 21.26 MB (Beats 95.51 %).

class Solution
{
public:
    int maximumCount(vector<int> &nums)
    {
        int pos = 0, neg = 0;
        for (const auto &n : nums)
        {
            if (n > 0)
            {
                pos++;
            }
            else if (n < 0)
            {
                neg++;
            }
        }
        return max(pos, neg);
    }
};
