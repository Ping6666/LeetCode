#include <limits.h>
#include <vector>
using std::vector, std::max, std::min;

// Runtime: 0 ms (Beats 100.00 %), Memory: 66.50 MB (Beats 97.28 %).

class Solution
{
public:
    long long gridGame(vector<vector<int>> &grid)
    {
        int n = grid[0].size();
        if (n == 1)
        {
            return 0;
        }

        long long upper_sum = 0;
        long long lower_sum = 0;
        for (int i = 0; i < n; i++)
        {
            upper_sum += grid[0][i];
        }
        upper_sum -= grid[0][0];

        long long ans = LLONG_MAX;
        for (int i = 0; i < n; i++)
        {
            if (i != 0)
            {
                upper_sum -= grid[0][i];
            }

            // printf("%d %d %d\n", i, upper_sum, lower_sum);
            ans = min(ans, max(upper_sum, lower_sum));

            lower_sum += grid[1][i];
        }
        return ans;
    }
};
