#include <vector>
using std::vector;

// Runtime: 0 ms (Beats 100.00 %), Memory: 38.26 MB (Beats 87.50 %).

class Solution
{
public:
    long long maxMatrixSum(vector<vector<int>> &matrix)
    {
        long long ans = 0;
        int _min = INT_MAX;
        int neg_count = 0;

        for (const auto &row : matrix)
        {
            for (const auto &val : row)
            {
                ans += abs(val);

                if (val < 0)
                {
                    neg_count++;
                }

                _min = min(_min, abs(val));
            }
        }

        if (neg_count % 2 != 0)
        {
            ans -= 2 * _min;
        }

        return ans;
    }
};
