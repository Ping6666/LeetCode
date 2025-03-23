#include <limits.h>
#include <vector>
using std::vector, std::min;

// Runtime: 0 ms (Beats 100.00 %), Memory: 7.99 MB (Beats 42.85 %).
// DP

class Solution
{
public:
    int minSteps(int n)
    {
        vector<int> table(n, INT_MAX);

        table[0] = 0;
        for (int i = 0; i < n; i++)
        {
            int prev = table[i] + 1;
            for (int j = 2 * (i + 1) - 1; j < n; j += (i + 1))
            {
                prev++;
                table[j] = min(table[j], prev);
            }
        }

        return table[n - 1];
    }
};
