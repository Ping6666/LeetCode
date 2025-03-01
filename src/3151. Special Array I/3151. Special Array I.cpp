#include <vector>
using std::vector;

// Runtime: 0 ms (Beats 100.00 %), Memory: 27.54 MB (Beats 86.97 %).

class Solution
{
public:
    bool isArraySpecial(vector<int> &nums)
    {
        int p = -1;
        for (const auto &n : nums)
        {
            if (p != -1)
            {
                if (p % 2 == n % 2)
                {
                    return false;
                }
            }
            p = n;
        }
        return true;
    }
};
