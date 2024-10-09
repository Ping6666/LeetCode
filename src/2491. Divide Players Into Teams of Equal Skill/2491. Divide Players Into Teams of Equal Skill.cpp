#include <vector>
#include <unordered_map>
using std::vector, std::unordered_map;

// Runtime: 54 ms (Beats 92.60 %), Memory: 57.24 MB (Beats 14.60 %).

class Solution
{
public:
    long long dividePlayers(vector<int> &skill)
    {
        // all skill > 0

        int n = skill.size(), sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += skill[i];
        }
        int avg = sum / (n / 2);

        unordered_map<int, int> table;
        // or use vector

        for (int i = 0; i < n; i++)
        {
            table[skill[i] % avg]++;
        }

        long long ans = 0;

        int l, r;
        if (avg % 2 == 0)
        {
            if (table.find(avg / 2) != table.end())
            {
                l = table[avg / 2];
                if (l % 2 != 0)
                {
                    return -1;
                }
                else
                {
                    ans += (l / 2) * (long long)((avg / 2) * (avg / 2));
                }
            }
        }

        int mid = (avg % 2 == 0) ? ((avg / 2) - 1) : (avg / 2);
        for (int i = 1; i <= mid; i++)
        {
            l = -1, r = -1;
            if (table.find(i) != table.end())
            {
                l = table[i];
            }

            if (table.find(avg - i) != table.end())
            {
                r = table[avg - i];
            }

            if (l == -1 && r == -1)
            {
                continue;
            }
            else if (l != r)
            {
                return -1;
            }
            else
            {
                ans += l * (long long)(i * (avg - i));
            }
        }

        return ans;
    }
};
