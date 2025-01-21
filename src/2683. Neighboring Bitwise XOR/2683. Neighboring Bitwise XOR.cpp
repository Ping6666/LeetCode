#include <vector>
using std::vector;

// Runtime: 0 ms (Beats 100.00 %), Memory: 263.86 MB (Beats 74.77 %).

class Solution
{
public:
    bool doesValidArrayExist(vector<int> &derived)
    {
        int ans = 0;
        for (const auto &d : derived)
        {
            ans ^= d;
        }
        return ans == 0;
    }
};
