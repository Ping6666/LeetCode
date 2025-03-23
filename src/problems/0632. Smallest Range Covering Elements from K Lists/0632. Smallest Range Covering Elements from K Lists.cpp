#include <vector>
#include <algorithm>
using std::vector, std::pair, std::sort;

// Runtime: 31 ms (Beats 98.24 %), Memory: 21.64 MB (Beats 60.47 %).

class Solution
{
public:
    vector<int> smallestRange(vector<vector<int>> &nums)
    {
        int n = nums.size();
        vector<pair<int, int>> table;
        for (int i = 0; i < n; i++)
        {
            for (const auto &num : nums[i])
            {
                table.emplace_back(num, i);
            }
        }
        sort(table.begin(), table.end());

        vector<int> freq(n, 0);

        int l = 0, c = 0;
        int rl = -100000, rr = 100000;

        for (int r = 0; r < table.size(); r++)
        {
            if (freq[table[r].second] == 0)
            {
                c++;
            }
            freq[table[r].second]++;

            if (c == n)
            {
                while (l < r)
                {
                    if (freq[table[l].second] <= 1)
                    {
                        // can not shrink
                        break;
                    }

                    freq[table[l++].second]--;
                }

                // curr idx range [l, r]

                // [a, b]: [table[l].first, table[r].first]
                // [c, d]: [            rl,             rr]

                if (((table[r].first - table[l].first) < (rr - rl)) ||
                    (((table[r].first - table[l].first) == (rr - rl)) && (table[l].first < rl)))
                {
                    rl = table[l].first;
                    rr = table[r].first;
                }
            }
        }

        return {rl, rr};
    }
};
