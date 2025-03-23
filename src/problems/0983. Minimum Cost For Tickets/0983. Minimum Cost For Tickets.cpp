#include <vector>
using std::vector, std::max, std::min;

// Runtime: 0 ms (Beats 100.00 %), Memory: 12.73 MB (Beats 62.37 %).

class Solution
{
public:
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        int n = days.size();
        int last_day = days[n - 1];
        vector<int> dp(last_day + 1, 0);

        int idx = 0;
        for (int d = 1; d <= last_day; d++)
        {
            if (d < days[idx])
            {
                dp[d] = dp[d - 1];
            }
            else
            {
                dp[d] = min({
                    dp[d - 1] + costs[0],
                    dp[max(d - 7, 0)] + costs[1],
                    dp[max(d - 30, 0)] + costs[2],
                });
                idx++;
            }
        }
        return dp[last_day];
    }
};
