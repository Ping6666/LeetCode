#include <vector>
#include <algorithm>

using std::vector, std::sort, std::min, std::max;

class Solution
{
public:
    int minLights(vector<int> &lights)
    {
        const int n = lights.size();
        vector<vector<int>> intervals;

        for (int i = 0; i < n; i++)
        {
            int v = lights[i];
            if (v == 0)
            {
                continue;
            }

            vector<int> interval = vector<int>(2);
            interval[0] = max(0, i - v);
            interval[1] = min(n - 1, i + v);
            intervals.push_back(interval);
        }

        int ans = 0, p = 0, d, l, r;
        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < intervals.size(); i++)
        {
            l = intervals[i][0];
            r = intervals[i][1];

            d = l - p;
            p = max(p, r + 1);
            if (d <= 0)
            {
                // covered
                continue;
            }

            ans += d / 3;
            if (d % 3 != 0)
            {
                ans++;
            }
        }

        d = n - p; // magic (suppose [n, ...] is covered)
        if (d > 0)
        {
            ans += d / 3;
            if (d % 3 != 0)
            {
                ans++;
            }
        }
        return ans;
    }
};
