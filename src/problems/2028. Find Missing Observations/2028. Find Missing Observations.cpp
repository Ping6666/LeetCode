#include <vector>
using std::vector;

// Runtime: 80 ms (Beats 95.83 %), Memory: 116.29 MB (Beats 86.03 %).

class Solution
{
public:
    vector<int> missingRolls(vector<int> &rolls, int mean, int n)
    {
        int remains = (rolls.size() + n) * mean;
        for (const auto &r : rolls)
        {
            remains -= r;
        }

        int e = remains % n, b = remains / n;
        if (b < 1 || b > 6 || (b == 6 && e > 0))
        {
            return {};
        }

        vector<int> ans(n, b);
        for (int i = 0; i < e; i++)
        {
            ans[i]++;
        }

        return ans;
    }
};
