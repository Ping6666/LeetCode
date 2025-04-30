#include <vector>
#include <algorithm>
using std::vector, std::sort, std::max;

// Runtime: 59 ms (Beats 86.39 %), Memory: 126.42 MB (Beats 80.10 %).

class Solution
{
public:
    int countDays(int days, vector<vector<int>> &meetings)
    {
        sort(meetings.begin(), meetings.end());

        int ans = 0;
        int prev = 0;
        for (const auto &m : meetings)
        {
            // printf("%d %d\n", m[0], m[1]);

            // got available days
            ans += max(m[0] - prev - 1, 0);

            prev = max(prev, m[1]);
        }
        ans += max(days - prev, 0);
        return ans;
    }
};
