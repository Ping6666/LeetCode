#include <vector>
#include <unordered_map>
using std::vector, std::unordered_map;

// Runtime: 3 ms (Beats 99.75 %), Memory: 12.48 MB (Beats 24.87 %).

class Solution
{
public:
    int countMaxOrSubsets(vector<int> &nums)
    {
        unordered_map<int, int> table, next_table;

        int max_or = 0;

        for (const auto &n : nums)
        {
            next_table.clear();

            next_table[n] += 1;

            if (max_or < n)
            {
                max_or = n;
            }

            for (const auto &t : table)
            {
                next_table[t.first | n] += t.second;
            }

            for (const auto &t : next_table)
            {
                table[t.first] += t.second;

                if (max_or < t.first)
                {
                    max_or = t.first;
                }
            }
        }

        return table[max_or];
    }
};
