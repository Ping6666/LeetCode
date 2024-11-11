#include <vector>
#include <algorithm>
using std::vector, std::sort;

// Runtime: 27 ms (Beats 93.10 %), Memory: 12.81 MB (Beats 65.63 %).

// ref. LeetCode Editorial - Approach 4: Space Optimized Tabulation

class Solution
{
public:
    long long minimumTotalDistance(vector<int> &robot, vector<vector<int>> &factory)
    {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        vector<int> factory_pos;
        for (const auto &f : factory)
        {
            for (int i = 0; i < f[1]; i++)
            {
                factory_pos.push_back(f[0]);
            }
        }

        int n = robot.size(), m = factory_pos.size();
        vector<long long> _curr(m + 1, 0), _next(m + 1, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            if (i != n - 1)
            {
                _next[m] = 1e12;
            }
            _curr[m] = 1e12;

            for (int j = m - 1; j >= 0; j--)
            {
                _curr[j] = min(
                    // use curr factory
                    abs(robot[i] - factory_pos[j]) + _next[j + 1],
                    // skip curr factory
                    _curr[j + 1]
                );
            }

            _next = _curr;
        }

        return _next[0];
    }
};
