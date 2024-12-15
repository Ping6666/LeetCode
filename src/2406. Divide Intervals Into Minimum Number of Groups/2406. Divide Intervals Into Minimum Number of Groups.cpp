#include <vector>
#include <limits.h>
using std::vector, std::min, std::max;

// Runtime: 247 ms (Beats 87.16 %), Memory: 214.67 MB (Beats 14.41 %).

class Solution
{
public:
    int minGroups(vector<vector<int>> &intervals)
    {
        int range_start = INT_MAX, range_end = INT_MIN;
        for (const auto &i : intervals)
        {
            range_start = min(range_start, i[0]);
            range_end = max(range_end, i[1]);
        }

        vector<int> table(range_end + 2, 0);
        for (const auto &i : intervals)
        {
            table[i[0]]++;
            table[i[1] + 1]--;
        }

        int curr_groups = 0, max_groups = 0;
        for (int i = range_start; i <= range_end; i++)
        {
            curr_groups += table[i];
            max_groups = max(max_groups, curr_groups);
        }

        return max_groups;
    }
};
