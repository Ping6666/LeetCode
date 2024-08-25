#include <vector>
using std::vector, std::max;

// Runtime: 156 ms (Beats 95.37 %), Memory: 87.55 MB (Beats 85.83 %).

class Solution
{
public:
    long long maxPoints(vector<vector<int>> &points)
    {
        int m = points.size(), n = points[0].size();
        // printf("%d %d\n", m, n);

        vector<long long> curr(n, 0);
        vector<long long> prev(n, 0);
        long long _max;

        for (const auto &p : points)
        {
            // l to r
            _max = 0;
            for (int i = 0; i < n; i++)
            {
                _max = max(_max - 1, prev[i]);

                curr[i] = _max + p[i];
            }

            // r to l
            _max = 0;
            for (int i = n - 1; i >= 0; i--)
            {
                _max = max(_max - 1, prev[i]);

                curr[i] = max(_max + p[i], curr[i]);
            }

            prev = curr;
        }

        _max = 0;
        for (int i = 0; i < n; i++)
        {
            _max = max(_max, curr[i]);
        }

        return _max;
    }
};
